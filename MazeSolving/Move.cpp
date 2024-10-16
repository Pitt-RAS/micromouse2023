#include "Move.h"
#include <iostream>

using namespace std;

//sets initial coordinates
Move::Move(int x_coor, int y_coor)
{
    x = x_coor;
    y = y_coor;
}

 void Move::goStraight(int sensorL, int sensorR, int sensorF) //assuming 0 is wall (closed), and 1 is no wall (open area)
        {
            while(!sensorL && !sensorR && sensorF) //loops if there are walls in the left and right. And no wall infront.
            {
                x += eastWest; //indicates movement in x direction
                y += northSouth; //ind,icates movement in y direction
            }
        }

