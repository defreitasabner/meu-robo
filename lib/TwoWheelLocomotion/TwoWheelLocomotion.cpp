#include "TwoWheelLocomotion.hpp"

TwoWheelLocomotion::TwoWheelLocomotion(
    int leftMotorForwardPin, 
    int leftMotorBackwardPin, 
    int rightMotorForwardPin, 
    int rightMotorBackwardPin
):
_leftMotor(leftMotorForwardPin, leftMotorBackwardPin),
_rightMotor(rightMotorForwardPin, rightMotorBackwardPin) 
{
}

void TwoWheelLocomotion::init()
{
    _leftMotor.init();
    _rightMotor.init();
}

void TwoWheelLocomotion::brake()
{
    _leftMotor.brake();
    _rightMotor.brake();
}

void TwoWheelLocomotion::forward(int velocity)
{
    _leftMotor.forward(velocity);
    _rightMotor.forward(velocity);
}

void TwoWheelLocomotion::backward(int velocity)
{
    _leftMotor.backward(velocity);
    _rightMotor.backward(velocity);
}
