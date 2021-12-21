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

#include "GYRO_DISCO_F429ZI.h"

// Constructor
GYRO_DISCO_F429ZI::GYRO_DISCO_F429ZI()
{
    BSP_GYRO_Init();
}

// Destructor
GYRO_DISCO_F429ZI::~GYRO_DISCO_F429ZI()
{

}

//=================================================================================================================
// Public methods
//=================================================================================================================

uint8_t GYRO_DISCO_F429ZI::Init(void)
{
    return BSP_GYRO_Init();
}

uint8_t GYRO_DISCO_F429ZI::ReadID(void)
{
    return BSP_GYRO_ReadID();
}

void GYRO_DISCO_F429ZI::Reset(void)
{
    BSP_GYRO_Reset();
}

void GYRO_DISCO_F429ZI::ITConfig(GYRO_InterruptConfigTypeDef *pIntConfig)
{
    BSP_GYRO_ITConfig(pIntConfig);
}

void GYRO_DISCO_F429ZI::EnableIT(uint8_t IntPin)
{
    BSP_GYRO_EnableIT(IntPin);
}

void GYRO_DISCO_F429ZI::DisableIT(uint8_t IntPin)
{
    BSP_GYRO_DisableIT(IntPin);
}

void GYRO_DISCO_F429ZI::GetXYZ(float *pfData)
{
    BSP_GYRO_GetXYZ(pfData);
}

//=================================================================================================================
// Private methods
//=================================================================================================================
