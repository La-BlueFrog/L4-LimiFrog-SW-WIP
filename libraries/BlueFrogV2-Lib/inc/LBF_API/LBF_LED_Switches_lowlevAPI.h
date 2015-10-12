/*******************************************************************************
 * LBF_LED_Switches_lowlevAPI.h
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
#ifndef __LBF_LED_SW_LOWLEVAPI_H
#define __LBF_LED_SW_LOWLEVAPI_H

#include "LBF_custom_types.h"   //to be able to use boolean type in function prototype below and keep this header seld-sufficient

/* Exported Macros ------------------------------------------------------- */



/* Exported functions ------------------------------------------------------- */

/* LEDs */
void LBF_Led_ON(void);
void LBF_Led_OFF(void);
void LBF_Led_TOGGLE(void);

/* Switches */
boolean_t LBF_State_Switch1_IsOn(void);
boolean_t LBF_State_Switch2_IsOn(void);

#endif  /*__LBF_LED_SW_LOWLEVAPI_H*/

/***************************************************************END OF FILE****/
