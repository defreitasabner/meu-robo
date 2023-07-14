#include <Arduino.h>

#include "ultrasonicSensor.hpp"
#include "locomotion.hpp"
#include "soundSensor.hpp"

void setup() {
  Serial.begin(9600);
  ultrasonicSensor::init();
  soundSensor::init();
  locomotion::motors.init();
}

void loop() {
  soundSensor::detect();
  if(soundSensor::isActive) 
  {
    Serial.println("Parado!");
  } 
  else 
  {
    Serial.println("Andando!");
    if(ultrasonicSensor::distance < 20)
    {
      locomotion::motors.brake();
    }
    else
    {
      locomotion::motors.forward();
    }
  }
}