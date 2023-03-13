//Node.hpp
//2.7.2023

//A Node is a spot on the maze where the car needs to make a decision that isn't just forward 
//and is given an option of a left and/or right turn

//Changes:
//Instead of item, it needs a coordinate
//Each node needs a North, South, East, and West "Next"
//Each node needs a Left, Right, Straight boolean


#ifndef NODE_HPP_
#define NODE_HPP_

#include <memory>
using std::shared_ptr;
#include "Move.hpp"


class Node : public Move
{
private:
   int X;
   int Y;   //Stores the location at that node
   int index;

   int canTurn[3];      //Stores the potential/verified turns that allow for a route to the center
   int hasTurned[3];     //Stores the previous turn made at the node

   shared_ptr<Node> next1;   // Pointer to next nodes
   shared_ptr<Node> next2; 
   shared_ptr<Node> next3;
   shared_ptr<Node> next4; 


//These set nexts are private functions that can only be called by the public setNext function
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

   
public:
   //Constructors
   Node();
   Node(const int &x, const int &y, const int &i);
   Node(const int &x, const int &y, const int &i, shared_ptr<Node> nextNodePtr);
   //Mutator Functions
   void setCoordinate(const int &x, const int &y, const int &i);
   void setNext(shared_ptr<Node> nextNodePtr);
   void removeNext(shared_ptr<Node> nextNodePtr);
   void setX(int x) const ;
   void setY(int y) const ;
   void setIndex(int i) const ;
    //Accessor Functions
   int getX() const ;
   int getY() const ;
   int getIndex() const ;
   shared_ptr<Node> getNext1() const ;
   shared_ptr<Node> getNext2() const ;
   shared_ptr<Node> getNext3() const ;
   shared_ptr<Node> getNext4() const ;
}; // end Node

#include "Node.cpp"
#endif



//Do we want 4 nexts as private member variables, make an array of 4 node pointers, or dynamically allocate node pointers every time there is a new path
