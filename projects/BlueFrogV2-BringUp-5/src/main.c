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
    // LBF_Delay_ms(1000);
    // Success &= LBF_LaunchUSB_MassStorage();
 
    /* ... To initialize FatFS                                      */
    /*     and mount the Data Flash as FAT File System              */
    // Success &= LBF_FatFS_Init();

    /* ... To initialize the STemWin Graphical Library              */ 
    /*     Caution: reserves some RAM - keep some for stack/heap    */
    Success &= LBF_emWin_Init();

    // ERROR HANDLER
    /* Replace by your own as wished */
    LBF_Led_StopNBlinkOnFalse (Success);
    	// stops here if one of above inits has failed

    LBF_Led_OFF();



/* ===================================================== */
/* Application Code Below */
/* ===================================================== */


/* ==  User Declarations =============================== */

uint8_t ReadValue;



/* ==  Body     ====================================================== */

    LBF_OLED_Switch_ON();
    // Provide power (13V) to OLED panel, enable display



  /* ---     Check access to ALS/Proximity Sensor : ST VL6180X  --- */

  ReadValue = LBF_I2CSensors_ReadSingleReg(VL6180X_CHIPID, VL6180X_WHOAMI);
  if (ReadValue == VL6180X_WHOAMI_CONTENTS)
  { 
     LBF_OLED_PrintString("VL6180X OK \nWHO_AM_I = ");
  }
  else 
  { 
     LBF_OLED_PrintString("VL6180X FAIL \nReported WHO_AM_I = ");
  }
  LBF_OLED_PrintHex(ReadValue);
  LBF_OLED_PrintString("\n\n");


  /* ---     Check access to Magnetometer :  ST LIS3MDL   -------- */

  ReadValue = LBF_I2CSensors_ReadSingleReg(LIS3MDL_CHIPID, LIS3MDL_WHOAMI);
  if (ReadValue == LIS3MDL_WHOAMI_CONTENTS)
  { 
     LBF_OLED_PrintString("LIS3MDL OK \nWHO_AM_I = ");
  }
  else 
  { 
     LBF_OLED_PrintString("LIS3MDL FAIL \nReported WHO_AM_I = ");
  }
  LBF_OLED_PrintHex(ReadValue);
  LBF_OLED_PrintString("\n\n");


  /* ---     Check access to Accelerometer/Gyro :  ST LSM6DS3  ----- */

  ReadValue = LBF_I2CSensors_ReadSingleReg(LSM6DS3_CHIPID, LSM6DS3_WHOAMI);
  if (ReadValue == LSM6DS3_WHOAMI_CONTENTS)
  { 
     LBF_OLED_PrintString("LSM6DS3 OK \nWHO_AM_I = ");
  }
  else 
  { 
     LBF_OLED_PrintString("LSM6DS3 FAIL \nReported WHO_AM_I = ");
  }
  LBF_OLED_PrintHex(ReadValue);
  LBF_OLED_PrintString("\n\n");


  /* ---     Check access to Pressure/Temp Sensor : ST LPS25H  ----- */

  ReadValue = LBF_I2CSensors_ReadSingleReg(LPS25H_CHIPID, LPS25H_WHOAMI);
  if (ReadValue == LPS25H_WHOAMI_CONTENTS)
  { 
     LBF_OLED_PrintString("LPS25H OK \nWHO_AM_I = ");
  }
  else 
  { 
     LBF_OLED_PrintString("LPS25H FAIL \nReported WHO_AM_I = ");
  }
  LBF_OLED_PrintHex(ReadValue);
  LBF_OLED_PrintString("\n\n");


while(1);

}


/***************************************************************END OF FILE****/
