#include <Arduino.h>
#include "pins.hpp"

#pragma once

namespace soundSensor
{
    bool isActive = false;
    const int maxSoundTime = 150;
    const int maxTimeBetweenSounds = 500;

    long waitingTime = 0;
    long waitingTimeBetweenSounds = 0;
    int soundsDetected = 0;

    void init()
    {
        pinMode(pins::sensors::SOUND, INPUT);
    }

    void detect()
    {
        int sensorRead = digitalRead(pins::sensors::SOUND);

        // Contabiliza quantos sons foram detectados
        if(sensorRead == LOW)
        {
            // Se for a primeira som
            if(waitingTime == 0)
            {
                waitingTime = waitingTimeBetweenSounds = millis();
                soundsDetected++;
            }
            else if((millis() - waitingTime) >= maxSoundTime)
            {
                waitingTime = 0;
            }
        }
        
        // Verifica se o tempo máximo de espera entre dois sons foi excedido
        if(
            (soundsDetected != 0) 
            && (millis() - waitingTimeBetweenSounds) > maxTimeBetweenSounds
        )
        {
            isActive = !isActive;
            soundsDetected = 0;
            waitingTimeBetweenSounds = millis();
        }
    }
}