#include <Arduino.h>

#include "pins.hpp"

#pragma once

namespace ultrasonicSensor 
{
    double risingTime;
    double fallingTime;
    double timeVariation;
    
    double distance;

    void echoRisingISR();
    void echoFallingISR();
    void calculateDistance();

    void init() 
    {
        attachInterrupt(digitalPinToInterrupt(pins::sensors::ULTRASONIC_ECHO), echoRisingISR, RISING);
        pinMode(pins::sensors::ULTRASONIC_TRIGGER, OUTPUT);
    }

    void pulse() 
    {
        digitalWrite(pins::sensors::ULTRASONIC_TRIGGER, HIGH);
        delayMicroseconds(10);
        digitalWrite(pins::sensors::ULTRASONIC_TRIGGER, LOW);
    }

    void echoRisingISR() 
    {
        risingTime = micros();
        attachInterrupt(digitalPinToInterrupt(pins::sensors::ULTRASONIC_ECHO), echoFallingISR, FALLING);
    }

    void echoFallingISR() 
    {
        fallingTime = micros();
        calculateDistance();
        attachInterrupt(digitalPinToInterrupt(pins::sensors::ULTRASONIC_ECHO), echoRisingISR, RISING);
        pulse();
    }

    void calculateDistance() 
    {
        timeVariation = fallingTime - risingTime;
        distance = (timeVariation * 0.034) / 2;
    }
}