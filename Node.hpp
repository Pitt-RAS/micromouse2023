// Node.hpp
// 2.7.2023

// A Node is a spot on the maze where the car needs to make a decision that isn't just forward
// and is given an option of a left and/or right turn

// Changes:
// Instead of item, it needs a coordinate
// Each node needs a North, South, East, and West "Next"
// Each node needs a Left, Right, Straight boolean

#ifndef NODE_
#define NODE_

class Node
{
private:
   static int totalNodes;
   int nodeIndex;

   Node *next1; // Pointer to next node
   Node *next2; // Pointer to next node
   Node *next3; // Pointer to next node
   Node *next4; // Pointer to next node

public:
   // Constructors
   Node();
   Node(const &x, const &y);
   Node(const &x, const &y, Node *nextNodePtr);
   // Mutator Functions
   void setCoordinate();
   void setNext1(Node *nextNodePtr);
   void setNext2(Node *nextNodePtr);
   void setNext3(Node *nextNodePtr);
   void setNext4(Node *nextNodePtr);
   // Accessor Functions
   int getXCoordinate() const;
   int getYCoordinate() const;
   Node *getNext() const;
}; // end Node

static totalNodes = 0;

#include "Node.tpp"
#endif

// Do we want 4 nexts as private member variables, make an array of 4 node pointers, or dynamically allocate node pointers every time there is a new path
