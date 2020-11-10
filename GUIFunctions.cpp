/*!
 * GUIFunctions.cpp - Function Handler between Nextion Display and ESP32 Chipset
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com >
 * All rights reserved under the library's licence
 */

#include <arduino.h>
#include <string.h>
#include "NextionSerialString.h"

/*!
 * Function handler which reads the incoming serial data and hands off to a custom function
 */
void NextionSerialString::_readData(String _serialData){
  if(_serialData != ""){      // Check for blank string
      
    _serial->print(_serialData);

  }
}
