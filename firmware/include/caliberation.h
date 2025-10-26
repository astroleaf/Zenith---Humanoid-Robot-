#include "Arduino.h"
#include "motor_driver.h"
#include "pid_controller.h"
#include "sensor_driver.h"

PIDController balancer(1.2, 0.01, 0.5);

void calibrateMotors() {
  Serial.println("Starting motor calibration...");
  for (int spd = 100; spd <= 255; spd += 25) {
    moveForward(spd);
    delay(400);
  }
  stopMotors();
  Serial.println("Calibration complete.");
}

void testPIDBalance() {
  float setpoint = 0.0;  // desired tilt angle
  while (true) {
    float angle = analogRead(A1) - 512; // mock tilt sensor
    float controlSignal = balancer.compute(setpoint, angle);
    int motorSpeed = constrain((int)controlSignal, -255, 255);

    if (motorSpeed > 0) moveForward(motorSpeed);
    else if (motorSpeed < 0) moveBackward(abs(motorSpeed));
    else stopMotors();

    delay(20);
  }
}
