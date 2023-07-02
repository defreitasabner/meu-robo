#include <Arduino.h>

#include "pins.hpp"

#pragma once

namespace ultrasonicSensor {

    double risingTime;
    double fallingTime;
    double timeVariation;
    
    double distance;

    void echoRisingISR();
    void echoFallingISR();
    void calculateDistance();

    void initUltrasonicSensor() {
        attachInterrupt(digitalPinToInterrupt(pins::PIN_ULTRASONIC_SENSOR_ECHO), echoRisingISR, RISING);
        pinMode(pins::PIN_ULTRASONIC_SENSOR_TRIGGER, OUTPUT);
    }

    void ultrasonicTrigger() {
        digitalWrite(pins::PIN_ULTRASONIC_SENSOR_TRIGGER, HIGH);
        delayMicroseconds(10);
        digitalWrite(pins::PIN_ULTRASONIC_SENSOR_TRIGGER, LOW);
    }

    void echoRisingISR() {
        risingTime = micros();
        attachInterrupt(digitalPinToInterrupt(pins::PIN_ULTRASONIC_SENSOR_ECHO), echoFallingISR, FALLING);
    }

    void echoFallingISR() {
        fallingTime = micros();
        calculateDistance();
        attachInterrupt(digitalPinToInterrupt(pins::PIN_ULTRASONIC_SENSOR_ECHO), echoRisingISR, RISING);
        ultrasonicTrigger();
    }

    void calculateDistance() {
        timeVariation = fallingTime - risingTime;
        distance = (timeVariation * 0.034) / 2;
    }

}