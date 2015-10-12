/*******************************************************************************
 * LBF_Timer_lowlevAPI.h
 * 
 * Author: La BlueFrog, 2015
 *
 * This program is free software; you can redistribute it and/or modify
 * t under the terms of the GNU General Public License as published by
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
#ifndef __LBF_TIMER_LOWLEVAPI_H
#define __LBF_TIMER_LOWLEVAPI_H


/* Constants        ---------------------------------------------------------*/

#define TIMER_UNIT_US	1
#define TIMER_UNIT_MS	1000



/* Custom Types      ---------------------------------------------------------*/
typedef enum {
  TIMER1 = 1,
  TIMER2 = 2,
  TIMER3 = 3,
  TIMER4 = 4,
  TIMER5 = 5,
  TIMER6 = 6,
  TIMER7 = 7,
  TIMER8 = 8,
  TIMER15 = 15,
  TIMER16 = 16,
  TIMER17 = 17
}    
TimerID_t;


typedef enum {
  CHANNEL1 = 1,
  CHANNEL2 = 2,
  CHANNEL3 = 3,
  CHANNEL4 = 4
}    
ChannelID_t;


/* Exported functions ------------------------------------------------------- */

void LBF_Timer_Setup( TimerID_t TimerID, uint16_t Timer_TimeUnit_us, uint32_t Period_as_TimerUnits );
void LBF_Timer_Start_ITout( TimerID_t TimerID );
void LBF_Timer_Stop( TimerID_t TimerID );

void LBF_PWMchannel_Setup ( TimerID_t TimerID, ChannelID_t ChannelID, uint32_t Pulse_as_TimerUnits );
void LBF_PWMChannel_UpdatePulse (TimerID_t TimerID, ChannelID_t ChannelID, uint32_t  Pulse_as_TimerUnits);
void LBF_PWMChannel_Start (TimerID_t TimerID, ChannelID_t ChannelID);
void LBF_PWMChannel_Stop (TimerID_t TimerID, ChannelID_t ChannelID);



#endif  /*__LBF_TIMER_LOWLEVAPI_H*/

/***************************************************************END OF FILE****/
