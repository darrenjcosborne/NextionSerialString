/*!
 * NextionSerialString.cpp - Library for Serial Communication between ESP32 Chipsets & Nextion Displays using strings
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com >
 * All rights reserved under the library's licence
 */

#include <arduino.h>
#include "NextionSerialString.h"

/*!
 * Couples the Nextion to a Serial and passes default values. If the defaults are omitted, 9600 baud and SERIAL_8N1 are used.
 */
NextionSerialString::NextionSerialString(HardwareSerial &serial, uint32_t baud, uint32_t RX, uint32_t TX, uint32_t defaultBaud, uint32_t serialPara){
  _serial = &serial;
  _RX = RX;
  _TX = TX;
  _defaultBaud = defaultBaud;
  _serialPara = serialPara;
  _baud = baud;
}

/*!
 * Starts the communication with the Nextion and sets the baud rate
 */
void NextionSerialString::begin(){
  _serial->begin(_defaultBaud, _serialPara, _RX, _TX);     // Baud rate begin function at default value with selected RX/TX pins
  _triple0xFF();      // Updates the Nextion
  _serial->print("baud=");      // Forward the desired baud rate to the Nextion
  _serial->print(_baud);
  _triple0xFF();      // Updates the Nextion
  delay(100);     // Gives the Nextion time to respond to the update
  _serial->begin(_baud, _serialPara, _RX, _TX);      // Restart the serial at the desired baud rate
  _clear(400UL);      // Clears the serial buffer (time in unsigned long)
}
 
/*!
 * Kicks the local timer 0 that updates the Nextion
 */
void NextionSerialString::_triple0xFF(){
  _serial->write(0xFF);
  _serial->write(0xFF);
  _serial->write(0xFF);
}

/*!
 * Clears the serial buffer using a set time interval
 */
void NextionSerialString::_clear(unsigned long _setTime){
  _timer = millis();      // Set timer to millis()
  while(_serial->available() > 0){      // Read the serial until is is empty (used to clear serial buffer)
    if((millis() - _timer) > _setTime){     // Reading... waiting... but not forever...
      break;
    }
  }
}

/*
 * Placed in main loop. Reads the serial buffer
 */
void NextionSerialString::listen(){
  _serialData = "";     // Initialises serialData String to be blank
  while(_serial->available()){      // Looks for any serial data available
    _serialData += char(_serial->read());     // Reads each byte of serial data and adds this to the _serialData string
  }
  readData(_serialData);     // Sends _serialData to be read
  _serialData = "";      // Resets serialData to be blank
}
