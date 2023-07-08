#include <Arduino.h>

#include "ultrasonicSensor.hpp"
#include "locomotion.hpp"
#include "soundSensor.hpp"

void setup() {
  Serial.begin(9600);
  ultrasonicSensor::init();
  soundSensor::init();
  locomotion::init();
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
      locomotion::brake();
    }
    else
    {
      locomotion::forward();
    }
  }
}