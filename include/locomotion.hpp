#include <Arduino.h>
#include "pins.hpp"
#include"TwoWheelLocomotion.hpp"

namespace locomotion 
{
    TwoWheelLocomotion motors(
      pins::motors::LEFT_FORWARD, 
      pins::motors::LEFT_BACKWARD,
      pins::motors::RIGHT_FORWARD, 
      pins::motors::RIGHT_BACKWARD
    );
}