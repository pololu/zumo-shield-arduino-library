# Pololu Zumo Shield Arduino library

Version: 2.0.0 <br>
Release date: 2016-??-?? <br>
[![Build Status](https://travis-ci.org/pololu/zumo-shield-arduino-library.svg?branch=master)](https://travis-ci.org/pololu/zumo-shield-arduino-library) <br>
[www.pololu.com](https://www.pololu.com/)

## Summary

This is a collection of libraries for the
[Arduino](https://pololu.com/catalog/product/2191) that interfaces with
the Pololu [Zumo Shield](https://www.pololu.com/catalog/product/2508),
[Zumo Reflectance Sensor Array](https://www.pololu.com/catalog/product/1419),
[Zumo robot kit](https://www.pololu.com/catalog/product/2509), and
[Zumo robot for Arduino](https://www.pololu.com/catalog/product/2510). These
libraries provide functions to help you program an Arduino-controlled
Zumo robot, and the included example projects demonstrate how to use
them for more complex tasks.

For more information about the libraries and examples, please see the
[Zumo Shield user's guide](https://www.pololu.com/docs/0J57).

## Getting started

### Hardware

The Zumo Shield for Arduino can be purchased on Pololu's website:
* **[by itself](https://www.pololu.com/catalog/product/2508)**;
* as part of a
  **[Zumo robot kit for Arduino](https://www.pololu.com/catalog/product/2509)**
  that also includes a
  [Zumo chassis](https://www.pololu.com/catalog/product/1418) and a
  stainless steel
  [Zumo blade](http://www.pololu.com/catalog/product/1410); or
* as a fully-assembled
  **[Zumo robot for Arduino](https://www.pololu.com/catalog/product/2510)**
  with [75:1 HP motors](https://www.pololu.com/catalog/product/2361)
  and a
  [reflectance sensor array](https://www.pololu.com/catalog/product/1419)
  installed.

See the [Zumo Shield user's guide](https://www.pololu.com/docs/0J57) for
more details about purchasing and assembling the hardware.


### Software

If you are using version 1.6.2 or later of the
[Arduino software (IDE)](https://www.arduino.cc/en/Main/Software), you can use
the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then
   "Manage Libraries...".
2. Search for "ZumoShield".
3. Click the ZumoShield entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the
   [latest release archive from GitHub](https://github.com/pololu/zumo-shield-arduino-library/releases)
   and decompress it.
2. Rename the folder "zumo-shield-arduino-library-xxxx" to "ZumoShield".
3. Drag the "ZumoShield" folder into the "libraries" directory inside your
   Arduino sketchbook directory. You can view your sketchbook location by
   opening the "File" menu and selecting "Preferences" in the Arduino IDE. If
   there is not already a "libraries" folder in that location, you should make
   the folder yourself.
4. After installing the library, restart the Arduino IDE.

Some of the examples also require our
[LSM303 library](https://github.com/pololu/lsm303-arduino) to be
installed.


## Library parts

The following sections describe parts of the library that can be
included in your sketch. For example, to include ZumoMotors, you would
add this to the top of your sketch:

~~~{.cpp}
#include <ZumoMotors.h>
~~~

### ZumoMotors

ZumoMotors provides functions for PWM-based speed (and direction)
control of the two motors on the Zumo with the onboard DRV8835 dual
motor driver. On Arduinos with ATmega328P, ATmega168, and ATmega32U4
microcontrollers (which include the Leonardo, Uno, and most older
Arduinos), the motor control functions use hardware PWM outputs from
Timer1 to generate pulse width modulation at a 20 kHz frequency.

If you accidentally soldered a motor to the Zumo Shield backwards
(opposite the orientation indicated in the assembly instructions), you
can simply call `flipLeftMotor(true)` and/or `flipRightMotor(true)` to
make the motors behave consistently with the directions in your code.

### ZumoBuzzer

ZumoBuzzer provides functions that allow various sounds to be played
on the buzzer of the Zumo Shield, from simple beeps to complex tunes.
This library is fully compatible with the OrangutanBuzzer functions in
the [Pololu AVR C/C++ Library](https://www.pololu.com/docs/0J18), so
any melodies written for OrangutanBuzzer functions will also work with
ZumoBuzzer functions.

### Pushbutton

Pushbutton, which can also be found in the
[pushbutton-arduino repository](https://github.com/pololu/pushbutton-arduino),
provides a set of functions that are useful for detecting and
debouncing pushbutton presses. While the most obvious application of
this library is to work with the Zumo Shield's user pushbutton on
digital pin 12, this library can be used as a general-purpose library
for interfacing many types of buttons and switches to an Arduino, even
without a Zumo Shield.

### ZumoReflectanceSensorArray

ZumoReflectanceSensorArray provides a set of functions for reading
reflectance values from a
[Zumo Reflectance Sensor Array](https://www.pololu.com/catalog/product/1419).

The ZumoReflectanceSensorArray class is a subclass of QTRSensorsRC.
The functions provided by QTRSensorsRC can also be used on the
ZumoReflectanceSensorArray class, and are documented in the
[Arduino Library for the Pololu QTR Reflectance Sensors](https://www.pololu.com/docs/0J19)
document on Pololu's website.

### QTRSensors

QTRSensors, which can also be found in the
[qtr-sensors-arduino repository](https://github.com/pololu/qtr-sensors-arduino),
is code for interfacing with
[Pololu QTR reflectance sensors](https://www.pololu.com/catalog/category/123).
Since the
[Zumo Reflectance Sensor Array](https://www.pololu.com/catalog/product/1419)
has the same interface as the QTR RC reflectance sensors, the
ZumoReflectanceSensorArray library uses QTRSensors to read the sensor
array.

## Examples

Several example sketches are available that show how to use the
library. You can access them from the Arduino IDE by opening the
"File" menu, selecting "Examples", and then selecting "ZumoShield". If
you cannot find these examples, the library was probably installed
incorrectly and you should retry the installation instructions above.

The Example Projects section of the
[Zumo Shield user's guide](https://www.pololu.com/docs/0J57) describes
these examples in more detail.

## Version history

* 2.0.0 (2016-??-??):
    * Forked [https://github.com/pololu/zumo-shield](https://github.com/pololu/zumo-shield)
    * Consolidated sub-libraries into one library called ZumoShield.
    * Added Travis CI testing.
    * Updated library to work with the Arduino Library Manager.
* 1.2.3 (2013-11-27): Updated examples to work with LSM303 library version 2.0.0.
* 1.2.2 (2013-10-08): Added SumoCollisionDetect example.
* 1.2.1 (2013-07-19): Added LineFollower example.
* 1.2.0 (2013-06-03): Added ZumoExamples dummy library containing example projects.
* 1.1.3 (2013-05-14): Added CompassExample.
* 1.1.2 (2013-04-18): Pulled in QTRSensors version 2.1.0.
* 1.1.1 (2013-04-17): Added ZumoReflectanceSensorArray constructors with parameters to call init() with and pulled fix from qtr-sensors-arduino 2.0.2.
* 1.1.0 (2013-01-07): Added ZumoReflectanceSensorArray and QTRSensors libraries.
* 1.0.0 (2012-11-09): Original release.
