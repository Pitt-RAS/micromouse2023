//maze.hpp
//10.22.2023

//The maze will be implemented by a n x n array of boxes, n x n+1 array of horizontal walls, and n+1 x n array of vertical walls
//The boxes will store if they were explored and the cost to get from the start to the center

//It is assumed that the maze is empty with its borders having walls at the start (bottom left box bottom wall is open because that is the start)


#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <iostream>
#include <cstdint>
#include <queue>
#include <stack>

using namespace std;

//This is used to store directions from current box to destination box
//n = 0, ne = 1, e = 2, ... nw = 7
enum dir {n, ne, e, se, s, sw, w, nw};

//coordinate struct: x and y position
struct coord{
  uint8_t x;
  uint8_t y;
};


//Box values (cost to finish + if we've been there before)
struct box{
  uint8_t cost;
  bool explored;
};

//Grid Walls (horizontal and vertical walls)
struct grid{
  bool horzWalls[16][17];
  bool vertWalls[17][16];
};

//Box Walls (NSEW)
struct bw{
  bool nWall;
  bool eWall;
  bool sWall;
  bool wWall;
};

//Flood fill queue filled with this struct
//Sorted by cost
//Queue adjacent nodes based of coord n
//c=true at start. If 1 box was unexplored, c=false
struct q{
  uint8_t cost;
  coord n;
  bool c;
};


class Maze
{
private:

  box mazeBoxes[16][16];
  grid mazeWalls;
  bool complete;

public:
  //Constructors
  Maze();


  ////Accessor Functions////
  grid getGrid();
  bool getSWall(const coord &n);
  bool getNWall(const coord &n);
  bool getWWall(const coord &n);
  bool getEWall(const coord &n);
  bw getWalls(const coord &n);
  box getBox(const coord &n);
  uint8_t getCost(const coord &n);
  bool getExplored(const coord &n);
  bool getFinished();
  
  
  

  ////Mutator Functions////
  //Walls//
  void setSWall(const coord &n);
  void setNWall(const coord &n);
  void setWWall(const coord &n);
  void setEWall(const coord &n);
  void setBorder();

  void removeSWall(const coord &n);
  void removeNWall(const coord &n);
  void removeWWall(const coord &n);
  void removeEWall(const coord &n);

  //Clears the middle walls, leaves/creates a border
  void clearWalls();

  //Boxes//
  void setCost(const coord &n, const uint8_t &cost);
  void setExplored(const coord &n);

  void removeCost(const coord &n);
  void removeExplored(const coord &n);
  
  
  void clearCost();
  void clearExplored();
  void clearBoxes();

  //General//
  void setFinished();
  void setUnfinished();
  void clear();

  

  ////Flood Fill Functions////
  //If all adjacent boxes are explored, the middle box is also explored
  void autoExploreBoxes();
  //From 4 middle boxes to bottom left, used to find best path from S->F
  bool floodFill(bool startToFinish);
  //Finds best path from current box to desired box
  //Will return a stack of directions that it will follow after
  
};


#endif