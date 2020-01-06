/*
  TMP125.h - Library for reading the TMP125 Temperature sensor
  Created by TurtleForGaming.
  Shared under the GNU General Public License v3.0
*/

#include "Arduino.h"
#include "TMP125.h"
#include "SPI.h"

TMP125::TMP125()
{
}

void TMP125::begin(int SS)
{
	_ss = SS;
	SPI.begin();
	SPI.setBitOrder(MSBFIRST);
}


double TMP125::read()
{
	
  digitalWrite(_ss, LOW);
  delay(1);
  unsigned char v1 = SPI.transfer(0xFF);
  unsigned char v2 = SPI.transfer(0xFF);
  delay(1);
  digitalWrite(_ss, HIGH);
  
  _raw = (B10000000 & v1) << 8 | (B01111111 & v1) << 5 | (B11111111 & v2) >> 2;
  
  _value = _raw * 0.0625f;
  return _value;
}
