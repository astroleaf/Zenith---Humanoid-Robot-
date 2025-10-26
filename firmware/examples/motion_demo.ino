#include "motor_driver.h"
#include "sensor_driver.h"
#include "safety_controller.h"

void setup() {
  Serial.begin(115200);
  initMotors();
  initSensors();
  initSafety();
  Serial.println("Motion Demo Started...");
}

void loop() {
  moveForward(150);
  updateSafety();
  delay(1000);

  turnLeft(150);
  delay(800);
  stopMotors();
}
