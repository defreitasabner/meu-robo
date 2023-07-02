#include <Arduino.h>

#include "ultrasonicSensor.hpp"
#include "leds.hpp"

void setup() {
  Serial.begin(9600);
  ultrasonicSensor::initUltrasonicSensor();
  leds::initLeds();
}

void loop() {
  leds::verifyDistance(ultrasonicSensor::distance);
  //Serial.println(String(ultrasonicSensor::distance));
}