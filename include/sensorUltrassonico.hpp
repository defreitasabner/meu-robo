#include <Arduino.h>

#define PIN_ULTRASSONICO_ECHO 2
#define PIN_ULTRASSONICO_TRIGGER 12

namespace sensorUltrassonico {

    long tempoRising;
    long tempoFalling;
    long variacaoTempoPulso;

    long distancia;

    // Funções do Interrupt
    void echoRisingISR();
    void echoFallingISR();

    void initUltrassonico() {
        attachInterrupt(PIN_ULTRASSONICO_ECHO, echoRisingISR, RISING);
        pinMode(PIN_ULTRASSONICO_TRIGGER, OUTPUT);
    }

    void dispararUltrassonico() {
        digitalWrite(PIN_ULTRASSONICO_TRIGGER, HIGH);
    }

    void echoRisingISR() {
        tempoRising = micros();
        attachInterrupt(PIN_ULTRASSONICO_ECHO, echoFallingISR, FALLING);
    }

    void echoFallingISR() {
        tempoFalling = micros();
        variacaoTempoPulso = tempoFalling - tempoRising;
        attachInterrupt(PIN_ULTRASSONICO_ECHO, echoRisingISR, RISING);
    }

    void calculaDistancia() {
        distancia = (variacaoTempoPulso * 0.034) / 2;
    }

}