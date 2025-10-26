#include "motor_driver.h"
#include <Arduino.h>

void testMotorForward() {
  initMotors();
  moveForward(200);
  delay(1000);
  stopMotors();
}

void testMotorBackward() {
  initMotors();
  moveBackward(200);
  delay(1000);
  stopMotors();
}

int main() {
  Serial.begin(115200);
  testMotorForward();
  delay(1000);
  testMotorBackward();
  delay(1000);
  Serial.println("Motor Driver tests completed.");
  return 0;
}
