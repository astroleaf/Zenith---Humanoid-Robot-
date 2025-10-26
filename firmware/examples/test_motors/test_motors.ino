#include "sensor_driver.h"

void setup() {
  Serial.begin(115200);
  initSensors();
}

void loop() {
  int dist = getUltrasonicDistance();
  float temp = getTemperature();
  Serial.print("Distance (cm): ");
  Serial.print(dist);
  Serial.print(" | Temp (C): ");
  Serial.println(temp);
  delay(500);
}
