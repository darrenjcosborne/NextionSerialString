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
