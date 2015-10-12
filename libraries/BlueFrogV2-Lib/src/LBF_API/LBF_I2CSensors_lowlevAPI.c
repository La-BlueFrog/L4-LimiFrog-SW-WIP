/*******************************************************************************
 * LBF_I2CSensors_lowlevAPI.c
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



/* Functions -----------------------------------------------------------------*/


/*******************************************************************************
 * @brief  : Write a value in one register of peripheral IC using I2C protocoal.
 * @param  : RegAdd = Register Address (or name alias)
 *           RegVal: value to write.
 * @return : none.
 ******************************************************************************/
void LBF_I2CSensors_WriteSingleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t RegVal)
{

uint16_t MemAddSize = I2C_MEMADD_SIZE_8BIT;


/*****   ATTENTION   ATTENTION    ATTENTION   ATTENTION   ATTENTION   ********/
/*****  The "7-bit device address that HAL expects is actually the    ********/
/*****  8-bit I2C write address (i.e. shift left by one bit, pad a 0) !!! ****/

    //VL6180X uses 16-bit register addressing, other sensors on board use 8 bit
    if (ChipID==VL6180X_CHIPID)
    {
        MemAddSize = I2C_MEMADD_SIZE_16BIT;
    }

    // I2C2, blocking write into 1 register with 1s timeout
    // (hi2c2 is global)
    HAL_I2C_Mem_Write( &hi2c2, (uint16_t) (ChipID<<1), RegAdd,  
                               MemAddSize, &RegVal, 0x1, 1000) ;

}

/*******************************************************************************
 * @brief  : Write values in succesive registers of peripheral IC using I2C protocoal.
 * @param  : RegAdd = Initial Register Address (or name alias) -- autoincremented
 *           pVal: pointer to array of values to write
 *           Nb: number of successive registers to write
 * @return : none.
 ******************************************************************************/
void  LBF_I2CSensors_WriteMultipleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t* pVal, uint16_t NumByteToWrite )
{

uint16_t MemAddSize = I2C_MEMADD_SIZE_8BIT;

/*****   ATTENTION   ATTENTION    ATTENTION   ATTENTION   ATTENTION   ********/
/*****  The "7-bit device address that HAL expects is actually the    ********/
/*****  8-bit I2C write address (i.e. shift left by one bit, pad a 0) !!! ****/

    //VL6180X uses 16-bit register addressing, other sensors on board use 8 bit
    if (ChipID==VL6180X_CHIPID)
    {
        MemAddSize = I2C_MEMADD_SIZE_16BIT;
    }

    // I2C2, blocking write into 'Nb' successive registers with 1s timeout
    // (hi2c2 is global)
    HAL_I2C_Mem_Write( &hi2c2, (uint16_t) (ChipID<<1), RegAdd,  
                               MemAddSize, pVal, NumByteToWrite, 1000) ;
  
}


/*******************************************************************************
 * @brief  : Read a value from one register of peripheral IC using I2C protocoal.
 * @param  : RegAdd = Register Address (or name alias)
 * @return : register contents.
 ******************************************************************************/
uint8_t LBF_I2CSensors_ReadSingleReg (uint8_t ChipID, uint16_t RegAdd)
{

uint8_t RegVal = 0;
uint16_t MemAddSize = I2C_MEMADD_SIZE_8BIT;


/*****   ATTENTION   ATTENTION    ATTENTION   ATTENTION   ATTENTION   ********/
/*****  The "7-bit device address that HAL expects is actually the    ********/
/*****  8-bit I2C write address (i.e. shift left by one bit, pad a 0) !!! ****/

    //VL6180X uses 16-bit register addressing, other sensors on board use 8 bit
    if (ChipID==VL6180X_CHIPID)
    {
        MemAddSize = I2C_MEMADD_SIZE_16BIT;
    }

    // I2C2, read 1 register in blocking mode with 1s timeout
    // (hi2c2 is global)
    HAL_I2C_Mem_Read( &hi2c2, (uint16_t)(ChipID<<1), RegAdd,
                               MemAddSize, &RegVal, 0x1, 1000);

    return RegVal;
}


/*******************************************************************************
 * @brief  : Read values from successive registers of peripheral IC using I2C protocoal.
 * @param  : RegAdd = Initial Register Address (or name alias)
 *           pVal: pointer to array to store values read
 *           Nb: number of successive registers to read
 * @return : register contents.
 ******************************************************************************/
void LBF_I2CSensors_ReadMultipleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t* pVal, uint16_t NumByteToRead )
{


uint16_t MemAddSize = I2C_MEMADD_SIZE_8BIT;


/*****   ATTENTION   ATTENTION    ATTENTION   ATTENTION   ATTENTION   ********/
/*****  The "7-bit device address that HAL expects is actually the    ********/
/*****  8-bit I2C write address (i.e. shift left by one bit, pad a 0) !!! ****/

    //VL6180X uses 16-bit register addressing, other sensors on board use 8 bit
    if (ChipID==VL6180X_CHIPID)
    {
        MemAddSize = I2C_MEMADD_SIZE_16BIT;
    }

    // I2C2, read 1 register in blocking mode with 1s timeout
    // (hi2c2 is global)
    HAL_I2C_Mem_Read( &hi2c2, (uint16_t)(ChipID<<1), RegAdd,
                               MemAddSize, pVal, NumByteToRead, 1000);

}



/*******************************************************************************
 * @brief  : Read-Modify-Write (not atomic) of one periph register using I2C2
 *           Read the value, modify relevant bits using write mask, write back.
 * @param  : RegAdd = Register Address (or name alias)
 *           RegVal: value to write.
 * @return : none.
 ******************************************************************************/
void LBF_I2CSensors_RmodWSingleReg (uint8_t ChipID, uint16_t RegAdd, uint8_t RegMask, uint8_t RegUpdateVal)
{

uint8_t RegVal = 0;
uint16_t MemAddSize = I2C_MEMADD_SIZE_8BIT;

    //VL6180X uses 16-bit register addressing, other sensors on board use 8 bit
    if (ChipID==VL6180X_CHIPID)
    {
        MemAddSize = I2C_MEMADD_SIZE_16BIT;
    }


    // Read the register
    HAL_I2C_Mem_Read( &hi2c2, (uint16_t)(ChipID<<1), RegAdd,
                               MemAddSize, &RegVal, 0x1, 1000);

    // Update read value according to mask and update bits
    RegVal =  (RegVal & ~(RegMask)) | (RegUpdateVal & RegMask) ;

    // Write back result
    HAL_I2C_Mem_Write( &hi2c2, (uint16_t) (ChipID<<1), (uint16_t) RegAdd,  
                               MemAddSize, &RegVal, 0x1, 1000) ;
  
}



/***************************************************************END OF FILE****/
