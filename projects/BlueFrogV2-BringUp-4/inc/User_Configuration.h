/*******************************************************************************
 * User_Configuration.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USER_CONF_H
#define __USER_CONF_H



// ============================================================================
//    OLED presence
// ============================================================================

// Comment out next line if no OLED or not used. Uncomment if OLED is used :
// #define USE_OLED  
   // WARNING:
   // - do not keep uncommented if no OLED present
   // - this initializes OLED but powering on/off the screen is left to user 
   //   code, using e.g. functions OLED_Switch_ON() and OLED_Switch_OFF()



// ============================================================================
//    Enable/Disable BlueTooth Low-Energy Functionality
// ============================================================================

// Comment out / Uncomment next line as needed :
// #define ENABLE_BTLE

// Select here the required code to download in the BTLE module 
// Must be stored on the Data Flash - Would typically be put there 
// by USB 
// Ignored if ENABLE_BTLE is undefined
#define  BTLE_CODE_FILENAME   "BTLECODE.BIN"

// indicate here required baudrate in bits/s
// This is for exchanges between STM32 and application running on PAN1740
// Does NOT affect baud rate used for booting PAN1740 from UART (which must not be changed)
// Ignored if BTLE is not enabled
#define	UART1_BAUDRATE	 115200  	



// ============================================================================
//    Parameters of peripherals usable on extension connector
// ============================================================================


// -------------------------------------------------
//    UART3 Baud Rate 
// -------------------------------------------------

// If UART3 is used (on Connector Positions 5 or 6) below,
// specify here the required baud rate :
//   (no effect if UART3 not used on extension connector pins)

#define	UART3_BAUDRATE	 57600	// indicate here required baudrate in bits/s

// Other UART parameters default to :
//   8 bit data, 1 Stop bit, no Parity bit ...
// Write your own code if you need something different


// -------------------------------------------------
//    I2C1 Clock Speed  
// -------------------------------------------------

// If I2C #1 is used (on Connector Positions 9 or 10) below,
// specify here the required baud rate :
//   (no effect if I2C1 not used on extension connector pins)

#define	I2C1_SPEED	100000	// indicate here required I2C clock speed in Hz

// Other I2C1 parameters default to :
//   7-bit addressing mode, dual address disabled, general call disabled
// Write your own code if you need something different


// -------------------------------------------------
//    SPI1 Bit Rate  
// -------------------------------------------------

// If SPI #1 is used (on Connector Positions 1, 2 or 3) below,
// specify here the required baud rate :
//   (no effect if SPI1 not used on extension connector pins)

//
// TODO
// CAUTION - FOR NOW SPI1 is used by OLED !!!!!!!!!!!!!!!!!!
// Other SPI1 parameters default to :
//   xxxx
// Write your own code if you need something different



// ============================================================================
// CONNECTOR POSITION 1  -  Optionally usable as :
//    GPIO or SPI1 SCLK or ...
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.1:  Uncomment ONE of following lines if needed

// -------------------------------------------------
//    Simple GPIO Usage on External Connector pos. 1 
// -------------------------------------------------
// #define POS1_IS_GPIO_IN	// Pin used as input     
// #define POS1_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS1_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS1_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS1_IS_GPIO_OUT_OD  // Pin used as open-drain output

// ---------------------------------------------------------------------
//    SPI1 SCK Usage on External Connector pos. 1 
// ---------------------------------------------------------------------
// TODO



// ============================================================================
// CONNECTOR POSITION 2  -  Optionally usable as :
//    GPIO or SPI1 MISO or TIMER3 CH.1 or TIMER10 CH.1 
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.2:  Uncomment ONE of following lines if needed

// -------------------------------------------------
//    Simple GPIO Usage on External Connector pos. 2
// -------------------------------------------------
// #define POS2_IS_GPIO_IN	// Pin used as input     
// #define POS2_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS2_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS2_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS2_IS_GPIO_OUT_OD  // Pin used as open-drain output

// ---------------------------------------------------------------------
//    SPI1 MISO Usage on External Connector pos. 2
// ---------------------------------------------------------------------
// TODO

// ---------------------------------------------------------------------
//    TIMER3/TIMER10 Usage on External Connector pos. 2  (typ. for PWM)
// ---------------------------------------------------------------------
//#define POS2_IS_TIM3_CH1	//Pin bears Channel1 of Timer3
//#define POS2_IS_TIM10_CH1	//Pin bears Channel1 of Timer10  



// ============================================================================
// CONNECTOR POSITION 3  -  Optionally usable as :
//    GPIO or SPI1 MOSI or TIMER3 CH.2 or TIMER11 CH.1 
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.3:  Uncomment ONE of following lines if needed

// -------------------------------------------------
//    Simple GPIO Usage on External Connector pos. 3
// -------------------------------------------------
// #define POS3_IS_GPIO_IN	// Pin used as input     
// #define POS3_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS3_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS3_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS3_IS_GPIO_OUT_OD  // Pin used as open-drain output

// ---------------------------------------------------------------------
//    SPI1 MOSI Usage on External Connector pos. 3
// ---------------------------------------------------------------------
// TODO

// ---------------------------------------------------------------------
//    TIMER3/TIMER11 Usage on External Connector pos. 3  (typ. for PWM)
// ---------------------------------------------------------------------
// Note:  different channels of SAME timer can have different duty cycles 
//        but will share SAME period

//#define POS3_IS_TIM3_CH2	//Pin bears Channel2 of Timer3
//#define POS3_IS_TIM11_CH1	//Pin bears Channel1 of Timer11



// ============================================================================
// CONNECTOR POSITION 4 :     
//	Bears Microphone output - Also goes to STM32 PB0 used as analog input 
// ============================================================================

// Pos.4:  Uncomment ONE of following lines if needed

// TODO



// ============================================================================
// CONNECTOR POSITION 5  -  Optionally usable as :
//    GPIO or UART3 TX or ...
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.5:  Uncomment ONE of following lines if needed

// ---------------------------------------------------------------------
//    Simple GPIO Usage on External Connector pos.5
// ---------------------------------------------------------------------
// #define POS5_IS_GPIO_IN	// Pin used as input     
// #define POS5_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS5_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS5_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS5_IS_GPIO_OUT_OD  // Pin used as open-drain output

// ---------------------------------------------------------------------
//    UART3 Usage on External Connector pos. 5
// ---------------------------------------------------------------------
// #define POS5_IS_UART3_TX 	// Position 5 bears USART3 Tx
   //  !!!! If used, make sure you specify the BAUD RATE required    !!!
   //  !!!!   at top of this file       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



// ============================================================================
// CONNECTOR POSITION 6  -  Optionally usable as :
//    GPIO or UART3 RX or ...
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.6:  Uncomment ONE of following lines if needed

// ---------------------------------------------------------------------
//    Simple GPIO Usage on External Connector pos.6
// ---------------------------------------------------------------------
// #define POS6_IS_GPIO_IN	// Pin used as input     
// #define POS6_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS6_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS6_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS6_IS_GPIO_OUT_OD  // Pin used as open-drain output

// ---------------------------------------------------------------------
//    UART3 Usage on External Connector pos. 6
// ---------------------------------------------------------------------
// #define POS6_IS_UART3_RX 	// Position 6 bears USART3 Rx
   //  !!!! If used, make sure you specify the BAUD RATE required    !!!
   //  !!!!   at top of this file       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



// ============================================================================
// CONNECTOR POSITION 7 :   
//	Optionally usable as GPIO or (USART3 CLK?)...
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.7:  Uncomment ONE of following lines if needed

// ---------------------------------------------------------------------
//    Simple GPIO Usage on External Connector pos.7
// ---------------------------------------------------------------------
// #define POS7_IS_GPIO_IN	// Pin used as input     
// #define POS7_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS7_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS7_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS7_IS_GPIO_OUT_OD  // Pin used as open-drain output



// ============================================================================
// CONNECTOR POSITION 8 is VDD  (3V)
// ============================================================================



// ============================================================================
// CONNECTOR POSITION 9  -  Optionally usable as :
//    GPIO or I2C21 SCL or TIMER4 Ch.3
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.9:  Uncomment ONE of following lines if needed

// -------------------------------------------------
//    Simple GPIO Usage on External Connector pos. 9
// -------------------------------------------------
// #define POS9_IS_GPIO_IN	// Pin used as input     
// #define POS9_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS9_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS9_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS9_IS_GPIO_OUT_OD  // Pin used as open-drain output

// ---------------------------------------------------------------------
//    I2C1 SCL Usage on External Connector pos. 9 
// ---------------------------------------------------------------------
// #define POS9_IS_I2C1_SCL 	//defined means Position 9 bears I2C1 SCL
   //  !!!! If used, make sure you specify the SPEED required        !!!
   //  !!!!   at top of this file       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// ---------------------------------------------------------------------
//    TIMER4 Usage on External Connector pos. 9  (typ. for PWM)
// ---------------------------------------------------------------------
// #define POS9_IS_TIM4_CH3   	//Pin bears Channel3 of Timer4



// ============================================================================
// CONNECTOR POSITION 10  -  Optionally usable as :
//    GPIO or I2C1 SDA or TIMER4 Ch.4
//      ( it's exclusive, make sure you have ONE single define uncommented )
// ============================================================================

// Pos.10:  Uncomment ONE of following lines if needed

// -------------------------------------------------
//    Simple GPIO Usage on External Connector pos. 10
// -------------------------------------------------
// #define POS10_IS_GPIO_IN	// Pin used as input     
// #define POS10_IS_GPIO_IN_PU	// Pin used as input with weak pull-up 
// #define POS10_IS_GPIO_IN_PD	// Pin used as input with weak pull-down
// #define POS10_IS_GPIO_OUT	// Pin used as regular CMOS ouput
// #define POS10_IS_GPIO_OUT_OD  // Pin used as open-drain output


// ---------------------------------------------------------------------
//    I2C1 SDA Usage on External Connector pos. 10
// ---------------------------------------------------------------------
// #define POS10_IS_I2C1_SDA 	//defined means Position 10 bears I2C1 SD
   //  !!!! If used, make sure you specify the SPEED required        !!!
   //  !!!!   at top of this file       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// ---------------------------------------------------------------------
//    TIMER4 Usage on External Connector pos.10  (typ. for PWM)
// ---------------------------------------------------------------------
// #define POS10_IS_TIM4_CH4   	//Pin bears Channel4 of Timer4



// ============================================================================
// CONNECTOR POSITIONS 11 is GND
// ============================================================================




#endif  /*__USER_CONF_H*/

/***************************************************************END OF FILE****/

