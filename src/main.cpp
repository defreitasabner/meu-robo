#include <Arduino.h>

#include "sensorUltrassonico.hpp"

#define PIN_LED_VERDE 4
#define PIN_LED_AMARELO 7 
#define PIN_LED_VERMELHO 8


void setup() {
  sensorUltrassonico::initUltrassonico();
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_AMARELO, OUTPUT);
  pinMode(PIN_LED_VERMELHO, OUTPUT);
}

void loop() {


  if(sensorUltrassonico::distancia < 100 && sensorUltrassonico::distancia >= 50) {
    digitalWrite(PIN_LED_VERDE, HIGH);
    digitalWrite(PIN_LED_AMARELO, LOW);
    digitalWrite(PIN_LED_VERMELHO, LOW);
  }
  
  else if(sensorUltrassonico::distancia < 50 && sensorUltrassonico::distancia >= 5) {
    digitalWrite(PIN_LED_VERDE, LOW);
    digitalWrite(PIN_LED_AMARELO, HIGH);
    digitalWrite(PIN_LED_VERMELHO, LOW);
  }
  
  else if(sensorUltrassonico::distancia < 5) {
    digitalWrite(PIN_LED_VERDE, LOW);
    digitalWrite(PIN_LED_AMARELO, LOW);
    digitalWrite(PIN_LED_VERMELHO, HIGH);
  }

  else {
    digitalWrite(PIN_LED_VERDE, LOW);
    digitalWrite(PIN_LED_AMARELO, LOW);
    digitalWrite(PIN_LED_VERMELHO, LOW);
  }

}