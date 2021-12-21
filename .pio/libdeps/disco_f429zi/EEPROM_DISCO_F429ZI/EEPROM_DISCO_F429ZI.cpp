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

#include "EEPROM_DISCO_F429ZI.h"

// Constructor
EEPROM_DISCO_F429ZI::EEPROM_DISCO_F429ZI()
{
  BSP_EEPROM_Init();
  BSP_EEPROM_WaitEepromStandbyState();
}

// Destructor
EEPROM_DISCO_F429ZI::~EEPROM_DISCO_F429ZI()
{
}

//=================================================================================================================
// Public methods
//=================================================================================================================

uint32_t EEPROM_DISCO_F429ZI::Init(void)
{
  uint32_t status = BSP_EEPROM_Init();
  if (status == EEPROM_OK) {
    return BSP_EEPROM_WaitEepromStandbyState();
  }
  else {
    return status;
  }
}

uint32_t EEPROM_DISCO_F429ZI::ReadBuffer(uint8_t *pBuffer, uint16_t ReadAddr, uint16_t *NumByteToRead)
{
  return BSP_EEPROM_ReadBuffer(pBuffer, ReadAddr, NumByteToRead);
}

uint32_t EEPROM_DISCO_F429ZI::WritePage(uint8_t *pBuffer, uint16_t WriteAddr, uint8_t *NumByteToWrite)
{
  return BSP_EEPROM_WritePage(pBuffer, WriteAddr, NumByteToWrite);
}

uint32_t EEPROM_DISCO_F429ZI::WriteBuffer(uint8_t *pBuffer, uint16_t WriteAddr, uint16_t NumByteToWrite)
{
  return BSP_EEPROM_WriteBuffer(pBuffer, WriteAddr, NumByteToWrite);
}

uint32_t EEPROM_DISCO_F429ZI::WaitEepromStandbyState(void)      
{
  return BSP_EEPROM_WaitEepromStandbyState();
}

extern I2C_HandleTypeDef EEP_I2cHandle;

/**
  * @brief  This function handles sEE DMA TX interrupt request.
  * @param  None
  * @retval None
  */
void EEPROM_I2C_DMA_TX_IRQHandler(void)
{ 
  HAL_DMA_IRQHandler(EEP_I2cHandle.hdmatx);
}

/**
  * @brief  This function handles sEE DMA RX interrupt request.
  * @param  None
  * @retval None
  */
void EEPROM_I2C_DMA_RX_IRQHandler(void)
{ 
  HAL_DMA_IRQHandler(EEP_I2cHandle.hdmarx);
}
