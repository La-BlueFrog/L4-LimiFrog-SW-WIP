/*******************************************************************************
 * LBF_ADC_lowlevAPI.h
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LBF_ADC_LOWLEVAPI_H
#define __LBF_ADC_LOWLEVAPI_H


/* Custom Types      ---------------------------------------------------------*/

typedef enum {    // ADC_CHANNEL_xx are defined in HAL ADC driver
  ADC_CH_1 = ADC_CHANNEL_1,  // channel available on PA5 = Position 1 of extension port
  ADC_CH_6 = ADC_CHANNEL_6,  // channel available on PA6 = Position 2 of extension port
  ADC_CH_7 = ADC_CHANNEL_7,  // channel available on PA7 = Position 3 of extension port
  ADC_CH_8 = ADC_CHANNEL_8,  // channel available on PB0 = Position 4 of extension port
  ADC_CH_11 = ADC_CHANNEL_11  // channel available on PA11 = IO connected to Vbat on the board
}    
ADC1_ChannelID_t;



/* Exported functions ------------------------------------------------------- */

void LBF_ADC1_Init_Single_Shot(void);
void LBF_ADC1_Init_Single_Channel( ADC1_ChannelID_t ChannelID );
uint32_t  LBF_ADC1_Get_Value_Single_Shot(void);

void LBF_ADC1_Deinit(void);



#endif  /*__LBF_ADC_LOWLEVAPI_H */


/***************************************************************END OF FILE****/
