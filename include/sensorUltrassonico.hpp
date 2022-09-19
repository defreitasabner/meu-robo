#include <Arduino.h>

#define PIN_ULTRASSONICO_ECHO 2
#define PIN_ULTRASSONICO_TRIGGER 12

namespace sensorUltrassonico {

    double tempoRising;
    double tempoFalling;
    double variacaoTempoPulso;
    
    double distancia;

    // Funções do Interrupt
    void echoRisingISR();
    void echoFallingISR();
    void calculaDistancia();

    void initUltrassonico() {
        attachInterrupt(digitalPinToInterrupt(PIN_ULTRASSONICO_ECHO), echoRisingISR, RISING);
        pinMode(PIN_ULTRASSONICO_TRIGGER, OUTPUT);
    }

    void dispararUltrassonico() {
        digitalWrite(PIN_ULTRASSONICO_TRIGGER, HIGH);
        delayMicroseconds(10);
        digitalWrite(PIN_ULTRASSONICO_TRIGGER, LOW);
    }

    void echoRisingISR() {
        tempoRising = micros();
        attachInterrupt(digitalPinToInterrupt(PIN_ULTRASSONICO_ECHO), echoFallingISR, FALLING);
    }

    void echoFallingISR() {
        tempoFalling = micros();
        calculaDistancia();
        attachInterrupt(digitalPinToInterrupt(PIN_ULTRASSONICO_ECHO), echoRisingISR, RISING);
        dispararUltrassonico();
    }

    void calculaDistancia() {
        variacaoTempoPulso = tempoFalling - tempoRising;
        distancia = (variacaoTempoPulso * 0.034) / 2;
    }

}