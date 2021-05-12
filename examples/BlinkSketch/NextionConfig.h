/*!
 * NextionConfig.h - Configuration Library for Serial Communication between ESP32 & Nextion Display using strings
 * Copyright (c) 2020 Darren Osborne < darren@ozzyimages.com >
 * All rights reserved under the library's licence
 */

// Define library only once
#ifndef NextionConfig_h
#define NextionConfig_h

#include <arduino.h>

#define NEXSERIAL Serial2     // Define serial communication channel
#define BAUD 115200     // Define baud rate. esp32 uses a baud rate of 115200
#define RX 16     // Define receiving data pin (RX)
#define TX 17     // Define transmission data pin (TX)
#define LEDPIN 4     // Define a gpio output pin for testing a led

#endif
