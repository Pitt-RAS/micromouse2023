#ifndef ROBOT_HPP
#define ROBOT_HPP

class Robot{
    private:
    public:
        //Constructor
        Robot();
        
        //Move Motors
        moveTank(uint8_t, uint8_t);
        
        //Get Distnce sensor data from #n sensor, typedef tbd
        uint32_t getDistanceSensor(uint32_t);
};

#include "Robot.cpp"

#endif
