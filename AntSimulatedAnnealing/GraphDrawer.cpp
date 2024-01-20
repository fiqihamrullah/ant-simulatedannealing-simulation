#include "StdAfx.h"
#include "GraphDrawer.h"


GraphDrawer::GraphDrawer( String ^titlegraph,Graphics ^g,int envlengthpx,int  envwidthpx,int envreallengthm,int envrealwidthm,Graph^ graph)
{
   this->g=g;
   this->envlengthpx = envlengthpx;
   this->envwidthpx = envwidthpx;
   this->envreallengthm=envreallengthm;
   this->envrealwidthm=envrealwidthm;
   this->graph = graph;
   this->titlegraph= titlegraph;
}

double GraphDrawer::ConvertMtoPx(double m)
{
  int hasil;
  hasil = m * (envlengthpx / envreallengthm);
  return hasil;
}

double GraphDrawer::ConvertPxtoM(double px){
  int hasil;
  hasil = px * (envreallengthm / envlengthpx);
  return hasil;
}

void GraphDrawer::DrawNodesTrail(array<Point^> ^posisikota, array<int> ^ trail)
{
        int x,y;
       
        int onemeter;
        onemeter = ConvertMtoPx(1);
      
         int i=0;
		 

		 for(i=0;i<envlengthpx;i+=10){
			 g->DrawLine(gcnew Pen(Color::DarkGreen),0,i,envwidthpx,i);
		 }

		 for(i=0;i<envwidthpx;i+=10){
			 g->DrawLine(gcnew Pen(Color::DarkGreen),i,0,i,envlengthpx);
		 }
        
	   g->DrawString(this->titlegraph,gcnew Font("Verdana",10,FontStyle::Bold,GraphicsUnit::Point),Brushes::White,220,5);
       int jari2=2;
       int diameterpoint = jari2*2;
       int radius,diameter;
      
	   for(int i=0;i<posisikota->Length;i++)
		{  
			x = ConvertMtoPx(posisikota[i]->X);
			y = ConvertMtoPx(posisikota[i]->Y);
            radius = ConvertMtoPx(jari2);
			diameter = ConvertMtoPx(diameterpoint);                 
			g->DrawEllipse(gcnew Pen(Color::Red, 3), x - jari2, y - jari2, diameterpoint, diameterpoint);

			g->FillEllipse(Brushes::Red, x - jari2, y - jari2, diameterpoint - 1, diameterpoint - 1);
                    
          //  colorCircle(g, x - CType(radius, Integer), y - CType(radius, Integer), diameter, diameter, cl(i))
			g->DrawEllipse(gcnew Pen(Color::Yellow, 1), x - radius, y - radius, diameter, diameter);
         //  g->DrawString(curkromosom.GetGen(i).NamaSensor + "(" + curkromosom.GetGen(i).Radius.ToString() + ")", New Font("Verdana", 8, FontStyle.Regular), Brushes.SkyBlue, (x - jari2) - 10, (y - jari2) - 20)
			g->DrawString("(" + posisikota[i]->X.ToString() + "," +  posisikota[i]->Y.ToString() + ")", gcnew Font("Verdana", 6, FontStyle::Regular), Brushes::Yellow, (x - jari2) - 10, (y - jari2) + 10);
		}
	    int x2,y2;
       
      for(int i=0;i<graph->GetJumlahNode();i++)
		{
				CityNode ^cnode = graph->GetNode(i);
				x = ConvertMtoPx(cnode->GetPoint()->X);
				y = ConvertMtoPx(cnode->GetPoint()->Y);
				for(int j=0;j<cnode->getTotalNeighbour();j++)
				{
					CityNode ^cnodetetanggga = cnode->GetNeighbourNode(j); 
					x2 = ConvertMtoPx(cnodetetanggga->GetPoint()->X);
				    y2 = ConvertMtoPx(cnodetetanggga->GetPoint()->Y);
					g->DrawLine(gcnew Pen(Color::Red,2),x,y,x2,y2);
				}
		}

	  for(int i=0;i<posisikota->Length-1;i++)
			{
				x = ConvertMtoPx(posisikota[i]->X);
				y = ConvertMtoPx(posisikota[i]->Y);
				x2 = ConvertMtoPx(posisikota[i+1]->X);
				y2 = ConvertMtoPx(posisikota[i+1]->Y);
				g->DrawLine(gcnew Pen(Color::Red),x,y,x2,y2);
			}


         //Menggambar Jejak
		if (trail!=nullptr) {
			 
			
		 
			for(int i=0;i<trail->Length-1;i++)
			{
				x = ConvertMtoPx(posisikota[trail[i]]->X);
				y = ConvertMtoPx(posisikota[trail[i]]->Y);
				x2 = ConvertMtoPx(posisikota[trail[i+1]]->X);
				y2 = ConvertMtoPx(posisikota[trail[i+1]]->Y);
				g->DrawLine(gcnew Pen(Color::Yellow),x,y,x2,y2);

			}   

			



		}


             
}

