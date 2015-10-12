/*******************************************************************************
 * Services.c
 * 
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


#include "LBF_lowlev_API.h"


/****************
 * @brief  : idle loop for a delay expressed in ms.
 * @param  : nTime - required delay in ms.
 * @return : none.
 ****************/


void LBF_Delay_ms (uint32_t nTime)

/**************************************************************
  Timer-based implementation WITHOUT interrupt 
  to be usable with no issue in ISR
 **************************************************************/
{
    // Use Timer5 ( a 16-bit timer, not usable on external pins) with 1ms resolution- 
    LBF_Timer_Setup( TIMER5, TIMER_UNIT_MS, 0xFFFF);  
	//Counter wrap around at max value

    // Start timer5 (no IT)
    HAL_TIM_Base_Start(&htim5);

    while( __HAL_TIM_GetCounter(&htim5) < nTime);
      // Loop while specified duration not reached
      // TODO - possible issue if loops gets interrupted for over 1ms
      // just when Counter reached target value...

}



/***************************************************************END OF FILE****/
