#include "Node.hpp"

Node::Node() : next(nullptr)
{
} // end default constructor

Node::Node(const int &X, const int &Y) : x(X), y(Y), next(nullptr)
{
} // end constructor

Node::Node(const ItemType &anItem, Node<ItemType> *nextNodePtr) : item(anItem), next(nextNodePtr)
{
} // end constructor

void Node::setCoordinate(const ItemType &anItem) // Change this to either 2 ints (x, y) or a 2d array
{
   item = anItem;
} // end setItem

void Node::setNext1(Node *nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template <class ItemType>
void Node::setNext2(Node *nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template <class ItemType>
void Node::setNext3(Node *nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

void Node::setNext4(Node *nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

int Node::getXCoordinate() const
{
   return xCoor[nodeIndex];
}

int Node::getYCoordinate() const
{
   return yCoor[nodeIndex];
}

Node *Node::getNext1() const
{
   return next;
} // end getNext

Node *Node::getNext2() const
{
   return next;
} // end getNext

Node *Node::getNext3() const
{
   return next;
} // end getNext

Node *Node::getNext4() const
{
   return next;
} // end getNext