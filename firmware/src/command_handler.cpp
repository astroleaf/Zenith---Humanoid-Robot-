#include "Arduino.h"
#include "motor_driver.h"
#include "String.h"

String inputString = "";
bool stringComplete = false;

void processCommand(String command);

void setupCommandHandler() {
  inputString.reserve(200);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

void processCommand(String command) {
  command.trim();
  if (command.startsWith("MOVE_FORWARD")) {
    int speed = command.substring(12).toInt();
    moveForward(speed);
    Serial.println("ACK MOVE_FORWARD");
  } else if (command.startsWith("MOVE_BACKWARD")) {
    int speed = command.substring(13).toInt();
    moveBackward(speed);
    Serial.println("ACK MOVE_BACKWARD");
  } else if (command.startsWith("TURN_LEFT")) {
    int speed = command.substring(9).toInt();
    turnLeft(speed);
    Serial.println("ACK TURN_LEFT");
  } else if (command.startsWith("TURN_RIGHT")) {
    int speed = command.substring(10).toInt();
    turnRight(speed);
    Serial.println("ACK TURN_RIGHT");
  } else if (command.equalsIgnoreCase("STOP")) {
    stopMotors();
    Serial.println("ACK STOP");
  } else {
    Serial.println("ERR UNKNOWN_COMMAND");
  }
}
