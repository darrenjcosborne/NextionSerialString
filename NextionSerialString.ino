/*!
 * NextionSerialString.ino - Ozzy Images NextionSerialString Setup Page
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com > 
 * All rights reserved under the library's licence
 */

#include <arduino.h>
#include "NextionSerialString.h"
#include "NextionConfig.h"

NextionSerialString connection(nexSerial, baud, RX, TX);    // Initialise connection object

void setup()
{
  connection.begin();       // Starts the communication with the Nextion
}

void loop()
{  
  connection.listen();        // Listen for serial communications  
}
