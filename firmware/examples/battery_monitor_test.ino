#include "battery_monitor.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  float voltage = readBatteryVoltage();
  Serial.print("Battery Voltage: ");
  Serial.println(voltage);
  delay(2000);
}
