/*******************************************************************************
 * LBF_ExtIT_lowlevAPI.h
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LBF_EXTIT_LOWLEVAPI_H
#define __LBF_EXTIT_LOWLEVAPI_H


/* Custom Types      ---------------------------------------------------------*/
typedef enum {
  FALLING = 0,
  RISING = 1
}    
IT_Polarity_t;

/* Exported functions ------------------------------------------------------- */

void LBF_Enable_ExtIT( GPIO_TypeDef* GPIO_Port, uint16_t  GPIO_Pin, IT_Polarity_t  IT_Polarity );
void LBF_Disable_ExtIT( GPIO_TypeDef* GPIO_Port, uint16_t  GPIO_Pin );


#endif  /*__LBF_EXTIT_LOWLEVAPI_H*/

/***************************************************************END OF FILE****/
