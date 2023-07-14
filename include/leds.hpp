#include <Arduino.h>

#include "pins.hpp"
#include "Led.hpp"

#pragma once

namespace leds {

    Led greenLed(pins::leds::GREEN);
    Led yellowLed(pins::leds::YELLOW);
    Led redLed(pins::leds::RED);
    
    void init() 
    {
        greenLed.init();
        yellowLed.init();
        redLed.init();
    }

    void verifyDistance(long distance) 
    {    
        if(distance < 100 && distance >= 50) 
        {
            greenLed.on();
            yellowLed.off();
            redLed.off();
        }
        
        else if(distance < 50 && distance >= 5) 
        {
            greenLed.off();
            yellowLed.on();
            redLed.off();
        }
        
        else if(distance < 5) 
        {
            greenLed.off();
            yellowLed.off();
            redLed.on();
        }

        else 
        {
            greenLed.off();
            yellowLed.off();
            redLed.off();
        }
    }
}