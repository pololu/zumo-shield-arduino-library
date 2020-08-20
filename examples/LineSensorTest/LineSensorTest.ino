/*
This example is designed to be run an Arduino that is connected
to a Zumo Reflectance Sensor Array through a Zumo Shield.

This example shows how to read the raw values from the six line
sensors on the array.  It is useful if you are having trouble
with the sensors or just want to characterize their behavior.

The raw (uncalibrated) values are reported to the serial monitor,
You can press the user pushbutton to toggle whether the IR
emitters are on during the reading.
*/

#include <Wire.h>
#include <ZumoShield.h>

ZumoReflectanceSensorArray reflectanceSensors;
Pushbutton button(ZUMO_BUTTON);

// Define an array for holding sensor values.
#define NUM_SENSORS 6
uint16_t sensorValues[NUM_SENSORS];

bool useEmitters = true;

uint8_t selectedSensorIndex = 0;

void setup()
{
  reflectanceSensors.init();
}

// Prints a line with all the sensor readings to the serial
// monitor.
void printReadingsToSerial()
{
  char buffer[80];
  sprintf(buffer, "%4d %4d %4d %4d %4d %4d %c\n",
    sensorValues[0],
    sensorValues[1],
    sensorValues[2],
    sensorValues[3],
    sensorValues[4],
    sensorValues[5],
    useEmitters ? 'E' : 'e'
  );
  Serial.print(buffer);
}

void loop()
{
  static uint16_t lastSampleTime = 0;

  if ((uint16_t)(millis() - lastSampleTime) >= 100)
  {
    lastSampleTime = millis();

    // Read the reflectance sensors.
    reflectanceSensors.read(sensorValues, useEmitters ? QTR_EMITTERS_ON : QTR_EMITTERS_OFF);

    // Send the results to the serial monitor.
    printReadingsToSerial();
  }

  // If the user pushbutton is pressed, toggle the state of the
  // emitters.
  if (button.getSingleDebouncedPress())
  {
    useEmitters = !useEmitters;
  }
}
