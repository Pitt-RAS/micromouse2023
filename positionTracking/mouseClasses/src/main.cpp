#include <Arduino.h>
#include <motor.h>
#include <mouseConfig.h>
#include "QuadEncoder.h"

//Motor mtr;

/*void setup() {
  //mtr = Motor(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PWM_PIN, MOTOR_STBY_PIN, ENCODER_PIN_A, ENCODER_PIN_B, MOTOR_KV, ENCODER_TICKS_PER_ROTATION, MIN_VOLTAGE, MOTOR_VEL_PID_P, MOTOR_VEL_PID_I, MOTOR_VEL_PID_D);
  //mtr.setRawPWM(64,false);
  //mtr.initMotor();
}


void loop() {
  //Motor mtr(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PWM_PIN, MOTOR_STBY_PIN, ENCODER_PIN_A, ENCODER_PIN_B, MOTOR_KV, ENCODER_TICKS_PER_ROTATION, MIN_VOLTAGE, MOTOR_VEL_PID_P, MOTOR_VEL_PID_I, MOTOR_VEL_PID_D);
  //mtr.initMotor();
  Serial.println("test");
  //Serial.println(mtr.input1);
  //mtr.setRawPWM(64,false);
  delay(1);
  //float velocity = Serial.parseFloat();
  /*float velocity = 0.5;
  mtr.setVelocity(velocity);
  Serial.printf("Target Velocity: %f\nActual Velocity: %f\n",velocity,mtr.getVelocity());*/
//}
Motor mtr;
QuadEncoder enc(1, ENCODER_PIN_A, ENCODER_PIN_B);

void setup(){
  mtr.setMotorPins(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_PWM);
  mtr.setMotorAttr(MOTOR_KV, ENCODER_TICKS_PER_ROTATION, MIN_VOLTAGE);
  mtr.setEncoder(&enc);

  mtr.initMotor();
}

void loop() {

  mtr.setRawPWM(64, false);
  delay(1);
}
