/*
 ******************************************************************************

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.

  This library is GP2Y10 dust concentration sensor module

  ******************************************************************************
 */

#ifndef GP2Y10_H_
#define GP2Y10_H_

#include "Arduino.h"


#define		SAMPLE_TIME		280 // us
#define 	SAMPLE_TIME_2	40
#define     PLUSE_TIME		9680


class GP2Y10
{
    public:
        GP2Y10(uint16_t dustPin,uint16_t ledPin,float voltage = 0.5);
        void begin(void);
        void Read(void);

        uint16_t CalculatedConcentration(void);

    private:
        uint16_t _dustPin;
        uint16_t _ledPin;
        uint32_t dustVoltage;
        float refVoltage;

};


#endif
