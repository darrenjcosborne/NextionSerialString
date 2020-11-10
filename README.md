# NextionSerialString

## Description
A simple Nextion HMI library which computes string commands. The library is both a simple and powerful tool, easily modified to meet one’s needs. Designed and tested on the esp32 - however it is compatible with other MCUs.

Feel free to support my work! If you found this code useful and it saved you time and effort, send a small sum of appreciation (to the value you think it is worth)
to my paypal, via this link: (https://paypal.me/ozzyimagesdonate)

## Installation

### First Method
1.  In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries
2.  In the Library Manager you will find a list of libraries that are already installed, or ready for installation.
3.  Search for NextionSerialString using the search bar.
4.  Click on the text area and select the latest version to install.

/*![enter image description here](./extras/media/EasyNextionLibrary_Arduino_Library_Manager.png)*/

### Second Method
1. Download the latest release of the NextionSerial String library.
- From: [https://github.com/darrenjcosborne/NextionSerialString](https://github.com/darrenjcosborne/NextionSerialString)
2. Extract the `.zip` file 
3. Copy the NextionSerialString folder, to: ....\Arduino\libraries\

***NOTE***: `.HMI` files for Nextion Editor are also included in the example folder.
All `.HMIs` are set for 2.8" Basic screens for easier modification to bigger screens.

## A Simple Setup

### NextionConfig.h

1. Define the each of the parameters according to your preferred settings
````Cpp
#define nexSerial Serial2     // Define serial communication channel
#define baud 115200     // Define baud rate. esp32 uses a baud rate of 115200
#define RX 16     // Define receiving data pin (RX)
#define TX 17     // Define transmission data pin (TX)
````
### NextionSerialString.ino

1.  **Include** ***NextionSerialString*** and create an object of `NextionSerialString` class
````Cpp
#include "NextionSerialString.h"      // Include NextionSerialString Library
#include "NextionConfig.h"      // Include NextionConfig
````
2.  **Begin the object** using parameters from NextionConfig.h
````Cpp
NextionSerialString connection(nexSerial, baud, RX, TX);    // Initialise connection object                  
````
3.  **Place** the **begin()** function in the setup
````Cpp
void setup(){
  connection.begin();     // This function must be called to reset the baud rate on the Nextion, to match that of the esp32
}
````
4. **Place** the **listen()** function in the loop.
````Cpp
void loop(){
  connection.listen();      // This function must be called repeatedly to respond to touch events from the Nextion panel
}
````

### GUIFunctions.cpp

1. **Create any custom function** from this point on to read the incoming serial data
````Cpp
_serial->println(_serialData);      // Prints the string data received from the Nextion

/*!
  * Put your code here and create any custom function to read the incoming serial data
  * Utilise the string.h library for optimal efficiency
  */
````

Enjoy the NextionSerialString Library!! :)

## Full Example Code

### NextionConfig.h
````Cpp
/*!
 * NextionConfig.h - Configuration Library for Serial Communication between ESP32 & Nextion Display using strings
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com >
 * All rights reserved under the library's licence
 */

// Define library only once
#ifndef NextionConfig_h
#define NextionConfig_h

#include <arduino.h>

#define nexSerial Serial2     // Define serial communication channel
#define baud 115200     // Define baud rate. esp32 uses a baud rate of 115200
#define RX 16     // Define receiving data pin (RX)
#define TX 17     // Define transmission data pin (TX)

#endif
````

### NextionSerialString.ino
````Cpp
/*!
 * NextionSerialString.ino - Ozzy Images NextionSerialString Simple Example Code
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com > 
 * All rights reserved under the library's licence
 */

#include <arduino.h>
#include "NextionSerialString.h"      // Include NextionSerialString
#include "NextionConfig.h"      // Include NextionConfig

NextionSerialString connection(nexSerial, baud, RX, TX);    // Create an object of NextionSerialString class with the name < connection >

void setup()
{
  connection.begin();       // This function must be called to reset the baud rate on the Nextion, to match that of the esp32
}

void loop()
{  
  connection.listen();        // This function must be called repeatedly to respond to touch events from the Nextion panel
}
````

### HMIFunctions.cpp
````Cpp
/*!
 * HMIFunctions.cpp - Function Handler between ESP32 & Nextion Display
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com >
 * All rights reserved under the library's licence
 */

#include <arduino.h>
#include <string.h>
#include "NextionSerialString.h"      // Include NextionSerialString

/*!
 * Function handler which reads the incoming serial data and hands off to a custom function
 * Separated from NextionSerialString.cpp in order to see code modifications/custom functions more clearly
 */
void NextionSerialString::_handleData(String _serialData){
  if(_serialData != ""){      // Check for blank string
      
    _serial->println(_serialData);      // Prints the string data received from the Nextion

    /*!
     * Put your code here and create any custom function to read the incoming serial data
     * Utilise the string.h library for optimal efficiency
     */

  }
}
````

## Compatibility
* ESP32
* Arduino (assumed)

Tested MCUs:
1. ESP32

## Licence
MIT License

Copyright (c) 2020 darrenjcosborne

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
