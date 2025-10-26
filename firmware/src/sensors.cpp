#include "Arduino.h"
#include "sensor_driver.h"

#define TRIG 2
#define ECHO 3
#define TEMP_SENSOR A0

void initSensors() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TEMP_SENSOR, INPUT);
}

int getUltrasonicDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

float getTemperature() {
  int val = analogRead(TEMP_SENSOR);
  float voltage = val * 5.0 / 1024.0;
  float tempC = (voltage - 0.5) * 100;
  return tempC;
}
