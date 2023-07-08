#include <Arduino.h>
#include "pins.hpp"

namespace locomotion 
{
    void init()
    {
      pinMode(pins::motors::LEFT_FORWARD, OUTPUT);
      pinMode(pins::motors::LEFT_BACKWARD, OUTPUT);
      pinMode(pins::motors::RIGHT_FORWARD, OUTPUT);
      pinMode(pins::motors::RIGHT_FORWARD, OUTPUT);
    }

    void forward()
    {
      digitalWrite(pins::motors::LEFT_FORWARD, HIGH);
      digitalWrite(pins::motors::RIGHT_FORWARD, HIGH);
    }

    void backward()
    {
      digitalWrite(pins::motors::LEFT_BACKWARD, HIGH);
      digitalWrite(pins::motors::RIGHT_BACKWARD, HIGH);
    }

    void brake()
    {
      digitalWrite(pins::motors::LEFT_FORWARD, LOW);
      digitalWrite(pins::motors::RIGHT_FORWARD, LOW);
      digitalWrite(pins::motors::LEFT_BACKWARD, LOW);
      digitalWrite(pins::motors::RIGHT_BACKWARD, LOW);
    }
}