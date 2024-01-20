#pragma once

#include "Graph.h"

using namespace System;
using namespace System::Windows::Forms;

ref class SimulatedAnnealing
{
private:
	array<double,2> ^jarakkota;
	array<int> ^current;
	array<int> ^bestroute;
	int totkota;
	int nkota;
	Graph ^graph;
	double alpha,temperature,epsilon,delta;//parameter SA
	double maxiterasi,maksukses;
	double GetDistance(array<int > ^t);  //mencari panjang jalur
	double GetDistanceCurrent();  //mencari panjang jalur sekarang
	void SearchAnotherRoute( array<int > ^next); //melakukan permutasi posisi solusi
	void SwitchRoute( array<int > ^next); //tukar rute yang akan dipakai
	String^ ShowCurrentRoute();
	void SaveBestRoute();
	double shortdistance;
	bool checkRouteExist(int r,int mkota);

public:
	SimulatedAnnealing(Graph^graph, array<double,2> ^jarakkota,double maxiterasi,double maksukses,double alpha,double tempawal,double epsilon,int nkota);
	void StartAnnealing(RichTextBox ^rtb);
	double GetShortestDistance();
	String^ ShowBestRoute();
	array<int>^ InitRoute();
    array<int>^ GetBestRoute();
};
