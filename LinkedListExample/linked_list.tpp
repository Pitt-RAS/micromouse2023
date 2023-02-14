#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : headPtr(nullptr), itemCount(0)
  {}


template <typename T>
LinkedList<T>::~LinkedList()
  {clear();}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x) : itemCount(x.itemCount)
{
  itemCount = x.itemCount;
  //Copy x's head pointer to use as a traversing node
  Node<T>* oldListPtr = x.headPtr;
  //If the new list is empty
  if(oldListPtr == nullptr)
    headPtr = nullptr;
  else{
    //Copy first node
    headPtr = new Node<T>();
    headPtr -> setItem(oldListPtr->getItem());

    ////Copy the rest of the nodes////

    //Create a copy of headptr to get incremented
    Node<T>* newListPtr = headPtr;
    //Increment the imported pointer
    oldListPtr = oldListPtr -> getNext();

    while(oldListPtr != nullptr){  //keep incrementing until the end of x
        //Create a new node set with the next item
        Node<T>* newNodePtr = new Node<T>(oldListPtr->getItem());
        //Link the new node to the end
        newListPtr -> setNext(newNodePtr);
       //Increment pointers
        oldListPtr = oldListPtr -> getNext();
        newListPtr = newListPtr -> getNext();    
      } //End while once the list has ended

      //Set the end of the list
     newListPtr -> setNext(nullptr);
    }
}


template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}


template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(itemCount, x.itemCount);
  std::swap(headPtr, x.headPtr);
}


template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  if(itemCount==0)
    return true;
  else
    return false;
}


template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
  {return itemCount;}


template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //If position is out of scope
  if(position>itemCount)
    return false;

  //Define incrementable node
  Node<T>* nodePtr = headPtr;

  //Define new node with the item
  Node<T>* newNodePtr = new Node<T>(item);

  //If you want to insert in the head
  if(position==0){
    //Make this node point to the old head
    newNodePtr -> setNext(headPtr);
    //Make the headPtr private member be equal to the new node ptr
    headPtr = newNodePtr;
  }

  else if(position<=itemCount){

    //Increment to one before the position
    for(unsigned int i=1; i<position; i++)
      nodePtr = nodePtr -> getNext();
    
    if(position<itemCount)
      //Make both nodes point to position + 1 
      newNodePtr -> setNext(nodePtr->getNext());

    //Set the node before the position to point to the position node
    nodePtr -> setNext(newNodePtr);
  }


  itemCount++;
  return true;
}


template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //If position is out of scope
  if(position>=itemCount)
    return false;

  //Define incrementable node
  Node<T>* nodePtr = headPtr;

  //In this one, the headPtr must be changed
  if(position==0){
    //Define the new headPtr
    headPtr = headPtr->getNext();

    //Deallocate everything in the removed node
    nodePtr -> setNext(nullptr);
    delete nodePtr;
    nodePtr = nullptr;

  }

  //In this one, the node needs to be removed and must connect the node before and after
  if(position<itemCount){
    //Increment to one before the position position
    for(unsigned int i=1; i<position; i++)
      nodePtr = nodePtr -> getNext();
    
    //Save the pointer at the position that will be deleted
    Node<T>* removePtr = nodePtr -> getNext();

    //If we need to connect the nodes before and after the position
    if(position<itemCount-1)
      nodePtr -> setNext(removePtr->getNext());

    //Deallocate everything in the removed node
    removePtr -> setNext(nullptr);
    delete removePtr;
    removePtr = nullptr;
  }

  itemCount--;
  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* removePtr = headPtr;
  while(headPtr != nullptr){
    //Delete the first node
    headPtr = headPtr -> getNext();
    //Deallocate everything
    removePtr -> setNext(nullptr);
    delete removePtr;
    removePtr = headPtr;
  }

  itemCount = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //Return an empty object if an invalid entry was made
  if(position>itemCount)
    return T();

  //Create incrementable node that will be incremented until it reaches position
  Node<T>* nodePtr = headPtr;

  for(unsigned int i=0; i<position; i++)
    nodePtr = nodePtr->getNext();

  return nodePtr->getItem();
}


template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(0<=position && position<itemCount){
    //Create incrementable node that will be incremented until it reaches position
    Node<T>* nodePtr = headPtr;

    for(unsigned int i=0; i<position; i++)
      nodePtr = nodePtr->getNext();

    nodePtr->setItem(newValue);
  }
}
