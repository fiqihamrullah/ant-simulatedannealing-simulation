#pragma once

using namespace System;
#include "CityNode.h"

ref class Graph
{
private:
	array<CityNode ^> ^nodes;
	array<double,2> ^jarakkota;
	int idxnode;
	array<int> ^GetNearestCity(int idxcityStart);
public:
	Graph(int ncity);
	void setCityDistances(array<double,2> ^jarakkota);
	void addCityNode(CityNode ^node);
	CityNode ^GetNode(int idx);
	bool checkSpanningTree(array<int> ^ trail);
	int GetJumlahNode();
	void createGraph();

	
};
