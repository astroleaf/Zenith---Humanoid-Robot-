#include "safety_policy.h"
#include "sensor_driver.h"
#include "motor_driver.h"
#include <Arduino.h>

bool isSafeToProceed() {
  int distance = getUltrasonicDistance();
  return distance > 15; // Safe to proceed if > 15cm ahead
}

void triggerEmergencyStop() {
  stopMotors();
  Serial.println("Emergency stop triggered!");
}
