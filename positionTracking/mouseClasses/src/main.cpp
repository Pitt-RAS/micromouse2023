#include <Arduino.h>
#include <motor.h>
#include <mouseConfig.h>
#include "QuadEncoder.h"
#include "chassis.h"

Motor rightMotor;
QuadEncoder rightEnc(1, RIGHT_ENCODER_PIN_A, RIGHT_ENCODER_PIN_B);
MiniPID rightPid(MOTOR_VEL_PID_P, MOTOR_VEL_PID_I, MOTOR_VEL_PID_D, MOTOR_VEL_PID_F);

Motor leftMotor;
QuadEncoder leftEnc(2, LEFT_ENCODER_PIN_A, LEFT_ENCODER_PIN_B);
MiniPID leftPid(MOTOR_VEL_PID_P, MOTOR_VEL_PID_I, MOTOR_VEL_PID_D, MOTOR_VEL_PID_F);

MiniPID anglePID(0,0,0);
MiniPID turnPID(0,0,0);
MiniPID distancePID(0,0,0);
Chassis chassis;

void setup(){
  Serial.begin(230400);

  rightPid.setMaxIOutput(255);
  rightPid.setOutputLimits(0,255);

  rightMotor.setMotorPins(RIGHT_MOTOR_PIN_1, RIGHT_MOTOR_PIN_2, RIGHT_MOTOR_PIN_PWM);
  rightMotor.setMotorAttr(MAX_VELOCITY);
  rightMotor.setEncoder(&rightEnc);
  rightMotor.setVelPID(&rightPid);

  rightMotor.initMotor();

  leftPid.setMaxIOutput(255);
  leftPid.setOutputLimits(0,255);

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
  /*
  if (Serial.available() > 0) {
    double input = (double)Serial.parseInt()/100;
    if(input != 0){
      mtr.setVelocity(input);
    }
  }

  mtr.stepVelocityPID();


 
  */
  chassis.updatePosition();
  chassis.printPosition();
  //Serial.printf("Left Enc: %d Right Enc: %d\n",leftMotor.getEncoder(), rightMotor.getEncoder());
  delayMicroseconds(5000);
}
