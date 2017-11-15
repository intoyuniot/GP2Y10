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

#include "gp2y10.h"

//Specifications Pin
GP2Y10::GP2Y10(uint16_t dustPin,uint16_t ledPin,float voltage)
{
    _dustPin = dustPin;
    _ledPin = ledPin;
    dustVoltage = 0;
    refVoltage = voltage;
}

//This function is called before use
void GP2Y10::begin(void)
{
   pinMode(_dustPin,AN_INPUT);
   pinMode(_ledPin,OUTPUT);
   digitalWrite(_ledPin, HIGH);

}

//Read data
void GP2Y10::Read(void)
{
    digitalWrite(_ledPin,LOW);
    delayMicroseconds(SAMPLE_TIME);
    dustVoltage = analogRead(_dustPin);
    delayMicroseconds(SAMPLE_TIME_2);
    digitalWrite(_ledPin,HIGH);
    delayMicroseconds(PLUSE_TIME);
    //return dustVoltage;
}

//Calculate the concentration
uint16_t GP2Y10::CalculatedConcentration(void) // ug/m^3
{
    Read();
    return (((dustVoltage * 3.3)/4095-refVoltage)/5)*1000;
}
