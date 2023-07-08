#pragma once

class Motor 
{
    private:
        unsigned short int _pinForward;
        unsigned short int _pinBackward;

    public:
        Motor(int pinFoward, int pinBackward);
        void init();
        void forward();
        void backward();
        void brake();
};