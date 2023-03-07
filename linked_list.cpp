// ECE 302 Linked List Solution

#include "linked_list.hpp"

LinkedList::LinkedList() : headPtr(nullptr), total(0)
{
  
} //end default constructor

LinkedList::~LinkedList()
{
  //empty the existing linked list
	clear();
} // end destructor

////This might be useful when the car goes for a second trial, but for now it is just too much to think about
/*
LinkedList::LinkedList(const LinkedList& x)                 ////FIX SO THAT IT CAN WORK WITH ALL NEXTS   
{
  total = x.total;
  Node* origPtr = x.headPtr;
	//check if original is empty, if so make copy empty
	if (origPtr == nullptr) 
		headPtr = nullptr;
	else {
		//make copy of first node
		headPtr = new Node();
		headPtr -> setX(origPtr -> getX(0));
        headPtr -> setY(origPtr -> getY(0));
		//copy remaining nodes
		Node* newPtr = headPtr; 
		origPtr = origPtr -> getNext();
		while (origPtr != nullptr) {
			//get next item in list, and make new node with item, and link
			int nextX = origPtr -> getX();
            int nextY = origPtr -> getY();
			Node* newNodePtr = new Node(nextX, nextY);
			newPtr -> setNext(newNodePtr);
			//shift pointers
			newPtr = newPtr -> getNext();
			origPtr = origPtr -> getNext();
		} // end while
	} // end if
} // end copy

*/

LinkedList& LinkedList::operator=(LinkedList x)
{
	swap(x);
	return *this;
} // end = operator

void LinkedList::swap(LinkedList& x) 
{
	std::swap(total, x.total);
	std::swap(headPtr, x.headPtr);
}

bool LinkedList::isEmpty() const noexcept
{
  return (total == 0);
}

//// Maybe make it to show how many nodes you must go through in order to get to position i
int LinkedList::getLength() const noexcept
{
  return total;
}

bool LinkedList::insert(int position, const int &x, const int &y)
{
	if ((position >= 0) && (position <= total)) {
		Node* newNodePtr = new Node(x, y);
		if (position == 0) {
			newNodePtr -> setNext(headPtr);
			headPtr = newNodePtr;
		}
		else {
			Node* prevPtr = getNodeAt(position-1);
			newNodePtr -> setNext( prevPtr -> getNext() );
			prevPtr -> setNext( newNodePtr );
		}
		total++;
		return true;
	} 
	return false;
} //end insert

bool LinkedList::remove(int position)
{
	if ((position >= 0) && (position < total)) {
		Node* curPtr = nullptr;
		if (position == 0) {
			curPtr = headPtr;
			headPtr = headPtr -> getNext();
		}
		else {
			Node* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr -> getNext();
			prevPtr -> setNext( curPtr -> getNext() );
		}
		delete curPtr;
		total--;
		return true;
	} 
	return false;
} //end remove;

void LinkedList::clear()
{
	while (!isEmpty())
	remove(0);
} // end clear

int LinkedList::getXCoordinate(int position) const
{
	if ((position >= 0) && (position < total)) 
	{
		return getNodeAt(position)->getX();
	}
	else throw(std::range_error("error in range"));
} // end getEntry

int LinkedList::getYCoordinate(int position) const
{
	if ((position >= 0) && (position < total)) 
	{
		return getNodeAt(position)->getY();
	}
	else throw(std::range_error("error in range"));
} // end getEntry

Node* LinkedList::getNodeAt(int position) const
{
	//This traverses the list and returns the node at position
	Node* curPtr = headPtr;
	for (int next = 0; next < position; next++) {
		curPtr = curPtr -> getNext();
	}
	return curPtr;
} //end getNodeAt


void LinkedList::setXCoordinate(int position, const int &x)
{
	if((position >= 0) && (position < total))
	getNodeAt(position)->setX(x);
} //end setEntry


void LinkedList::setYCoordinate(int position, const int &y)
{
	if((position >= 0) && (position < total))
	getNodeAt(position)->setY(y);
} //end setEntry
