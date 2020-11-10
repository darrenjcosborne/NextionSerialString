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
      
    _serial->println(_serialData);      // Prints the serial data received from the Nextion

    /*!
     * Put your code here and create any custom function to read the incoming serial data
     * Utilise the string.h library for optimal efficiency
     */

  }
}
