#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"

#include <memory>
using std::shared_ptr;


//TODO
//Have to change to work with 4 nexts
//For getNodeAt funciton, it is necessary to find how to get to the node at the position. To do this,
//  it could work to go through every possible combination of getNexts until we find it or
//  we could make a private member variable that keeps a key of how to get to the node, but this seems insanely complicated

class LinkedList: public AbstractList
{
private:
  shared_ptr<Node> headPtr;
  int total;    //Stores the total amount of nodes that have been declared
  int X[144], Y[144];    //Stores all the coordinates of the nodes, with each node index matching the coordinate index

  //Locates a specified node in linked list
  // @pre position is number of desired node, greater than 0 and less than or equal to itemCount
  // @post pointer to specific node is returned
  // @param position -- number of the node to be found
  // @return ponter to node at position
  shared_ptr<Node> getNodeAt(int position) const;

public:
  
  // default constructor
  LinkedList();
  
  // copy constructor
  ////LinkedList(const LinkedList& x);
    
  // destructor
  ~LinkedList();
  
  // copy assignment
  LinkedList& operator=(LinkedList x);

  void swap(LinkedList& x);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  int getLength() const noexcept;

  // insert item at position in the list
  bool insert(int position, const int &x, const int &y);

  // remove item at position in the list
  bool remove(int position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position
  int getXCoordinate(int position) const;
  int getYCoordinate(int position) const;

  // set the value of the item at position 
  void setXCoordinate(int position, const int &x);
  void setYCoordinate(int position, const int &y);


};

#include "linked_list.cpp"

#endif

