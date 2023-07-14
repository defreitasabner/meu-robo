#include <Arduino.h>
#pragma once

class PID 
{
    private:
        double _min;
        double _max;
        double _Kp;
        double _Ki;
        double _Kd;
        double _derivativeTime;
        double _previousError;
        double _integral;
    public:
        PID(
            double min, 
            double max,
            double Kp,
            double Ki,
            double Kd
        );
        double calculate(double target, double read);
        void reset();
};