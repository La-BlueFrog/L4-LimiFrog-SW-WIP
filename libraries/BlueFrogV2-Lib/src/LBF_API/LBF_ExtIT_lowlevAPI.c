/*******************************************************************************
 * LBF_ExtIT_lowlevAPI.c
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

#include "IT_Priorities_UserDefinable.h"

/*******************************************************************************
* Function Name  : Enable_ExtIT
* Description    : Enable selected externa interrupt pin at GPIO EXTI level and at NVIC level
* Input          : Name of the pin (GPIO_Pin), Required Edge polarity of IT
* Output         : None
* Return         : None
*******************************************************************************/

void LBF_Enable_ExtIT( GPIO_TypeDef* GPIO_Port, uint16_t  GPIO_Pin, IT_Polarity_t  IT_Polarity )
{
GPIO_InitTypeDef GPIO_InitStruct;


  // ---- Enable the GPIO as External Interrupt  -------------

    GPIO_InitStruct.Pin = GPIO_Pin;
    if ( IT_Polarity == RISING)  {
        GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;  
    }
    else {
        GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;  
    }
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct);



  // ---- Set Nested Vectored Interrupt Controller (NVIC)  ---
 
    // Ext interrrupts that use pin 0 of ports GPIOA/B/C/D:
    if ( GPIO_Pin == IRQ_ALS_PROX_PIN )  //PA0
    {
         HAL_NVIC_SetPriority(EXTI0_IRQn, __EXTI0_IRQn_PRIO , 0); 
         HAL_NVIC_EnableIRQ(EXTI0_IRQn);  
    }

    // Ext interrrupts that use pin 1 of ports GPIOA/B/C/D:
    // None in La BlueFrog

    // Ext interrrupts that use pin 2 of ports GPIOA/B/C/D:
    // None in La BlueFrog

    // Ext interrrupts that use pin 3 of ports GPIOA/B/C/D:
    // None in La BlueFrog

    // Ext interrrupts that use pin 4 of ports GPIOA/B/C/D:
    // None in La BlueFrog

    // Ext interrrupts that use pins 5 to 9 of ports GPIOA/B/C/D:
    if ( (GPIO_Pin == INT2_ACC_GYR_PIN) ||  // PC6
         (GPIO_Pin == CONN_POS1_PIN)    ||   // PA5
         (GPIO_Pin == CONN_POS2_PIN)    ||   // PA6  -- Caution, avoid conflict in IRQ handler with PC6=INT2_ACC_GYR_PIN
         (GPIO_Pin == CONN_POS3_PIN)    ||   // PA7 
         (GPIO_Pin == CONN_POS9_PIN)    ||   // PB8 
         (GPIO_Pin == CONN_POS10_PIN)    )   // PB9 
       //TBD: also PC8 as an IT from switch 2 ?
    {
         HAL_NVIC_SetPriority(EXTI9_5_IRQn, __EXTI9_5_IRQn_PRIO , 0); 
         HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);  
    }

     // Ext interrrupts that use pins 10 to 15 of ports GPIOA/B/C/D:
    if ( (GPIO_Pin == INT1_ACC_GYR_PIN) ||   // PB15
         (GPIO_Pin == IRQ_MAG_PIN)      ||   // PB14
         (GPIO_Pin == IRQ_PRESS_PIN)    ||   // PB12
         (GPIO_Pin == ONOFF_STAT_PIN)   ||   // PC13  (already configured at init by LBF_Fixed_Inits())
         (GPIO_Pin == CONN_POS5_PIN)    ||   // PC10
         (GPIO_Pin == CONN_POS6_PIN)    ||   // PC11
         (GPIO_Pin == CONN_POS7_PIN)     )   // PC12  -- Caution, avoid conflict in IRQ handler with PB12=IRQ_PRESS_PIN
    {
         HAL_NVIC_SetPriority(EXTI15_10_IRQn, __EXTI15_10_IRQn_PRIO , 0); 
         HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); 
    }

}


/* --------------------------------------------------------------------------------------------- */

/*******************************************************************************
* Function Name  : Disable_ExtIT
* Description    : Disable selected external interrupt pin - configure as std input
*                   ** at GPIO EXTI level ONLY ** (because NVIC maye shared with other IT lines)
* Input          : Name of the pin (GPIO_Pin)
* Output         : None
* Return         : None
*******************************************************************************/

void LBF_Disable_ExtIT( GPIO_TypeDef* GPIO_Port, uint16_t  GPIO_Pin )
{
GPIO_InitTypeDef GPIO_InitStruct;


  // ----Set GPIO as input with weak pull-down  -------------

    GPIO_InitStruct.Pin = GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct); 

}


/***************************************************************END OF FILE****/
