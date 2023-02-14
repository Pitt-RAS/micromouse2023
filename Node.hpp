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
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNextN(Node<ItemType>* nextNodePtr);
   void setNextS(Node<ItemType>* nextNodePtr);
   void setNextE(Node<ItemType>* nextNodePtr);
   void setNextW(Node<ItemType>* nextNodePtr);
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
}; // end Node

#include "Node.tpp"
#endif