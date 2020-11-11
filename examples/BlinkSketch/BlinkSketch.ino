/*!
 * BlinkSketch.ino - Ozzy Images NextionSerialString Simple Example Code
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com > 
 * All rights reserved under the library's licence
 */

#include <arduino.h>
#include "NextionSerialString.h"      // Include NextionSerialString
#include "NextionConfig.h"      // Include NextionConfig

NextionSerialString myNextion(NEXSERIAL, BAUD, RX, TX);    // Create an object of NextionSerialString class with the name < myNextion >

void setup(){
  pinMode(LEDPIN, OUTPUT);
  myNextion.begin();       // This function must be called to reset the baud rate on the Nextion, to match that of the esp32
}

void loop(){  
  myNextion.listen();        // This function must be called repeatedly to respond to touch events from the Nextion panel
}
