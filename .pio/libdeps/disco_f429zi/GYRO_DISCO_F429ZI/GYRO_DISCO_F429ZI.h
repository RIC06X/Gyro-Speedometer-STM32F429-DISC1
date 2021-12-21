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

#ifndef __GYRO_DISCO_F429ZI_H
#define __GYRO_DISCO_F429ZI_H

#ifdef TARGET_DISCO_F429ZI

#include "mbed.h"
#include "stm32f429i_discovery_gyroscope.h"

/*
  Class to drive the Gyroscope (L3GD20 device) present on DISCO_F429ZI board.

  Usage:

  #include "mbed.h"
  #include "GYRO_DISCO_F429ZI.h"

  GYRO_DISCO_F429ZI gyro;

  int main()
  {
    float GyroBuffer[3];
    while(1) {
        // Read Gyroscope values
        gyro.GetXYZ(GyroBuffer);
        // Display values
        printf("X = %f\n", GyroBuffer[0]);
        printf("Y = %f\n", GyroBuffer[1]);
        printf("Z = %f\n", GyroBuffer[2]);
        wait(1);
    }
  }
*/
class GYRO_DISCO_F429ZI
{

public:
    //! Constructor
    GYRO_DISCO_F429ZI();

    //! Destructor
    ~GYRO_DISCO_F429ZI();

    /**
      * @brief  Set Gyroscope Initialization.
      * @param  None
      * @retval GYRO_OK if no problem during initialization
      */
    uint8_t Init(void);

    /**
      * @brief  Read ID of Gyroscope component.
      * @param  None
      * @retval ID
      */
    uint8_t ReadID(void);

    /**
      * @brief  Reboot memory content of Gyroscope.
      * @param  None
      * @retval None
      */
    void Reset(void);

    /**
      * @brief  Configures INT1 interrupt.
      * @param  pIntConfig: pointer to a L3GD20_InterruptConfig_TypeDef
      *         structure that contains the configuration setting for the L3GD20 Interrupt.
      * @retval None
      */
    void ITConfig(GYRO_InterruptConfigTypeDef *pIntConfig);

    /**
      * @brief  Enables INT1 or INT2 interrupt.
      * @param  IntPin: Interrupt pin
      *      This parameter can be:
      *        @arg L3GD20_INT1
      *        @arg L3GD20_INT2
      * @retval None
      */
    void EnableIT(uint8_t IntPin);

    /**
      * @brief  Disables INT1 or INT2 interrupt.
      * @param  IntPin: Interrupt pin
      *      This parameter can be:
      *        @arg L3GD20_INT1
      *        @arg L3GD20_INT2
      * @retval None
      */
    void DisableIT(uint8_t IntPin);

    /**
      * @brief  Gets XYZ angular acceleration/
      * @param  pfData: pointer on floating array
      * @retval None
      */
    void GetXYZ(float *pfData);

private:

};

#else
#error "This class must be used with DISCO_F429ZI board only."
#endif // TARGET_DISCO_F429ZI

#endif
