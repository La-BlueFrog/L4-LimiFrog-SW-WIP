/*******************************************************************************
 * LBF_BTLE_IOcfg.c
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

#include "LBF_BTLE_IOcfg.h"


/* Privates prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/*******************************************************************************
 * @brief  : Initialise the Adesto Data Flash.
 * @param  : Aucun.
 * @return : Rien.
 ******************************************************************************/
void LBF_BTLE_IOcfg(void)
{

GPIO_InitTypeDef GPIO_InitStruct;

// PC9 = BT_RST (active high)
// Std CMOS output, no pull-up/-down resistor, low speed
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL; 
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;  
  GPIO_InitStruct.Pin = BT_RST_PIN;
  HAL_GPIO_Init(BT_RST_PORT, &GPIO_InitStruct);


/* Initialise pin in high (active) state */
  GPIO_HIGH(BT_RST_PORT, BT_RST_PIN); // assert BTLE reset

}





/***************************************************************END OF FILE****/
