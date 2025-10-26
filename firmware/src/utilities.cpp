#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController {
  public:
    PIDController(float kp, float ki, float kd);
    float compute(float setpoint, float input);
    void reset();

  private:
    float Kp, Ki, Kd;
    float integral, prevError;
};

#endif
