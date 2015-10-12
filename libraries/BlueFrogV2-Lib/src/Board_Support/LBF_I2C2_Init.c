/*******************************************************************************
 * LBF_I2C2_Init.c

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

#include "LBF_I2C2_Init.h"


I2C_HandleTypeDef hi2c2;  // global variable used by SPI HAL functions 


/*******************************************************************************
 * @brief  : Initialise et configure le peripherique I2C #2
 * @param  : Aucun.
 * @return : Rien.
 ******************************************************************************/
void LBF_I2C2_Init (void)
{
// Following settings assume I2C2 core clock (=APB1 clock in Default LimiFrog setting)
// is 8MHz and target I2C2 speed is 400KHz
// TODO Find a way to ensure I2C2 clock remains 8MHz if STM32L4 core clock modified

#define I2C2_PRESC	0x0   // tPRESC = (PRESC+1) x tI2C2CLK  -- 0.125us (8MHz)
#define I2C2_SCLL  	0x9   // tSCLL = (SCLL+1) x tPRESC  --  1.25us
#define I2C2_SCLH 	0x3   // tSCLH = (SCLH+1) x tPRESC  --  0.5us
#define I2C2_SDADEL 	0x1   // tSDADEL = SDADEL x tPRESC  -- 0.125us
#define I2C2_SCLDEL	0x3   // tSCLDEL = (SCLDEL+1) x tPRESC  -- 0.5us
// I2C speed: 400KHz,
//  defined by tSCL = tSCLL + tSCLH + tSYNC1 + tSYNC2 ~ 2.5us  (400KHz)
//  where tSYNC1 and tSYNC2 are delays introduced by the analog and/or digital noise filters and resync mechasinsms -- refer to Ref Manual I2C section (I2C master mode)
// SCLDEL defines setup time: SDA stable before SCL rising edge
// SDADEL defines hold time: SDA stable after SCL *falling* edge (as per I2C spec?)


  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = ((uint32_t)I2C2_PRESC ) << 28
		    | ((uint32_t)I2C2_SCLDEL ) << 20
		    | ((uint32_t)I2C2_SDADEL ) << 16
		    | ((uint32_t)I2C2_SCLH ) << 8
		    | ((uint32_t)I2C2_SCLL )  ;
      //Contents of the I2C_TIMINGR_register value
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLED; 
  HAL_I2C_Init(&hi2c2);


}



/***************************************************************END OF FILE****/