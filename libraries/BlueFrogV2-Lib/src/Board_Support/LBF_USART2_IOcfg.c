/*************************************************************************
 * LBF_USART2_IOcfg.c
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

#include "LBF_USART2_IOcfg.h"

/*******************************************************************************
* @brief  : Initialize & configure pins for USART2 alternate function
* Input          : None.
* Return         : None.
*******************************************************************************/

void LBF_USART2_IOcfg (void)
{
//Based on Cube MX

GPIO_InitTypeDef GPIO_InitStruct;

    /* Peripheral clock enable */
//    __USART2_CLK_ENABLE();
  
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    PA4     ------> USART2_CK 
    */
/*
    GPIO_InitStruct.Pin = USART2_TX_PIN|USART2_RX_PIN|USART2_CK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL; //but HAL user manual says pull-up
    GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
*/

  // Set as Floating Inputs
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Pin = USART2_TX_PIN|USART2_RX_PIN|USART2_CK_PIN;
  HAL_GPIO_Init(USART2_PORT, &GPIO_InitStruct);



}

/***************************************************************END OF FILE****/
