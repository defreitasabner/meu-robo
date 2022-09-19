#include <Arduino.h>

#define PIN_ULTRASSONICO_ECHO 2
#define PIN_ULTRASSONICO_TRIGGER 12

namespace sensorUltrassonico {

    long tempoRising;
    long tempoFalling;

    // Funções do Interrupt
    void echoRisingISR();
    void echoFallingISR();

    void initUltrassonico() {
        attachInterrupt(PIN_ULTRASSONICO_ECHO, echoRisingISR, RISING);
        pinMode(PIN_ULTRASSONICO_TRIGGER, OUTPUT);
    }

    void echoRisingISR() {
        tempoRising = micros();
        attachInterrupt(PIN_ULTRASSONICO_ECHO, echoFallingISR, FALLING);
    }

    void echoFallingISR() {
        tempoFalling = micros();
        attachInterrupt(PIN_ULTRASSONICO_ECHO, echoRisingISR, RISING);
    }

    void calculaDistancia() {
        
    }

}