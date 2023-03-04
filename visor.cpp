#include <Arduino.h>
#include "visor.hpp"
#include "include/PID/PID.hpp"
#include "include/Robot/Robot.hpp"

void visor(void){
  //Main function here
  PID<double> Controller = PID<double>(1, 1, 1);
}
