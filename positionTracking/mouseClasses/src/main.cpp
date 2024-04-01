#include <Arduino.h>
#include <motor.h>
#include <mouseConfig.h>
#include "QuadEncoder.h"

Motor mtr;
QuadEncoder enc(1, ENCODER_PIN_A, ENCODER_PIN_B);
MiniPID pid(MOTOR_VEL_PID_P, MOTOR_VEL_PID_I, MOTOR_VEL_PID_D, MOTOR_VEL_PID_F);

void setup(){
  Serial.begin(230400);

  pid.setMaxIOutput(255);
  pid.setOutputLimits(0,255);

  mtr.setMotorPins(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_PWM);
  //mtr.setMotorAttr(MOTOR_KV, ENCODER_TICKS_PER_ROTATION, MIN_VOLTAGE);
  mtr.setMotorAttr(MAX_VELOCITY);
  mtr.setEncoder(&enc);
  mtr.setVelPID(&pid);

  mtr.initMotor();

  mtr.setVelocity(1);
}


void loop() {
  
  if (Serial.available() > 0) {
    double input = (double)Serial.parseInt()/100;
    if(input != 0){
      mtr.setVelocity(input);
    }
  }

  mtr.stepVelocityPID();


  delayMicroseconds(1);
}
