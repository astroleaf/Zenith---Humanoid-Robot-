#include "motor_driver.h"
#include "sensor_driver.h"
#include "safety_controller.h"

void setup() {
  Serial.begin(115200);
  initMotors();
  initSensors();
  initSafety();
  Serial.println("Humanoid Robot: Core system initialized.");
}

void loop() {
  readSensors();
  updateSafety();
  
  // Example simple walking routine
  int distance = getUltrasonicDistance();
  if (distance < 20) {
    stopMotors();
    Serial.println("Obstacle detected - stopping.");
  } else {
    moveForward(150);
  }

  delay(50);
}
