#include <Arduino.h>
#include <motor.h>
#include <mouseConfig.h>
#include "QuadEncoder.h"
#include "chassis.h"
#include <string>

using namespace std;

Motor rightMotor;
QuadEncoder rightEnc(1, RIGHT_ENCODER_PIN_A, RIGHT_ENCODER_PIN_B);
MiniPID rightPid(MOTOR_VEL_PID_P, MOTOR_VEL_PID_I, MOTOR_VEL_PID_D, MOTOR_VEL_PID_F);

Motor leftMotor;
QuadEncoder leftEnc(2, LEFT_ENCODER_PIN_A, LEFT_ENCODER_PIN_B);
MiniPID leftPid(MOTOR_VEL_PID_P, MOTOR_VEL_PID_I, MOTOR_VEL_PID_D, MOTOR_VEL_PID_F);

MiniPID anglePID(0,0,0);
MiniPID turnPID(0.5,0,0);
MiniPID distancePID(0,0,0);
Chassis chassis;

void setup(){
  Serial.begin(230400);

  pinMode(17, OUTPUT);
  digitalWrite(17, HIGH);

  rightPid.setMaxIOutput(255);
  rightPid.setOutputLimits(-255,255);

  rightMotor.setMotorPins(RIGHT_MOTOR_PIN_1, RIGHT_MOTOR_PIN_2, RIGHT_MOTOR_PIN_PWM);
  rightMotor.setMotorAttr(MAX_VELOCITY);
  rightMotor.setEncoder(&rightEnc);
  rightMotor.setVelPID(&rightPid);

  rightMotor.initMotor();

  leftPid.setMaxIOutput(255);
  leftPid.setOutputLimits(-255,255);

  leftMotor.setMotorPins(LEFT_MOTOR_PIN_1, LEFT_MOTOR_PIN_2, LEFT_MOTOR_PIN_PWM);
  leftMotor.setMotorAttr(MAX_VELOCITY);
  leftMotor.setEncoder(&leftEnc);
  leftMotor.setVelPID(&leftPid);

  leftMotor.initMotor();

  chassis.setMotors(&rightMotor, &leftMotor);
  chassis.setChassisAttr(WHEEL_DIAMETER, ENCODER_TICKS_PER_WHEEL_ROTATION, WHEEL_TRACK);
  chassis.setPID(&distancePID, &anglePID, &turnPID);
  chassis.setError(5,0.5);

  //rightMotor.setVelocity(1);
}


void loop() {
  
  //if (Serial.available() > 0) {
    /*size_t pos = 0;
    //std::string s = Serial.readString().c_str();
    std::string s  = "0.0|0.0|0.0|255|1.0";
    
    rightPid.setP(stod(s.substr(0, (pos = s.find("|")))));
    s.erase(0, pos + 1);
    rightPid.setI(stod(s.substr(0, (pos = s.find("|")))));
    s.erase(0, pos + 1);
    rightPid.setD(stod(s.substr(0, (pos = s.find("|")))));
    s.erase(0, pos + 1);
    //rightPid.setF(stod(s.substr(0, (pos = s.find("|")))));
    rightPid.setF(255);
    s.erase(0, pos + 1);

    rightMotor.setVelocity(1);*/

    double p, i, d, f, setVel;

    /*std::string s = Serial.readString().c_str();
    //std::string s  = "0.0|0.0|0.0|255|1.0";
    size_t pos = 0;

    p = stod(s.substr(0, (pos = s.find("|"))));
    s.erase(0, pos + 1);
    i = stod(s.substr(0, (pos = s.find("|"))));
    s.erase(0, pos + 1);
    d = stod(s.substr(0, (pos = s.find("|"))));
    s.erase(0, pos + 1);
    f = stod(s.substr(0, (pos = s.find("|"))));
    s.erase(0, pos + 1);
    setVel = stod(s.substr(0, (pos = s.find("|"))));

    rightPid.setPID(p,i,d,f);
    //rightMotor.setVelocity(setVel);*/


  //}
  //rightPid.setF(255);
  //rightMotor.setVelocity(1);

  //
  Serial.printf("%f\n",rightMotor.getVelocity());
  delayMicroseconds(5000);
  //chassis.updatePosition();
  //chassis.printPosition();
  /*
  for(int i = 90; i < 10000; i+=90){
    chassis.turnToOrientation(i);
  //leftMotor.setRawPWM(255, false);
  //rightMotor.setVelocity(-1);
  //rightMotor.stepVelocityPID();

  //leftMotor.setVelocity(1);
  //leftMotor.stepVelocityPID();
  //Serial.printf("Left Enc: %d Right Enc: %d\n",leftMotor.getEncoder(), rightMotor.getEncoder());
    rightMotor.stop();
    leftMotor.stop();
    
    delay(1000);
  }*/
  
}
