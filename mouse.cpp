#include "mouse.hpp"
#include <cstdint>
#include <iostream>
#include <string>

////--------------HELPER FUNCTIONS--------------////
// Checks if the given coord is in bounds of the 16x16 maze

////--------------CONSTRUCTORS--------------////

// Default constructor - setting all private variables to defaults
Mouse::Mouse() {
  direction = n;
  resetLocation();
}

Mouse::Mouse(Maze maze) {
  direction = n;
  resetLocation();
  m = maze;
}

////--------------ACCESSOR FUNCTIONS--------------///

// @Returns the current direction of the Mouse
dir Mouse::getDirection() { return direction; }

dir numToDir(int8_t num) {

  if (num < 0)
    num = 8 - num;

  switch (num) {
  // 0 = North
  case 0:
    return n;
    break;
  // 1 = North East
  case 1:
    return ne;
    break;
  // 2 = East
  case 2:
    return e;
    break;
  // 3 = South East
  case 3:
    return se;
    break;
  // 4 = South
  case 4:
    return n;
    break;
  // 5 = South West
  case 5:
    return ne;
    break;
  // 6 = West
  case 6:
    return e;
    break;
  // 7 = North West
  case 7:
    return se;
    break;
  // if direction isn't between 0 and 7
  default:
    throw(std::range_error("error in direction"));
  }
}

uint8_t dirToNum(const dir &d) {
  switch (d) {
  // 0 = North
  case n:
    return 0;
    break;
  // 1 = North East
  case ne:
    return 1;
    break;
  // 2 = East
  case e:
    return 2;
    break;
  // 3 = South East
  case se:
    return 3;
    break;
  // 4 = South
  case s:
    return 4;
    break;
  // 5 = South West
  case sw:
    return 5;
    break;
  // 6 = West
  case w:
    return 6;
    break;
  // 7 = North West
  case nw:
    return 7;
    break;
  // if direction isn't between 0 and 7
  default:
    throw(std::range_error("error in direction"));
  }
}

dir Mouse::turnToDir(const int8_t &turn) {
  int8_t d = direction;
  d = d + turn;
  // If D is now negative
  if (d < 0)
    // Get it's positive equivalent
    d = 8 - d;

  switch (d) {
  // 0 = North
  case 0:
    return n;
    break;
  // 1 = North East
  case 1:
    return ne;
    break;
  // 2 = East
  case 2:
    return e;
    break;
  // 3 = South East
  case 3:
    return se;
    break;
  // 4 = South
  case 4:
    return n;
    break;
  // 5 = South West
  case 5:
    return ne;
    break;
  // 6 = West
  case 6:
    return e;
    break;
  // 7 = North West
  case 7:
    return se;
    break;
  // if direction isn't between 0 and 7
  default:
    throw(std::range_error("error in direction"));
  }
}

// @Returns the current location of the Mouse
coord Mouse::getLocation() { return location; }


////----Get Costs----////

// @returns the cost of the Mouse's current location
uint8_t Mouse::getCurrCost() { return m.getCost(location); }

// @returns cost of box that is on the left of the mouse
uint8_t Mouse::getLeftCost() {
  switch (direction) {
  // left = west = x--
  case n:
    if (inBounds(coord{location.x--, location.y}))
        return m.getCost(coord {location.x--, location.y}));
    break;
  // left = east = x++
  case s:
    if (inBounds(coord{location.x++, location.y}))
        return m.getCost(coord {location.x++, location.y}));
    break;
  // left = south = y--
  case w:
    if (inBounds(coord{location.x, location.y--}))
        return m.getCost(coord {location.x, location.y--}));
    break;
  // left = north = y++
  case e:
    if (inBounds(coord{location.x, location.y++}))
        return m.getCost(coord {location.x, location.y++}));
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction"));
  }
}

// @returns cost of box that is in front of the mouse
uint8_t Mouse::getForwardCost() {
  switch (direction) {
  // forward = y++
  case n:
    if (inBounds(coord{location.x, location.y++}))
        return m.getCost(coord {location.x, location.y++}));
    break;
  // forward = y--
  case s:
    if (inBounds(coord{location.x, location.y--}))
        return m.getCost(coord {location.x, location.y--}));
    break;
  // forward = x--
  case w:
    if (inBounds(coord{location.x--, location.y}))
        return m.getCost(coord {location.x--, location.y}));
    break;
  // forward = x++
  case e:
    if (inBounds(coord{location.x++, location.y}))
        return m.getCost(coord {location.x++, location.y}));
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction"));
  }
}

// @returns cost of box that is on the right of the mouse
uint8_t Mouse::getRightCost() {
  switch (direction) {
  // right = east = x++
  case n:
    if (inBounds(coord{location.x++, location.y}))
        return m.getCost(coord {location.x++, location.y}));
    break;
  // right = west = x+--
  case s:
    if (inBounds(coord{location.x--, location.y}))
        return m.getCost(coord {location.x--, location.y}));
    break;
  // right = north = y++
  case w:
    if (inBounds(coord{location.x, location.y++}))
        return m.getCost(coord {location.x, location.y++}));
    break;
  // right = south = y--
  case e:
    if (inBounds(coord{location.x, location.y--}))
        return m.getCost(coord {location.x, location.y--}));
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction"));
  }
}

////--------------MUTATOR FUNCTIONS--------------////

// Sets the current direction of the Mouse to new direction
// Setting a new direction requires a physical turn from the mouse
void Mouse::setDirection(const dir &d) {
  // if direction is to the left
  if (d == direction - 2)
    turnLeft();
  if (d == direction + 2)
    turnRight();
  if (d == direction - 4)
    turnAround();

  direction = d;
}

// Sets the current location of the Mouse to new location
void Mouse::setLocation(const coord &n) { location = n; }

// Resets the current location to the starting point
void Mouse::resetLocation() { location = coord{0, 0}; }

////----Set Walls----////

// Sets left wall to value of sensor
void Mouse::setLeftWall(bool left) {
  switch (direction) {
  // if left, set west wall = 1
  case n:
    if (left)
      m.setWWall(location);
    break;
    // if left, set left wall = 1
  case s:
    if (left)
      m.setEWall(location);
    break;
  // if left, set south wall = 1
  case w:
    if (left)
      m.setSWall(location);
    break;
  // if left, set north wall = 1
  case e:
    if (left)
      m.setNWall(location);
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction"));
  }
}

// Sets forward wall to value of sensor
void Mouse::setForwardWall(bool forward) {
  switch (direction) {
  // if forward, set north wall = 1
  case n:
    if (forward)
      m.setNWall(location);
    break;
  // if forward, set south wall = 1
  case s:
    if (forward)
      m.setSWall(location);
    break;
  // if forward, set west wall = 1
  case w:
    if (forward)
      m.setWWall(location);
    break;
  // if forward, set east wall = 1
  case e:
    if (forward)
      m.setEWall();
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction"));
  }
}

// Sets right wall to value of sensor
void Mouse::setRightWall(bool right) {
  switch (direction) {
  // if right, set east wall = 1
  case n:
    if (right)
      m.setEWall(location);
    break;
    // if right, set west wall = 1
  case s:
    if (right)
      m.setWWall(location);
    break;
    // if right, set north wall = 1
  case w:
    if (right)
      m.setNWall(location);
    break;
    // if right, set south wall = 1
  case e:
    if (right)
      m.setSWall(location);
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction"));
  }
}

// Set walls of all surrounding walls to sensor values
void Mouse::setWalls(bool left, bool forward, bool right) {
  bool *sensorData = getSensorData();

  setLeftWall(sensorData[0]);
  setForwardWall(sensorData[1]);
  setRightWall(sensorData[2]);
}

////--------------MOVEMENT FUNCTIONS--------------////

// Moves the Mouse forward
void Mouse::moveForward() {

  // marks the location that is being left from as explored
  m.setExplored(location);

  coord newLoc;

  switch (direction) {
  case n:
    newLoc = {location.x, location.y++};
    if (inBounds(newLoc)) {
      moveForwardOne();
      location.y++;
      setLocation(location);
    }
    break;
  case e:
    newLoc = {location.x++, location.y};
    if (inBounds(newLoc)) {
      moveForwardOne();
      location.x++;
      setLocation(location);
    }
    break;
  case s:
    newLoc = {location.x, location.y--};
    if (inBounds(newLoc)) {
      moveForwardOne();
      location.y--;
      setLocation(location);
    }
    break;
  case w:
    newLoc = {location.x--, location.y};
    if (inBounds(newLoc)) {
      moveForwardOne();
      location.x--;
      setLocation(location);
    }
    break;
  default:
    break;
  }
}

// Moves the mouse forwards one unit
void Mouse::moveForwardOne() {
  /* PLEASE PUT CODE THAT MOVES THE MOUSE FORWARD HERE */
}

// Turns the Mouse left
void Mouse::turnLeft() { /* PLEASE PUT CODE THAT TURNS THE MOUSE LEFT HERE */ }

// Turns the Mouse right
void Mouse::turnRight() { /* PLEASE PUT CODE THAT TURNS THE MOUSE LEFT HERE */ }

// Turns the Mouse around
void Mouse::turnAround() {
  /* PLEASE PUT CODE THAT TURNS THE MOUSE AROUND HERE */
}

/* THESE TWO METHODS HAVE TO BE UPDATED */

// Moves the Mouse left
void Mouse::moveLeft() {
  turnLeft();
  moveForward();
  updateDirection(false);
}

// Moves the Mouse right
void Mouse::moveRight() {
  turnRight();
  moveForward();
  updateDirection(true);
}

// Returns the statuses for the wall from sensors
bool *Mouse::getSensorData() {

  // 0 - left; 1 - forward; 2 - right
  bool sensors[3];

  /* PLEASE PUT CODE THAT RETURNS SENSOR DATA HERE HERE */

  return sensors;
}

////--------------GENERAL FUNCTIONS--------------////

bool Mouse::deadEndFound() {
  bool *sensorData = getSensorData();
  if (sensorData[0] == true && sensorData[1] == true && sensorData[2] == true) {
    return true;
  } else
    return false;
}

/* PLEASE LOOK AT NOTES ISABELLA PLEASE PLEASE */
// @returns the direction the mouse should go in
dir Mouse::findNextMove() {

  // If none of the boxes will help to get the fastest path, these
  // values won't change and we will say to go backwards
  int8_t newDir = -4;
  uint8_t minCost = getCurrCost();

  // If the left box's cost is less than current cost, we should go left
  if (minCost >= getLeftCost()) {
    newDir = -2;
    minCost = getLeftCost();
  }

  // If forward box is the best place to go next, go there
  if (minCost >= getForwardCost()) {
    newDir = 0;
    minCost = getLeftCost();
  }

  if (minCost >= getRightCost()) {
    newDir = 2;
    minCost = getRightCost();
  }

  ///***Find a way to return the best direction. If can't use operation,
  /// just use switch cases
  /* if newDir = dir +- 2 || dir
        setDir(newDir)
        moveForward() */

  return
}

void Mouse::explore() {}

void Mouse::findBestPath() {}
