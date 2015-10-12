/*******************************************************************************
 * LBF_SPI3_IOcfg.c
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
 *************************************************************************/


#include "LBF_lowlev_API.h"

#include "LBF_SPI3_IOcfg.h"



/*******************************************************************************
 * @brief  : Configuration of GPIOs used by SPI #3
 * @param  : none.
 * @return : none.
 ******************************************************************************/

void LBF_SPI3_IOcfg(void)
{
GPIO_InitTypeDef GPIO_InitStruct;

    /* Peripheral clock enable */
    __SPI3_CLK_ENABLE();
  
    /**SPI1 GPIO Configuration    
    PB3     ------> SPI3_SCK
    PB4     ------> SPI3_MISO
    PB5     ------> SPI3_MOSI 
    */
    GPIO_InitStruct.Pin = SPI3_SCK_PIN|SPI3_MISO_PIN|SPI3_MOSI_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init(SPI3_PORT, &GPIO_InitStruct);

}





/***************************************************************END OF FILE****/
