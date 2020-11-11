/*!
 * HMIFunctions.cpp - Function Handler between ESP32 & Nextion Display
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com >
 * All rights reserved under the library's licence
 */

#include <arduino.h>
#include <string.h>
#include "NextionSerialString.h"      // Include NextionSerialString
#include "NextionConfig.h"      // Include NextionConfig

/*!
 * Function handler which reads the incoming serial data and hands off to a custom function
 * Separated from NextionSerialString.cpp in order to see code modifications/custom functions more clearly
 */
void NextionSerialString::_handleData(String _serialData){
  if(_serialData != ""){      // Check for blank string
    if(_serialData == "on"){
      digitalWrite(LEDPIN, HIGH);
      _serial->println("Switching the LEDPIN to HIGH");
    }else if(_serialData == "off"){
      digitalWrite(LEDPIN, LOW);
      _serial->println("Switching the LEDPIN to LOW");
    }else{
      // Do nothing
    } 
  }
}
