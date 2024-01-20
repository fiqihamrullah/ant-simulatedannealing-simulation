#include "StdAfx.h"
#include "SimulatedAnnealing.h"



SimulatedAnnealing::SimulatedAnnealing(Graph^graph,array<double,2> ^jarakkota,double maxiterasi,double maksukses,double alpha,double tempawal,double epsilon,int nkota)
{
	this->jarakkota = jarakkota;
	this->maxiterasi = maxiterasi;
	this->maksukses =maksukses;
	this->alpha = alpha;
	this->temperature = tempawal;
	this->epsilon = epsilon;
	this->nkota = nkota;
	this->graph = graph;
	current =gcnew array<int>(nkota);


}

String^ SimulatedAnnealing::ShowCurrentRoute()
{
    String^ temp="";
	for(int i=0;i<nkota;i++)
	{
       temp += (current[i]+1).ToString() + " ";
	}
   return temp;
}

 array<int> ^SimulatedAnnealing::GetBestRoute()
 {
            return bestroute;
 }

String^ SimulatedAnnealing::ShowBestRoute()
{
    String^ temp="";
	for(int i=0;i<nkota;i++)
	{
       temp += (bestroute[i]+1).ToString() + " ";
	}
	return temp;
}

double SimulatedAnnealing::GetDistanceCurrent()
{
	 double d=0.0;
   // for(int i=0;jarakkota
	 for(int  i=0;i<nkota-1;i++)
	 {
               d+=jarakkota[current[i],current[i+1]];
	 }

	 

     return d;
}

void SimulatedAnnealing::SearchAnotherRoute( array<int > ^next)
{

	Random ^rand = gcnew Random();
	for(int i=0;i<nkota;i++)	
		next[i]=current[i];

	bool sesuai=false;
	while (sesuai==false)
	{
		
		int i1 =  rand->Next(0,nkota);
		int i2 =  rand->Next(0,nkota);
		int aux = next[i1];
		next[i1]=next[i2];
		next[i2]=aux; 
	 	sesuai = graph->checkSpanningTree(next);
	    //System::Diagnostics::Trace::WriteLine(temp); 		
	}
	//MessageBox::Show("Sesuai");
}

void SimulatedAnnealing::SwitchRoute( array<int > ^next)
{
	for(int i=0;i<nkota;i++)
				current[i]=next[i];

}

double SimulatedAnnealing::GetDistance(array<int > ^t)
{
     double d=0.0;
     // for(int i=0;jarakkota
	 for(int  i=0;i<nkota-1;i++)
	 {
               d+=jarakkota[t[i],t[i+1]];
	 }
     return d;
}

double SimulatedAnnealing::GetShortestDistance()
{
    return shortdistance;
}
 void  SimulatedAnnealing::SaveBestRoute()
 {
    for(int i=0;i<nkota;i++)
       bestroute[i]=current[i];
 }

bool SimulatedAnnealing::checkRouteExist(int r,int mkota)
{
	bool ada=false;
     for(int i=0;i<mkota;i++)
	{
		if (current[i]==r){
              ada =true;
			  break;
		}
	 }

	 return ada;

}

array<int>^ SimulatedAnnealing::InitRoute()
{
	Random ^rand = gcnew Random();
	array<int> ^initr = gcnew array<int>(nkota);
	array<int> ^next = gcnew array<int>(nkota);
	int k=0;
    for(int i=0;i<nkota;i++)
	{
		 
		do{ 
		 k= rand->Next(nkota);     
		 current[i] = k;
		 initr[i]= k;
		}while(checkRouteExist(k,i)==true);		
	}

	 
	for(int i=0;i<nkota;i++)	
		next[i]=current[i];

	bool sesuai=false;
	while (sesuai==false)
	{
		
		int i1 =  rand->Next(0,nkota);
		int i2 =  rand->Next(0,nkota);
		int aux = next[i1];
		next[i1]=next[i2];
		next[i2]=aux; 
	 	sesuai = graph->checkSpanningTree(next);
	    //System::Diagnostics::Trace::WriteLine(temp); 		
	}

    for(int i=0;i<nkota;i++)
	{
           current[i] = next[i];
		   initr[i] = next[i];
	} 

	 
	return initr;
}

void SimulatedAnnealing::StartAnnealing(RichTextBox^rtb)
{
	array<int> ^next = gcnew array<int>(nkota);    
	bestroute = gcnew array<int>(nkota);
    Random^rnd = gcnew Random();
	
	//inisial posisi pertama
	for(int i=0;i<nkota;i++)
	{
        current[i] = i;     
	}	 	   
	
    int iteration =-1;
	int isukses=0;
    double proba=0.0;
    delta=0.0;
	double distance = GetDistanceCurrent();
	shortdistance = distance;
    rtb->Text +=  "Jalur Sekarang -->" + ShowCurrentRoute() + System::Environment::NewLine;
	
	while(temperature > epsilon  )//&& iteration<maxiterasi 
			{
				iteration++;
				rtb->Text +=  "Iterasi-" + (iteration+1).ToString() + System::Environment::NewLine;				

				SearchAnotherRoute(next);			 
				delta = GetDistance(next)-distance;	
				
				if(GetDistance(next)<distance)
				{
					SwitchRoute(next);
					//distance = delta+distance;
					distance = GetDistance(next);
					
					if (distance < shortdistance)
					{
                       shortdistance = distance;
					   SaveBestRoute(); 

					}
					rtb->Text +=  "Jalur Sekarang[Delta<0] -->" + ShowCurrentRoute() + System::Environment::NewLine;
					rtb->Text +=  "Panjang Jarak : " + distance.ToString() + System::Environment::NewLine;
				}
					
				else
				{
					proba = rnd->NextDouble(); 					 
					if(proba < Math::Exp(-delta/temperature))
					{						 
						SwitchRoute(next);
						rtb->Text +=  "Jalur Sekarang[p] -->" + ShowCurrentRoute() + System::Environment::NewLine;
						distance = delta+distance;
						//isukses++;
						rtb->Text +=  "Panjang Jarak : " + distance.ToString() + System::Environment::NewLine;
					}else{
                       rtb->Text +=  " Tidak Diterima Sebagai Jalur Baru "  + System::Environment::NewLine;   
					}
				}			 
				
				temperature *=alpha;
				rtb->Text +=  "Temperatur : " + temperature.ToString() + System::Environment::NewLine;
				//System::Threading::Thread::Sleep(10);
				Application::DoEvents();
				 
			}
        
			 
			 


}
