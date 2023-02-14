//Node.hpp
//2.7.2023

//A Node is a spot on the maze where the car needs to make a decision that isn't just forward 
//and is given an option of a left and/or right turn

//Changes:
//Instead of item, it needs a coordinate
//Each node needs a North, South, East, and West "Next"
//Each node needs a Left, Right, Straight boolean



#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   
public:
   //Constructors
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   //Mutator Functions
   void setCoordinate(const ItemType& anItem);
   void setNextN(Node<ItemType>* nextNodePtr);
   void setNextS(Node<ItemType>* nextNodePtr);
   void setNextE(Node<ItemType>* nextNodePtr);
   void setNextW(Node<ItemType>* nextNodePtr);
   //Accessor Functions
   ItemType getCoordinate() const ;
   Node<ItemType>* getNextN() const ;
   Node<ItemType>* getNextS() const ;
   Node<ItemType>* getNextE() const ;
   Node<ItemType>* getNextW() const ;
}; // end Node

#include "Node.tpp"
#endif