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
    //60000 is the amount of microseconds in a minute
    //kv is measured in minutes
    maxVelocity = minVoltage * encTicksPerRot * motorKv / 60000000;
}

void Motor::setMotorAttr(float maxVel){
    maxVelocity = maxVel;
}

void Motor::setEncoder(QuadEncoder *enc){
    encoder = enc;
}

void Motor::setVelPID(MiniPID *pid){
    velPID = pid;
}

void Motor::initMotor(){
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    pinMode(pwmPin, OUTPUT);

    encoder->init();
    encoder->write(0);
    lastEncTime = micros();
    
    velPID->reset();
    currentVelocity = 0;
}

void Motor::setVelocity(float velocity){
    targetVelocity = velocity;
    //velPID->setSetpoint(targetVelocity);
}

void Motor::setRawPWM(int pwm, bool reverse){
    //Serial.printf(" PWM: %d\n ", pwm);
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

double Motor::getVelocity(){
    /*int deltaEnc = encoder->read() - lastEnc;
    int deltaTime = micros() - lastEncTime;
    //Serial.printf("Delta Time: %d Delta Enc: %d Max Velocity: %f Last Enc: %d Cur Enc %d ", deltaTime, deltaEnc, maxVelocity, lastEnc, encoder->read());
    lastEnc = encoder->read();
    lastEncTime = micros();

    //ticks per millisecond
    
    return (double)deltaEnc / deltaTime / maxVelocity;*/

    //return (double) deltaEnc / deltaTime;
    if(lastEnc != encoder->read()){
        
        int deltaTime = micros() - lastEncTime;
        int deltaEnc = encoder->read() - lastEnc;
        Serial.printf("Delta Time: %d Delta Enc: %d Max Velocity: %f Last Enc: %d Cur Enc %d ", deltaTime, deltaEnc, maxVelocity, lastEnc, encoder->read());
        currentVelocity = (double)deltaEnc / deltaTime / maxVelocity;

        lastEncTime = micros();
    }

    lastEnc = encoder->read();

    return currentVelocity;

}

void Motor::stepVelocityPID(){
    double motorVel = getVelocity();
    Serial.printf("%.20f\n",motorVel);
    //setRawPWM(velPID->getOutput(getVelocity(), targetVelocity), targetVelocity > 0);
    setRawPWM(velPID->getOutput(motorVel, targetVelocity), targetVelocity > 0);
}

int Motor::getEncoder(){
    return encoder->read();
}

