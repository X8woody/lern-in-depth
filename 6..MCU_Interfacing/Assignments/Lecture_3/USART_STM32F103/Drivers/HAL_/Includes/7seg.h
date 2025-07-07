/*
 * 7seg.h
 *
 *  Created on: May 21, 2025
 *      Author: Abdulrhman
 */


#ifndef _7_SEGMENT_7SEG_H_
#define _7_SEGMENT_7SEG_H_

#define __STM32F103C6                   0UL
#define __ATmega32						1UL

#define MCU_DVICE						__STM32F103C6

//-----------------------------
//Includes
//-----------------------------
#if MCU_DVICE == __STM32F103C6
	#include "../../MCAL_/Include/stm32f103x6_gpio.h"

	#define DataType_Pins          uint16_t

#else
	#include "Atmega32_gpio.h"
	#include <util/delay.h>

	#define DataType_Pins          uint8_t

#endif
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct {
	volatile DataType_Pins SEG_P1;
	volatile DataType_Pins SEG_P2;
	volatile DataType_Pins SEG_P3;
	volatile DataType_Pins SEG_P4;
	volatile DataType_Pins SEG_P5;
	volatile DataType_Pins SEG_P6;
	volatile DataType_Pins SEG_P7;
}SEG_PINS;
//-----------------------------
//Macros Configuration References
//-----------------------------
#define SEG_GPIO_DATA               GPIOB

#define COMMON_CATHODE              0UL
#define COMMON_ANODE				1UL

#define COMMON_HW					COMMON_ANODE

#if COMMON_HW == COMMON_ANODE
#define _7SEG_GPIO_PIN_SET			GPIO_PIN_RESET
#define _7SEG_GPIO_PIN_RESET		GPIO_PIN_SET

#define ZERO						0b1000000
#define ONE							0b1111001
#define TWO							0b0100100
#define THREE						0b0110000
#define FOUR						0b0011001
#define FIVE						0b0010010
#define SIX						    0b0000010
#define SEVEN						0b1111000
#define EIGHT						0b0000000
#define NINE						0b0010000
#define A_LETT						0b0001000
#define B_LETT						0b0000011
#define C_LETT						0b1000110
#define D_LETT						0b0100001
#define E_LETT						0b0000110
#define F_LETT						0b0001110
#define H_LETT						0b0001001
#define L_LETT						0b1000111
#define G_LETT						0b1000010
#define O_LETT						0b0100011
#define P_LETT						0b0001100

#else
#define _7SEG_GPIO_PIN_SET			GPIO_PIN_SET
#define _7SEG_GPIO_PIN_RESET		GPIO_PIN_RESET

#define ZERO						0b0111111
#define ONE							0b0000110
#define TWO							0b1011011
#define THREE						0b1001111
#define FOUR						0b1100110
#define FIVE						0b1101101
#define SIX						    0b1111101
#define SEVEN						0b0000111
#define EIGHT						0b1111111
#define NINE						0b1101111
#define A_LETT						0b1110111
#define B_LETT						0b1111100
#define C_LETT						0b0111001
#define D_LETT						0b1011110
#define E_LETT						0b1111001
#define F_LETT						0b1110001
#define H_LETT						0b1110110
#define L_LETT						0b0111000
#define G_LETT						0b0111101
#define O_LETT						0b1011100
#define P_LETT						0b1110011

#endif
/*
* ===============================================
* APIs Supported by "HAL KeyPad DRIVER"
* ===============================================
*/
void HAL_7SEG_INIT(volatile DataType_Pins SEG_P1, volatile DataType_Pins SEG_P2, volatile DataType_Pins SEG_P3, volatile DataType_Pins SEG_P4, volatile DataType_Pins SEG_P5, volatile  DataType_Pins SEG_P6, volatile DataType_Pins SEG_P7);
void HAL_7SEG_SEND_DATA(uint8_t data);
//-----------------------------

#endif /* 7_SEGMENT_7SEG_H_ */
