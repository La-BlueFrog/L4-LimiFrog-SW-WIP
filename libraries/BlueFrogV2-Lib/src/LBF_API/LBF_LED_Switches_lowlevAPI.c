/*******************************************************************************
 * LBF_LED+Switches_lowlevAPI.c
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
 ******************************************************************************/


#include "LBF_lowlev_API.h"



/*******************************************************************************
* Function Name  : Stm32_Led_ON
* Description    : Switched Red LED On.
* Return         : None.
*******************************************************************************/
void LBF_Led_ON(void)
{
    GPIO_HIGH(STM32_LED_PORT, STM32_LED_PIN);
}

/*******************************************************************************
* Function Name  : Stm32_Led_OFF
* Description    : Switched Red LED Off.
* Return         : None.
*******************************************************************************/
void LBF_Led_OFF(void)
{
    GPIO_LOW(STM32_LED_PORT, STM32_LED_PIN);
}

/*******************************************************************************
* Function Name  : Stm32_Led_TOGGLE
* Description    : Toggles Red LED.
* Return         : None.
*******************************************************************************/
void LBF_Led_TOGGLE(void)
{
    GPIO_TOGGLE(STM32_LED_PORT, STM32_LED_PIN);
}




/*******************************************************************************
* Function Name  : Get_Slider_Select1
* Description    : Determines if slider is in position #1.
* Return         : True/False
*******************************************************************************/
boolean_t LBF_State_Switch1_IsOn(void)
{
  return( (HAL_GPIO_ReadPin(SWITCH1_PORT, SWITCH1_PIN)==GPIO_PIN_RESET)? TRUE:FALSE );
}
// Physical switch connects signal to GND when pressed ('on')


/*******************************************************************************
* Function Name  : Get_Slider_Select2
* Description    : Determines if slider is in position #2.
* Return         : True/False
*******************************************************************************/
boolean_t LBF_State_Switch2_IsOn(void)
{
  return( (HAL_GPIO_ReadPin(SWITCH2_PORT, SWITCH2_PIN)==GPIO_PIN_RESET)? TRUE:FALSE );
}
// Physical switch connects signal to GND when pressed ('on')

/***************************************************************END OF FILE****/
