#include "Node.hpp"

template <class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
}

Node::Node(const int &X, const int &Y) : x(X), y(Y), next(nullptr)
{
}

Node::Node(const int &X, const int &Y, Node *nextNodePtr) : item(anItem), next(nextNodePtr)
{
}

void Node::setCoordinate() // Change this to either 2 ints (x, y) or a 2d array
{
   // TODO
}

void Node::setNext1(Node *nextNodePtr)
{
   next = nextNodePtr;
}

void Node::setNext2(Node *nextNodePtr)
{
   next = nextNodePtr;
}

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