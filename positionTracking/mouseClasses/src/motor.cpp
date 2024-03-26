#include <cstdint>
#include <Arduino.h>
#include "QuadEncoder.h"
#include <MiniPID.h>
#include <motor.h>

Motor::Motor(){};


void Motor::setMotorPins(uint16_t in1, uint16_t in2, uint16_t pwmMotorPin){
    input1 = in1;
    input2 = in2;
    pwmPin = pwmMotorPin;
}

void Motor::setMotorAttr(int motorKv, int encTicksPerRot, float minVoltage){
    maxVelocity = minVoltage * motorKv/60000 * encTicksPerRot;
}

void Motor::setEncoder(QuadEncoder *enc){
    encoder = enc;
}

void Motor::initMotor(){
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    pinMode(pwmPin, OUTPUT);

    //encoder = QuadEncoder(1, encA, encB);
    //encoder.write(0);
    //lastEncTime = millis();
    
    //velPID.setPID(0,0,0);
}

void Motor::setVelocity(float velocity){
    targetVelocity = velocity * maxVelocity;
    //velPID.setSetpoint(targetVelocity);
}

void Motor::setRawPWM(int pwm, bool reverse){
    if(!reverse){
        digitalWrite(input1, LOW);
        digitalWrite(input2, HIGH);
        analogWrite(pwmPin, pwm);
    }
    else{
        digitalWrite(input1, HIGH);
        digitalWrite(input2, LOW);
        analogWrite(pwmPin, pwm);
    }
}

void Motor::stop(){
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
}

float Motor::getVelocity(){
    int deltaEnc =  getEncoder() - lastEnc;
    int deltaTime = millis() - lastEncTime;
    lastEnc = getEncoder();
    lastEncTime = millis();
    //ticks per millisecond
    return deltaEnc / deltaTime / maxVelocity;
}

void Motor::stepVelocityPID(){
    //setRawPWM(velPID.getOutput(getVelocity(), targetVelocity), targetVelocity > 0);
}

int Motor::getEncoder(){
    return 1;
    //return encoder.read();
}

