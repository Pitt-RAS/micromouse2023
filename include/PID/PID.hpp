#ifndef PID_HPP
#define PID_HPP

template<typename T>
class PID{
    private:
        unsigned long last_time;
        T Kp;
        T Ki;
        T Kd;
        T laste;
    public:
        //Constructors
        PID();
        PID(T, T, T);
        
        //Mutators
        setKp(T);
        setKi(T);
        setKd(T);
        
        //Accesors
        T getKp();
        T getKi();
        T getKd();
        
        
        //Reset last time
        void resetTime();
        
        //Get output from commanded position, current position
        T compute(T);
        
};

#include "PID.cpp"

#endif
