#include <Arduino.h>
#include "Motor.hpp"

Motor::Motor(int pinFoward, int pinBackward)
{
    this->_pinForward = pinFoward;
    this->_pinBackward = pinBackward;
}

void Motor::init() 
{
    pinMode(_pinForward, OUTPUT);
    pinMode(_pinBackward, OUTPUT);
}

void Motor::forward() 
{
    digitalWrite(_pinForward, HIGH);
}

void Motor::backward() 
{
    digitalWrite(_pinBackward, HIGH);
}

void Motor::brake() 
{
    digitalWrite(_pinForward, LOW);
    digitalWrite(_pinBackward, LOW);
}