/*******************************************************************************
 * LBF_BATT_IOcfg.c
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

#include "LBF_BATT_IOcfg.h"


/* Privates prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/*******************************************************************************
 * @brief  : Configures IOs used to monitor battery voltage.
 * @param  : None.
 * @return : None.
 ******************************************************************************/
void LBF_BATT_IOcfg(void)
{

GPIO_InitTypeDef GPIO_InitStruct;

// PC7 = BATT_MEAS_ENB (active low)
// Open-drain output, no pull-up/-down resistor, low speed
  GPIO_InitStruct.Pin = BATT_MEAS_ENB_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL; 
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(BATT_PORT, &GPIO_InitStruct); 

// PC1 = BATT_ADC_MEAS_PIN
// Analog input, no pull-up/-down resistor
  GPIO_InitStruct.Pin = BATT_ADC_MEAS_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL; 
  HAL_GPIO_Init(BATT_PORT, &GPIO_InitStruct); 

// Initialise measurement enable pin in high (inactive) state 
  GPIO_HIGH(BATT_PORT, BATT_MEAS_ENB_PIN );

}





/***************************************************************END OF FILE****/
