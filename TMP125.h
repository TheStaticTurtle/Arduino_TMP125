/*
  TMP125.h - Library for reading the TMP125 Temperature sensor
  Created by TurtleForGaming.
  Shared under the GNU General Public License v3.0
*/

#ifndef TMP125_h
#define TMP125_h

#include "Arduino.h"
#include "SPI.h"

class TMP125
{
	public:
		TMP125();
		void begin(int SS);
		double read();
	private:
		int _ss;
		int _raw;
		double _value;
};

#endif 
