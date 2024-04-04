#include "mouse.h"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>

////--------------HELPER FUNCTIONS--------------////
// Checks if the given coord is in bounds of the 16x16 maze

////--------------CONSTRUCTORS--------------////

// Default constructor - setting all private variables to defaults
Mouse::Mouse() : direction(n), fromCenter(0) {
  resetLocation();
  resetCenter();
  resetDestination();
  m.floodFill(location, destination);
  //explore();
}

Mouse::Mouse(Maze maze) : direction(n), fromCenter(0), m(maze) {
  resetLocation();
  resetCenter();
  resetDestination();
  m.floodFill(location, destination);
  //explore();
}

////--------------ACCESSOR FUNCTIONS--------------///

// @Returns the current direction of the Mouse
dir Mouse::getDirection() { return direction; }

dir Mouse::numToDir(int8_t num) {

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
    return s;
    break;
  // 5 = South West
  case 5:
    return sw;
    break;
  // 6 = West
  case 6:
    return w;
    break;
  // 7 = North West
  case 7:
    return nw;
    break;
  // if direction isn't between 0 and 7
  default:
    throw(std::range_error("error in direction 1"));
  }
}

int8_t Mouse::dirToNum(const dir &d) {
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
    throw(std::range_error("error in direction 2"));
  }
}

dir Mouse::turnToDir(const int8_t &turn) {
  int8_t d = direction;
  d += turn;

  // If D is now negative
  if (d < 0)
    // Get it's positive equivalent
    d = 8 + d;
  if (d > 7)
    d = d - 8;

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
    return s;
    break;
  // 5 = South West
  case 5:
    return se;
    break;
  // 6 = West
  case 6:
    return w;
    break;
  // 7 = North West
  case 7:
    return nw;
    break;
  // if direction isn't between 0 and 7
  default:
    throw(std::range_error("error in direction 3"));
  }
}

// @Returns the current location of the Mouse
coord Mouse::getLocation() { return location; }

vector<coord> Mouse::getCenter() { return center; }

vector<coord> Mouse::getDestination() { return destination; }

bool Mouse::isAtDestination() {
  for (int i = 0; i < destination.size(); i++) {
    if (location == destination[i])
      return true;
  }
  return false;
}

bool Mouse::isAtFinish() {
  if (location == coord{0, 0} && fromCenter)
    return true;
  else if ((location == coord{7, 7} || location == coord{7, 8} ||
            location == coord{8, 7} || location == coord{8, 8}) &&
           !fromCenter)
    return true;
  else
    return false;
}

////----Get Costs----////

// @returns the cost of the Mouse's current location
uint8_t Mouse::getCurrCost() { return m.getCost(location); }

// @returns cost of box that is on the left of the mouse
uint8_t Mouse::getLeftCost() {
  switch (direction) {
  // left = west = x--
  case n:
    if (m.inBounds(coord{location.x--, location.y}))
      return m.getCost(coord{location.x--, location.y});
    else
      return UINT8_MAX;
    break;
  // left = east = x++
  case s:
    if (m.inBounds(coord{location.x++, location.y}))
      return m.getCost(coord{location.x++, location.y});
    else
      return UINT8_MAX;
    break;
  // left = south = y--
  case w:
    if (m.inBounds(coord{location.x, location.y--}))
      return m.getCost(coord{location.x, location.y--});
    else
      return UINT8_MAX;
    break;
  // left = north = y++
  case e:
    if (m.inBounds(coord{location.x, location.y++}))
      return m.getCost(coord{location.x, location.y++});
    else
      return UINT8_MAX;
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction 4"));
  }
}

// @returns cost of box that is in front of the mouse
uint8_t Mouse::getForwardCost() {
  switch (direction) {
  // forward = y++
  case n:
    if (m.inBounds(coord{location.x, location.y++}))
      return m.getCost(coord{location.x, location.y++});
    else
      return UINT8_MAX;
    break;
  // forward = y--
  case s:
    if (m.inBounds(coord{location.x, location.y--}))
      return m.getCost(coord{location.x, location.y--});
    else
      return UINT8_MAX;
    break;
  // forward = x--
  case w:
    if (m.inBounds(coord{location.x--, location.y}))
      return m.getCost(coord{location.x--, location.y});
    else
      return UINT8_MAX;
    break;
  // forward = x++
  case e:
    if (m.inBounds(coord{location.x++, location.y}))
      return m.getCost(coord{location.x++, location.y});
    else
      return UINT8_MAX;
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction 5"));
  }
}

// @returns cost of box that is on the right of the mouse
uint8_t Mouse::getRightCost() {
  switch (direction) {
  // right = east = x++
  case n:
    if (m.inBounds(coord{location.x++, location.y}))
      return m.getCost(coord{location.x++, location.y});
    else
      return UINT8_MAX;
    break;
  // right = west = x+--
  case s:
    if (m.inBounds(coord{location.x--, location.y}))
      return m.getCost(coord{location.x--, location.y});
    else
      return UINT8_MAX;
    break;
  // right = north = y++
  case w:
    if (m.inBounds(coord{location.x, location.y++}))
      return m.getCost(coord{location.x, location.y++});
    else
      return UINT8_MAX;
    break;
  // right = south = y--
  case e:
    if (m.inBounds(coord{location.x, location.y--}))
      return m.getCost(coord{location.x, location.y--});
    else
      return UINT8_MAX;
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction 6"));
  }
}

////--------------MUTATOR FUNCTIONS--------------////

// Sets the current direction of the Mouse to new direction
// Setting a new direction requires a physical turn from the mouse
void Mouse::setDirection(const dir &d) {
  // if direction is to the left
  if (d == turnToDir(-2))
    turnLeft();
  if (d == turnToDir(2))
    turnRight();
  if (d == turnToDir(4) || d == turnToDir(-4))
    turnAround();
}

// Sets the current location of the Mouse to new location
void Mouse::setLocation(const coord &n) {
  if (m.inBounds(n))
    location = n;
}

void Mouse::setCenter(const coord &n) {
  if (m.inBounds(n))
    center = {n};
}

// Sets destination to a new location(s)
void Mouse::setDestination(const vector<coord> &n) {
  if (m.inBounds(n))
    destination = n;
}

// 0 = "forwards", 1 = "backwards"
// 0 = started in corder, 1 = started in center
void Mouse::setFromCenter(const bool &b) { fromCenter = b; }

// Resets the current location to the starting point
void Mouse::resetLocation() { location = coord{0, 0}; }

void Mouse::resetCenter() {
  center = {coord{7, 7}, coord{7, 8}, coord{8, 7}, coord{8, 8}};
}

void Mouse::resetDestination() {
  if (fromCenter)
    destination = {coord{0, 0}};
  else
    destination = center;
}

void Mouse::resetFromCenter() { fromCenter = false; };

void Mouse::toggleFromCenter() { fromCenter = !fromCenter; }

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
    throw(std::range_error("error in direction 7"));
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
      m.setEWall(location);
    break;
  // if direction is diagonal
  default:
    throw(std::range_error("error in direction 8"));
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
    throw(std::range_error("error in direction 9"));
  }
}

// Set walls of all surrounding walls to sensor values
void Mouse::setWalls(bool left, bool forward, bool right) {
  uint8_t sensorData = getSensorData();

  setLeftWall(sensorData % 2);
  setForwardWall(sensorData % 4);
  setRightWall(sensorData % 8);
}

////--------------MOVEMENT FUNCTIONS--------------////

// Returns the statuses for the wall from sensors
uint8_t Mouse::getSensorData() {

  // bit 2 = left; bit 1 = forward; bit 0 = right
  uint8_t sensors = 0;

  string wall;

  for(int i=0; i<3; i++){
    switch (i) {
      case 0:
        // Prompting the simulation to enter a number
        API::wallRight();
        break;
      case 1:
        // Prompting the simulation to enter a number
        API::wallFront();
        break;
      case 2:
        // Prompting the simulation to enter a number
        API::wallLeft();
        break;
      default:
        throw(std::range_error("error in for loop"));
        break;
      
      // Reading input from the user
      std::cin >> wall;

      if(wall == "True"){
        sensors += 2^i;
      } else if(wall != "False"){
          throw(std::range_error("error in stdin"));
          break;
      }
    }

    return sensors;
  }


  /* PLEASE PUT CODE THAT RETURNS SENSOR DATA HERE HERE */

  // return sensors;
  return sensors;
}

// Add coord to unexplored list - no duplicates
void Mouse::addUnexplored(const coord &n) {
  std::vector<coord>::iterator it;
  it = find(unexplored.begin(), unexplored.end(), n);
  if (it == unexplored.end())
    unexplored.push_back(n);

  // int foundLoc = -1;
  // for (int i = 0; i < unexplored.size(); i++) {
  //   if (unexplored[i] == n)
  //     foundLoc = i;
  // }
  // // if not found, add to unexplored
  // if (foundLoc == -1)
  //   unexplored.push_back(n);
}

// Removes coord if found on unexplored
void Mouse::removeUnexplored(const coord &n) {
  std::vector<coord>::iterator it;
  it = find(unexplored.begin(), unexplored.end(), n);
  if (it != unexplored.end())
    unexplored.erase(it);

  // int foundLoc = -1;
  // for (int i = 0; i < unexplored.size(); i++) {
  //   if (unexplored[i] == n)
  //     foundLoc = i;
  // }
  // // if not found, add to unexplored
  // if (foundLoc != -1)
  //   unexplored.erase(unexplored.begin() + foundLoc);
}

// Moves the Mouse forward
void Mouse::moveForwardOne() {

  coord newLoc;
  uint8_t x = location.x, y = location.y;

  switch (direction) {
    case n:
      newLoc = coord{x, static_cast<uint8_t>(y + 1)};
      if (m.inBounds(newLoc)) {
        ////ARDUINO FUNCTION TO MOVE FORWARD ONE////
        location.y++;
        m.setExplored(newLoc);
        removeUnexplored(newLoc);
        setLocation(location);
      } else
        throw(std::range_error("out of range 1"));
      break;
    case e:
      newLoc = coord{static_cast<uint8_t>(x + 1), y};
      if (m.inBounds(newLoc)) {
        ////ARDUINO FUNCTION TO MOVE FORWARD ONE////
        location.x++;
        m.setExplored(newLoc);
        removeUnexplored(newLoc); // Now that this location has been explored,
        setLocation(location);
      } else
        throw(std::range_error("out of range 2"));
      break;
    case s:
      newLoc = coord{x, static_cast<uint8_t>(y - 1)};
      if (m.inBounds(newLoc)) {
        ////ARDUINO FUNCTION TO MOVE FORWARD ONE////
        location.y--;
        m.setExplored(newLoc);
        removeUnexplored(newLoc);
        setLocation(location);
      } else
        throw(std::range_error("out of range 3"));
      break;
    case w:
      newLoc = coord{static_cast<uint8_t>(x - 1), y};
      if (m.inBounds(newLoc)) {
        ////ARDUINO FUNCTION TO MOVE FORWARD ONE////
        location.x--;
        m.setExplored(newLoc);
        removeUnexplored(newLoc);
        setLocation(location);
      } else
        throw(std::range_error("out of range 4"));
      break;
    default:
      break;
  }

  //Move forward 1 in Simulation
  API::moveForward();
  string ack;
  std::cin>>ack;
  if(ack == "crash"){
    throw(std::range_error("crash in simulation"));
  }
  else if(ack != "ack"){
    throw(std::range_error("error in simulation"));
  }
}

// Turns the Mouse left and updates direction
void Mouse::turnLeft() {
  ////ARDUINO TURN LEFT////
  direction = turnToDir(-2);
  //Turn left in Simulation
  API::turnLeft();
  string ack;
  std::cin>>ack;
  if(ack != "ack"){
    throw(std::range_error("error in simulation"));
  }
}

// Turns the Mouse right and updates direction
void Mouse::turnRight() {
  ////ARDUINO TURN RIGHT////
  direction = turnToDir(2);
  //Turn left in Simulation
  API::turnRight();
  string ack;
  std::cin>>ack;
  if(ack != "ack"){
    throw(std::range_error("error in simulation"));
  }
}

// Turns the Mouse left and updates direction
void Mouse::turnAround() {
  ////ARDUINO TURN RIGHT TWICE////
  direction = turnToDir(4);
  //Turn 180 degrees in Simulation
  API::turnRight();
  string ack;
  std::cin>>ack;
  if(ack != "ack"){
    throw(std::range_error("error in simulation"));
  }
  API::turnRight();
  std::cin>>ack;
  if(ack != "ack"){
    throw(std::range_error("error in simulation"));
  }
}

////--------------GENERAL FUNCTIONS--------------////

// @returns the direction the mouse should go in
dir Mouse::findNextMove() {

  // If none of the boxes will help to get the fastest path, these
  // values won't change and we will say to go backwards
  dir newDir = turnToDir(-4);
  uint8_t minCost = getCurrCost();

  // If the left box's cost is less than current cost, we should go left
  if (minCost >= getLeftCost()) {
    newDir = turnToDir(-2);
    minCost = getLeftCost();
  }

  // If right box is the best place to go next, go there
  if (minCost >= getRightCost()) {
    newDir = turnToDir(2);
    minCost = getRightCost();
  }

  // If forward box is the best place to go next, go there
  // Forward box is the prefered move because it doesn't involve wasting time to
  // turn
  if (minCost >= getForwardCost()) {
    newDir = direction;
    minCost = getLeftCost();
  }

  ///***Find a way to return the best direction. If can't use operation,
  /// just use switch cases
  /* if newDir = dir +- 2 || dir
        setDir(newDir)
        moveForward() */

  return newDir;
}

////--------------EXPLORATION FUNCTIONS--------------////

// This is the navigation function. This will call findNextMove and deadend as
// needed
void Mouse::explore() {

  // Continue exploring until best path is fully explored
  // Floodfill will change the finished bool
  while (!m.getFinished()) {
    // While mouse isn't at desired point yet (start, finish, nextBestSquare)
    while (!isAtDestination()) {

      dir newDir = findNextMove();
      // If there's a good move
      if (newDir != turnToDir(-4)) {
        //////INCLUDE TURN FUNCTION IF NECESSARY
        setDirection(newDir);
        moveForwardOne();
      }
      // If there's a dead end
      else {
        // Change destination to the next sqaure
        setDestination({nextBestSquare()});
        // Go to that next best square
        m.floodFill(location, destination);
        // Do 1 move before leaving loop because mouse is allowed
        // to turn around
        newDir = findNextMove();
        setDirection(newDir);
        moveForwardOne();
      }
    }

    // If mouse is currently at the finish, go to the other end
    if (isAtFinish()) {
      // Set the center as the square with the exit
      if (center.size() > 1)
        /////MAYBE CHANGE A LITTLE
        setCenter(location);
      toggleFromCenter();
    }

    if (!fromCenter) {
      setDestination(center);
      ////MIGHT WANT TO DO LOCATION INSTEAD OF {0, 0}
      m.floodFill(coord{0, 0}, destination);
    } else {
      setDestination({coord{0, 0}});
      ////MIGHT WANT TO DO LOCATION INSTEAD OF CENTER
      m.floodFill(center[0], {coord{0, 0}});
    }
  }
}

////ONLY UNFINISHED FUNCTION////
// This is called when a deadend is found
// This will look at the unexplored list and determine which square is best to
// go to next
coord Mouse::nextBestSquare() {

  // Map that holds the cost from curr square + cost to center
  std::map<coord, uint8_t> costMap;
  // Get cost from current square to all squares
  m.floodFill({location});
  for (int i = 0; i < unexplored.size(); i++)
    costMap.at(unexplored[i]) += m.getCost(unexplored[i]);

  // Make hash with all squares from unexplored list

  // Get cost to finish
  if (!fromCenter) {
    m.floodFill(coord{0, 0}, center);
  } else {
    m.floodFill(center[0], {coord{0, 0}});
  }

  // Add these costs to map
  for (int i = 0; i < unexplored.size(); i++)
    costMap[unexplored[i]] += m.getCost(unexplored[i]);

  // Next holds the square with the lowest cost
  coord next;
  // minVal holds the cost of the lowest square
  uint8_t minVal = UINT8_MAX;

  // Iterate through the map
  for (const auto &pair : costMap) {
    if (pair.second < minVal) { // Check if the current value is less than the
                                // current minimum value
      next = pair.first;        // Update with new min coord
      minVal = pair.second;
    }
  }

  // Return the minimum cost square
  return next;
}