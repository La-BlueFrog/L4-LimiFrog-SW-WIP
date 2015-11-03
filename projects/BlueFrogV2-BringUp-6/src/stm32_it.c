/*******************************************************************************
 * stm32_it.c
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

#include "stm32_it.h"
#include "LBF_lowlev_API.h"


extern PCD_HandleTypeDef hpcd;


/* ---   Private Function Prototypes ------------------ */



/******************************************************************************/
/*             Cortex-M Processor Exceptions Handlers                         */
/******************************************************************************/



/*******************************************************************************
* Function Name  : EXTI0_IRQHandler
* Description    : Handles EXT interrupts from Pin0 of ports GPIOA/B/C/D .
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

// On La BlueFrog V2, possible external interrupts expected here would be :
//  - IRQ from VL6180X, through pin PA0
//  - From ext. connector pos. #4, if configured by user as IT source, thru PB0

void EXTI0_IRQHandler(void)
{

}


/*******************************************************************************
* Function Name  : EXTI1_IRQHandler
* Description    : Handles EXT interrupts from Pin 1 of ports GPIOA/B/C/D .
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

// On La BlueFrog V2, possible external interrupts expected here would be :
//  - none

void EXTI1_IRQHandler(void)
{

}

/*******************************************************************************
* Function Name  : EXTI2_IRQHandler
* Description    : Handles EXT interrupts from Pin 2 of ports GPIOA/B/C/D .
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

// On La BlueFrog V2, possible external interrupts expected here would be :
//  - none

void EXTI2_IRQHandler(void)
{

}

/*******************************************************************************
* Function Name  : EXTI3_IRQHandler
* Description    : Handles EXT interrupts from Pin 3 of ports GPIOA/B/C/D .
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI3_IRQHandler(void)

// On La BlueFrog V2, possible external interrupts expected here would be :
//  - none

{

}

/*******************************************************************************
* Function Name  : EXTI4_IRQHandler
* Description    : Handles EXT interrupts from Pin 4 of ports GPIOA/B/C/D .
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI4_IRQHandler(void)

// On La BlueFrog V2, possible external interrupts expected here would be :
//  - none

{

}

/*******************************************************************************
* Function Name  : EXTI9_5_IRQHandler
* Description    : Handles EXT interrupts from Pins 5 to 9 of ports GPIOA/B/C/D 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

// On La BlueFrog V2, possible external interrupts expected here would be :
//  - Mechanical Switch #2 if configured by user as IT source, through PC8
//    (caution: this switch is not debounced)
//  - Interrupt INT2 from LSM6DS3 (Accel/Gyro), through pin PC6
//  - From ext. connector pos. #1, if configured by user as IT source, thru PA5
//  - From ext. connector pos. #2, if configured by user as IT source, thru PA6
//  - From ext. connector pos. #3, if configured by user as IT source, thru PA7
//  - From ext. connector pos. #9, if configured by user as IT source, thru PB8
//  - From ext. connector pos. #10, if configured by user as IT source, thru PB9

void EXTI9_5_IRQHandler(void)
{

}

/*******************************************************************************
* Function Name  : EXTI15_10_IRQHandler
* Description    : Handles EXT interrupts from Pins 10 to 15 of ports GPIOA/B/C/D 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

// On La BlueFrog V2, possible external interrupts expected here would be :
//  - Mechanical Switch #1 if configured by user as IT source, on PA15
//    (caution: this switch is not debounced)
//  - Interrupt INT1 from LSM6DS3 (Accel/Gyro), through pin PB15
//  - Interrupt INT from LIS3MDL (Magneto), through pin PB14
//  - Interrupt DRDY from LIS3MDL (Magneto), through pin PB13
//  - Interrupt INT1 from LPS25H (Pressure), through pin PB12
//  - Debounced ON/OFF from PMIC (LTC3553), through pin PC13
//  - From ext. connector pos. #5, if configured by user as IT source, thru PC10
//  - From ext. connector pos. #6, if configured by user as IT source, thru PC11
//  - From ext. connector pos. #7, if configured by user as IT source, thru PC12


void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(ONOFF_STAT_PIN);
  // Checks if ONOFF_STAT_PIN is source of IT
  // if so: HAL clears the IT and calls HAL_GPIO_EXTI_Callback (see below)
}

/*******************************************************************************
* Function Name  : RTC_WKUP_IRQHandler
* Description    : Actualise l'heure toute les secondes.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTC_WKUP_IRQHandler(void)
{

   
}

/*******************************************************************************
* Function Name  : NMI_Handler
* Description    : This function handles NMI exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NMI_Handler(void)
{
}

/*******************************************************************************
* Function Name  : HardFault_Handler
* Description    : This function handles Hard Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1);
}

/*******************************************************************************
* Function Name  : MemManage_Handler
* Description    : This function handles Memory Manage exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1);
}

/*******************************************************************************
* Function Name  : BusFault_Handler
* Description    : This function handles Bus Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1);
}

/*******************************************************************************
* Function Name  : UsageFault_Handler
* Description    : This function handles Usage Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1);
}

/*******************************************************************************
* Function Name  : SVC_Handler
* Description    : This function handles SVCall exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SVC_Handler(void)
{
}

/*******************************************************************************
* Function Name  : DebugMon_Handler
* Description    : This function handles Debug Monitor exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DebugMon_Handler(void)
{
}

/*******************************************************************************
* Function Name  : PendSV_Handler
* Description    : This function handles PendSVC exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PendSV_Handler(void)
{
}

/*******************************************************************************
* Function Name  : SysTick_Handler
* Description    : This function handles SysTick Handler.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/*                 STM32 Peripherals Interrupt Handlers                       */
/******************************************************************************/


/**
  * @brief  This function handles USB-On-The-Go FS global interrupt request.
  * @param  None
  * @retval None
  */
void OTG_FS_IRQHandler(void)
{
  HAL_PCD_IRQHandler(&hpcd);
}




/**===========================================================================*/
/**==     Callback functions called by above IRQ handlers associated to EXTI, */
/**==       (EXTI = External Interrupts through GPIO pins)                    */
/**===========================================================================*/


/**
  * @brief EXTI line detection callbacks
  * @param GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None 
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

// Servicing Interrupt from PWR_ONSTAT (power off required)

  if (GPIO_Pin == ONOFF_STAT_PIN)
  {
        LBF_Led_OFF();        

#ifdef USE_OLED  // (defined in User_Configuration.h)
	// Do not send command if no OLED (else SPI hangs)

        OLED_Switch_OFF();
        LBF_Delay_ms(100); // Delay between cutting OLED VDDH (13V) and VDD (logic) 
                       // to preserve panel lifetile - as per DD160128FC-1A datasheet
	    //Caution: TimerTick involved, its IRQ priority must be high (urgent) enough
	    // in Interrupt Configuration files
#endif


        // wait as long as ONOFF is active (ie. until user has finished pushing button)
        while(HAL_GPIO_ReadPin(ONOFF_STAT_PORT, ONOFF_STAT_PIN) == GPIO_PIN_RESET);

        
	//Quickly blink LED 3 times
	LBF_Led_ON();
        LBF_Delay_ms(100);        
	LBF_Led_OFF();
        LBF_Delay_ms(200);      

	LBF_Led_ON();
        LBF_Delay_ms(100);        
	LBF_Led_OFF();
        LBF_Delay_ms(200);   

	LBF_Led_ON();
        LBF_Delay_ms(100);        
	LBF_Led_OFF();


        // Bye bye:  Power down VCC_NUM by resetting pin BUCK3V_ON
        GPIO_LOW(BUCK3V_ON_PORT, BUCK3V_ON_PIN);
        LBF_Delay_ms(3000);
        while(1);

  }



}



/***************************************************************END OF FILE****/
