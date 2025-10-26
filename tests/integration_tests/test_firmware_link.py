#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Firmware link test started.");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    Serial.print("Echo: ");
    Serial.println(cmd);
  }
}
