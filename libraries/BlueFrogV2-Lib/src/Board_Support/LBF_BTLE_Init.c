/*************************************************************************
 * LBF_BTLE_Init.c
 * Author: La BlueFrog, 2015
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
2
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
#include "User_Configuration.h"
#include "LBF_UART1_Init.h"

#include "ff_gen_drv.h" // includes ff.h (and in turn ffconf.h) and diskio.h
#include "DataFlash_diskio.h"

/*******************************************************************************
 * @brief  : Obtain BTLE boot code from storage space and download into BTLE
 * @param  : Name of .bin file containing code for PAN1740 BTLE module
 * @return : True if successful boot, else false.
 ******************************************************************************/

boolean_t  LBF_BTLE_Init(char* FileName)
{

boolean_t	Success = TRUE;

uint8_t		RecvdData;
uint8_t		CodeCRC = 0x00;
uint8_t 	CodeBuffer[16384];	//16K max FOR NOW 
                //TODO support up to 32K - caution SRAM of STM32 is 32K
uint32_t 	ActualCodeSize;
uint32_t 	i;
uint32_t 	StartTime_ms;

boolean_t    Acquire_Code_From_File( char* FileName, 
                                     BYTE* pCodeBuffer, 
				     uint32_t BufferSize,
                                     uint32_t* pActualCodeSize);


    // Acquire Code to Download 
    Success = Acquire_Code_From_File( FileName, CodeBuffer, sizeof(CodeBuffer), &ActualCodeSize );
    if (!Success) // then stop here
    {
        return Success; 
    }

    //Compute CRC = XOR of all code bytes
    for (i=0; i<ActualCodeSize; i++)
    {
	CodeCRC = CodeCRC ^ CodeBuffer[i] ;
    }
    

    // Reset BTLE
    GPIO_HIGH(BT_RST_PORT, BT_RST_PIN); // assert BTLE reset
    LBF_Delay_ms(2); 
    GPIO_LOW(BT_RST_PORT, BT_RST_PIN);  // release BTLE reset


    // Receive 1 byte from UART1 RX - check it's STX=0x02
/*
    Success = (LBF_UART_ReceiveByte(UART1)==0x02);
    if (!Success)  // then stop here
    {
        return Success; 
    }
*/
// See D14580 Boot-from-serial AN: leave up to 146ms (+margin here) for boot-from-serial protocol
    StartTime_ms = HAL_GetTick();
    while ( ((HAL_GetTick()- StartTime_ms) < 200) )
    {
        Success = (LBF_UART_ReceiveByte(UART1)==0x02);
        if (Success)
	   break;
    }
    if (!Success)  // then stop here
    {
        return Success; 
    }

    // Boot start byte well received, 
    // respond according to DA14580 "Boot from Serial i/f" spec 
    LBF_UART_SendByte(UART1, 0x01);  // SOH
    LBF_UART_SendByte(UART1, (uint8_t) (ActualCodeSize &   0xFF) );       // LEN_LSB 
    LBF_UART_SendByte(UART1, (uint8_t)((ActualCodeSize & 0xFF00)>>8)  );  // LEN_MSB

    // Get acknowledge from BTLE
    RecvdData = LBF_UART_ReceiveByte(UART1);
    if ( RecvdData != 0x06)  // ACK=0x06,  NACK=0x15
    {
        Success = FALSE; 
        if (RecvdData != 0x15)  //problem, not a proper NACK
        {
	    //may want to add an error handler here
        }
        return Success;
    }


    // Tx data acknowledged, so :

    // Send all bytes from file over UART 
    for (i=0; i<ActualCodeSize; i++)
    {
	LBF_UART_SendByte( UART1, CodeBuffer[i] );
    }
    

    // Get CRC = XOR over code bytes from DA14580
    if (LBF_UART_ReceiveByte(UART1)!= CodeCRC ) 
    {
        Success = FALSE;
        return Success;
    }

    // Send ACK = 0x06 to DA14580
    LBF_UART_SendByte( UART1, 0x06 );


    LBF_UART1_Init( UART1_BAUDRATE );   
    // Value required by application running on PAN1740, replaces
    // value required when PAN1740 boots from UART on P0_4/5 (no choice there)

    LBF_Delay_ms(6);
    // Found that 4ms (some margin here) latency was needed between code download
    // and start of Tx to DA14580 through UART,
    // else DA1480 does not advertize. 
    // Possible relationship with connection interval / advertizing interval settings ???


    return Success;  


}

/* ========================================================================== */


boolean_t    Acquire_Code_From_File( char* FileName, 
                                     BYTE* pCodeBuffer, 
				     uint32_t BufferSize,
                                     uint32_t* pActualCodeSize)
{

/* --  FatFS Objects     ----------------------------------------  */
FATFS DataFlash_DISK_FatFs; /* File system object for User logical drive */
char DataFlash_DISK_Path[4]; /* User logical drive path */

boolean_t FatFS_Ok = TRUE;
FIL MyFile;
UINT rbytes_count; /* File read counts */



   /* -- Initialize FatFS and Mount DataFlash  ------------- */

    FatFS_Ok &= (FATFS_LinkDriver(&DataFlash_DISK_Driver, DataFlash_DISK_Path) == 0);
    if (FatFS_Ok)
    {
        FatFS_Ok &= 
        ( f_mount(&DataFlash_DISK_FatFs, (TCHAR const*)DataFlash_DISK_Path, 0) == FR_OK);
    }
    

    /* --- Open File and Read it        ------------------- */

    FatFS_Ok &= ( f_open(&MyFile, FileName, FA_OPEN_EXISTING|FA_READ) == FR_OK );
    FatFS_Ok &= ( f_read( &MyFile, pCodeBuffer, BufferSize, &rbytes_count ) == FR_OK);

    /* --- Close File                   ------------------- */
    FatFS_Ok  &=  (f_close(&MyFile) == FR_OK);

    /* --- DeInit                       ------------------- */
    FATFS_UnLinkDriver(DataFlash_DISK_Path);


    *pActualCodeSize = rbytes_count;

    return ( FatFS_Ok );

}




/***************************************************************END OF FILE****/
