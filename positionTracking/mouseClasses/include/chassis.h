#pragma once
#include <motor.h>
#include <MiniPID.h>

class Chassis{

    private:
        float wheelDiameter;
        float wheelTrack;
        float encRatio;
        struct position {double x; double y; double rotation;};
        position currentPos;
        Motor *rightMotor;
        Motor *leftMotor;
        double pointDistance(position pos1, position pos2);
        double pointAngle(position pos1, position pos2);
        int lastLeftEnc;
        int lastRightEnc;
        MiniPID *distancePID;
        MiniPID *anglePID;
        MiniPID *turnPID;
        float distanceError;
        float angleError;

    public:
        Chassis();
        void setMotors(Motor *rm, Motor *lm);
        void setChassisAttr(float ws, float er, float wt);
        void setPID(MiniPID *dPID, MiniPID *aPID, MiniPID *tPID);
        void updatePosition();
        void moveToPostion(double x, double y);
        void turnToOrientation(double theta);
        void driveVector(double velocity, double theta);
        void setError(float dError, float aError);
        void printPosition();
};

