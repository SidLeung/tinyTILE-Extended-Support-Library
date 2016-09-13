// Copyright (c) 2016 Intel Corporation.  All rights reserved.
// See the bottom of this file for the license terms.

/*
 *  This sketch is to demonstrate SPI reading from a BMI160 device, as a bus master.  It first makes a request to
 *  read the chip id from the device, the returned chip id should be 0xD1. Then proceed with reading out one byte at a time and dump in onto the serial term
 *  for display, in hex.  The sketch continue doing the above steps.  If the read chip is not 0xD1, please check
 *  the connection to the external device:  verify the signals, make sure the board and the device share a
 *  common ground connection.
 *
 *  Please note:
 *    1. This sketch makes use of ARC_SPI0.  One of the two SPI connections from the ARC core.  For the QUARK core SPI
 *       connection, please refer to the SPI library.
 *    2. The ARC_SPI0 connections are not available in the Arduino 101 hardware platform.
 */

// inslude the SPI library:
#include <ARC_SPI.h>

void setup()
{
  uint8_t dummy_reg = 0x7F;

  Serial.begin(9600);  // start serial for output
  while(!Serial);

  ARC_SPI0.begin(); // initialize SPI:
  ARC_SPI0.transfer(dummy_reg);
}

void loop()
{
  Serial.println("Read the BMI160 chip id, should be 0xD1"); // print the character
  uint8_t chip_id = ARC_SPI1.transfer(0x80);
  Serial.println(chip_id, HEX); // print the character
  delay(1000);
}

/*
   Copyright (c) 2016 Intel Corporation.  All rights reserved.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/
