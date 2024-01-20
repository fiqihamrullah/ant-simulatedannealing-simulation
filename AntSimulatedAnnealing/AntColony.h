#pragma once

#include "Graph.h"
using namespace System;
using namespace System::Windows::Forms;

ref class AntColony
{
private:
    RichTextBox ^rtb;


	//alpha derajat kepentingan jejak feromon
	//beta derajat kepentingan antara node yang berdekatan
	//rho koefisien penguapan
	//Q koefisien penambahan feromon
	Graph^ graph;
	double alpha,beta,rho,Q;
	int max_ants,max_city,max_siklus;	   
	array<int > ^ bestTrail; 
	array<array<int >^ > ^jarakkota;
    array<array<double >^ > ^pheromones;
	array<array<int >^ > ^ants;
    //Metode
	void InitAnts();
	void InitPheromones();
	array<int > ^RandomTrail(int start);
	int IndexOfTarget(array<int > ^trail,int target);
    array<int > ^BestTrail();
 	double CountLength(array<int > ^trail);
    void UpdateAnts();
	array<int> ^ BuildTrail(int k,int start);
	int NextCity(int k, int cityX, array<bool> ^visited );
	array<double> ^ MoveProbs(int k, int cityX, array<bool> ^visited);
	void UpdatePheromones();
	bool EdgeInTrail(int cityX, int cityY, array<int> ^trail);

public:
	AntColony(double alpha,double beta,double rho,double Q,int max_ants,int max_city,int max_siklus);
    array<int > ^GetBestTrail();
	double GetBestTrailDistance();
	String^ ShowBestRoute();
    void SetGraphDistances(array<array<int >^ > ^jarakkota);
	void runAntColony(RichTextBox ^rtb);
	


};
