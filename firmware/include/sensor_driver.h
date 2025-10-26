#ifndef SENSOR_DRIVER_H
#define SENSOR_DRIVER_H

#include <Arduino.h>
void initSensors();
int getUltrasonicDistance();
float getTemperature();

#endif
