#include "TwoWheelLocomotion.hpp"

TwoWheelLocomotion::TwoWheelLocomotion(
    const unsigned short int leftMotorForwardPin, 
    const unsigned short int leftMotorBackwardPin, 
    const unsigned short int rightMotorForwardPin, 
    const unsigned short int rightMotorBackwardPin
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

void TwoWheelLocomotion::forward()
{
    _leftMotor.forward();
    _rightMotor.forward();
}

void TwoWheelLocomotion::backward()
{
    _leftMotor.backward();
    _rightMotor.backward();
}
