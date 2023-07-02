#pragma once

class Led
{
    private:
        unsigned short int _pin;
    public:
        Led(int pin);
        void init();
        void on();
        void off();
};