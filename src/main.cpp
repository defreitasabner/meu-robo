#include <Arduino.h>

#include "ultrasonicSensor.hpp"
#include "locomotion.hpp"

void setup() {
  Serial.begin(9600);
  ultrasonicSensor::init();
  locomotion::init();
}

void loop() {
  if(ultrasonicSensor::distance > 10)
  {
    locomotion::forward();
    Serial.println("Indo para frente");
  }
  else
  {
    locomotion::backward();
    Serial.println("Indo para trás");
  }
}