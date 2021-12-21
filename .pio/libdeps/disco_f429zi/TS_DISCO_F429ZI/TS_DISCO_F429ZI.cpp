/* Copyright (c) 2010-2011 mbed.org, MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software
* and associated documentation files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "TS_DISCO_F429ZI.h"

// Constructor
TS_DISCO_F429ZI::TS_DISCO_F429ZI()
{
  // X = ILI9341_LCD_PIXEL_WIDTH
  // Y = ILI9341_LCD_PIXEL_HEIGHT
  BSP_TS_Init(240, 320);
}

// Destructor
TS_DISCO_F429ZI::~TS_DISCO_F429ZI()
{

}

//=================================================================================================================
// Public methods
//=================================================================================================================

uint8_t TS_DISCO_F429ZI::Init(uint16_t XSize, uint16_t YSize)
{
  return BSP_TS_Init(XSize, YSize);
}

uint8_t TS_DISCO_F429ZI::ITConfig(void)
{
  return BSP_TS_ITConfig();
}

uint8_t TS_DISCO_F429ZI::ITGetStatus(void)
{
  return BSP_TS_ITGetStatus();
}

void TS_DISCO_F429ZI::GetState(TS_StateTypeDef* TsState)
{
  BSP_TS_GetState(TsState);
}

void TS_DISCO_F429ZI::ITClear(void)
{
  BSP_TS_ITClear();
}

//=================================================================================================================
// Private methods
//=================================================================================================================
