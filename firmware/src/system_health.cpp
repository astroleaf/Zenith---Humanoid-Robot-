#include "Arduino.h"
#include "battery_monitor.h"

void checkSystemHealth() {
  float voltage = readBatteryVoltage();
  if (voltage < 3.3) {
    Serial.println("Warning: Battery voltage critically low!");
    // Add optional emergency stop or alert logic here
  }
}
