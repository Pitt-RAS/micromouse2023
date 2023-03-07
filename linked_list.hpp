#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"


//Have to change to work with 4 nexts

class LinkedList: public AbstractList
{
private:
  Node* headPtr;
  int total;    //Stores the total amount of nodes that have been declared
  int X[144], Y[144];    //Stores all the coordinates of the nodes, with each node index matching the coordinate index

  //Locates a specified node in linked list
  // @pre position is number of desired node, greater than 0 and less than or equal to itemCount
  // @post pointer to specific node is returned
  // @param position -- number of the node to be found
  // @return ponter to node at position
  Node* getNodeAt(int position) const;

public:
  
  // default constructor
  LinkedList();
  
  // copy constructor
  LinkedList(const LinkedList& x);
    
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
