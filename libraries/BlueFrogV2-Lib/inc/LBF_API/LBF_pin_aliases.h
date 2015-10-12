/*******************************************************************************
 * LBF_pin_aliases.h
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

#ifndef __LBF_PIN_ALIASES_H
#define __LBF_PIN_ALIASES_H

#include "stm32l4xx.h"  //to allow using Cortex-M register names while keeping this header self-sufficient


/**  P I N   A L I A S E S  *********************************************/


/*  ==== Power Management ============================================== */


/* --- LTC3533 PMIC ---*/

//PC2 - HPWR, STM32 output
#define	HPWR_PIN		GPIO_PIN_2
#define HPWR_PORT		GPIOC

//PB6 - BUCK_ON, STM32 output
#define	BUCK3V_ON_PIN		GPIO_PIN_6
#define BUCK3V_ON_PORT		GPIOB

//PC13 - ONOFF_STAT (debounced On/Off push-button), STM32 input
#define	ONOFF_STAT_PIN		GPIO_PIN_13
#define ONOFF_STAT_PORT		GPIOC


/* --- TPS22929 Power Switch (DC-DC Boost Converter On/Off) ---*/

// PC0 -  BOOSTCONV_EN,  STM32 output
#define	VDDH_EN_PIN	GPIO_PIN_0
#define VDDH_EN_PORT	GPIOC


/*  ==== LEDs  ======================================================== */

// PC3 -  STM32_LED,  STM32 output
#define	STM32_LED_PIN	GPIO_PIN_3
#define STM32_LED_PORT	GPIOC


/*  ==== Selection Switches  =========================================== */

// PA15 -  SWITCH1,  STM32 input
#define	SWITCH1_PIN	GPIO_PIN_15
#define SWITCH1_PORT	GPIOA

// PC8 -  SWITCH2,  STM32 input
#define	SWITCH2_PIN	GPIO_PIN_8
#define SWITCH2_PORT	GPIOC

/*  ==== I2C1   ======================================================== */

// PB8 - SCL, STM32 output, Open-Drain
// PB9 - SDA, STM32 output/input, Open-Drain
#define	I2C1_SCL_PIN	GPIO_PIN_8
#define	I2C1_SDA_PIN	GPIO_PIN_9
#define	I2C1_PORT	GPIOB

/*  ==== I2C2   ======================================================== */

// PB10 - SCL, STM32 output, Open-Drain
// PB11 - SDA, STM32 output/input, Open-Drain
#define	I2C2_SCL_PIN	GPIO_PIN_10
#define	I2C2_SDA_PIN	GPIO_PIN_11
#define	I2C2_PORT	GPIOB

/*  ==== SPI1   ========================================================= */

// PA5 - CK, STM32 output, Std CMOS
// PA6 - MISO, STM32 input
// PA7 - MOSI, STM32 output, Std CMOS
#define	SPI1_SCK_PIN	GPIO_PIN_5
#define	SPI1_MISO_PIN	GPIO_PIN_6
#define	SPI1_MOSI_PIN	GPIO_PIN_7
#define	SPI1_PORT	GPIOA

/*  ==== SPI3   ========================================================= */

// PB3 - CK, STM32 output, Std CMOS
// PB4 - MISO, STM32 input
// PB5 - MOSI, STM32 output, Std CMOS
#define	SPI3_SCK_PIN	GPIO_PIN_3
#define	SPI3_MISO_PIN	GPIO_PIN_4
#define	SPI3_MOSI_PIN	GPIO_PIN_5
#define	SPI3_PORT	GPIOB

/*  ==== UART1  ======================================================= */
// PA9 - TX, STM32 output, Std CMOS
// PA10 - RX, STM32 input

#define	UART1_TX_PIN	GPIO_PIN_9
#define	UART1_RX_PIN	GPIO_PIN_10
#define	UART1_PORT	GPIOA

/*  ==== USART 2  ======================================================= */
// PA2 - TX, STM32 output, Std CMOS
// PA3 - RX, STM32 input
// PA4 - CK, STM32 output, Std CMOS

#define	USART2_TX_PIN	GPIO_PIN_2
#define	USART2_RX_PIN	GPIO_PIN_3
#define	USART2_CK_PIN	GPIO_PIN_4
#define	USART2_PORT	GPIOA

/*  ==== UART 3  ======================================================= */
// PC10 - TX, STM32 output, Std CMOS
// PC11 - RX, STM32 input

#define	UART3_TX_PIN	GPIO_PIN_10
#define	UART3_RX_PIN	GPIO_PIN_11
#define	UART3_PORT	GPIOC

/*  ==== DATA FLASH (excl SPI)   ======================================== */
// PB7 = nCS
#define FLASH_CS_PIN	GPIO_PIN_7
#define FLASH_CS_PORT	GPIOB

/*  ==== BTLE (excl UART)       ======================================== */
// PC9 = BT_RST (active high)
#define BT_RST_PIN	GPIO_PIN_9
#define BT_RST_PORT	GPIOC

/*  ==== LSM6DS3 ACCEL/GYRO     ======================================== */
// PB15 = INT1_ACC_GYR, PC6 = INT2_ACC_GYR
#define INT1_ACC_GYR_PIN	GPIO_PIN_15
#define INT1_ACC_GYR_PORT	GPIOB
#define INT2_ACC_GYR_PIN	GPIO_PIN_6
#define INT2_ACC_GYR_PORT	GPIOC

/*  ==== LIS3MDL MAGNETO        ======================================== */
// PB13 = DRDY_MAG, PB14 = IRQ_MAG
//#define DRDY_MAG_PIN	GPIO_PIN_13
#define IRQ_MAG_PIN	GPIO_PIN_14
#define IRQ_MAG_PORT	GPIOB

/*  ==== VL6180X ALS/PROXIMITY/DISTANCE        ========================= */
// PA0(WKUP1) = IRQ_ALS_PROX
#define IRQ_ALS_PROX_PIN	GPIO_PIN_0
#define IRQ_ALS_PROX_PORT	GPIOA

/*  ==== LPS25H PRESSURE/TEMP SENSOR           ========================= */
// PB12 = IRQ_PRESS
#define IRQ_PRESS_PIN	GPIO_PIN_12
#define IRQ_PRESS_PORT	GPIOB

/*  ==== BATTERY                 ======================================== */
// PC1 = BATT_ADC_MEAS, PC7 = BATT_MEAS_EN
#define BATT_ADC_MEAS_PIN	GPIO_PIN_1
#define BATT_MEAS_ENB_PIN	GPIO_PIN_7
#define BATT_PORT		GPIOC


/*  ==== OLED (excl SPI)         ======================================== */
// PC4 - OLED_RS, STM32 output
// PC5, OLED_NCS, STM32 output
// PB1 - OLED_RESET, STM32 output
#define	OLED_RS_PIN		GPIO_PIN_4
#define OLED_RS_PORT		GPIOC
#define	OLED_CS_PIN		GPIO_PIN_5
#define OLED_CS_PORT		GPIOC
#define	OLED_RESET_PIN		GPIO_PIN_1
#define OLED_RESET_PORT		GPIOB


/*  ==== EXTENSION CONNECTOR      ======================================== */

// Pos1: PA5
#define	CONN_POS1_PIN		GPIO_PIN_5
#define CONN_POS1_PORT		GPIOA

// Pos2: PA6
#define	CONN_POS2_PIN		GPIO_PIN_6
#define CONN_POS2_PORT		GPIOA

// Pos3: PA7
#define	CONN_POS3_PIN		GPIO_PIN_7
#define CONN_POS3_PORT		GPIOA

// Pos4: PB0
#define	CONN_POS4_PIN		GPIO_PIN_0
#define CONN_POS4_PORT		GPIOB
#define MICOUT_PIN		GPIO_PIN_0  // PBO also used to capture sound from microphone
#define MICOUT_PORT		GPIOB


// Pos5: PC10
#define	CONN_POS5_PIN		GPIO_PIN_10
#define CONN_POS5_PORT		GPIOC

// Pos6: PC11
#define	CONN_POS6_PIN		GPIO_PIN_11
#define CONN_POS6_PORT		GPIOC

// Pos7: PC12
#define	CONN_POS7_PIN		GPIO_PIN_12
#define CONN_POS7_PORT		GPIOC

// Pos8: VCC (3V)

// Pos9: PB8
#define	CONN_POS9_PIN		GPIO_PIN_8
#define CONN_POS9_PORT		GPIOB

// Pos10: PB9
#define	CONN_POS10_PIN		GPIO_PIN_9
#define CONN_POS10_PORT		GPIOB

// Pos11: GND



// PA1, OLED_UPDOWN  ******** Ici ou avec Power ?
// !! External pull-down on board,
// !! suitable for OLED facing down (when FPC conn is straight)
// ******  ONLY SET TO 0, WILL DISAPPEAR IN NEXT VERSION ANYWAY **************
#define	OLED_UPDOWN_PIN		GPIO_PIN_1
#define OLED_UPDOWN_PORT	GPIOA


#endif /*__LBF_PIN_ALIASES_H*/

/***************************************************************END OF FILE****/
