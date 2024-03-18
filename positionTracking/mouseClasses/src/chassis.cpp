#include <cmath>
#include <tuple>
#include <numbers>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <math.h>
#include <chassis.h>

Chassis::Chassis(float ws, float er, float wt, double x, double y, double theta/*,Motor rm, Motor lm*/){
    wheelDiameter = ws;
    encRatio = er;
    wheelTrack = wt;
    currentPos.x = x;
    currentPos.y = y;
    currentPos.rotation = theta;
    /*
    rightMotor = rm;
    leftMotor = lm;
    */
}

void Chassis::updatePosition(float leftEncDelta, float rightEncDelta, float orientation) {
    
    double tickToMM = M_PI * wheelDiameter / encRatio; 
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
    //update instance varibles
    currentPos.x += dX;
    currentPos.y += dY;
    currentPos.rotation += deltaTheta;
}
//blocking code with no async 
//if future implementation requires a step method can be implemented

void Chassis::moveToPostion(double x, double y){
    position target = position{x, y, 0};
    target.rotation = pointAngle(currentPos, target);
    /*
    PID angleController(pGain,iGain,dGain,..);
    PID distanceController(pGain,iGain,dGain,..);
    distanceController.setTarget(0));
    */
    while(/* !angleController.isSettled && !distanceController.isSettled */ true){
        /*
        updatePosition();
        angleController.setTarget(pointAngle(currentPos,target));
        angleController.setInput(currentPos.rotation);
        distanceController.setInput(pointDistance(currentPos,target));
        driveVector(distanceController.getOutput(),angleController.getOutput());
        */
    }
}
double Chassis::pointDistance(position pos1, position pos2){
    return sqrt(pow(pos2.x - pos1.x,2) + pow(pos2.y - pos1.y,2));
}
double Chassis::pointAngle(position pos1, position pos2){
    return atan((pos2.y - pos1.y)/(pos2.x-pos1.x));
}
void Chassis::turnToOrientation(double theta){
    /*
    pseduocode PID implementation
    replace with real PID
    
    PID turnController(pGain,iGain,dGain,..);
    turnController.setTarget(theta);
    */
    while(/* !turnController.isSettled */ true){
        //updatePosition();
        //turnController.setInput(currentPos.rotation);
        //driveVector(0, turnController.getOutput());
    }
}
//set drive train to follow a vector
void Chassis::driveVector(double velocity, double theta){
    //set max velocities between -1 and 1
    const double forwardSpeed = std::clamp(velocity, -1.0, 1.0);
    const double yaw = std::clamp(theta, -1.0, 1.0);
    //turn motors with yaw
    double leftOutput = forwardSpeed + yaw;
    double rightOutput = forwardSpeed - yaw;
    //continue turning if one of the motor is over max velocity
    if (const double maxInputMag = std::max<double>(std::abs(leftOutput), std::abs(rightOutput)); maxInputMag > 1) {
        leftOutput /= maxInputMag;
        rightOutput /= maxInputMag;
    } 
    /*---------------------------------------------------------------------------------------------------
    pseduocode for actual motor implementation
    replace with real functions
    leftMotor.setVelocity(leftOutput * maxVelocity);
    rightMotor.setVelocity(rightOutput * maxVelocity);
    */
}
