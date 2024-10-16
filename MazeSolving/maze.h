// maze.hpp
// 10.22.2023

// The maze will be implemented by a n x n array of boxes, n x n+1 array of
// horizontal walls, and n+1 x n array of vertical walls The boxes will store if
// they were explored and the cost to get from the start to the center

// It is assumed that the maze is empty with its borders having walls at the
// start (bottom left box bottom wall is open because that is the start)

#ifndef MAZE_H_
#define MAZE_H_

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>

#include "API.h"

using namespace std;

// coordinate struct: x and y position
// coord operation: coord n + coord{0, -1} == n.y-1
struct coord {
  uint8_t x;
  uint8_t y;

  bool operator==(const coord &other) const {
    return x == other.x & y == other.y;
  }

  // Define operator< for ordering keys in a map
  bool operator<(const coord &other) const {
    // Compare x values first, then y values
    return (x < other.x) || (x == other.x && y < other.y);
  }
};

// Box values (cost to finish + if we've been there before)
struct box {
  uint8_t cost;
  bool explored;

  // Custom assignment operator
  box &operator=(const box &other) {
    if (this != &other) {
      this->cost = other.cost;
      this->explored = other.explored;
    }
    return *this;
  }
};

// Grid Walls (horizontal and vertical walls)
struct grid {
  bool horzWalls[16][17];
  bool vertWalls[17][16];

  // Custom assignment operator
  grid &operator=(const grid &other) {
    if (this != &other) {
      // Copy horzWalls array
      for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 17; ++j)
          this->horzWalls[i][j] = other.horzWalls[i][j];
      // Copy vertWalls array
      for (int i = 0; i < 17; ++i)
        for (int j = 0; j < 16; ++j)
          this->vertWalls[i][j] = other.vertWalls[i][j];
    }
    return *this;
  }
};

// Box Walls (NSEW)
struct bw {
  bool nWall;
  bool eWall;
  bool sWall;
  bool wWall;
};

// Flood fill queue filled with this struct
// Sorted by cost
// Queue adjacent nodes based of coord n
// c=true at start. If 1 box was unexplored, c=false
struct q {
  uint8_t cost;
  coord n;

  bool operator<(const q &q2) const {
    if (cost == q2.cost)
      return cost > q2.cost;
    else
      return cost > q2.cost;
  }

  
};

class Maze {
private:
  box mazeBoxes[16][16];
  grid mazeWalls;
  bool finished;

public:
  // Constructors
  Maze();

  ////Helper Function////
  bool inBounds(const coord &n);
  bool inBounds(const vector<coord> &n);

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
  // Walls//
  void setSWall(const coord &n);
  void setNWall(const coord &n);
  void setWWall(const coord &n);
  void setEWall(const coord &n);
  void setBorder();

  void removeSWall(const coord &n);
  void removeNWall(const coord &n);
  void removeWWall(const coord &n);
  void removeEWall(const coord &n);

  // Clears the middle walls, leaves/creates a border
  void clearWalls();

  // Boxes//
  void setCost(const coord &n, const uint8_t &cost);
  void setExplored(const coord &n);

  void removeCost(const coord &n);
  void removeExplored(const coord &n);

  void clearCost();
  void clearExplored();
  void clearBoxes();

  // General//
  void setFinished();
  void clear();

  ////Flood Fill Functions////

  bool checkAdjacent(const coord &n, box (&b)[16][16]);
  // If all adjacent boxes are explored, the middle box is also explored
  void autoExploreBoxes();
  // From 4 middle boxes to bottom left, used to find best path from S->F
  void floodFill(coord start, vector<coord> finish);
  // Finds best path from current box to desired box
  // Will return a stack of directions that it will follow after

  // Finds best path from current box to desired box - just requires start coord
  void floodFill(vector<coord> start);
};

#endif