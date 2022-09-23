#include <Arduino.h>

#include "pinagem.hpp"

#pragma once

namespace leds {
    
    void initLeds() {
        pinMode(pins::PIN_LED_VERDE, OUTPUT);
        pinMode(pins::PIN_LED_AMARELO, OUTPUT);
        pinMode(pins::PIN_LED_VERMELHO, OUTPUT);
    }

    void ligarLedVerde() {
        digitalWrite(pins::PIN_LED_VERDE, HIGH); 
    }

    void desligarLedVerde() {
        digitalWrite(pins::PIN_LED_VERDE, LOW); 
    }

    void ligarLedAmarelo() {
        digitalWrite(pins::PIN_LED_AMARELO, HIGH);
    }

    void desligarLedAmarelo() {
        digitalWrite(pins::PIN_LED_AMARELO, LOW); 
    }


    void ligarLedVermelho() {
        digitalWrite(pins::PIN_LED_VERMELHO, HIGH);
    }

    void desligarLedVermelho() {
        digitalWrite(pins::PIN_LED_VERMELHO, LOW); 
    }

    void verificaLeds(long distancia) {
        
        if(distancia < 100 && distancia >= 50) {
            ligarLedVerde();
            desligarLedAmarelo();
            desligarLedVermelho();
        }
        
        else if(distancia < 50 && distancia >= 5) {
            desligarLedVerde();
            ligarLedAmarelo();
            desligarLedVermelho();
        }
        
        else if(distancia < 5) {
            desligarLedVerde();
            desligarLedAmarelo();
            ligarLedVermelho();
        }

        else {
            desligarLedVerde();
            desligarLedAmarelo();
            desligarLedVermelho();
        }
    }

}