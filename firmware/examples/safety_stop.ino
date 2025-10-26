#include "safety_controller.h"
#include "motor_driver.h"

void setup() {
  Serial.begin(115200);
  initMotors();
  initSafety();
}

void loop() {
  moveForward(120);
  updateSafety();
  delay(50);
}
