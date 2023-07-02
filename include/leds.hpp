#include <Arduino.h>

#include "pins.hpp"
#include "Led.hpp"

#pragma once

namespace leds {

    Led greenLed(pins::PIN_GREEN_LED);
    Led yellowLed(pins::PIN_YELLOW_LED);
    Led redLed(pins::PIN_RED_LED);
    
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