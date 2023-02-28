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
<<<<<<< HEAD
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
=======
   static int total;    //Stores the total amount of nodes that have been declared
   static int X[144], Y[144];     //Stores all the coordinates of the nodes, with each node index matching the coordinate index
   
   int index;
   int canTurn[3];      //Stores the potential/verified turns that allow for a route to the center
   int hasTurned[3];     //Stores the previous turn made at the node

   Node* next1;   // Pointer to next nodes
   Node* next2; 
   Node* next3;
   Node* next4; 
   
public:
   //Constructors
   Node();
   Node(const int &x, const int &y);
   Node(const int &x, const int &y, Node* nextNodePtr);
   //Mutator Functions
   void setCoordinate(const int &x, const int &y, const int &i);
   void setNext1(Node* nextNodePtr);
   void setNext2(Node* nextNodePtr);
   void setNext3(Node* nextNodePtr);
   void setNext4(Node* nextNodePtr);
   //Accessor Functions
   int getXCoordinate(int i) const ;
   int getYCoordinate(int i) const ;
   Node* getNext() const ;
>>>>>>> 508bebcc5984ae6c668574f829a8a5deda257c46
}; // end Node

static totalNodes = 0;

#include "Node.tpp"
#endif

<<<<<<< HEAD
// Do we want 4 nexts as private member variables, make an array of 4 node pointers, or dynamically allocate node pointers every time there is a new path
=======


//Do we want 4 nexts as private member variables, make an array of 4 node pointers, or dynamically allocate node pointers every time there is a new path
>>>>>>> 508bebcc5984ae6c668574f829a8a5deda257c46
