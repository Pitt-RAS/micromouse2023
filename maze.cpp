#include "maze.h"
#include "API.h"

////--------------CONSTRUCTORS--------------////

// Default Maze Constructor
// PURPOSE: This will initialize all borders walls to true and middle walls
// false Every box will have a cost = max and explored = false
Maze::Maze() { clear(); }

////--------------ACCESSOR FUNCTIONS--------------////

bool Maze::inBounds(const coord &n) {
  return (n.x >= 0 && n.x < 16 && n.y >= 0 && n.y < 16);
}

bool Maze::inBounds(const vector<coord> &n) {
  for (int i = 0; i < n.size(); i++) {
    if (!inBounds(n[i]))
      return false;
  }
  return true;
}

grid Maze::getGrid() { return mazeWalls; }

/// @returns Wall on South edge of box
bool Maze::getSWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.horzWalls[n.x][n.y];
  else
    throw(std::range_error("error in range1"));
}

/// @returns Wall on North edge of box
bool Maze::getNWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.horzWalls[n.x][n.y + 1];
  else
    throw(std::range_error("error in range2"));
}

/// @returns Wall on West edge of box
bool Maze::getWWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.vertWalls[n.x][n.y];
  else
    throw(std::range_error("error in range3"));
}

/// @returns Wall on East edge of box
bool Maze::getEWall(const coord &n) {
  if (inBounds(n))
    return mazeWalls.vertWalls[n.x + 1][n.y];
  else
    throw(std::range_error("error in range4"));
}

/// @returns NESW walls in struct
bw Maze::getWalls(const coord &n) {
  if (!inBounds(n))
    throw(std::range_error("error in range5"));

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
    throw(std::range_error("error in range6"));
}

/// @returns cost from box n to finish
uint8_t Maze::getCost(const coord &n) {
  if (inBounds(n))
    return mazeBoxes[n.x][n.y].cost;
  else
    throw(std::range_error("error in range7"));
}

/// @returns if explored before
bool Maze::getExplored(const coord &n) {
  if (inBounds(n))
    return mazeBoxes[n.x][n.y].explored;
  else
    throw(std::range_error("error in range8"));
}

bool Maze::getFinished() { return finished; }

////--------------MUTATOR FUNCTIONS--------------////

////----Set Walls----////

void Maze::setSWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.horzWalls[n.x][n.y] = true;
  else
    throw(std::range_error("error in range9"));
}

void Maze::setNWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.horzWalls[n.x][n.y + 1] = true;
  else
    throw(std::range_error("error in range10"));
}

void Maze::setWWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x][n.y] = true;
  else
    throw(std::range_error("error in range11"));
}

void Maze::setEWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x + 1][n.y] = true;
  else
    throw(std::range_error("error in range12"));
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
    throw(std::range_error("error in range13"));
}

void Maze::removeNWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.horzWalls[n.x][n.y + 1] = false;
  else
    throw(std::range_error("error in range14"));
}

void Maze::removeWWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x][n.y] = false;
  else
    throw(std::range_error("error in range15"));
}

void Maze::removeEWall(const coord &n) {
  if (inBounds(n))
    mazeWalls.vertWalls[n.x + 1][n.y] = false;
  else
    throw(std::range_error("error in range16"));
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
  if (inBounds(n)){
    mazeBoxes[n.x][n.y].cost = cost;
    API::setText(n.x, n.y, to_string(cost));
  }else
    throw(std::range_error("error in range17"));
}

/// @brief Set explored to true
void Maze::setExplored(const coord &n) {
  if (inBounds(n)){
    mazeBoxes[n.x][n.y].explored = true;
    API::setColor(n.x, n.y, 'b');
  }else
    throw(std::range_error("error in range18"));
}

////----Remove Boxes----////

/// @brief Set cost to max value
void Maze::removeCost(const coord &n) {
  if (inBounds(n)){
    mazeBoxes[n.x][n.y].cost = UINT8_MAX;
    API::setText(n.x, n.y, to_string(mazeBoxes[n.x][n.y].cost));
  }else
    throw(std::range_error("error in range19"));
}

/// @brief Set explored to false
void Maze::removeExplored(const coord &n) {
  if (inBounds(n)){
    mazeBoxes[n.x][n.y].explored = false;
    API::setColor(n.x, n.y, 'r');
  }else
    throw(std::range_error("error in range20"));
}

////----General Functions----////

// If finished, this will make private member variable finished=true
// If not finished, finished=false
///***Later want to add functionality for diagonal travel
////CHANGE!!!!!!////
void Maze::setFinished() {

  queue<coord> coordQueue;
  coord n;

  // If currently at corner
  if (getCost(coord{0, 0}) == 0) {
    for (uint8_t i = 7; i < 9; i++) {
      for (uint8_t j = 7; j < 9; j++) {
        n = coord{i, j};
        coordQueue.push(n);
      }
    }
  }
  // If currently at center
  else if (getCost(coord{7, 7}) == 0 || getCost(coord{7, 8}) == 0 ||
           getCost(coord{8, 7}) == 0 || getCost(coord{8, 8}) == 0) {
    n = coord{0, 0};
    coordQueue.push(n);
  }
  // If not from start to end
  else
    return;

  finished = true;

  coord n2;
  uint8_t x, y;

  // While queue is not empty
  while (!coordQueue.empty()) {
    n = coordQueue.front();
    x = n.x;
    y = n.y;
    coordQueue.pop();

    uint8_t currCost = getCost(n);
    // If we made it to the finish
    if (!currCost)
      return;

    // Queue checks all surrounding squares to see if they are on the best path
    // If they are, add it to the queue

    n2 = coord{x, static_cast<uint8_t>(y + 1)};
    // If north box can be traveled to
    if (!getNWall(n)) {
      if(inBounds(n2)){
        // If box is on best path
        if (currCost - 1 == getCost(n2)) {
          // If box is explored
          if (getExplored(n2))
            coordQueue.push(n2);
        }
      }
    }

    n2 = coord{x, static_cast<uint8_t>(y - 1)};
    // If south box can be traveled to
    if (!getSWall(n)) {
      if(inBounds(n2)){
        // If box is on best path
        if (currCost - 1 == getCost(n2)) {
          // If box is explored
          if (getExplored(n2))
            coordQueue.push(n2);
        }
      }
    }

    n2 = coord{static_cast<uint8_t>(x + 1), y};
    // If east box can be traveled to
    if (!getEWall(n)) {
      if(inBounds(n2)){
        // If box is on best path
        if (currCost - 1 == getCost(n2)) {
          // If box is explored
          if (getExplored(n2))
            coordQueue.push(n2);
        }
      }
    }

    n2 = coord{static_cast<uint8_t>(x - 1), y};
    // If west box can be traveled to
    if (!getWWall(n)) {
      if(inBounds(n2)){
        // If box is on best path
        if (currCost - 1 == getCost(n2)) {
          // If box is explored
          if (getExplored(n2))
            coordQueue.push(n2);
        }
      }
    }
  }

  // Only get here if there wasn't a fully explored path to the finish
  finished = false;
}

////----Clear Functions----////

/// @brief Set all costs to max
void Maze::clearCost() {
  for (uint8_t i = 0; i < 16; i++)
    for (uint8_t j = 0; j < 16; j++)
      // reset cost to MAX
      removeCost(coord{i, j});
}

void Maze::clearExplored() {
  for (uint8_t i = 0; i < 16; i++)
    for (uint8_t j = 0; j < 16; j++)
      removeExplored(coord{i, j});
}

void Maze::clearBoxes() {
  clearCost();
  clearExplored();
}

void Maze::clear() {
  clearBoxes();
  clearWalls();
  finished = false;
}

////--------------FLOODFILL FUNCTIONS--------------////

bool Maze::checkAdjacent(const coord &n, box (&b)[16][16]) {
  bool explored = true;

  coord n2;
  uint8_t x = n.x;
  uint8_t y = n.y;

  n2 = coord{static_cast<uint8_t>(x - 1), y};
  if (inBounds(n2)) {
    explored = explored & getExplored(n2);
    b[n2.x][n2.y].explored = true;
  }
  n2 = coord{static_cast<uint8_t>(x + 1), y};
  if (inBounds(n2)) {
    explored = explored & getExplored(n2);
    b[n2.x][n2.y].explored = true;
  }
  n2 = coord{x, static_cast<uint8_t>(y - 1)};
  if (inBounds(n2)) {
    explored = explored & getExplored(n2);
    b[n2.x][n2.y].explored = true;
  }
  n2 = coord{x, static_cast<uint8_t>(y + 1)};
  if (inBounds(n2)) {
    explored = explored & getExplored(n2);
    b[n2.x][n2.y].explored = true;
  }

  return explored;
}

// If an unexplored box has all adjacent boxes = explored, then that box =
// explored
// adjacent, take them out. Whatever's left should be made explored
void Maze::autoExploreBoxes() {
  box copy[16][16];
  for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
      copy[i][j] = mazeBoxes[i][j];
    }
  }

  for (uint8_t i = 0; i < 16; i++) {
    for (uint8_t j = 0; j < 16; j++) {
      if (copy[i][j].explored) {
        if (checkAdjacent(coord{i, j}, copy))
          setExplored(coord{i, j});
      }
    }
  }
}


////NOTHING STOPPING US FROM QUEUING THE SAME SQUARE TWICE????

// Performs floodFill to fill boxes with the cost to get to the center
void Maze::floodFill(coord start, vector<coord> finish) {
  // get boxes ready for flood fill
  ////autoExploreBoxes();
  // clearing cost makes all costs MAX=
  clearCost();

  // priority queue is sorted by cost
  // uint8_t holds the cost
  // coord holds the box
  priority_queue<q> pq;

  // The finish can be 1 square or all 4 center squares
  // We start at the place we want to go
  for (uint8_t i = 0; i < finish.size(); i++) {
    pq.push(q{0, finish[i]});
    setCost(finish[i], 0);
  }

  // Curr stores the box we're currently on
  q curr;
  coord n, n2;
  uint8_t x, y;
  uint8_t cost, change = 1;

  std::cerr << "In the Flood Fill" << endl;

  // While there are unexplored boxes and we haven't found the exit
  while (!pq.empty()) {

    curr = pq.top();
    n = curr.n;
    cost = curr.cost;
    x = n.x;
    y = n.y;
    pq.pop();

    // Cost of adjacent boxes
    cost++;

    // If we're at the our current square//
    if (x == start.x && y == start.y) {
      std::cerr << "Found the finish" << endl;
      setFinished();
      return;
    }

    // Queueing Boxes //

    // If north box can be traveled to and hasn't been queued yet, queue it
    if (!getNWall(n)) {
      n2 = coord{x, static_cast<uint8_t>(y + 1)};
      if(inBounds(n2)){
        // If the box hasn't gotten a cost yet
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }

    // If south box can be traveled to and hasn't been queued yet
    if (!getSWall(n)) {
      n2 = coord{x, static_cast<uint8_t>(y - 1)};
      if(inBounds(n2)){
        // If the box hasn't gotten a cost yet
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }
    // If east box can be traveled to and hasn't been queued yet
    if (!getEWall(n)) {
      n2 = coord{static_cast<uint8_t>(x + 1), y};
      if(inBounds(n2)){
        // If the box hasn't gotten a cost yet
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }

    // If west box can be traveled to and hasn't been queued yet
    if (!getWWall(n)) {
      n2 = coord{static_cast<uint8_t>(x - 1), y};
      if(inBounds(n2)){
        // If the box hasn't gotten a cost yet
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }
    
  }
  // Only get here if we didn't find the finish
  throw(std::invalid_argument("No path found"));
}

// Performs FloodFill to every box in the maze. Does not stop when reaching
// the target boxes. Used for
void Maze::floodFill(vector<coord> start) {
  // get boxes ready for flood fill
  autoExploreBoxes();
  // clearing cost makes all costs MAX=
  clearCost();

  // priority queue is sorted by cost
  // uint8_t holds the cost
  // coord holds the box
  priority_queue<q> pq;

  // Pushing the four center squares to represent the finish :(
  for (int i = 0; i < start.size(); i++) {
    pq.push(q{0, start[i]});
    setCost(start[i], 0);
  }

  // Curr stores the box we're currently on
  q curr;
  coord n, n2;
  uint8_t x, y;
  uint8_t cost;

  // While there are unexplored boxes and we haven't found the exit
  while (!pq.empty()) {

    curr = pq.top();
    n = curr.n;
    cost = curr.cost;
    x = n.x;
    y = n.y;
    pq.pop();

    cost++;

    // Queueing Boxes //

    // If north box can be traveled to and hasn't been queued yet, queue it
    if (!getNWall(n)) {
      n2 = coord{x, static_cast<uint8_t>(y + 1)};
      if(inBounds(n2)){
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }

    // If south box can be traveled to and hasn't been queued yet
    if (!getSWall(n)) {
      n2 = coord{x, static_cast<uint8_t>(y - 1)};
      if(inBounds(n2)){
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }
    // If east box can be traveled to and hasn't been queued yet
    if (!getEWall(n)) {
      n2 = coord{static_cast<uint8_t>(x + 1), y};
      if(inBounds(n2)){
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }

    // If west box can be traveled to and hasn't been queued yet
    if (!getWWall(n)) {
      n2 = coord{static_cast<uint8_t>(x - 1), y};
      if(inBounds(n2)){
        if (getCost(n2) == UINT8_MAX) {
          pq.push(q{cost, n2});
          setCost(n2, cost);
        }
      }
    }
  }
}