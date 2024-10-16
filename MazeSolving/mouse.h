//Mouse.hpp
//10.22.2023

// @Description ____


#ifndef MOUSE_H_
#define MOUSE_H_

#include "maze.h"

#include <iostream>
#include <cstdint>
#include <queue>
#include <stack>
#include <list>

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



class Mouse
{
private:

  dir direction;
  coord location;
  vector<coord> destination;
  vector<coord> center;
  bool fromCenter;
  Maze m;
  
  //This keeps track if we are going from start to finish or vice versa
  //This is used to flood fill the maze differently depending on our start
  bool startToFinish;

  //Anytime an adjacent unexplored box is found but not explored, we add it to this list
  //This list will be used to help figure out where the best next square to go is
  //If any explored square goes into unexplored, something is wrong
  vector<coord> unexplored;


public:
  //Constructor
  /// @Note Should make another constructor that takes in preset mazes so that the mouse doesn't have start from scratch so we are able to compare mouse's mazes from scratch
  Mouse();
  Mouse(Maze maze);

  //Accessor Functions
  dir getDirection(); ///
  dir numToDir(int8_t num); ///
  int8_t dirToNum(const dir &d); ///
  dir turnToDir(const int8_t &turn);///
  coord getLocation(); ///
  vector<coord> getCenter();
  vector<coord> getDestination(); ///
  bool isAtDestination(); ///
  bool isAtFinish();///
  uint8_t getCurrCost();///
  uint8_t getLeftCost();
  uint8_t getForwardCost();
  uint8_t getRightCost();
  bool getUnexplored(const coord &n); //(returns true if on unexplored)

  //Mutator Functions
  void setDirection(const dir &d); ///
  void setLocation(const coord &n); ///
  void setCenter(const coord &n);
  void setDestination(const vector<coord> &d); ///
  void setFromCenter(const bool &b);
  void addUnexplored(const coord &n); //(adds coord to unexplored list. Can't have multiple of same coord)
  void removeUnexplored(const coord &n);  //(removes coord if found on unexplored)

  void resetLocation(); ///
  void resetCenter();
  void resetDestination(); ///
  void resetFromCenter();
  void toggleFromCenter();

  void setLeftWall(bool left);
  void setForwardWall(bool forward);
  void setRightWall(bool right);
  void setWalls(bool left, bool forward, bool right);

  //Movement Functions
  uint8_t getSensorData();
  void moveForwardOne(); ///
  void turnLeft(); ///
  void turnRight(); ///
  void turnAround(); ///
  

  //Set the values of the surrounding walls
  //Use direction to figure out what specific wall needs to be set in Maze

  dir findNextMove();///


  
  /*When deciding what direction to go, look at maze cost
  
  Floodfill: at start, at finish(center), and at dead end */



  void explore();
  coord nextBestSquare();

  
};


#endif


//----------TODO--------//


//Add diagonal functionality
//Add "Explore" which switches between exploring and deadend until maze is "finished"
//Create functions for Unexplored Vector and integrate those into functions - DONE :); There is a find method for vectors :(
//



//Finish the autoExploreBoxes() function



//-----------NOTES-----------//

//***Add somewhere to add unexplored squares to the list

//Mouse should be getting a list of directuions or a singular direction and following that. This will involve either changing

///***Make a square explored only after setting all the walls. It can be at the very start of the goForward function where you turn your current location = explored then leave and go forward

///***Only things you change in the maze regularly are the walls and explored. Any time you go to a new box, you have to add the new walls and set the new box to explored

///***The maze is in private member variables as an object but is in the constructor as a pointer




/*
@psuedo-code Exploration

//Continue exploring until best path is fully explored
//Floodfill will change the finished bool
vector<coord> center = destination;
while(!m.getFinished){
  //While mouse isn't at desired point yet (start, finish, nextBestSquare)
  while(location != destination){
    
    newDir = findNextMove();
    //If there's a good move
    if(newDir != turnToDir(-4)){
      setDirection(newDir);
      moveForwardOne();
    }
    //If there's a dead end
    else{
      //Change destination to the next sqaure
      destination = nextBestSquare();
      //Go to that next best square
      m.floodFill(location, destination);
      //Do 1 move before leaving loop because mouse is allowed
      //to turn around
      newDir = findNextMove();
      setDirection(newDir);
      moveForwardOne();
    }
  }

   //If mouse is currently at the desired end, go to the other end
   if(isAtFinish()){
    //Set the center as the square with the exit
    if(center.size() > 1)
      center = location;
    toggleFromCenter();
   }
   
   if(fromCenter){
    setDestination(coord{0, 0});
    ////MIGHT WANT TO DO LOCATION INSTEAD OF CENTER
    m.floodFill(center, coord{0, 0});
  }
   else{
    setDestination(center);
    ////MIGHT WANT TO DO LOCATION INSTEAD OF {0, 0}
    m.floodFill(coord{0, 0}, destination);
  }
}
*/






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


//bool notDiagonal();
///***A helper function that checks to make sure that current direction isn't diagonal when we should be straight
///***If the int is a negative number, use 8-int to get the positive number
