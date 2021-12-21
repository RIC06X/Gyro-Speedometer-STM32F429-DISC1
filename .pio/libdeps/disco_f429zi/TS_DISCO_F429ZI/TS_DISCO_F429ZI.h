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

#ifndef __TS_DISCO_F429ZI_H
#define __TS_DISCO_F429ZI_H

#ifdef TARGET_DISCO_F429ZI

#include "mbed.h"
#include "stm32f429i_discovery_ts.h"

/*
  This class drives the touch screen module of the LCD display
  present on DISCO_F429ZI board.

  Usage:

  #include "mbed.h"
  #include "TS_DISCO_F429ZI.h"

  TS_DISCO_F429ZI ts;

  DigitalOut led1(LED1);

  int main()
  {
      TS_StateTypeDef TS_State;
    
      ts.Init(420, 272);
    
      while(1)
      {
        ts.GetState(&TS_State);
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 240))
        {
          led1 = 1;
        }
        else
        {
          led1 = 0;
        }
      }
  }
*/
class TS_DISCO_F429ZI
{
  
public:
  //! Constructor
  TS_DISCO_F429ZI();

  //! Destructor
  ~TS_DISCO_F429ZI();

  /**
    * @brief  Initializes and configures the touch screen functionalities and 
    *         configures all necessary hardware resources (GPIOs, clocks..);.
    * @param  XSize: The maximum X size of the TS area on LCD
    * @param  YSize: The maximum Y size of the TS area on LCD  
    * @retval TS_OK: if all initializations are OK. Other value if error.
    */
  uint8_t Init(uint16_t XSize, uint16_t YSize);

  /**
    * @brief  Configures and enables the touch screen interrupts.
    * @param  None
    * @retval TS_OK: if ITconfig is OK. Other value if error.
    */
  uint8_t ITConfig(void);

  /**
    * @brief  Gets the TS IT status.
    * @param  None
    * @retval Interrupt status.
    */  
  uint8_t ITGetStatus(void);

  /**
    * @brief  Returns status and positions of the touch screen.
    * @param  TsState: Pointer to touch screen current state structure
    * @retval None.
    */
  void GetState(TS_StateTypeDef* TsState);

  /**
    * @brief  Clears all touch screen interrupts.
    * @param  None
    * @retval None
    */  
  void ITClear(void);
  
private:

};

#else
#error "This class must be used with DISCO_F429ZI board only."
#endif // TARGET_DISCO_F429ZI

#endif   
