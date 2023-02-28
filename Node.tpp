#include "Node.hpp"
#include <string>

<<<<<<< HEAD
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
=======
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

void Node::setNext1(Node* nextNodePtr)
>>>>>>> 508bebcc5984ae6c668574f829a8a5deda257c46
{
   next1 = nextNodePtr;
} // end setNext

<<<<<<< HEAD
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
=======
void Node::setNext2(Node* nextNodePtr)
{
   next2 = nextNodePtr;
} // end setNext

void Node::setNext3(Node* nextNodePtr)
>>>>>>> 508bebcc5984ae6c668574f829a8a5deda257c46
{
   next3 = nextNodePtr;
} // end setNext


void Node::setNext4(Node* nextNodePtr)
{
   next4 = nextNodePtr;
} // end setNext


int Node::getXCoordinate(const int &i) const
{
   return X[i];
}

int Node::getYCoordinate(const int &i) const
{
   return Y[i];
}


Node* Node::getNext1() const
{
   return next1;
} // end getNext

<<<<<<< HEAD
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
=======

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
>>>>>>> 508bebcc5984ae6c668574f829a8a5deda257c46
