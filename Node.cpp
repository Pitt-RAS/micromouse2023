#include "Node.hpp"
#include <string>


//Default Node Constructor
//PURPOSE: This will be called when we first start 
Node::Node() : next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
   //Fill the coordinate arrays with 0's
   for(int i=0; i<144; i++){
      X[i] = 0;
      Y[i] = 0;
   }

   //Update total
   total++;
   //Initialize node index
   index = total;

   //Go forward 1 square
   //**Might need to make it call a function that goes until it hits a wall then centers itself instead**
}

Node::Node(const int &x, const int &y) : next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
   //Update total
   total++;
   //Initialize node index
   index = total;
   //Update the coordinate array with the new coordinate
   X[total] = x;
   Y[total] = y;
}

Node::Node(const int &x, const int &y, Node* nextNodePtr) : next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
   //Update total
   total++;
   //Initialize node index
   index = total;
   //Update the coordinate array with the new coordinate
   X[total] = x;
   Y[total] = y;
}


void Node::setCoordinate(const int &x, const int &y, const int &i)  //Change this to either 2 ints (x, y) or a 2d array
{
   X[i] = x;
   Y[i] = y;
} // end setItem

int Node::getXCoordinate(int i) const
{
   return X[i];
}

int Node::getYCoordinate(int i) const
{
   return Y[i];
}

void Node::setNext1(Node* nextNodePtr)
{
   next1 = nextNodePtr;
} // end setNext

void Node::setNext2(Node* nextNodePtr)
{
   next2 = nextNodePtr;
} // end setNext

void Node::setNext3(Node* nextNodePtr)
{
   next3 = nextNodePtr;
} // end setNext


void Node::setNext4(Node* nextNodePtr)
{
   next4 = nextNodePtr;
} // end setNext


Node* Node::getNext1() const
{
   return next1;
} // end getNext


Node* Node::getNext2() const
{
   return next2;
} // end getNext

Node* Node::getNext3() const
{
   return next3;
} // end getNext


Node* Node::getNext4() const
{
   return next4;
} // end getNext


int Node::total = 0;