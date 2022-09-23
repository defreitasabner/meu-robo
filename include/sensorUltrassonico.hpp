#include <Arduino.h>

#include "pinagem.hpp"

namespace sensorUltrassonico {

    double tempoRising;
    double tempoFalling;
    double variacaoTempoPulso;
    
    double distancia;

    // Protótipos das funções de Interrupt
    void echoRisingISR();
    void echoFallingISR();
    void calculaDistancia();

    void initUltrassonico() {
        attachInterrupt(digitalPinToInterrupt(pin::PIN_SENSOR_ULTRASSONICO_ECHO), echoRisingISR, RISING);
        pinMode(pin::PIN_SENSOR_ULTRASSONICO_TRIGGER, OUTPUT);
    }

    void dispararUltrassonico() {
        digitalWrite(pin::PIN_SENSOR_ULTRASSONICO_TRIGGER, HIGH);
        delayMicroseconds(10);
        digitalWrite(pin::PIN_SENSOR_ULTRASSONICO_TRIGGER, LOW);
    }

    void echoRisingISR() {
        tempoRising = micros();
        attachInterrupt(digitalPinToInterrupt(pin::PIN_SENSOR_ULTRASSONICO_ECHO), echoFallingISR, FALLING);
    }

    void echoFallingISR() {
        tempoFalling = micros();
        calculaDistancia();
        attachInterrupt(digitalPinToInterrupt(pin::PIN_SENSOR_ULTRASSONICO_ECHO), echoRisingISR, RISING);
        dispararUltrassonico();
    }

    void calculaDistancia() {
        variacaoTempoPulso = tempoFalling - tempoRising;
        distancia = (variacaoTempoPulso * 0.034) / 2;
    }

}