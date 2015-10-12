/*************************************************************************
 * LBF_UART3_Init.c
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
#include "LBF_UART3_Init.h"

UART_HandleTypeDef huart3;  // global variable used by  HAL functions 



/*******************************************************************************
* Description  : Configures GPIO connected to header pins - either as std GPIO or as selected alternate function
* Input          : None.
* Return         : None.
*******************************************************************************/

void LBF_UART3_Init (uint32_t BaudRate)
{
// Based on Cube MX

  huart3.Instance = USART3;
  huart3.Init.BaudRate = BaudRate;  
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart3);

}

/***************************************************************END OF FILE****/
