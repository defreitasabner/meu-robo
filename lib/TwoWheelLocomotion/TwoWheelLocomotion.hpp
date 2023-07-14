#include "Motor.hpp"

class TwoWheelLocomotion {
    private:
        Motor _leftMotor;
        Motor _rightMotor;
    public:
        TwoWheelLocomotion(
            const unsigned short int leftMotorForwardPin, 
            const unsigned short int leftMotorBackwardPin,
            const unsigned short int rightMotorForwardPin,
            const unsigned short int rightMotorBackwardPin
        );
        void init();
        void brake();
        void forward();
        void backward();
};