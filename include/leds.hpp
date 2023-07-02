#include <Arduino.h>

#include "pins.hpp"

#pragma once

namespace leds {
    
    void initLeds() {
        pinMode(pins::PIN_GREEN_LED, OUTPUT);
        pinMode(pins::PIN_YELLOW_LED, OUTPUT);
        pinMode(pins::PIN_RED_LED, OUTPUT);
    }

    void greenLedOn() {
        digitalWrite(pins::PIN_GREEN_LED, HIGH); 
    }

    void greenLedOff() {
        digitalWrite(pins::PIN_GREEN_LED, LOW); 
    }

    void yellowLedOn() {
        digitalWrite(pins::PIN_YELLOW_LED, HIGH);
    }

    void yellowLedOff() {
        digitalWrite(pins::PIN_YELLOW_LED, LOW); 
    }


    void redLedOn() {
        digitalWrite(pins::PIN_RED_LED, HIGH);
    }

    void redLedOff() {
        digitalWrite(pins::PIN_RED_LED, LOW); 
    }

    void verifyDistance(long distance) {
        
        if(distance < 100 && distance >= 50) {
            greenLedOn();
            yellowLedOff();
            redLedOff();
        }
        
        else if(distance < 50 && distance >= 5) {
            greenLedOff();
            yellowLedOn();
            redLedOff();
        }
        
        else if(distance < 5) {
            greenLedOff();
            yellowLedOff();
            redLedOn();
        }

        else {
            greenLedOff();
            yellowLedOff();
            redLedOff();
        }
    }

}