/*******************************************************************************
 * LBF_LED+Switches_IOcfg.c
 * 
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

#include "LBF_LED+Switches_IOcfg.h"



/*******************************************************************************
* Function Name  : Led_Config
* Description    : configure the Read/Write LEDs.
* Input          : None.
* Return         : None.
*******************************************************************************/
void LBF_LED_IOcfg(void)
{
GPIO_InitTypeDef GPIO_InitStruct;

  // Standard output, no pull-up/-down resistor, low speed
  // STM32_LED (PC3)
  GPIO_InitStruct.Pin = STM32_LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(STM32_LED_PORT, &GPIO_InitStruct);

}

/*******************************************************************************
* Function Name  : LBF_SelSwitches_IOcfg
* Description    : Configure the 2 selection switches 
* Input          : None.
* Return         : None.
*******************************************************************************/
void LBF_SelSwitches_IOcfg(void)
{
GPIO_InitTypeDef GPIO_InitStruct;

  // Inputs, need pull-up resistor
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;

  //Slider Switch Position 1: SWITCH1 (PA15)    
  GPIO_InitStruct.Pin = SWITCH1_PIN;
  HAL_GPIO_Init(SWITCH1_PORT, &GPIO_InitStruct);

  //Slider Switch Position 2 SWITCH1 (PC8)    
  GPIO_InitStruct.Pin = SWITCH2_PIN;
  HAL_GPIO_Init(SWITCH2_PORT, &GPIO_InitStruct);


}





/***************************************************************END OF FILE****/
