#include <cmath>
#include <tuple>
#include <numbers>
#include <iomanip>
#include <iostream>


class PositionTracker{

    //All units are in millimeters
    float wheelDiameter;
    float wheelTrack;

    //amount of encoder ticks per axle turn
    //i.e. encRatio = 4096 means 4096 encoder ticks per 1 turn
    float encRatio;
    
    //position structure
    struct position {double x; double y; double rotation;};

    position currentPos;


    PositionTracker(float ws, float er, float wt){
        wheelDiameter = ws;
        encRatio = er;
        wheelTrack = wt;
    }

    auto posFromDelta(float leftEncDelta, float rightEncDelta, float orientation) {
        
        double tickToMM = std::numbers::pi * wheelDiameter / encRatio; //using c++20

        double lDis = leftEncDelta * tickToMM;
        double rDis = rightEncDelta * tickToMM;

        //calculate the change in orientation
        double deltaTheta = (lDis- rDis) / wheelTrack; //in radians

        //local cordinates for the movement
        //y is the direction of the movement
        //x is perpendicular
        double localOffsetY;

        if (deltaTheta != 0) {
            //if movement was an arc
            //calculate y
            localOffsetY = 2 * std::sin(deltaTheta / 2) * (rDis / deltaTheta + wheelTrack / 2);
        } 
        else {
            //if each wheel spun the same amount
            localOffsetY = rDis;
        }

        //convert local to polar cords and then to field cords
        double avgA = orientation + (deltaTheta / 2);
        
        double polarR = std::sqrt(localOffsetY * localOffsetY);
        double polarA = std::atan2(localOffsetY, 0) - avgA;

        double dX = std::sin(polarA) * polarR;
        double dY = std::cos(polarA) * polarR;

        if (isnan(dX)){
            dX = 0;
        }

        if (isnan(dY)) {
            dY = 0;
        }

        if (isnan(deltaTheta)) {
            deltaTheta = 0;
        }

        return position {dX, dY, deltaTheta};
    }
};