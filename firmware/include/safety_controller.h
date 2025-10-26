#include "Arduino.h"
#include "safety_controller.h"
#include "sensor_driver.h"
#include "motor_driver.h"

int WARNING_THRESHOLD = 15;

void initSafety() {
  Serial.println("Safety controller armed.");
}

void updateSafety() {
  int distance = getUltrasonicDistance();
  if (distance < WARNING_THRESHOLD) {
    stopMotors();
    Serial.println("Safety stop triggered!");
  }
}
