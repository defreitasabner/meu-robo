#pragma once

namespace pins 
{
    namespace leds 
    {
        const unsigned short int GREEN = 3;
        const unsigned short int YELLOW = 5; 
        const unsigned short int RED = 6;
    }

    namespace sensors 
    {
        const unsigned short int ULTRASONIC_ECHO = 2;
        const unsigned short int ULTRASONIC_TRIGGER = 12;
    }

    namespace motors 
    {
        const unsigned short int LEFT_FORWARD = 4;
        const unsigned short int LEFT_BACKWARD = 7;
        const unsigned short int RIGHT_FORWARD = 8;
        const unsigned short int RIGHT_BACKWARD = 13;
    }
}