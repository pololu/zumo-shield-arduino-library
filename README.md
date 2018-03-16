# Pololu Zumo Shield Arduino library

Version: 2.0.0 <br>
Release date: 2018-03-15 <br>
[![Build Status](https://travis-ci.org/pololu/zumo-shield-arduino-library.svg?branch=master)](https://travis-ci.org/pololu/zumo-shield-arduino-library) <br>
[www.pololu.com](https://www.pololu.com/)

## Summary

This is a library for an
[Arduino-compatible controller](https://www.pololu.com/arduino) that
interfaces with the Pololu
[Zumo Shield](https://www.pololu.com/catalog/product/2508),
[Zumo Reflectance Sensor Array](https://www.pololu.com/catalog/product/1419),
[Zumo robot kit](https://www.pololu.com/catalog/product/2509), and
[Zumo robot for Arduino](https://www.pololu.com/catalog/product/2510). It
provides functions to help you program an Arduino-controlled Zumo
robot, and the included example sketches demonstrate how to use them
for more complex tasks.

For more information about the library and examples, please see the
[Zumo Shield user's guide](https://www.pololu.com/docs/0J57).

Please note that this library does NOT work with the Zumo 32U4 Robot, which is a very different product.  The Zumo 32U4 Robot has an integrated Arduino-compatible microcontroller.  If you have the Zumo 32U4 Robot, then you should not use this library and instead refer to the [Zumo 32U4 Robot documentation](https://www.pololu.com/docs/0J63).

## Getting started

### Hardware

The Zumo Shield for Arduino can be purchased on Pololu's website:
* **[by itself](https://www.pololu.com/catalog/product/2508)**;
* as part of a
  **[Zumo robot kit for Arduino](https://www.pololu.com/catalog/product/2509)**
  that also includes a
  [Zumo chassis](https://www.pololu.com/catalog/product/1418) and a
  stainless steel
  [Zumo blade](https://www.pololu.com/catalog/product/1410); or
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

## Examples

Several example sketches are available that show how to use the
library. You can access them from the Arduino IDE by opening the
"File" menu, selecting "Examples", and then selecting "ZumoShield". If
you cannot find these examples, the library was probably installed
incorrectly and you should retry the installation instructions above.

The Example sketches section of
the [Zumo Shield user's guide](https://www.pololu.com/docs/0J57)
describes some of these examples in more detail.

## Classes

The main classes provided by the library are listed below:

* ZumoMotors
* ZumoBuzzer
* ZumoReflectanceSensorArray

## Component libraries

This library also includes copies of several other Arduino libraries inside it, which are used to help implement the classes and functions above.

* [LSM303](https://github.com/pololu/lsm303-arduino)
* [L3G](https://github.com/pololu/l3g-arduino)
* [PololuBuzzer](https://github.com/pololu/pololu-buzzer-arduino)
* [Pushbutton](https://github.com/pololu/pushbutton-arduino)
* [QTRSensors](https://github.com/pololu/qtr-sensors-arduino)

You can use these libraries in your sketch automatically without any extra installation steps and without needing to add any extra `#include` lines to your sketch.

You should avoid adding extra `#include` lines such as `#include <Pushbutton.h>` because then the Arduino IDE might try to use the standalone Pushbutton library (if you previously installed it), and it would conflict with the copy of the Pushbutton code included in this library.  The only `#include` lines needed to access all features of this library are:

~~~{.cpp}
#include <Wire.h>
#include <ZumoShield.h>
~~~

## Documentation

For complete documentation, see
https://pololu.github.io/zumo-shield-arduino-library. If you are
already on that page, then click on the links in the "Classes and
functions" section above.

## Version history

* 2.0.0 (2018-03-15):
    * Forked [https://github.com/pololu/zumo-shield](https://github.com/pololu/zumo-shield)
    * Consolidated sub-libraries into one library called ZumoShield.
    * Added LSM303 and L3G as component libraries
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
