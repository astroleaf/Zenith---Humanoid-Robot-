#include "pid_controller.h"
#include <Arduino.h>

int main() {
  Serial.begin(115200);
  PIDController pid(1.0, 0.1, 0.05);
  float setpoint = 100;
  float input = 90;
  for(int i=0; i<10; i++) {
    float output = pid.compute(setpoint, input);
    Serial.print("PID output: ");
    Serial.println(output);
    delay(500);
    input += 1.5;
  }
  return 0;
}
