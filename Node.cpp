#include "Node.hpp"
#include <string>
#include <memory>
using std::shared_ptr;



///TODO
//1. remove next function


//Default Node Constructor
//PURPOSE: This will be called when we first start 
Node::Node() : X(0), Y(0), index(0),
               next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
   //Go forward 1 square
   //**Might need to make it call a function that goes until it hits a wall then centers itself instead**
}

Node::Node(const int &x, const int &y, const int &i) :  X(x), Y(y), index(total),
                                          next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
   //**Put move functions here**
}

Node::Node(const int &x, const int &y, const int &i, shared_ptr<Node> nextNodePtr) : X(x), Y(y),
                                                            next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
}


void Node::setCoordinate(const int &x, const int &y)  //Change this to either 2 ints (x, y) or a 2d array
{
   setX(x);
   setY(y);
}

void Node::setX(int x)  //Change this to either 2 ints (x, y) or a 2d array
{
   X = x;
}
void Node::setY(int y)  //Change this to either 2 ints (x, y) or a 2d array
{
   Y = y;
}
   
void Node::setIndex(int i)  //Change this to either 2 ints (x, y) or a 2d array
{
   index = i;
}


int Node::getX() const
{
   return X;
}

int Node::getY() const
{
   return Y;
}

int Node::getIndex() const
{
   return index;
}

void Node::setNext(shared_ptr<Node> nextNodePtr)
{
   if(next1 == nullptr)
      setNext1(nextNodePtr);
   else if(next2 == nullptr)
      setNext2(nextNodePtr);
   else if(next3 == nullptr)
      setNext3(nextNodePtr);
   else if(next4 == nullptr)
      setNext4(nextNodePtr);
   else throw(std::range_error("error in range"));
} // end setNext

void Node::removeNext(shared_ptr<Node> nextNodePtr)   ////Need to change the parameters
{
   
} // end setNext


shared_ptr<Node> Node::getNext1() const
{
   return next1;
} // end getNext


shared_ptr<Node> Node::getNext2() const
{
   return next2;
} // end getNext

shared_ptr<Node> Node::getNext3() const
{
   return next3;
} // end getNext


shared_ptr<Node> Node::getNext4() const
{
   return next4;
} // end getNext