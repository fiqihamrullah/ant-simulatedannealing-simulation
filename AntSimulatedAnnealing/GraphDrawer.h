#pragma once
#include "Graph.h"
using namespace System::Drawing;
ref class GraphDrawer
{
private:
   int envlengthpx;
   int envwidthpx;
   int envreallengthm;
   int envrealwidthm;

   Graphics ^g;
   Graph ^graph;
   
   double ConvertMtoPx(double m);
   double ConvertPxtoM(double px);
   String ^titlegraph;
public:
	GraphDrawer( String ^titlegraph,Graphics ^g,int envlengthpx,int  envwidthpx,int envreallengthm,int envrealwidthm,Graph^ graph);
	void DrawNodesTrail(array<Point^> ^posisikota,array<int> ^ trail);
};
