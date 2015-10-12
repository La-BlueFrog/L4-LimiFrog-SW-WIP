/*******************************************************************************
 * LBF_UART_lowlevAPI.h
 * 
 * Author: La BlueFrog, 2015
 *
 * This program is free software; you can redistribute it and/or modify
 * t under the terms of the GNU General Public License as published by
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LBF_UART_LOWLEVAPI_H
#define __LBF_UART_LOWLEVAPI_H


/* Constants        ---------------------------------------------------------*/

// For UART software flow control
#define  XON   0x13
#define  XOFF  0x11

/* Custom Types      ---------------------------------------------------------*/
typedef enum {
  UART1 = 1,
  UART3 = 3
}    
UartID_t;


/* Exported functions ------------------------------------------------------- */

void LBF_UART_SendByte (UartID_t Uart_ID, uint8_t data);
uint8_t LBF_UART_ReceiveByte (UartID_t Uart_ID);
void LBF_UART_SendString(UartID_t Uart_ID, char* pString);
void LBF_UART_SendString_SwFlowControl(UartID_t Uart_ID, char* pString);
 
#endif  /*__LBF_UART_LOWLEVAPI_H*/

/***************************************************************END OF FILE****/
