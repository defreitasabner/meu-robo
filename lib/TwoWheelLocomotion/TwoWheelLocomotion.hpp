#include "Motor.hpp"

class TwoWheelLocomotion {
    private:
        Motor _leftMotor;
        Motor _rightMotor;
    public:
        TwoWheelLocomotion(
            int leftMotorForwardPin, 
            int leftMotorBackwardPin,
            int rightMotorForwardPin,
            int rightMotorBackwardPin
        );
        void init();
        void brake();
        void forward(int velocity);
        void backward(int velocity);
};