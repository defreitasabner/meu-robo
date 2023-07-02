#include <Arduino.h>

#include "ultrasonicSensor.hpp"
#include "leds.hpp"
#include "locomotion.hpp"

void setup() {
  Serial.begin(9600);
  ultrasonicSensor::init();
  locomotion::init();
  leds::init();
}

void loop() {
  leds::verifyDistance(ultrasonicSensor::distance);
  //Serial.println(String(ultrasonicSensor::distance));
}