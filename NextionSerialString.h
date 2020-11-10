/*!
 * NextionSerialString.h - Library for Serial Communication between ESP32 Chipsets & Nextion Displays using strings
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com >
 * All rights reserved under the library's licence
 */

// Define library only once
#ifndef NextionSerialString_h
#define NextionSerialString_h

#include <arduino.h>

class NextionSerialString
{
  public:
    // NextionSerialString.cpp
    NextionSerialString(HardwareSerial &serial, uint32_t baud, uint32_t RX, uint32_t TX, uint32_t defaultBaud = 9600, uint32_t serialPara = SERIAL_8N1);      // Builds the default class
    void begin();      // Begins serial communication setup between devices
    void listen();      // Listens for any serial communication from the Nextion
    
  private:
    // NextionSerialString.cpp
    HardwareSerial *_serial;      // Pointer to serial port used
    uint32_t _RX;     // For RX pin definition
    uint32_t _TX;     // For TX pin definition
    uint32_t _defaultBaud;      // Default baud rate = 9600
    uint32_t _serialPara;     // Set to default = SERIAL_8N1
    uint32_t _baud;     // Baud rate to be set
    void _triple0xFF();     // Updates the Nextion
    unsigned long _setTime;     // Wait time for clear function
    unsigned long _timer;     // Timer variable
    void _clear(unsigned long _setTime);      // Clears the serial buffer
    String _serialData;     // Serialdata variable
    
    // GUIFunctions.cpp
    void _readData(String _serialData);     // Function handler which reads the incoming serial data and hands off to a lightbox function
    char _cmd;      // Variable to store the command
    int _strLength;      // Variable to store the string length

};

#endif
