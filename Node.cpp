#include "Node.hpp"
#include <string>
#include <memory>
using std::shared_ptr;


//Default Node Constructor
//PURPOSE: This will be called when we first start 
Node::Node() : X(0), Y(0), 
               next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
   //Go forward 1 square
   //**Might need to make it call a function that goes until it hits a wall then centers itself instead**
}

Node::Node(const int &x, const int &y) :  X(x), Y(y),
                                          next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
   //**Put move functions here**
}

Node::Node(const int &x, const int &y, shared_ptr<Node> nextNodePtr) : X(x), Y(y),
                                                            next1(nullptr), next2(nullptr), next3(nullptr), next4(nullptr)
{
}


void Node::setX(int x)  //Change this to either 2 ints (x, y) or a 2d array
{
   X = x;
}
void Node::setY(int y)  //Change this to either 2 ints (x, y) or a 2d array
{
   Y = y;
}
   

int Node::getX() const
{
   return X;
}

int Node::getY() const
{
   return Y;
}

void Node::setNext1(shared_ptr<Node> nextNodePtr)
{
   next1 = nextNodePtr;
} // end setNext

void Node::setNext2(shared_ptr<Node> nextNodePtr)
{
   next2 = nextNodePtr;
} // end setNext

void Node::setNext3(shared_ptr<Node> nextNodePtr)
{
   next3 = nextNodePtr;
} // end setNext


void Node::setNext4(shared_ptr<Node> nextNodePtr)
{
   next4 = nextNodePtr;
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