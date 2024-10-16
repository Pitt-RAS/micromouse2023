#ifndef MOVE_H
#define MOVE_H

class Move
{
    private:
    //THESE LET US ADD AND SUBTRACT FROM X AND Y
        int eastWest = 0; //X-Coordinate: 1 for east, -1 for west
        int northSouth = 0; //Y-Coordinate: 1 for north, -1 for south

    //THESE LET US KNOW WHICH WAY THE BOT IS FACING AT ALL TIME, SO WE MOVE IN THE RIGHT DIRECTION
        int e,w,n,s; //whichever direction it is facing will be one. if south facing: s = 1, n = 0, e = 0, w = 0

    //x,y coordinates
        int x, y;
    public:
        Move(int x_coor = 0,int y_coor = 0); //give coordinates when making object. 0 assumed if not provided

        void setX(int newX) //sets x coordinate
        {x = newX;}

        void setY(int newY) //sets y coordinate
        {y = newY;}
        
        void setEWNS(int EW, int NS) //sets what direction it will be moving in
        {
            eastWest = EW; //1 if East, -1 if West, 0 if neither
            northSouth = NS; // 1 if North, -1 if South, 0 if neither
        }

        /*******************************************************
        *   WE NEED SOMETHING TO TURN THE BOT TO THE DIRECTION *
        *   IT NEEDS TO BE FACING TOWARDS.                     *
        *   THIS CAN BE DONE USING  e,w,n,s VARIABLES.         */

        /* SOMETHING LIKE THIS COULD BE USED 
        void turnBot(int east, int west, int north, int south)
        {
            e = east;
            w = west;
            n = north;
            s = south;
        } */

        //goStraight should only be used after the bot is facing the correct direction **We will also need to move one step in that direction before calling go front b/c walls will not be closed around at first**
        //because goStraight will keep going straight until it has walls on its sides.

        //sensors from left, right, and front
        //sensorF: makes sure that there is a space to move front
        //sensorL: makes sure there is still a wall to the left
        //sensorR: makes sure there is still a wall to the right

        void goStraight(int sensorL, int sensorR, int sensorF);
};
#endif