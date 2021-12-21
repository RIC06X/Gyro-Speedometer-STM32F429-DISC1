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

#ifndef __SDRAM_DISCO_F429ZI_H
#define __SDRAM_DISCO_F429ZI_H

#ifdef TARGET_DISCO_F429ZI

#include "mbed.h"
#include "stm32f429i_discovery_sdram.h"

/*
 Class used to drive the IS42S16400J SDRAM memory mounted on STM32F429I-Discovery board.

 Usage:

#include "mbed.h"
#include "SDRAM_DISCO_F429ZI.h"

SDRAM_DISCO_F429ZI sdram;

#define BUFFER_SIZE         ((uint32_t)0x0100)
#define WRITE_READ_ADDR     ((uint32_t)0x0800)

int main()
{
    uint32_t WriteBuffer[BUFFER_SIZE];

    // Fill buffer...

    // Write buffer
    sdram.WriteData(SDRAM_DEVICE_ADDR + WRITE_READ_ADDR, WriteBuffer, BUFFER_SIZE);

    while(1)
    {
    }
}

*/
class SDRAM_DISCO_F429ZI
{

public:
    //! Constructor
    SDRAM_DISCO_F429ZI();

    //! Destructor
    ~SDRAM_DISCO_F429ZI();

    /**
      * @brief  Initializes the SDRAM device.
      * @param  None
      * @retval None
      */
    void Init(void);

    /**
      * @brief  Programs the SDRAM device.
      * @param  RefreshCount: SDRAM refresh counter value
      * @retval None
      */
    void Initialization_sequence(uint32_t RefreshCount);

    /**
      * @brief  Reads an mount of data from the SDRAM memory in polling mode.
      * @param  uwStartAddress : Read start address
      * @param  pData : Pointer to data to be read
      * @param  uwDataSize: Size of read data from the memory
      * @retval None
      */
    void ReadData(uint32_t uwStartAddress, uint32_t *pData, uint32_t uwDataSize);

    /**
      * @brief  Reads an mount of data from the SDRAM memory in DMA mode.
      * @param  uwStartAddress : Read start address
      * @param  pData : Pointer to data to be read
      * @param  uwDataSize: Size of read data from the memory
      * @retval None
      */
    void ReadData_DMA(uint32_t uwStartAddress, uint32_t *pData, uint32_t uwDataSize);

    /**
      * @brief  Writes an mount of data to the SDRAM memory in polling mode.
      * @param  uwStartAddress : Write start address
      * @param  pData : Pointer to data to be written
      * @param  uwDataSize: Size of written data from the memory
      * @retval None
      */
    void WriteData(uint32_t uwStartAddress, uint32_t *pData, uint32_t uwDataSize);

    /**
      * @brief  Writes an mount of data to the SDRAM memory in DMA mode.
      * @param  uwStartAddress : Write start address
      * @param  pData : Pointer to data to be written
      * @param  uwDataSize: Size of written data from the memory
      * @retval None
      */
    void WriteData_DMA(uint32_t uwStartAddress, uint32_t *pData, uint32_t uwDataSize);

    /**
      * @brief  Sends command to the SDRAM bank.
      * @param  SdramCmd: Pointer to SDRAM command structure
      * @retval HAL status
      */
    uint8_t Sendcmd(FMC_SDRAM_CommandTypeDef *SdramCmd);

private:

};

#else
#error "This class must be used with DISCO_F429ZI board only."
#endif // TARGET_DISCO_F429ZI

#endif
