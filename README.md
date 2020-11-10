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

## The Main Functions
- `begin();`
- `listen();`

## 4(?) Step Example

### NextionConfig.h

1. Define the each of the parameters according to your preferred settings
````Cpp
#define nexSerial Serial2     // Define serial communication channel
#define baud 115200     // Define baud rate. esp32 uses a baud rate of 115200
#define RX 16     // Define receiving data pin (RX)
#define TX 17     // Define transmission data pin (TX)
````
### *.ino

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

1. ** Create any custom function from this point on to read the incoming serial data
````Cpp
_serial->println(_serialData);      // Prints the string data received from the Nextion
[ put your code here !!!!]
````

Enjoy the NextionSerialString Library!! :)
