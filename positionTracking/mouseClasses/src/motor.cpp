#include <cstdint>
#include <Arduino.h>

class Motor{
    uint16_t input1, input2, pwmPin;
    int kv, ticksPerRot;

    //MiniPID velPID = MiniPID(k,p,d);

    Motor(uint16_t in1, uint16_t in2, uint16_t pwmMotorPin, uint16_t standByPin, int motorKv, int encTicksPerRot){
        input1 = in1;
        input2 = in2;
        pwmPin = pwmMotorPin;
        kv = motorKv;
        ticksPerRot = encTicksPerRot;
        pinMode(input1, OUTPUT);
        pinMode(input2, OUTPUT);
        pinMode(pwmPin, OUTPUT);
        pinMode(standByPin, OUTPUT);
        digitalWrite(standByPin, HIGH);
    }

    void setVelocity(float velocity){
        //velPID.setPoint(velocity);
    }

    void setRawPWM(int pwm, bool reverse){
        if(reverse){
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

    void stop(){}

    float getVelocity(){}

    void stepVelocityPID(){}

    int getEncoder(){}


};