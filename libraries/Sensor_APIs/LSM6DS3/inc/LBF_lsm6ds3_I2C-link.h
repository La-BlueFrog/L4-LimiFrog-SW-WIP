/*******************************************************************************
 * LBF_lsm6ds3_I2C-link.h
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
#ifndef __LBF_LSM6DS3_I2C_LINK_H
#define __LBF_LSM6DS3_I2C_LINK_H


#include "LBF_custom_types.h"  //to use custom type defs below



/* Exported functions ------------------------------------------------------- */

ReturnStatus_t	LSM6DS3_IO_Init(void) ;

void	LSM6DS3_IO_Read( 	uint8_t* pBuffer, 
				uint8_t DeviceAddr, 
				uint8_t RegisterAddr, 
				uint16_t NumByteToRead );

void	LSM6DS3_IO_Write( 
				uint8_t* pBuffer, 
				uint8_t DeviceAddr, 
				uint8_t RegisterAddr, 
				uint16_t NumByteToWrite );


#endif  /*__LBF_LSM6DS3_I2C_LINK_H*/

/***************************************************************END OF FILE****/
