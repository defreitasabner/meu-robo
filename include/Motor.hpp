#pragma once

class Motor 
{
    private:
        unsigned short int _pinForward;
        unsigned short int _pinBackward;

    public:
        explicit Motor(int pinFoward, int pinBackward);
        void init();
        void forward(int velocity);
        void backward(int velocity);
        void brake();
};