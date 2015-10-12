/*******************************************************************************
 * LBF_OLED_IOcfg.c
 * 
 * Author: La BlueFrog, 2015
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
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
#include "LBF_OLED_IOcfg.h"
#include "User_Configuration.h"

/* Privates prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/*******************************************************************************
 * @brief  : Initialise et configure le peripherique I2C.
 * @param  : Aucun.
 * @return : Rien.
 ******************************************************************************/
void LBF_OLED_IOcfg (void)
{

GPIO_InitTypeDef GPIO_InitStruct;
 
  // GENERAL: Std CMOS outputs, no pull resistor
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;


  // First, initialize the pin that defines OLED orientation
  // and drives routing of signals inside the routing switch that's in front of the OLED :

  // OLED Orientation :  OLED_UPDOWN = PA1
  // !! External pull-down on this pin
  // !! suitable for OLED facing down (when FPC conn is straight)  
  GPIO_InitStruct.Pin = OLED_UPDOWN_PIN;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(OLED_UPDOWN_PORT, &GPIO_InitStruct);


  // OLED SPI CS, active low:  OLED_CS = PC5
  GPIO_InitStruct.Pin = OLED_CS_PIN;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(OLED_CS_PORT, &GPIO_InitStruct);

  // OLED Parameter&Data (high)/ Command (low) Selection:  OLED_RS = PC4
  GPIO_InitStruct.Pin = OLED_RS_PIN;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(OLED_RS_PORT, &GPIO_InitStruct);
 
  // Reset of OLED drive chip SEPS525, active low:  OLED_RESET = PB1
  GPIO_InitStruct.Pin = OLED_RESET_PIN;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(OLED_RESET_PORT, &GPIO_InitStruct);


  // Initial configuration of NCS, RS, NRESET
  LBF_OLED_RESET_LOW();
  LBF_OLED_RS_HIGH();
  LBF_OLED_CS_HIGH();
  LBF_OLED_RESET_HIGH();



}


/***************************************************************END OF FILE****/
