/*************************************************************************
 * LBF_Conn_IOcfg_UserDefd.c
 * Author: La BlueFrog, 2015
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
2
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 *************************************************************************/

#include "LBF_lowlev_API.h"
#include "LBF_Conn_Cfg_UserDefd.h"
#include "User_Configuration.h"
#include "LBF_UART3_Init.h"
#include "LBF_I2C1_Init.h"


/*******************************************************************************
* Description  : Configures GPIO connected to header pins 
*                - either as std GPIO or as selected alternate function
* Input          : None.
* Return         : None.
*******************************************************************************/

// Type of interface provided on connector to be defined by user
// See  User_Configuration.h

/* *************************************************************************** 
 * User-definable pins on external connector for La BlueFrog V2
 * For all positions of connector, default is unused  (floating input to STM32)
 *
 * User-definable options are:
 * Position 1 = GPIO PA5 or SPI1_CK
 * Position 2 = GPIO PA6 or SPI1_MISO
 * Position 3 = GPIO PA7 or SPI1_MOSI
 * Position 4 = GPIO PB0 (restricted usage) or MIC_OUT
 * Position 5 = GPIO PC10 or U(S)ART3_TX
 * Position 6 = GPIO PC11 or U(S)ART3_RX
 * Position 7 = GPIO PC12 or USART3_CK  (shared with BTLE GPIO)
 * <  Position 8 = VCC_NUM (3V)  >
 * Position 9 = GPIO_PB8 or I2C1_SCL
 * Position 10= GPIO_PB9 or I2C1_SDA 
 * <  Position 11= GND  > 
 * ***************************************************************************/


void LBF_Conn_Cfg_UserDefd(void)
{

// ***************************************************************************
// POSITIONS 1 to 3 :  SPI1 or GPIO or ....
// ***************************************************************************

// ==== Set up as SPI1 if required, and configure relevant pins  =============
// ====	   This uses parameters defined in User_Configuration.h   ============

// TODO



// ==== Set up as simple GPIO if required, and configure relevant pins  ======
// ====	   This uses parameters defined in User_Configuration.h   ============


// ==== Position 1    (Header Pos.#1 connects to STM32 pin PA5)

#if defined(POS1_IS_GPIO_IN) || defined(POS1_IS_GPIO_IN_PU) || defined(POS1_IS_GPIO_IN_PD) || defined(POS1_IS_GPIO_OUT) || defined(POS1_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos1;
   GPIO_InitStructPos1.Pin = CONN_POS1_PIN;
 #if defined(POS1_IS_GPIO_IN)
   GPIO_InitStructPos1.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos1.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS1_IS_GPIO_IN_PU)
   GPIO_InitStructPos1.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos1.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS1_IS_GPIO_IN_PD)
   GPIO_InitStructPos1.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos1.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS1_IS_GPIO_OUT)
  GPIO_InitStructPos1.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos1.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS1_IS_GPIO_OUT_OD)
  GPIO_InitStructPos1.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos1.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS1_PORT, &GPIO_InitStructPos1); 
#endif


// ==== Position 2    (Header Pos.#2 connects to STM32 pin PA6)

#if defined(POS2_IS_GPIO_IN) || defined(POS2_IS_GPIO_IN_PU) || defined(POS2_IS_GPIO_IN_PD) || defined(POS2_IS_GPIO_OUT) || defined(POS2_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos2;
   GPIO_InitStructPos2.Pin = CONN_POS2_PIN;
 #if defined(POS2_IS_GPIO_IN)
   GPIO_InitStructPos2.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos2.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS2_IS_GPIO_IN_PU)
   GPIO_InitStructPos2.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos2.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS2_IS_GPIO_IN_PD)
   GPIO_InitStructPos2.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos2.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS2_IS_GPIO_OUT)
  GPIO_InitStructPos2.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos2.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS2_IS_GPIO_OUT_OD)
  GPIO_InitStructPos2.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos2.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS2_PORT, &GPIO_InitStructPos2); 
#endif

// ==== Position 3    (Header Pos.#3 connects to STM32 pin PA7)

#if defined(POS3_IS_GPIO_IN) || defined(POS3_IS_GPIO_IN_PU) || defined(POS3_IS_GPIO_IN_PD) || defined(POS3_IS_GPIO_OUT) || defined(POS3_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos3;
   GPIO_InitStructPos3.Pin = CONN_POS3_PIN;
 #if defined(POS3_IS_GPIO_IN)
   GPIO_InitStructPos3.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos3.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS3_IS_GPIO_IN_PU)
   GPIO_InitStructPos3.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos3.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS3_IS_GPIO_IN_PD)
   GPIO_InitStructPos3.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos3.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS3_IS_GPIO_OUT)
  GPIO_InitStructPos3.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos3.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS3_IS_GPIO_OUT_OD)
  GPIO_InitStructPos3.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos3.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS3_PORT, &GPIO_InitStructPos3); 
#endif


// ==== Set up(POS2 and POS3 only) as Timer Outputs if required    ============
// ====   and configure relevant pins                              ============ 
// ====	   This uses parameters defined in User_Configuration.h :  ============


// ==== Position 2    (Header Pos.#2 connects to STM32 pin PA6)

#if defined(POS2_IS_TIM3_CH1)  || defined(POS2_IS_TIM10_CH1) 
GPIO_InitTypeDef GPIO_InitStructPos2;

 #if defined(POS2_IS_TIM3_CH1)  // Timer3, Channel1 (for ex. PWM) on Posn 2 
    GPIO_InitStructPos2.Alternate = GPIO_AF2_TIM3;
 #endif 
 #if defined(POS2_IS_TIM10_CH1)  // Timer10, Channel1 (for ex. PWM) on Posn 2 
    GPIO_InitStructPos2.Alternate = GPIO_AF3_TIM10;
 #endif 

    GPIO_InitStructPos2.Pin = CONN_POS2_PIN;
    GPIO_InitStructPos2.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructPos2.Pull = GPIO_NOPULL;
    GPIO_InitStructPos2.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(CONN_POS2_PORT, &GPIO_InitStructPos2);
#endif  // end (POS2_IS_TIM3_CH1 || POS3_IS_TIM3_CH2)


// ==== Position 3    (Header Pos.#3 connects to STM32 pin PA7)

#if defined(POS3_IS_TIM3_CH2)  || defined(POS3_IS_TIM11_CH1) 
GPIO_InitTypeDef GPIO_InitStructPos3;

 #if defined(POS3_IS_TIM3_CH2)  // Timer3, Channel2 (for ex. PWM) on Posn 3 
    GPIO_InitStructPos3.Alternate = GPIO_AF2_TIM3;
 #endif 
 #if defined(POS2_IS_TIM11_CH1)  // Timer11, Channel1 (for ex. PWM) on Posn 3
    GPIO_InitStructPos3.Alternate = GPIO_AF3_TIM11;
 #endif 

    GPIO_InitStructPos3.Pin = CONN_POS3_PIN;
    GPIO_InitStructPos3.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructPos3.Pull = GPIO_NOPULL;
    GPIO_InitStructPos3.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(CONN_POS3_PORT, &GPIO_InitStructPos3);
#endif  // end (POS3_IS_TIM3_CH2)  || (POS3_IS_TIM11_CH1) 



// ***************************************************************************
// POSITION 4 :   Microphone output - Can be captured on analog input of STM32
// ***************************************************************************

// ==== Set up STM32 Analog Input if required, and configure relevant pins  ==
// ====	   This uses parameters defined in User_Configuration.h   ============

#if defined(POS4_MIC_IS_CAPTURED_BY_STM32)
// TODO
#endif



// ***************************************************************************
// POSITIONS 5 and 6 : UART3 or GPIO or ...
// ***************************************************************************

// ==== Set up as USART3 if required, and configure relevant pins  ===========
// ====	   This uses parameters defined in User_Configuration.h   ============

#if defined(POS5_IS_UART3_TX) || defined(POS6_IS_UART3_RX) 
GPIO_InitTypeDef GPIO_InitStruct_Pos56;

    __USART3_CLK_ENABLE();

    GPIO_InitStruct_Pos56.Pin = 0; 
#ifdef POS5_IS_UART3_TX
    GPIO_InitStruct_Pos56.Pin |= UART3_TX_PIN;
#endif
#ifdef POS6_IS_UART3_RX
    GPIO_InitStruct_Pos56.Pin |= UART3_RX_PIN;
#endif
    GPIO_InitStruct_Pos56.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct_Pos56.Pull = GPIO_PULLUP;
    GPIO_InitStruct_Pos56.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct_Pos56.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(UART3_PORT, &GPIO_InitStruct_Pos56);

    LBF_UART3_Init( UART3_BAUDRATE );

#endif


// ==== Set up as simple GPIO if required, and configure relevant pins  ======
// ====	   This uses parameters defined in User_Configuration.h   ============


// ==== Position 5    (Header Pos.#5 connects to STM32 pin PC10)

#if defined(POS5_IS_GPIO_IN) || defined(POS5_IS_GPIO_IN_PU) || defined(POS5_IS_GPIO_IN_PD) || defined(POS5_IS_GPIO_OUT) || defined(POS5_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos5;
   GPIO_InitStructPos5.Pin = CONN_POS5_PIN;
 #if defined(POS5_IS_GPIO_IN)
   GPIO_InitStructPos5.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos5.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS5_IS_GPIO_IN_PU)
   GPIO_InitStructPos5.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos5.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS5_IS_GPIO_IN_PD)
   GPIO_InitStructPos5.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos5.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS5_IS_GPIO_OUT)
  GPIO_InitStructPos5.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos5.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS5_IS_GPIO_OUT_OD)
  GPIO_InitStructPos5.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos5.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS5_PORT, &GPIO_InitStructPos5); 
#endif

// ==== Position 6    (Header Pos.#6 connects to STM32 pin PC11)

#if defined(POS6_IS_GPIO_IN) || defined(POS6_IS_GPIO_IN_PU) || defined(POS6_IS_GPIO_IN_PD) || defined(POS6_IS_GPIO_OUT) || defined(POS6_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos6;
   GPIO_InitStructPos6.Pin = CONN_POS6_PIN;
 #if defined(POS6_IS_GPIO_IN)
   GPIO_InitStructPos6.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos6.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS6_IS_GPIO_IN_PU)
   GPIO_InitStructPos6.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos6.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS6_IS_GPIO_IN_PD)
   GPIO_InitStructPos6.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos6.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS6_IS_GPIO_OUT)
  GPIO_InitStructPos6.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos6.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS6_IS_GPIO_OUT_OD)
  GPIO_InitStructPos6.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos6.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS6_PORT, &GPIO_InitStructPos6); 
#endif



// ***************************************************************************
// POSITION 7 : GPIO or ...
// ***************************************************************************

// ==== Position 7    (Header Pos.#7 connects to STM32 pin PC12)

#if defined(POS7_IS_GPIO_IN) || defined(POS7_IS_GPIO_IN_PU) || defined(POS7_IS_GPIO_IN_PD) || defined(POS7_IS_GPIO_OUT) || defined(POS7_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos7;
   GPIO_InitStructPos7.Pin = CONN_POS7_PIN;
 #if defined(POS7_IS_GPIO_IN)
   GPIO_InitStructPos7.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos7.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS7_IS_GPIO_IN_PU)
   GPIO_InitStructPos7.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos7.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS7_IS_GPIO_IN_PD)
   GPIO_InitStructPos7.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos7.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS7_IS_GPIO_OUT)
  GPIO_InitStructPos7.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos7.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS7_IS_GPIO_OUT_OD)
  GPIO_InitStructPos7.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos7.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS7_PORT, &GPIO_InitStructPos7); 
#endif



// ***************************************************************************
// POSITION 8 is VDD  (3V)
// ***************************************************************************


// ***************************************************************************
// POSITIONS 9 and 10 : I2C1 or TIMER4 (Channels 3 and 4 - e.g. PWM)  or GPIO or ...
// ***************************************************************************

// ==== Set up as I2C1 if required, and configure relevant pins   ============
// ====	   This uses parameters defined in User_Configuration.h   ============

#if defined(POS9_IS_I2C1_SCL) || defined(POS10_IS_I2C1_SDA) 
GPIO_InitTypeDef GPIO_InitStructPos910;

    __I2C1_CLK_ENABLE();

    GPIO_InitStructPos910.Pin = 0; 
#ifdef POS9_IS_I2C1_SCL
    GPIO_InitStructPos910.Pin |= I2C1_SCL_PIN;
#endif
#ifdef POS10_IS_I2C1_SDA
    GPIO_InitStructPos910.Pin |= I2C1_SDA_PIN;
#endif
    GPIO_InitStructPos910.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStructPos910.Pull = GPIO_NOPULL;
    GPIO_InitStructPos910.Speed = GPIO_SPEED_LOW;
    GPIO_InitStructPos910.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(I2C1_PORT, &GPIO_InitStructPos910);

    LBF_I2C1_Init( I2C1_SPEED );

#endif

// ==== Set up as Timer Outputs (typ. for PWM) from TIMER4         ============
// ==== (channels 3 and 4) if required, and configure relevant pins============   
// ====	   This uses parameters defined in User_Configuration.h :  ============
// ====    POS9_IS_TIM4_CH3, POS9_IS_TIM4_CH4			   ============

#if defined(POS9_IS_TIM4_CH3)  // Timer4, Channel3 (for ex. PWM) on Posn 9 - from STM32 PB8
GPIO_InitTypeDef GPIO_InitStructPos9;
    GPIO_InitStructPos9.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructPos9.Pull = GPIO_NOPULL;
    GPIO_InitStructPos9.Speed = GPIO_SPEED_LOW;
    GPIO_InitStructPos9.Alternate = GPIO_AF2_TIM4;
    GPIO_InitStructPos9.Pin = CONN_POS9_PIN;
    HAL_GPIO_Init(CONN_POS9_PORT, &GPIO_InitStructPos9);
#endif 

#if defined(POS10_IS_TIM4_CH4)  // Timer4, Channel4 (for ex. PWM)  on Posn 10 - from STM32 PB9
GPIO_InitTypeDef GPIO_InitStructPos10;
    GPIO_InitStructPos10.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructPos10.Pull = GPIO_NOPULL;
    GPIO_InitStructPos10.Speed = GPIO_SPEED_LOW;
    GPIO_InitStructPos10.Alternate = GPIO_AF2_TIM4;
    GPIO_InitStructPos10.Pin = CONN_POS10_PIN;
    HAL_GPIO_Init(CONN_POS10_PORT, &GPIO_InitStructPos10);
#endif 



// ==== Set up as simple GPIO if required, and configure relevant pins  ======
// ====	   This uses parameters defined in User_Configuration.h   ============


// ==== Position 9    (Header Pos.#9 connects to STM32 pin PB8)

#if defined(POS9_IS_GPIO_IN) || defined(POS9_IS_GPIO_IN_PU) || defined(POS9_IS_GPIO_IN_PD) || defined(POS9_IS_GPIO_OUT) || defined(POS9_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos9;
   GPIO_InitStructPos9.Pin = CONN_POS9_PIN;
 #if defined(POS9_IS_GPIO_IN)
   GPIO_InitStructPos9.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos9.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS9_IS_GPIO_IN_PU)
   GPIO_InitStructPos9.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos9.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS9_IS_GPIO_IN_PD)
   GPIO_InitStructPos9.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos9.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS9_IS_GPIO_OUT)
  GPIO_InitStructPos9.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos9.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS9_IS_GPIO_OUT_OD)
  GPIO_InitStructPos9.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos9.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS9_PORT, &GPIO_InitStructPos9); 
#endif

// ==== Position 10   (Header Pos.#10 connects to STM32 pin PB9)

#if defined(POS10_IS_GPIO_IN) || defined(POS10_IS_GPIO_IN_PU) || defined(POS10_IS_GPIO_IN_PD) || defined(POS10_IS_GPIO_OUT) || defined(POS10_IS_GPIO_OUT_OD)
GPIO_InitTypeDef GPIO_InitStructPos10;
   GPIO_InitStructPos10.Pin = CONN_POS10_PIN;
 #if defined(POS10_IS_GPIO_IN)
   GPIO_InitStructPos10.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos10.Pull = GPIO_NOPULL;
 #endif
 #if defined(POS10_IS_GPIO_IN_PU)
   GPIO_InitStructPos10.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos10.Pull = GPIO_PULLUP;
 #endif
 #if defined(POS10_IS_GPIO_IN_PD)
   GPIO_InitStructPos10.Mode = GPIO_MODE_INPUT;
   GPIO_InitStructPos10.Pull = GPIO_PULLDOWN;
 #endif
 #if defined(POS10_IS_GPIO_OUT)
  GPIO_InitStructPos10.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructPos10.Speed = GPIO_SPEED_LOW;
 #endif
 #if defined(POS10_IS_GPIO_OUT_OD)
  GPIO_InitStructPos10.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructPos10.Speed = GPIO_SPEED_LOW;
 #endif
  HAL_GPIO_Init(CONN_POS10_PORT, &GPIO_InitStructPos10); 
#endif



// ***************************************************************************

// === TODO same for other posn and periph

}


/***************************************************************END OF FILE****/
