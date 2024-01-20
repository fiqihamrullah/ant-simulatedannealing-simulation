#include "StdAfx.h"
#include "Graph.h"

Graph::Graph(int ncity)
{
	nodes = gcnew array<CityNode ^>(ncity);
}

void Graph::addCityNode(CityNode ^node)
{
    nodes[idxnode] = node;
	idxnode++;
}

CityNode ^Graph::GetNode(int idx)
{
    return nodes[idx];
}

int Graph::GetJumlahNode()
{
     return idxnode;

}

array<int> ^Graph::GetNearestCity(int idxcityStart)
{
	array<double>^ lstjarak = gcnew array<double>(nodes->Length);
	array<int>^ idxjarak = gcnew array<int>(nodes->Length);

	for(int i=0;i<lstjarak->Length;i++){
		lstjarak[i] = jarakkota[idxcityStart,i];
		idxjarak[i]= i;
	}
    //Mencari Jarak Terpendek
	for(int i=0;i<lstjarak->Length - 1;i++)
	{
		for(int j=i+1;j<lstjarak->Length;j++)
		{
			if (lstjarak[i]>lstjarak[j]) 
			{
				double temp = lstjarak[i];
				int idxtemp = idxjarak[i];
				lstjarak[i] = lstjarak[j];
				idxjarak[i] = idxjarak[j];
				lstjarak[j] =temp;
				idxjarak[j] =  idxtemp;


			}
		}

	}
    
	return idxjarak;

}

bool Graph::checkSpanningTree(array<int> ^ trail)
{
	bool isSp=false;
	int nfit=0;
	for(int i=0;i<trail->Length-1;i++)
	{
		CityNode^ node = nodes[trail[i]];
		CityNode^ nextnode = nodes[trail[i+1]];
		bool ada = node->checkExist(nextnode->GetPoint());
		
		if (ada==false)
		{
             break;
		}else{
			if (i==trail->Length-2)
			{
				//System::Diagnostics::Trace::WriteLine("Yooondraang");
                    isSp=true;
			}
		}
            
	}
	return isSp;
}

void Graph::setCityDistances(array<double,2> ^jarakkota)
{
	this->jarakkota = jarakkota;
}

void Graph::createGraph()
{
	Random ^rnd = gcnew Random();
	int jterhubung = nodes->Length /3;
	for(int i=0;i<nodes->Length;i++)
	{
		
		int nbykconnected = 3;//rnd->Next(jterhubung);	
		nodes[i]->setManyNeighbour(nbykconnected);
		for(int j=1;j<nbykconnected+1;j++)
		{
			int inode=0;
			array<int>^ idxjarak = GetNearestCity(i);
			/*
			do {
			  inode =  rnd->Next(nodes->Length);              
			   if (inode!=i)
			   {*/

			nodes[i]->AddNeighbourNode(nodes[idxjarak[j]]->GetPoint());

			/*
			   }            
			}while (inode==i);*/

		}

	}
}