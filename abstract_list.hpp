
#ifndef _ABSTRACT_LIST_HPP_
#define _ABSTRACT_LIST_HPP_

#include <cstdlib>

class AbstractList
{
public:
    // determine if a list is empty
    virtual bool isEmpty() const noexcept = 0;

    // return current length of the list
    virtual int getLength() const noexcept = 0;

    // insert item at position in the list using 0-based indexing
    virtual bool insert(int position, const int &x, const int &y) = 0;

    // remove item at position in the list using 0-based indexing
    virtual bool remove(int position) = 0;

    // remove all items from the list
    virtual void clear() = 0;

    // get a copy of the item at position using 0-based indexing
    virtual int getXCoordinate(int position) const = 0;         //Change to get Coordinate
    virtual int getYCoordinate(int position) const = 0;         //Change to get Coordinate

    // set the value of the item at position using 0-based indexing
    virtual void setXCoordinate(int position, const int &x) = 0;
    virtual void setYCoordinate(int position, const int &y) = 0;
};

#endif
