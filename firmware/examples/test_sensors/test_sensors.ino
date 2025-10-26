#include "imu_sensor.h"
#include "kalman_filter.h"
#include "pid_controller.h"
#include "motor_driver.h"

KalmanFilter kf;
PIDController pid(2.0, 0.05, 0.8);

void setup() {
  Serial.begin(115200);
  initIMU();
  initMotors();
}

void loop() {
  float tilt = readTiltAngle();
  float rate = readAngularVelocity();
  float angle = kf.update(tilt, rate);

  float control = pid.compute(0, angle);
  int speed = constrain(control, -255, 255);

  if (speed > 0) moveForward(speed);
  else if (speed < 0) moveBackward(abs(speed));
  else stopMotors();

  delay(20);
}
