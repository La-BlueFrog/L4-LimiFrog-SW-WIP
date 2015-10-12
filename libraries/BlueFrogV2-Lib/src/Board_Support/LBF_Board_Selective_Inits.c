/*******************************************************************************
 * LBF_Board_Seelective_Inits.c
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


#include "LBF_Board_Selective_Inits.h"

#include "LBF_lowlev_API.h"

#include "LBF_Conn_Cfg_UserDefd.h"  

#include "LBF_UART1_Init.h"
#include "LBF_BTLE_Init.h"

//#include "LBF_Interrupts_Cfg.h"

#include "LBF_OLED_Init.h"

#include "User_Configuration.h"

#include "Debug_Utilities.h" 


/* Functions -----------------------------------------------------------------*/


/*******************************************************************************/



void LBF_Board_Selective_Inits(void) 
{

/******************************************************************
 * Actions performed by following functions 
 * depend on ifdef statements either here or in function code;
 * These examine the value of configuration paramaters set
 * by user through #define in User_Configuration.h   
 *****************************************************************/


/* ------- Configurations and inits for external connector  ---- */
/* --       as required according to user settings          ---- */
/* --       defined in his own file "User_Configuration.h"  ---- */

    LBF_Conn_Cfg_UserDefd();


/* --------  OLED Screen  --------------------------------------  */


#ifdef  USE_OLED  // (defined in User_Configuration.h)
    LBF_OLED_Init(NULL);  
    //sets up OLED with default config - screen not yet powered here
#endif


/* --------  BlueTooth Low-Energy Module   ---------------------  */

#ifdef ENABLE_BTLE   // defined in User_Configuration.h
boolean_t Success;

    LBF_UART1_Init(57600);   
        // UART1 is dedicated to BTLE module
        // Baud Rate = 57600 bit/s as this is what PAN1740 uses when 
        //   attempting to boot from UART on its P0_4 and P0_5

    Success = LBF_BTLE_Init(BTLE_CODE_FILENAME);
               /*  BTLE_CODE_FILENAME alias defined in User_Config.h */
	       /* Look for this binary file in File System          */
               /*  (-->Data Flash) and load it into BTLE module     */
    
    // Note:
    // Before returning, LBF_BTLE_Init() updates UART1 Baud Rate
    // with value specified in User_Configuration.h so that UART1
    // is ready to use by application for STM32-BTLE exchanges

    LBF_Led_StopNBlinkOnFalse (Success); 

#endif



/* --------  Interrupt Sources to STM32 + priorities  ----------  */

//    LBF_Interrupts_Cfg();
// Now done through API 


}





/***************************************************************END OF FILE****/
