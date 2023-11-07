//Mouse.hpp
//10.22.2023

// @Description ____


#ifndef MOUSE_HPP_
#define MOUSE_HPP_

#include "maze.hpp"
#include "maze.cpp"

#include <iostream>
#include <cstdint>
#include <queue>
#include <stack>

using namespace std;

/// @Note This is an unfinished struct
/// @Suggestion it might be better to not include diagonal directions. Might just be best to have a special turning function later for diagonal turns
//This is used to store direction of the mouse
//n = 0, ne = 1, e = 2, ... nw = 7
//if %2 = 1, going diagonal
//if %4 = 0, moving on y axis (north and south)
//if %4 = 2, moving on x axis (east and west)
//left turn is dir=dir-2, right turn is dir=dir+2
enum dir {n, ne, e, se, s, sw, w, nw};

//coordinate struct: x and y position
struct coord{
  uint8_t x;
  uint8_t y;
};




class Mouse
{
private:

  dir direction;
  coord location;
  ///*** Figure out if this should be a pointer
  Maze m; 
  
  //This keeps track if we are going from start to finish or vice versa
  //This is used to flood fill the maze differently depending on our start
  bool startToFinish;

  //Anytime an adjacent unexplored box is found but not explored, we add it to the queue
  priority_queue<>


  void turnLeft();
  void turnRight();
  void moveForwardOne();

public:
  //Constructor
  /// @Note Should make another constructor that takes in preset mazes so that the mouse doesn't have start from scratch so we are able to compare mouse's mazes from scratch
  Mouse();
  Mouse(Maze maze);

  //Accessor Functions
  dir getDirection();
  dir numToDir(int8_t num);
  uint8_t dirToNum(const dir &d);
  dir turnToDir(const int8_t &turn);
  dir numToDir(int8_t turn);
  coord getLocation();
  uint8_t getCurrCost();
  uint8_t getLeftCost();
  uint8_t getForwardCost();
  uint8_t getRightCost();

  //Mutator Functions
  void setDirection(const dir &d);
  void setLocation(const coord &n);
  void resetLocation();

  void setLeftWall(bool left);
  void setForwardWall(bool forward);
  void setRightWall(bool right);
  void setWalls(bool left, bool forward, bool right);

  //Movement
  void moveForward();
  bool* getSensorData();
  void moveLeft();
  void moveRight();
  void turnAround();
  

  //Set the values of the surrounding walls
  //Use direction to figure out what specific wall needs to be set in Maze

  bool deadEndFound();
  dir findNextMove();


  
  /*Please implement Isabella I need a method so bad*/
  /*When deciding what direction to go, look at maze cost
  
  Floodfill: at start, at finish(center), and at dead end */



  void explore();
  void findBestPath();

  void deadEndFloodFill(coord newLocation);

  
};


#endif




//-----------NOTES-----------//
//Mouse should be getting a list of directuions or a singular direction and following that. This will involve either changing

///***Make a square explored only after setting all the walls. It can be at the very start of the goForward function where you turn your current location = explored then leave and go forward

///***Only things you change in the maze regularly are the walls and explored. Any time you go to a new box, you have to add the new walls and set the new box to explored

///***The maze is in private member variables as an object but is in the constructor as a pointer




///*** @psuedo-code How direction and location change when exploring 
//{
  //getBestPath()
  //if (getBestPath == BAD)
    //deadEndFound();
  //else{
    //Compare getBestPath direction with current direction
    //if current direction is 2 more than new direction, turn left then go forward
    //else if current direction is equal to new direction, go forward
    //else if current direction is 2 less than new direction, turn right then go forward
    //else error (the new direction is not a good one)
  //}
//}




///*** @psuedo-code DeadEndFound()
//{
  //newLocation  
  //q = deadEndFloodFill(newLocation)

  //while(q.size()){
    //if(m.getExplored)
    //if(q.front is possible)
      //go that direction
    //else
      //q = deadEndFloodFill(newLocation)
      //(new location might need to be redecided)
  //}
//}




///*** @psuedo-code getBestPath()
//{
  ///make new direction face the opposite direction
  ///get cost of box you're on
  ///if a new direction's cost is less than cost of current box, change direction and change the best cost

  //dir newDirection = direction-4;
  //cost = getMyCost();

  ///do left right and forward separately and sequentially
  //if(getLeft/Right/ForwardCost) < cost
    //cost = left/right/forwardCost
    //dir = left/right/forward

  //return dir
  
//}




///***RECOMMENDED FUNCTIONS***///


//dir numToDir(int d);
///***A helper function that turns any int into its respective direction
///***If the int is a negative number, use 8-int to get the positive number
//OR
//dir turnToDir(int turn);
///***A helper function that takes the desired turn in int form and uses current direction to figure out what is the desired direction
///***If the int is a negative number, use 8-int to get the positive number

//bool notDiagonal();
///***A helper function that checks to make sure that current direction isn't diagonal when we should be straight
///***If the int is a negative number, use 8-int to get the positive number
