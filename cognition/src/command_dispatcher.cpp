#include "command_dispatcher.h"
#include <Arduino.h>
 
void sendCommandMoveForward(int speed) {
  Serial.print("MOVE_FORWARD ");
  Serial.println(speed);
}

void sendCommandTurnLeft(int speed) {
  Serial.print("TURN_LEFT ");
  Serial.println(speed);
}

void sendCommandStop() {
  Serial.println("STOP");
}
