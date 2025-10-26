#include "motor_driver.h"
#include "sensor_driver.h"

void setup() {
  Serial.begin(115200);
  initMotors();
  initSensors();
}

void loop() {
  int distance = getUltrasonicDistance();
  if (distance < 20) {
    stopMotors();
    turnLeft(150);
    delay(500);
  } else {
    moveForward(180);
  }
  delay(50);
}
