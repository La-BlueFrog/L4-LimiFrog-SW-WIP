/*******************************************************************************
 * LBF_PWR_lowlevAPI.c
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


/* Static variables:  
   accessible only from this C file and retain their value 
   between different calls of the functions where they're used */
static boolean_t VDDH_On;




/* Functions -----------------------------------------------------------------*/

/*******************************************************************************
 * @brief  : Check whether VDDH to OLED has been enabled on the board
 * @param  : none.
 * @return : TRUE if VDDH is on, else FALSE
 ******************************************************************************/
boolean_t Check_VDDH_On (void)
{
    return VDDH_On;
}

/*******************************************************************************
 * @brief  : Enable generation of VDDH (14V) to OLED on the board 
 * @param  : none.
 * @return : none.
 ******************************************************************************/
void Turn_VDDH_On (void)
{
    GPIO_HIGH(VDDH_EN_PORT, VDDH_EN_PIN);
    VDDH_On = TRUE;
}

/*******************************************************************************
 * @brief  : Disable generation of VDDH to OLED on the board 
 * @param  : xx.
 * @return : xx.
 ******************************************************************************/
void Turn_VDDH_Off (void)
{
    GPIO_LOW(VDDH_EN_PORT, VDDH_EN_PIN);
    VDDH_On = FALSE;
}






/***************************************************************END OF FILE****/
