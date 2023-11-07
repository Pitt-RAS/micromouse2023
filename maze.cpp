#include "maze.hpp"
#include <iostream>
#include <string>

////--------------HELPER FUNCTIONS--------------////
// Checks if the given coord is in bounds of the 16x16 maze
static bool inBounds(const coord &n) {
  return (n.x >= 0 && n.x < 16 && n.y >= 0 && n.y < 16);
}

////--------------CONSTRUCTORS--------------////

// Default Maze Constructor
// PURPOSE: This will initialize all borders walls to true and middle walls
// false Every box will have a cost = max and explored = false
Maze::Maze() { clear(); }

////--------------ACCESSOR FUNCTIONS--------------////

grid Maze::getGrid() { return mazeWalls; }

/// @returns Wall on South edge of box
bool Maze::getSWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.horzWalls[n.x][n.y];
  else
    throw(std::range_error("error in range"));
}

/// @returns Wall on North edge of box
bool Maze::getNWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.horzWalls[n.x][n.y + 1];
  else
    throw(std::range_error("error in range"));
}

/// @returns Wall on West edge of box
bool Maze::getWWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.vertWalls[n.x][n.y];
  else
    throw(std::range_error("error in range"));
}

/// @returns Wall on East edge of box
bool Maze::getEWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.vertWalls[n.x + 1][n.y];
  else
    throw(std::range_error("error in range"));
}

/// @returns NESW walls in struct
bw Maze::getWalls(const coord &n) {
  if (!inBounds(n))
    throw(std::range_error("error in range"));

  bw wall;

  wall.nWall = getNWall(n);
  wall.sWall = getSWall(n);
  wall.wWall = getWWall(n);
  wall.eWall = getEWall(n);

  return wall;
}

/// @returns cost and explored of box in struct
box Maze::getBox(const coord &n) {
  if (inBounds(n))
    return mazeBoxes[n.x][n.y];
  else
    throw(std::range_error("error in range"));
}

/// @returns cost from box n to finish
uint8_t Maze::getCost(const coord &n) {
  if (inBounds(n))
    return mazeBoxes[n.x][n.y].cost;
  else
    throw(std::range_error("error in range"));
}

/// @returns if explored before
bool Maze::getExplored(const coord &n) {
  if (inBounds(n))
    return mazeBoxes[n.x][n.y].explored;
  else
    throw(std::range_error("error in range"));
}

bool Maze::getFinished()
  {return finished;}

////--------------MUTATOR FUNCTIONS--------------////

////----Set Walls----////

void Maze::setSWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.horzWalls[n.x][n.y] = true;
  else
    throw(std::range_error("error in range"));
}

void Maze::setNWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.horzWalls[n.x][n.y + 1] = true;
  else
    throw(std::range_error("error in range"));
}

void Maze::setWWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x][n.y] = true;
  else
    throw(std::range_error("error in range"));
}

void Maze::setEWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x + 1][n.y] = true;
  else
    throw(std::range_error("error in range"));
}

void Maze::setBorder() {
  // Set all borders walls = true
  for (uint8_t i = 0; i < 16; i++) {
    setWWall({0, i});
    setEWall({15, i});
    setSWall({i, 0});
    setNWall({i, 15});
  }
}

////----Remove Walls----////

void Maze::removeSWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.horzWalls[n.x][n.y] = false;
  else
    throw(std::range_error("error in range"));
}

void Maze::removeNWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.horzWalls[n.x][n.y + 1] = false;
  else
    throw(std::range_error("error in range"));
}

void Maze::removeWWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x][n.y] = false;
  else
    throw(std::range_error("error in range"));
}

void Maze::removeEWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x + 1][n.y] = false;
  else
    throw(std::range_error("error in range"));
}

/// @return Only the border should be left for the walls
void Maze::clearWalls() {
  for (uint8_t i = 0; i < 15; i++) {
    for (uint8_t j = 0; j < 15; j++) {
      // Will remove horzWalls 1-15, leaving 0 and 16
      removeNWall(coord{i, j});
      // Will remove vertWalls 1-15, leaving 0 and 16
      removeEWall(coord{i, j});
    }
  }
  // If border didn't already exist, make one
  setBorder();
}

////----Set Boxes----////

/// @brief Set box to the parameter cost
void Maze::setCost(const coord &n, const uint8_t &cost) {
  if (inBounds(n))
    mazeBoxes[n.x][n.y].cost = cost;
  else
    throw(std::range_error("error in range"));
}

/// @brief Set explored to true
void Maze::setExplored(const coord &n) {
  if (inBounds(n))
    mazeBoxes[n.x][n.y].explored = true;
  else
    throw(std::range_error("error in range"));
}

////----Remove Boxes----////

/// @brief Set cost to max value
void Maze::removeCost(const coord &n) {
  if (inBounds(n))
    mazeBoxes[n.x][n.y].cost = INT8_MAX;
  else
    throw(std::range_error("error in range"));
}

/// @brief Set explored to false
void Maze::removeExplored(const coord &n) {
  if (inBounds(n))
    mazeBoxes[n.x][n.y].explored = false;
  else
    throw(std::range_error("error in range"));
}

////----General Functions----////
void Maze::setFinished(){
  finished = true;
}
void Maze::setUnfinished(){
  finished = false;
}

////----Clear Functions----////

/// @brief Set all costs to max
void Maze::clearCost() {
  for (uint8_t i = 0; i < 16; i++)
    for (uint8_t j = 0; j < 16; j++)
      // reset cost to MAX
      mazeBoxes[i][j].cost = UINT8_MAX;
}

void Maze::clearExplored() {
  for (uint8_t i = 0; i < 16; i++)
    for (uint8_t j = 0; j < 16; j++)
      mazeBoxes[i][j].explored = false;
}

void Maze::clearBoxes() {
  clearCost();
  clearExplored();
}

void Maze::clear() {
  clearWalls();
  clearBoxes();
  finished = 0;
}

////--------------FLOODFILL FUNCTIONS--------------////

// If an unexplored box has all adjacent boxes = explored, then that box =
// explored
//@note THIS SHOULD BE OPTIMIZED INSTEAD OF BRUTE FORCE
//@optimization maybe put all unexplored into a heap and if 2 in the heap are
// adjacent, take them out. Whatever's left should be made explored
void Maze::autoExploreBoxes() {}

// Performs floodFill to fill boxes with the cost to get to the center
bool Maze::floodFill(bool startToFinish) {
  //get boxes ready for flood fill
  autoExploreBoxes();
  //clearing cost makes all costs MAX=
  clearCost();

  //priority queue is sorted by cost but also holds whether the path has been completely explored before
  //uint8_t holds the cost
  //bool holds whether the path has been completely explored before. bool=true at start and will =false if box on this path hasn't been explored before

  //@note need to sort by cost, explore using coord, and have a bool to confirm if they've all been explored
  priority_queue< pair<coord, bool> > pq;

  //if we put minecraft water in center
  if(startToFinish){
    
    pq.queue()
  }
  
}