/*******************************************************************************
 * IT_Priorities_UserDefinable.h
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IT_PRIO_USERDEFINABLE_H
#define __IT_PRIO_USERDEFINABLE_H



/* ---------------  Interrupt Priorities for NVIC  ---------------------- */

/*  
 *  A list of the potential interrupt sources in La BlueFrog  
 *   can be found in stm32_it.c
 */


/* Priority levels can be set between 0x0 and 0xF                 */
/* !!!  LOWER NUMERICAL VALUE MEANS HIGHER PRE-EMPTION LEVEL  !!! */



#define	__SysTick_IRQn_PRIO	0xF
// if used in Delay function, level must be such that it pre-empts any ISR that use Delay_ms()

#define __OTG_FS_IRQn_PRIO	0x7
// was originally hard-coded to 0x7 by ST in reference usbd_conf.c

// External Interrupts 
#define	__EXTI0_IRQn_PRIO	0xA	
#define	__EXTI1_IRQn_PRIO	0xA	
#define	__EXTI2_IRQn_PRIO	0xA	
#define	__EXTI3_IRQn_PRIO	0xA	
#define	__EXTI4_IRQn_PRIO	0xA	
#define	__EXTI9_5_IRQn_PRIO   	0xA	// includes ONOFF_STAT pin from PMIC, triggers power-on/-off
#define	__EXTI15_10_IRQn_PRIO	0xA	

// Timer Interrupts,
// Some combined with IT from other peripherals
#define __TIM1_UP_TIM16_IRQn_PRIO	0xA
#define __TIM2_IRQn_PRIO	0xA
#define __TIM3_IRQn_PRIO	0xA
#define __TIM4_IRQn_PRIO	0xA
#define __TIM5_IRQn_PRIO	0xA
#define __TIM6_DAC_IRQn_PRIO	0xA
#define __TIM7_IRQn_PRIO	0xA
#define __TIM8_UP_IRQn_PRIO	0xA
#define __TIM1_BRK_TIM15_IRQn_PRIO	0xA
#define __TIM1_UP_TIM16_IRQn_PRIO	0xA
#define __TIM1_TRG_COM_TIM17_IRQn_PRIO	0xA


#endif  /*__IT_PRIO_USERDEFINABLE_H */

/***************************************************************END OF FILE****/
