//Maze.hpp
//10.22.2023

//The maze will be implemented by a n x n array of boxes and n+1 x n+1 array of walls
//The boxes will store if they were explored and the cost to get from the start to the center

//It is assumed that the maze is empty with its borders having walls at the start (bottom left box bottom wall is open because that is the start)


#ifndef MAZE_HPP_
#define MAZE_HPP_

using std::pair;

class Maze
{
private:
   /// @brief int holds the cost to get from the start to that square, bool holds if we've explored it
   /// @note we will change int to the smallest possible number so we can get faster performance
   std::pair<int, bool> box;
   bool walls[17][17];
   
public:
   //Constructors
   Maze();

   //Mutator Functions
   void setWall(const int &x, const int &y);
   void setExplore();
   void removeWall();
   void removeExplore();
   void clear();
}; // end Node

#include "Node.cpp"
#endif