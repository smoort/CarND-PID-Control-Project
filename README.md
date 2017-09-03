# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection - Effect each of the P, I, D components on the implementation

* P component controls the intensity of correction.  The higher the P value the car tends to overshoot the desired track and takes an oscillatory path.  The lower the P value, the correction is slow tending to get off the road in sharp turns.
* I component corrects for any systemic biases.  The wheels of the car in the simulator seemed to be aligned and hence did not have any systemic bias.  Hence no correction was needed.  Adding an I component tends to drag the car in one direction by that amount.
* D component helped get a smoother convergence to desired path while avoiding too much overshooting.  High value of D caused the car to overshoot the desired results, where as a low value did not correct course much leading to vehicle getting off road.
* Keeping I 0, P low and D high finally did the trick.


## Reflection - Method of chosing the final hyperparameters

* Manual tuning using trial and error was used to arrive at the final hyperparameters
* By observing the car in a straight lane, it was evident that the car did not have any systemic bias.  Hence the I component was set to 0.
* As high P value caused too much overshooting, used a low P value with high D value to achieve smooth convergence.
