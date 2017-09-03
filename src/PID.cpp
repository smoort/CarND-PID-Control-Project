#include "PID.h"
#include <iostream>

using namespace std;
#include<vector>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    i_error += cte;
    p_error = cte;
    return;
}

double PID::TotalError() {
    return PID::Kp*p_error + PID::Ki*i_error + PID::Kd*d_error;
}

