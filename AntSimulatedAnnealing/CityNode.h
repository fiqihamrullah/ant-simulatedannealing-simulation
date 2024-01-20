#pragma once
using namespace System::Drawing;
ref class CityNode
{
private :
   Point^ ptNode;
   array<CityNode^> ^lstptNode; 
   int jnode;
public:
   CityNode(Point^ ptNode);
   void setManyNeighbour(int n);
   CityNode^ GetNeighbourNode(int n);
   Point^ GetPoint();
   bool checkExist(Point^ ptNode);
   void AddNeighbourNode(Point^ ptNode);
   int getTotalNeighbour();

};
