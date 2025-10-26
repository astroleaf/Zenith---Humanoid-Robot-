#include "imu_sensor.h"
#include "kalman_filter.h"
#include "pid_controller.h"
#include "motor_driver.h"

KalmanFilter kf;
PIDController pid(2.0, 0.05, 0.8);

void balanceLoop() {
  float tilt = readTiltAngle();
  float rate = readAngularVelocity();
  float filteredAngle = kf.update(tilt, rate);

  float correction = pid.compute(0, filteredAngle);
  int speed = constrain(correction, -255, 255);

  if (speed > 0) moveForward(speed);
  else if (speed < 0) moveBackward(abs(speed));
  else stopMotors();
}
