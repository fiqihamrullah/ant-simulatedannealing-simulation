#include "StdAfx.h"
#include "CityNode.h"

CityNode::CityNode(Point^ ptNode)
{
	this->ptNode = ptNode;
	jnode = 0;
}

 Point^ CityNode::GetPoint()
 {
   return ptNode;
 }

bool CityNode::checkExist(Point^ ptNode)
{
   bool exist = false;
   for(int i=0;i<jnode;i++)
   {
	   if (ptNode->X==lstptNode[i]->GetPoint()->X && ptNode->Y==lstptNode[i]->GetPoint()->Y)
	   {
             exist =true;
			 break;
	   }

   }
   return exist;

}

void CityNode::setManyNeighbour(int n)
{
   lstptNode = gcnew array<CityNode ^>(n);
}

 void CityNode::AddNeighbourNode(Point^ ptNode)
 {
    lstptNode[jnode] = gcnew CityNode(ptNode);
    jnode++;
 }

CityNode^ CityNode::GetNeighbourNode(int n)
{
	return lstptNode[n];
}

 int CityNode::getTotalNeighbour()
 {
      return jnode;
 }
