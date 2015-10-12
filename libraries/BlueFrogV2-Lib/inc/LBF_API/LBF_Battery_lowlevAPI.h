/*******************************************************************************
 * LBF_Battery_lowlevAPI.h
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
#ifndef __LBF_BATTERY_LOWLEVAPI_H
#define __LBF_BATTERY_LOWLEVAPI_H



#include <stdint.h>  // to keep this header file self-sufficient as below function prototypes use uint32_t etc.



/* Exported functions ------------------------------------------------------- */

uint32_t LBF_Get_Battery_Voltage_mV(void);



#endif  /*__LBF_BATTERY_LOWLEVAPI_H */


/***************************************************************END OF FILE****/
