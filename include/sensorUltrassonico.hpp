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
        attachInterrupt(digitalPinToInterrupt(pins::PIN_SENSOR_ULTRASSONICO_ECHO), echoRisingISR, RISING);
        pinMode(pins::PIN_SENSOR_ULTRASSONICO_TRIGGER, OUTPUT);
    }

    void dispararUltrassonico() {
        digitalWrite(pins::PIN_SENSOR_ULTRASSONICO_TRIGGER, HIGH);
        delayMicroseconds(10);
        digitalWrite(pins::PIN_SENSOR_ULTRASSONICO_TRIGGER, LOW);
    }

    void echoRisingISR() {
        tempoRising = micros();
        attachInterrupt(digitalPinToInterrupt(pins::PIN_SENSOR_ULTRASSONICO_ECHO), echoFallingISR, FALLING);
    }

    void echoFallingISR() {
        tempoFalling = micros();
        calculaDistancia();
        attachInterrupt(digitalPinToInterrupt(pins::PIN_SENSOR_ULTRASSONICO_ECHO), echoRisingISR, RISING);
        dispararUltrassonico();
    }

    void calculaDistancia() {
        variacaoTempoPulso = tempoFalling - tempoRising;
        distancia = (variacaoTempoPulso * 0.034) / 2;
    }

}