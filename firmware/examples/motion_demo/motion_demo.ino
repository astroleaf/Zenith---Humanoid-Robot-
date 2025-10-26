#include "motor_driver.h"

void setup() {
  Serial.begin(115200);
  initMotors();
  Serial.println("Basic Movement Test: Starting...");
}

void loop() {
  moveForward(150);
  delay(2000);
  stopMotors();
  delay(1000);

  moveBackward(150);
  delay(2000);
  stopMotors();
  delay(1000);

  turnLeft(150);
  delay(1500);
  stopMotors();
  delay(1000);

  turnRight(150);
  delay(1500);
  stopMotors();
  delay(2000);
}
