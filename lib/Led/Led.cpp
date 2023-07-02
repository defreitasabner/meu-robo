#include <Arduino.h>
#include "Led.hpp"

Led::Led(int pin):
_pin(pin)
{
}

void Led::init()
{
    pinMode(_pin, OUTPUT);
}

void Led::on()
{
    digitalWrite(_pin, HIGH);
}

void Led::off()
{
    digitalWrite(_pin, LOW);
}
