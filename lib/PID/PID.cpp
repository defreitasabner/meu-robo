#include "PID.hpp"

PID::PID(double min, double max, double Kp, double Ki, double Kd):
_min(min),
_max(max),
_Kp(Kp),
_Ki(Ki),
_Kd(Kd),
_previousError(0),
_integral(0),
_derivativeTime(0)
{
}

double PID::calculate(double target, double read)
{
    _derivativeTime = millis() - _derivativeTime;
    double currentError = read - target;
    
    // Proportional
    double Pout = _Kp * currentError;
    
    // Integral
    _integral += currentError * _derivativeTime;
    double Iout = _Ki * _integral;
    
    // Derivative
    double derivative = (currentError - _previousError) / _derivativeTime;
    double Dout = _Kd * derivative;
    
    double pid = Pout + Iout + Dout;
    if(pid > _max) pid = _max;
    else if(pid < _min) pid = _min;

    _previousError = currentError;

    return pid;
}

void PID::reset()
{
    _previousError = 0;
    _derivativeTime = 0;
}
