/*******************************************************************************
 * LBF_I2C2_IOcfg.c

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

#include "LBF_I2C2_IOcfg.h"


/* Functions -----------------------------------------------------------------*/

/*******************************************************************************
 * @brief  : Initialize & configure pins for I2C  #2.
 * @param  : Aucun.
 * @return : Rien.
 ******************************************************************************/
void LBF_I2C2_IOcfg (void)
{
GPIO_InitTypeDef GPIO_InitStruct;


    /* Peripheral clock enable */
     __I2C2_CLK_ENABLE();
  
  
    /**I2C2 GPIO Configuration    
    PB10     ------> I2C2_SCL
    PB11     ------> I2C2_SDA 
    */
    GPIO_InitStruct.Pin = I2C2_SCL_PIN|I2C2_SDA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
    HAL_GPIO_Init(I2C2_PORT, &GPIO_InitStruct) ;

}


/***************************************************************END OF FILE****/
