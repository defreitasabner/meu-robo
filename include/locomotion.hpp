#include <Arduino.h>
#include "pins.hpp"
#include "Motor.hpp"

namespace locomotion 
{    
    const unsigned int MAX_VELOCITY = 200;
    
    Motor leftMotor(pins::PIN_LEFT_MOTOR_FORWARD, pins::PIN_LEFT_MOTOR_BACKWARD);
    Motor rightMotor(pins::PIN_RIGHT_MOTOR_FORWARD, pins::PIN_RIGHT_MOTOR_BACKWARD);

    void init() 
    {
        leftMotor.init();
        rightMotor.init();
    }

    void forward() 
    {
        leftMotor.forward(MAX_VELOCITY);
        rightMotor.forward(MAX_VELOCITY);
    }

    void backward() 
    {
        leftMotor.backward(MAX_VELOCITY);
        rightMotor.backward(MAX_VELOCITY);
    }

    void brake()
    {
        leftMotor.brake();
        rightMotor.brake();
    }
}