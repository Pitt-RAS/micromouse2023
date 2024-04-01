#ifndef MOTOR_H
#define MOTOR_H

#include <cstdint>
#include "QuadEncoder.h"
#include <MiniPID.h>

class Motor{
    public: 
        Motor();
        void setVelocity(float velocity);
        void setRawPWM(int pwm, bool reverse);
        void stop();
        double getVelocity();
        void stepVelocityPID();
        void initMotor();
        void setMotorPins(uint16_t in1, uint16_t in2, uint16_t pwmMotorPin);
        void setMotorAttr(int motorKv, int encTicksPerRot, float minVoltage);
        void setMotorAttr(float maxVel);
        void setVelPID(MiniPID *pid);
        void setEncoder(QuadEncoder *enc);
        int getEncoder();
        uint16_t input1, input2, pwmPin, encA, encB;
        int lastEnc;
        float targetVelocity;
        float lastEncTime;
        float maxVelocity;
        float currentVelocity;
        QuadEncoder *encoder;
        MiniPID *velPID;


};

#endif