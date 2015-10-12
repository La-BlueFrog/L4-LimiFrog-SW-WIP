/*******************************************************************************
 * LBF_FLASH_IOcfg.c
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

#include "LBF_FLASH_IOcfg.h"


 /* 
 *        +--------------------------------------------------------------+
 *        |                     Pin assignment                           |
 *        +-----------------------------+------------------+-------------+
 *        |  STM32 SPI Pins             | Adesto FLASH     |    Pin      |
 *        +-----------------------------+------------------+-------------+
 *        | FLASH_CS_PIN  - PB7         | ChipSelect(/CS)  |    4        |
 *        | FLASH_SPI_MISO_PIN / MISO   | SerialDataOut(SO)|    8        |
 *        | (VCC)                       | WriteProtect(/WP)|    5        |
 *        |                             | GND              |    7 (0 V)  |
 *        | FLASH_SPI_MOSI_PIN / MOSI   | SerialDataIn(SI) |    1        |
 *        | FLASH_SPI_SCK_PIN / SCK     | SerialClock(SCK) |    2        |
 *        | (VCC)                       | /RESET           |    3        |
 *        |                             | VCC              |    6 (3V)   |
 *        +-----------------------------+------------------+-------------+
 * 
 ******************************************************************************/



/* Privates prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/*******************************************************************************
 * @brief  : Initialise the Adesto Data Flash.
 * @param  : Aucun.
 * @return : Rien.
 ******************************************************************************/
void LBF_FLASH_IOcfg(void)
{

GPIO_InitTypeDef GPIO_InitStruct;

// PB7 = /CS
// Std CMOS output, no pull-up/-down resistor, high speed
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL; 
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;  
  GPIO_InitStruct.Pin = FLASH_CS_PIN;
  HAL_GPIO_Init(FLASH_CS_PORT, &GPIO_InitStruct);


/* Initialise pin in high (inactive) state */
  LBF_FLASH_CS_HIGH();

}





/***************************************************************END OF FILE****/
