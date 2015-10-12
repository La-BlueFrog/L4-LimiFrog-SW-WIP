/*************************************************************************
 * LBF_USART2_Init.c
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
#include "LBF_USART2_Init.h"

USART_HandleTypeDef husart2;  // global variable used by SPI HAL functions 



/*******************************************************************************
* Description  : Configures GPIO connected to header pins - either as std GPIO or as selected alternate function
* Input          : None.
* Return         : None.
*******************************************************************************/

void LBF_USART2_Init (void)
{
// Based on Cube MX

//Emulate SPI for now
  husart2.Instance = USART2;
  husart2.Init.BaudRate = 2000000; //Max APBclk/16  
  husart2.Init.WordLength = USART_WORDLENGTH_8B; //9 bits for later - 
  husart2.Init.StopBits = USART_STOPBITS_1;
  husart2.Init.Parity = USART_PARITY_NONE;
  husart2.Init.Mode = USART_MODE_TX; //USART_MODE_TX_RX;
  husart2.Init.CLKPolarity = USART_POLARITY_LOW;
  husart2.Init.CLKPhase = USART_PHASE_1EDGE;
  husart2.Init.CLKLastBit = USART_LASTBIT_ENABLE;
  HAL_USART_Init(&husart2);

}

/***************************************************************END OF FILE****/
