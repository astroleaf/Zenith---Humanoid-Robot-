#include "Arduino.h"

#define BATTERY_PIN A2
#define LOW_BATTERY_THRESHOLD 3.3

float readBatteryVoltage() {
  int val = analogRead(BATTERY_PIN);
  float voltage = val * (5.0 / 1023.0) * 2; // voltage divider
  return voltage;
}

void monitorBattery() {
  float voltage = readBatteryVoltage();
  if (voltage < LOW_BATTERY_THRESHOLD) {
    Serial.println("Warning: Low battery voltage!");
  }
}
