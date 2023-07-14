#include "PID.hpp"

namespace controller
{
    const double min = 0; 
    const double max = 255;
    const double Kp = 0;
    const double Ki = 0;
    const double Kd = 0;

    PID pid(
        min,
        max,
        Kp,
        Ki,
        Kd
    );
}