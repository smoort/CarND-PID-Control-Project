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

double PID::TotalError(std::vector<double> p) {
    Kp = p[0];
    Ki = p[1];
    Kd = p[2];

    return Kp*p_error + Ki*i_error + Kd*d_error;
}

std::vector<double> PID::twiddle(double tolerance){

    std::cout << "inside twiddle" << std::endl;

    std::vector<double> p = {0.0,0.0,0.0};
    std::vector<double> dp = {1.0,1.0,1.0};
    //double best_err = PID::p_error+PID::i_error+PID::d_error;
    double best_err = PID::TotalError(p);
    double dp_sum = dp[0]+dp[1]+dp[2];
    int it = 0;

    while (dp_sum > tolerance)  {
        cout << "inside twiddle while" << endl;

        for(int i=0;i<p.size();i++){
            p[i] += dp[i];
            double err = PID::TotalError(p);

            if (err < best_err) {
                best_err = err;
                dp[i] *= 1.1;
            }
            else {
                p[i] -= 2*dp[i];
                err = PID::TotalError(p);

                if(err < best_err) {
                    best_err = err;
                    dp[i] *= 1.1;
                }
                else {
                    p[i] += dp[i];
                    dp[i] *= 0.9;
                }
            }
        }
        cout << "dpsum = " << dp_sum << endl;
        dp_sum = dp[0]+dp[1]+dp[2];
        it += 1;
    }
/*
    p = [0, 0, 0]
    dp = [1, 1, 1]
    robot = make_robot()
    x_trajectory, y_trajectory, best_err = run(robot, p)

    it = 0
    while sum(dp) > tol:
        print("Iteration {}, best error = {}".format(it, best_err))
        for i in range(len(p)):
            p[i] += dp[i]
            robot = make_robot()
            x_trajectory, y_trajectory, err = run(robot, p)

            if err < best_err:
                best_err = err
                dp[i] *= 1.1
            else:
                p[i] -= 2 * dp[i]
                robot = make_robot()
                x_trajectory, y_trajectory, err = run(robot, p)

                if err < best_err:
                    best_err = err
                    dp[i] *= 1.1
                else:
                    p[i] += dp[i]
                    dp[i] *= 0.9
        it += 1
*/
    cout << "finishing twiddle" << endl;
    return p;
}

