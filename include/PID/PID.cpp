#include <Arduino.h>
#include "PID.hpp"

template<typename T>
PID<T>::PID(T P, T I, T D){
    Kp = P;
    Ki = I;
    Kd = D;
    laste=NULL;
    resetTime();
}

template<typename T>
void PID<T>::resetTime(){
    last_time = millis();
}

template<typename T>
T PID<T>::compute(T e){
    unsigned long dt = millis() - last_time;
    T total = 0;
    total += Kp * e;
    total += (e + laste)/2 * dt * Ki;
    if(laste!=NULL && dt != 0){
        total += (e - laste)/dt;
    }
    resetTime();
    laste = e;
    return total;
}

//Mutators
template<typename T>
PID<T>::setKp(T P){
    Kp = P;
}
template<typename T>
PID<T>::setKi(T I){
    Ki = I;
}
template<typename T>
PID<T>::setKd(T D){
    Kd = D;
}

//Accesors
template<typename T>
T PID<T>::getKp(){
    return Kp;
}
template<typename T>
T PID<T>::getKi(){
    return Ki;
}
template<typename T>
T PID<T>::getKd(){
    return Kd;
}
