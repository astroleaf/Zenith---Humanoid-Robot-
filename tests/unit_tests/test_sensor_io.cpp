#include "sensor_driver.h"
#include <Arduino.h>

int main() {
  Serial.begin(115200);
  initSensors();
  for (int i = 0; i < 10; i++) {
    int dist = getUltrasonicDistance();
    Serial.print("Distance: ");
    Serial.println(dist);
    delay(500);
  }
  return 0;
}
