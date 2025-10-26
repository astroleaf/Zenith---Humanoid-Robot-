#include "imu_sensor.h"
#include "sensor_driver.h"
#include "motor_driver.h"
#include "safety_controller.h"

void setup() {
  Serial.begin(115200);
  initIMU();
  initMotors();
  initSafety();
  Serial.println("Integration Test Started");
}

void loop() {
  float tilt = readTiltAngle();
  int dist = getUltrasonicDistance();

  if (dist < 15 || abs(tilt) > 10) {
    stopMotors();
    Serial.println("Emergency Stop Triggered!");
  } else {
    moveForward(180);
  }
  delay(100);
}
