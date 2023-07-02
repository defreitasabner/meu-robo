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

void Motor::forward(int velocity) 
{
    analogWrite(_pinForward, velocity);
}

void Motor::backward(int velocity) 
{
    analogWrite(_pinBackward, velocity);
}

void Motor::brake() 
{
    analogWrite(_pinForward, 0);
    analogWrite(_pinBackward, 0);
}