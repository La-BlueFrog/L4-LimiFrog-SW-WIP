/*******************************************************************************
 * LBF_I2CSensors_lowlevAPI.h
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
#ifndef __LBF_I2CSENSORS_LOWLEVAPI_H
#define __LBF_I2CSENSORS_LOWLEVAPI_H

#include "LBF_custom_types.h"  //to use type boolean_t in below prototype and keep this header file self-sufficient
#include <stdint.h>        //same rationale, to use uint8_t below


//#include "pin_aliases.h"

/* Exported constants --------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */


void LBF_I2CSensors_WriteSingleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t RegVal);
void  LBF_I2CSensors_WriteMultipleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t* pVal, uint16_t NumByteToWrite );

uint8_t LBF_I2CSensors_ReadSingleReg (uint8_t ChipID, uint16_t RegAdd);
void LBF_I2CSensors_ReadMultipleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t* pVal, uint16_t NumByteToRead );

void LBF_I2CSensors_RmodWSingleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t RegMask, uint8_t RegUpdateVal);


#endif  /*__LBF_I2CSENSORS_LOWLEVAPI_H*/

/***************************************************************END OF FILE****/
