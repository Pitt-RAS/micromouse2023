#include "Maze.hpp"
#include <string>



///TODO
//1. remove next function


//Default Maze Constructor
//PURPOSE: This will initialize all wall borders true and the middle false
Maze::Maze() : walls(0)
{
   //Make all borders walls
   for(int i=0; i<walls.size(); i++){
      setWalls(i, 0);
      setWalls(0, i);
      setWalls(i, 16);
      setWalls(16, i);
   }

}


void Maze::setWall(const int &x, const int &y)  //Change this to either 2 ints (x, y) or a 2d array
{
   walls[x][y] = true;
}

