/*******************************************************************************
 * main.c
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


#include "LBF_Global.h"
#include "User_Configuration.h"


/*******************************************************************************
* Function Name  : main.
* Description    : Main routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int main(void)
{

boolean_t  Success = TRUE;

/* ================================================================ */
/* Board Initializations and Configurations except OLED             */
/* (clocks, I/Os, on-chip peripherals, on-board ICs)                */
/* ================================================================ */

   LBF_Board_Fixed_Inits();
   LBF_Board_Selective_Inits(); 
             // actions driven by User_Configuration.h

   LBF_Led_ON();


/* ================================================================ */
/* Optional initialization of Middleware libraries :                */
/* USBD drivers, FatFS File System, STemWin GUI                     */
/* ================================================================ */

    // UNCOMMENT AS NEEDED:
    // (refer to INFO.txt for details on actions performed)

    /* ... To use La BlueFrog as USB Mass Storage (Full Speed)      */
//  Success &= LBF_LaunchUSB_MassStorage();
//    LBF_Delay_ms(1000);
    /* ... To initialize FatFS                                      */
    /*     and mount the Data Flash as FAT File System              */
    Success &= LBF_FatFS_Init();

    /* ... To initialize the STemWin Graphical Library              */ 
    /*     Caution: reserves some RAM - keep some for stack/heap    */
    // Success &= LBF_emWin_Init();

    // ERROR HANDLER
    /* Replace by your own as wished */
    LBF_Led_StopNBlinkOnFalse (Success);
    	// stops here if one of above inits has failed

    LBF_Led_OFF();


/* ===================================================== */
/* Application Code Below */
/* ===================================================== */


/* ==  User Declarations =============================== */

uint32_t i = 0;

FIL MyFile;
uint32_t wbytes_count; /* File write counts */
uint8_t wtext[] = "This was written into the Data Flash using FatFS\r\n"; /* File write buffer */
uint32_t rbytes_count; /* File read counts */
uint8_t rtext[100]; /* File read buffer */


/* ==  Body     ======================================== */

LBF_Led_ON();

    /* WRITE A TEXT FILE */
    if(f_open(&MyFile, "TOTO.TXT", FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
    {
        if(f_write(&MyFile, wtext, sizeof(wtext)-1, (void *)&wbytes_count) == FR_OK);
        {
           f_close(&MyFile);
        }
    }


    LBF_FatFS_DeInit();


    /* READ BACK FROM TEXT FILE */
    LBF_FatFS_Init();
        if(f_open(&MyFile, "TOTO.TXT", FA_READ) == FR_OK)
        {
            if(f_read(&MyFile, rtext, sizeof(wtext)-1, (void *)&rbytes_count) == FR_OK);
            {
                f_close(&MyFile);
            }
        }
    LBF_FatFS_DeInit();


    /* COMPARE RESULTS */
    if (wbytes_count != rbytes_count)
    {
        Success = FALSE;
    }
    for (i=0; i<rbytes_count; i++)
    {
        if (wtext[i]!=rtext[i])
        {
            Success = FALSE;
        }
    }


    /* Quick Blinking LED if success, else fixed LED */
    while(1)
    {
        if (Success==TRUE)
        {
            LBF_Led_OFF();
        }
        LBF_Delay_ms(100);
        LBF_Led_ON();
        LBF_Delay_ms(30);
     }     


}
 

/***  END OF FILE ************************************************************/    
