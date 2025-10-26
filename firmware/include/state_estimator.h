#include "pid_controller.h"

PIDController::PIDController(float kp, float ki, float kd) {
  Kp = kp;
  Ki = ki;
  Kd = kd;
  integral = 0;
  prevError = 0;
}

float PIDController::compute(float setpoint, float input) {
  float error = setpoint - input;
  integral += error;
  float derivative = error - prevError;
  prevError = error;
  return Kp * error + Ki * integral + Kd * derivative;
}

void PIDController::reset() {
  integral = 0;
  prevError = 0;
}
