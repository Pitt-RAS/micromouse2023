#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

// i changed a bunch of include statements bc Mouse and dir weren't found,
// everything seems to be working now that the files are .h instead of .hpp and
// when a class needs included, the .h file is included kinda confused why this
// works instead of hpp but it seems fine for now. when i run the errors dont
// look related
#include "maze.h"
#include "mouse.h"
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*****************************************

03/13/24
Tests Failing:
  -Flood Fill Default
  -Set Direction
  -Set Location
  -Move Forward (all)
  -Turn Left
  -Turn Right

*****************************************/
/*
TEST_CASE("UINT8_T Tests", "[Mouse]") {
  uint8_t cost;

  cost = 1;
  REQUIRE(++cost == 2);

  cost = 1;
  REQUIRE(--cost == 0);

  coord n = {0, 2};
  coord n2 =
      coord{static_cast<uint8_t>(n.x + 1), static_cast<uint8_t>(n.y - 1)};
  REQUIRE(n2.x == 1);
  REQUIRE(n2.y == 1);
}

TEST_CASE("Flood Fill Default", "[Mouse]") {
  Maze m;
  uint8_t cost;

  m.floodFill(coord{0, 0},
              {coord{7, 7}, coord{7, 8}, coord{8, 7}, coord{8, 8}});

  for (uint8_t i = 7; i < 9; i++) {
    for (uint8_t j = 7; j < 9; j++) {
      cost = m.getCost(coord{i, j});
      REQUIRE(cost == 0);
    }
  }

  cost = m.getCost(coord{7, 6});
  REQUIRE(cost == 1);
  cost = m.getCost(coord{6, 7});
  REQUIRE(cost == 1);
  cost = m.getCost(coord{8, 9});
  REQUIRE(cost == 1);
  cost = m.getCost(coord{9, 8});
  REQUIRE(cost == 1);

  cost = m.getCost(coord{0, 0});
  REQUIRE(cost == 14);
}



TEST_CASE("Number to Direction", "[Mouse]") {
  Mouse m;

  dir d;

  int8_t num = 0;

  d = m.numToDir(num);
  REQUIRE(d == n);

  num = 1;

  d = m.numToDir(num);
  REQUIRE(d == ne);

  num = 2;

  d = m.numToDir(num);
  REQUIRE(d == e);

  num = 3;

  d = m.numToDir(num);
  REQUIRE(d == se);

  num = 4;

  d = m.numToDir(num);
  REQUIRE(d == s);

  num = 5;

  d = m.numToDir(num);
  REQUIRE(d == sw);

  num = 6;

  d = m.numToDir(num);
  REQUIRE(d == w);

  num = 7;

  d = m.numToDir(num);
  REQUIRE(d == nw);

  // do i want something for bounds???
}
*/

TEST_CASE("Direction to Number", "[Mouse]") {
  Mouse m;

  uint8_t num;

  num = m.dirToNum(n);
  REQUIRE(num == 0);

  num = m.dirToNum(ne);
  REQUIRE(num == 1);

  num = m.dirToNum(e);
  REQUIRE(num == 2);

  num = m.dirToNum(se);
  REQUIRE(num == 3);

  num = m.dirToNum(s);
  REQUIRE(num == 4);

  num = m.dirToNum(sw);
  REQUIRE(num == 5);

  num = m.dirToNum(w);
  REQUIRE(num == 6);

  num = m.dirToNum(nw);
  REQUIRE(num == 7);
}

/*
//set direction
TEST_CASE("Set Direction", "[Mouse]") {
  Mouse m;
  dir d;

  m.setDirection(n);
  d = m.getDirection();
  REQUIRE(d == n);

  m.setDirection(ne);
  d = m.getDirection();
  REQUIRE(d == ne);

  m.setDirection(e);
  d = m.getDirection();
  REQUIRE(d == e);

  m.setDirection(se);
  d = m.getDirection();
  REQUIRE(d == se);

  m.setDirection(s);
  d = m.getDirection();
  REQUIRE(d == s);

  m.setDirection(sw);
  d = m.getDirection();
  REQUIRE(d == sw);

  m.setDirection(w);
  d = m.getDirection();
  REQUIRE(d == w);

}
*/

// location
TEST_CASE("Set Location", "[Mouse]") {
  Mouse m;
  coord n;
  coord t;

  n.x = 0;
  n.y = 0;
  t = m.getLocation();
  REQUIRE(t == n);

  n.x = 5;
  n.y = 10;
  m.setLocation(n);
  t = m.getLocation();
  REQUIRE(t == n);

  /// REQUIRE ERROR AND T IS STILL SAME
  n.x = 18;
  n.y = 0;
  m.setLocation(n);
  t = m.getLocation();
  REQUIRE(t.x == 5);

  /// REQUIRE ERROR AND T IS STIL SAME
  n.x = 0;
  n.y = -5;
  m.setLocation(n);
  t = m.getLocation();
  REQUIRE(t.y == 10);
}

TEST_CASE("Set Destination - Origin", "[Mouse]") {
  Mouse m;
  vector<coord> d;
  vector<coord> t;

  coord c;
  c.x = 0;
  c.y = 0;
  d.push_back(c);
  m.setDestination(d);
  t = m.getDestination();
  REQUIRE(d == t);
}

TEST_CASE("Set Destination - Center", "[Mouse]") {
  Mouse m;
  vector<coord> d;
  vector<coord> t;

  coord c;
  c.x = 8;
  c.y = 8;
  d.push_back(c);
  m.setDestination(d);
  t = m.getDestination();
  REQUIRE(d == t);
}

TEST_CASE("Set Destination - Center, Multiple Possibilities", "[Mouse]") {
  Mouse m;
  vector<coord> d;
  vector<coord> t;

  coord c1;
  c1.x = 8;
  c1.y = 8;
  coord c2;
  c2.x = 7;
  c2.y = 7;

  d.push_back(c1);
  d.push_back(c2);

  m.setDestination(d);
  t = m.getDestination();
  REQUIRE(d == t);
}

TEST_CASE("Reset Location", "[Mouse]") {
  Mouse m;
  coord c;
  coord r;

  c.x = 10;
  c.y = 3;

  m.setLocation(c);
  // maybe add require here
  m.resetLocation();

  r = m.getLocation();
  REQUIRE(r.x == 0);
  REQUIRE(r.y == 0);
}

TEST_CASE("Reset Destination", "[Mouse]") {
  Mouse m;
  coord c;
  vector<coord> v;
  vector<coord> t;

  c.x = 0;
  c.y = 0;

  v.push_back(c);

  m.setDestination(v);
  // maybe add require here
  m.resetDestination();

  t = m.getDestination();
  REQUIRE(t.size() == 4);
  REQUIRE(t[0].x == 7);
  REQUIRE(t[0].y == 7);
}

TEST_CASE("From Center", "Mouse") {
  // set center to 1
  // reset
  // toggle
}

TEST_CASE("Move Forward - North", "[Mouse]") {
  Mouse m;
  coord n;

  // set location
  m.setLocation(coord{7, 7});

  m.moveForwardOne();
  n = m.getLocation();

  REQUIRE(n.x == 7);
  REQUIRE(n.y == 8);
}

TEST_CASE("Move Forward - South", "[Mouse]") {
  Mouse m;
  coord n;

  // set direction
  m.setDirection(s);

  // set location
  m.setLocation(coord{7, 7});

  m.moveForwardOne();
  n = m.getLocation();

  REQUIRE(n.x == 7);
  REQUIRE(n.y == 6);
}

TEST_CASE("Move Forward - East", "[Mouse]") {
  Mouse m;
  coord n;

  // set direction
  m.setDirection(e);

  // set location
  m.setLocation(coord{7, 7});

  m.moveForwardOne();
  n = m.getLocation();

  REQUIRE(n.x == 8);
  REQUIRE(n.y == 7);
}

TEST_CASE("Move Forward - West", "[Mouse]") {
  Mouse m;
  coord n;

  // set direction
  m.setDirection(w);

  // set location
  m.setLocation(coord{7, 7});

  m.moveForwardOne();
  n = m.getLocation();

  REQUIRE(n.x == 6);
  REQUIRE(n.y == 7);
}

TEST_CASE("Turn to Direction", "[Mouse]") {
  Mouse m;
  dir d;

  // turn right
  d = m.turnToDir(2);
  REQUIRE(d == e);
  // set direction
  m.setDirection(d);
  REQUIRE(d == m.getDirection());

  // turn right
  d = m.turnToDir(2);
  REQUIRE(d == s);
  // set direction
  m.setDirection(d);
  REQUIRE(d == m.getDirection());

  // turn right
  d = m.turnToDir(4);
  REQUIRE(d == n);
  // set direction
  m.setDirection(d);
  REQUIRE(d == m.getDirection());

  // turn right
  d = m.turnToDir(-4);
  REQUIRE(d == s);
  // set direction
  m.setDirection(d);
  REQUIRE(d == m.getDirection());

  // turn right
  d = m.turnToDir(-2);
  REQUIRE(d == e);
  // set direction
  m.setDirection(d);
  REQUIRE(d == m.getDirection());
}

TEST_CASE("Turn Left", "[Mouse]") {
  Mouse m;
  dir d;

  m.setDirection(s);

  m.turnLeft();

  d = m.getDirection();
  REQUIRE(d == e);

  m.turnLeft();

  d = m.getDirection();
  REQUIRE(d == n);
}

TEST_CASE("Turn Right", "[Mouse]") {
  Mouse m;
  dir d;

  m.setDirection(w);

  m.turnRight();

  d = m.getDirection();
  REQUIRE(d == n);

  m.turnRight();

  d = m.getDirection();
  REQUIRE(d == e);
}

TEST_CASE("Turn Left and Right", "[Mouse]") {
  Mouse m;
  dir d;

  m.setDirection(e);

  m.turnLeft();

  d = m.getDirection();
  REQUIRE(d == n);

  m.turnRight();

  d = m.getDirection();
  REQUIRE(d == e);
}

TEST_CASE("Turn Around", "[Mouse]") {
  Mouse m;
  dir d;

  m.setDirection(e);

  m.turnAround();

  d = m.getDirection();
  REQUIRE(d == w);

  m.turnAround();

  d = m.getDirection();
  REQUIRE(d == e);
}

TEST_CASE("Find next move", "[Mouse]") {
  Maze maze;
  dir d;
  // void setCost(const coord &n, const uint8_t &cost);
  // location 5,5

  maze.setCost(coord{4, 5}, 3);  // w
  maze.setCost(coord{6, 5}, 7);  // e
  maze.setCost(coord{5, 4}, 34); // s
  maze.setCost(coord{5, 6}, 1);  // n

  Mouse m(maze);

  m.setLocation(coord{5, 5});

  d = m.findNextMove();

  REQUIRE(d == n);
}

TEST_CASE("isAtDestination", "[Mouse]") {
  Mouse m;

  vector<coord> d;

  d.push_back(coord{1, 2});
  d.push_back(coord{2, 3});
  d.push_back(coord{4, 5});

  m.setDestination(d);

  m.setLocation(coord{1, 2});

  REQUIRE(m.isAtDestination());

  m.setLocation(coord{2, 6});

  REQUIRE_FALSE(m.isAtDestination());
}

TEST_CASE("At Finish - Corner", "[Mouse]") {

  Mouse m;

  m.setFromCenter(true);
  m.setLocation(coord{0, 0});
  REQUIRE(m.isAtFinish());

  m.setFromCenter(false);
  REQUIRE_FALSE(m.isAtFinish());

  m.setFromCenter(true);
  m.setLocation(coord{7, 7});
  REQUIRE_FALSE(m.isAtFinish());
}

TEST_CASE("At Finish - Center", "[Mouse]") {

  Mouse m;

  m.setFromCenter(false);
  m.setLocation(coord{7, 7});
  REQUIRE(m.isAtFinish());

  m.setLocation(coord{7, 8});
  REQUIRE(m.isAtFinish());

  m.setLocation(coord{8, 7});
  REQUIRE(m.isAtFinish());

  m.setLocation(coord{8, 8});
  REQUIRE(m.isAtFinish());

  m.setFromCenter(true);
  REQUIRE_FALSE(m.isAtFinish());

  m.setFromCenter(false);
  m.setLocation(coord{0, 0});
  REQUIRE_FALSE(m.isAtFinish());
}

TEST_CASE("Get current cost", "[Mouse]") {
  Maze maz;

  // void setCost(const coord &n, const uint8_t &cost);
  maz.setCost(coord{1, 3}, 6);

  Mouse m(maz);

  m.setLocation(coord{1, 3});

  REQUIRE(m.getCurrCost() == 6);
}

TEST_CASE("Get left cost", "[Mouse]") {
  Maze maz;

  maz.setCost(coord{4, 5}, 1); // location
  maz.setCost(coord{4, 4}, 2); // south
  maz.setCost(coord{5, 5}, 3); // east
  maz.setCost(coord{4, 6}, 4); // north
  maz.setCost(coord{3, 5}, 5); // west

  Mouse m(maz);

  m.setLocation(coord{4, 5});
}
