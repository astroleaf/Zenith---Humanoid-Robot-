#include "command_handler.h"
#include "motor_driver.h"

void setup() {
  Serial.begin(115200);
  initMotors();
  setupCommandHandler();
  Serial.println("AI Command Demo Ready");
}

void loop() {
  if (stringComplete) {
    processCommand(inputString);
    inputString = "";
    stringComplete = false;
  }
  delay(10);
}
