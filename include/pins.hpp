#pragma once

namespace pins 
{
    namespace leds 
    {
        const unsigned short int GREEN = 4;
        const unsigned short int YELLOW = 7; 
        const unsigned short int RED = 8;
    }

    namespace sensors 
    {
        const unsigned short int ULTRASONIC_ECHO = 2;
        const unsigned short int ULTRASONIC_TRIGGER = 12;
    }

    namespace motors 
    {
        const unsigned short int LEFT_FORWARD = 5;
        const unsigned short int LEFT_BACKWARD = 6;
        const unsigned short int RIGHT_FORWARD = 9;
        const unsigned short int RIGHT_BACKWARD = 10;
    }
}