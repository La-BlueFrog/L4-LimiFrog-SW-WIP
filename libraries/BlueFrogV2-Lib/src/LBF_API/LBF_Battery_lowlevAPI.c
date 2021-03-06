/*******************************************************************************
 * LBF_Battery_lowlevAPI.c
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



/*******************************************************************************
* Function Name  : LBF_Get_Battery_Voltage_mV
* Description    : Measures voltage supplied by battery.
* Return         : Measured voltage in millivolt
*******************************************************************************/
uint32_t LBF_Get_Battery_Voltage_mV(void)
{

uint32_t  ADC_ConvertedValue, Vbat_mV;

    // --- Set-up ADC for single-shot conversion of single channel  --------

    LBF_ADC1_Init_Single_Shot();

    LBF_ADC1_Init_Single_Channel( ADC_CHANNEL_11 );  
	// Vbat is present on STM32 IO pin that goes to ADC Channel 11


    // --- Perform Measurement  ---------------------------------------------

    // Enable Battery measurement (active low)
    GPIO_LOW(BATT_PORT, BATT_MEAS_ENB_PIN);

    ADC_ConvertedValue = LBF_ADC1_Get_Value_Single_Shot();
   
    // Disable Battery measurement  (saves power)
    GPIO_HIGH(BATT_PORT, BATT_MEAS_ENB_PIN);

    // Deinit ADC -- which disables ADC clock (to save power)
    LBF_ADC1_Deinit();


    // --- Return Result  ---------------------------------------------
    
    Vbat_mV = (ADC_ConvertedValue * 293 * 14) / 4096;
    // as Vbat goes to 12-bit ADC through 10K/(4+10K) divider with 2.93V nominal reference voltage


    return( Vbat_mV );

}




/***************************************************************END OF FILE****/
