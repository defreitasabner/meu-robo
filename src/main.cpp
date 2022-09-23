#include <Arduino.h>

#include "sensorUltrassonico.hpp"
#include "leds.hpp"

void setup() {
  sensorUltrassonico::initUltrassonico();
  leds::initLeds();
}

void loop() {

  leds::verificaLeds(sensorUltrassonico::distancia);

}