#include "StdAfx.h"
#include "AntColony.h"

AntColony::AntColony(double alpha,double beta,double rho,double Q,int max_ants,int max_city,int max_siklus)
{
	this->alpha=alpha;
	this->beta=beta;
	this->rho = rho;
	this->Q =Q;
	this->max_ants = max_ants;
	this->max_city = max_city;
	this->max_siklus = max_siklus;
	
}

void AntColony::InitAnts()
{
  //  ants = gcnew array<double,2> (max_ants,max_city);
	Random ^random = gcnew Random();
    ants =gcnew array<array<int > ^ >(max_ants);
	for(int i=0;i<max_ants;i++)
	{
		int start = random->Next(0,max_city);
		ants[i] = RandomTrail(start);
	}
}



array<int > ^AntColony::RandomTrail(int start)
{
	Random ^random = gcnew Random();
    array<int > ^trail = gcnew  array<int >(max_city);

      for (int i = 0; i < max_city; ++i) { trail[i] = i; }  

      for (int i = 0; i < max_city; ++i)  
      {
        int r = random->Next(i, max_city);
        int tmp = trail[r]; trail[r] = trail[i]; trail[i] = tmp;
      }

      int idx = IndexOfTarget(trail, start);  
      int temp = trail[0];
      trail[0] = trail[idx];
      trail[idx] = temp;
      return trail;
}

int AntColony::IndexOfTarget(array<int > ^trail,int target)
{
	for (int i = 0; i < trail->Length; ++i)
      {
        if (trail[i] == target)
          return i;
      }
}
 
double AntColony::CountLength(array<int > ^trail)
{
    double result = 0.0;
	for (int i = 0; i < trail->Length - 1; ++i)
        result += jarakkota[trail[i]][trail[i + 1]]; 
    return result;
}

 array<int > ^AntColony::BestTrail()
 {	 
	 double bestLength = CountLength(ants[0]);
     int idxBestLength = 0;
     for (int k = 1; k < ants->Length; ++k)
     {
        double len = CountLength(ants[k]);
        if (len < bestLength)
        {
          bestLength = len;
          idxBestLength = k;
        }
      }
	 int numCities = ants[0]->Length;
     array<int> ^bestTrail = gcnew array<int>(max_city); 
	 ants[idxBestLength]->CopyTo(bestTrail,0);
     return bestTrail;
 }

 void AntColony::InitPheromones()
 {
     pheromones = gcnew array<array<double > ^ >(max_city);
      for (int i = 0; i < max_city; ++i)
        pheromones[i] = gcnew array<double>(max_city);
      for (int i = 0; i < pheromones->Length; ++i)
        for (int j = 0; j < pheromones[i]->Length; ++j)
          pheromones[i][j] = 0.01; 
     
 }

 void AntColony::UpdateAnts()
 {
	 Random ^random = gcnew Random();
     int numCities = pheromones->Length;
      for (int k = 0; k < ants->Length; ++k)
      {
		  int start = random->Next(0, max_city);
		   
       array<int> ^ newTrail = BuildTrail(k, start );
         ants[k] = newTrail;
      }
 }

  array<int> ^ AntColony::BuildTrail(int k,int start)
 {
	 int numCities = pheromones->Length;
	 array<int> ^trail = gcnew array<int>(max_city);
	 array<bool> ^visited = gcnew array<bool>(max_city);
     trail[0] = start;
     visited[start] = true;
	 for (int i = 0; i < max_city - 1; ++i)
      {
        int cityX = trail[i];
        int next = NextCity(k, cityX, visited);
        trail[i + 1] = next;
        visited[next] = true;
      }
      return trail;
 }

int AntColony::NextCity(int k, int cityX, array<bool> ^visited )
{
	  Random ^random = gcnew Random();
    
      array<double> ^probs = MoveProbs(k, cityX, visited);

      array<double> ^cumul = gcnew array<double>(probs->Length + 1);
      for (int i = 0; i < probs->Length; ++i)
        cumul[i + 1] = cumul[i] + probs[i]; 

      double p = random->NextDouble();

      for (int i = 0; i < cumul->Length - 1; ++i)
        if (p >= cumul[i] && p < cumul[i + 1])
          return i;
}

array<double> ^AntColony::MoveProbs(int k, int cityX, array<bool> ^visited)
{
 
      int numCities = pheromones->Length;
      array<double> ^taueta = gcnew array<double>(max_city); 
      double sum = 0.0;  
      for (int i = 0; i < taueta->Length; ++i)  
      {
        if (i == cityX)
          taueta[i] = 0.0;  
        else if (visited[i] == true)
          taueta[i] = 0.0; 
        else
        {
			taueta[i] = Math::Pow(pheromones[cityX][i], alpha) * Math::Pow((1.0 / jarakkota[cityX][i]), beta); 
          if (taueta[i] < 0.0001)
            taueta[i] = 0.0001;
		  else if (taueta[i] > (Double::MaxValue / (max_city * 100)))
			  taueta[i] = Double::MaxValue / (max_city * 100);
        }
        sum += taueta[i];
      }

      array<double> ^probs = gcnew array<double>(max_city);
      for (int i = 0; i < probs->Length; ++i)
        probs[i] = taueta[i] / sum; 
      return probs;
}

void AntColony::UpdatePheromones()
{
   for (int i = 0; i < pheromones->Length; ++i)
      {
        for (int j = i + 1; j < pheromones[i]->Length; ++j)
        {
          for (int k = 0; k < ants->Length; ++k)
          {
            double length = CountLength(ants[k]);
            double decrease = (1.0 - rho) * pheromones[i][j];
            double increase = 0.0;
			if (EdgeInTrail(i, j, ants[k]) == true) increase = (Q / length);

            pheromones[i][j] = decrease + increase;

            if (pheromones[i][j] < 0.0001)
              pheromones[i][j] = 0.0001;
            else if (pheromones[i][j] > 100000.0)
              pheromones[i][j] = 100000.0;

            pheromones[j][i] = pheromones[i][j];
          }
        }
      }
}
bool AntColony::EdgeInTrail(int cityX, int cityY, array<int> ^trail)
{
     
      int lastIndex = trail->Length - 1;
      int idx = IndexOfTarget(trail, cityX);

      if (idx == 0 && trail[1] == cityY) return true;
      else if (idx == 0 && trail[lastIndex] == cityY) return true;
      else if (idx == 0) return false;
      else if (idx == lastIndex && trail[lastIndex - 1] == cityY) return true;
      else if (idx == lastIndex && trail[0] == cityY) return true;
      else if (idx == lastIndex) return false;
      else if (trail[idx - 1] == cityY) return true;
      else if (trail[idx + 1] == cityY) return true;
      else return false;
}
 
 void AntColony::SetGraphDistances(array<array<int >^ > ^jarakkota)
 {
	 this->jarakkota = jarakkota;
 }

array<int > ^AntColony::GetBestTrail()
{
	return bestTrail;
}

String^ AntColony::ShowBestRoute()
{
    String^ temp="";
	for(int i=0;i<max_city;i++)
	{
       temp += (bestTrail[i]+1).ToString() + " ";
	}
	return temp;
}

double AntColony::GetBestTrailDistance()
{
    return CountLength(bestTrail);
}

 void AntColony::runAntColony(RichTextBox ^rtb){
	 this->rtb=rtb;
	 InitAnts();
	 bestTrail = BestTrail();
	 double bestJarak = CountLength(bestTrail);
	 InitPheromones();
	 int siklus=0;
	 while (siklus < max_siklus  )
	 {
		 rtb->Text += "Siklus - " + (siklus+1).ToString() + System::Environment::NewLine;
		 UpdateAnts();
		 UpdatePheromones(); 
		 array<int > ^ currBestTrail = BestTrail();
         double currBestJarak = CountLength(currBestTrail);
         if (currBestJarak < bestJarak)
          {
            bestJarak = currBestJarak;
            bestTrail = currBestTrail;     
			
          }
		 rtb->Text += "Jarak =" + bestJarak.ToString() + "\t" + ShowBestRoute() + System::Environment::NewLine;
		 ++siklus;
		
		 Application::DoEvents();
	 }
 }
