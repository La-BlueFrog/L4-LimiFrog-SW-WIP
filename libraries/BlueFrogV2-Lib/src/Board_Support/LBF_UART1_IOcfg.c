/*************************************************************************
 * LBF_UART1_IOcfg.c
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

#include "LBF_UART1_IOcfg.h"

/*******************************************************************************
* @brief  : Initialize & configure pins for UART1 alternate function
* Input          : None.
* Return         : None.
*******************************************************************************/

void LBF_UART1_IOcfg (void)
{
//Based on Cube MX

GPIO_InitTypeDef GPIO_InitStruct;

    /* Peripheral clock enable */
    __USART1_CLK_ENABLE();
  
    /**USART1 GPIO Configuration    
    PA9     ------> UART1_TX
    PA10     ------> UART1_RX 
    */
    GPIO_InitStruct.Pin = UART1_TX_PIN|UART1_RX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(UART1_PORT, &GPIO_InitStruct);

}

/***************************************************************END OF FILE****/
