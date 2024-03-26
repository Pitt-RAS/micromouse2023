#pragma once
#include <motor.h>

class Chassis{

    private:
        float wheelDiameter;
        float wheelTrack;
        float encRatio;
        struct position {double x; double y; double rotation;};
        position currentPos;
        Motor rightMotor;
        Motor leftMotor;
        double pointDistance(position pos1, position pos2);
        double pointAngle(position pos1, position pos2);

    public:
        Chassis(float ws, float er, float wt, double x, double y, double theta ,Motor rm, Motor lm);
        void updatePosition(float leftEncDelta, float rightEncDelta, float orientation);
        void moveToPostion(double x, double y);
        void turnToOrientation(double theta);
        void driveVector(double velocity, double theta);
};

