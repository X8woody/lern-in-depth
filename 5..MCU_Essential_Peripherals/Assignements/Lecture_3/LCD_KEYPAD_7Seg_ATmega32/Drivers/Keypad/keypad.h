/*
 * keypad.h
 *
 * Created: 4/29/2025 5:04:19 PM
 *  Author: Abdulrhman
 */ 


//[NOTE]: This driver is compatible with KEYPADs have size 4*4 only. !!  



#ifndef KEYPAD_H_
#define KEYPAD_H_
#define __STM32F103C6                   0UL
#define __ATmega32						1UL

#define MCU_DVICE						__ATmega32

//-----------------------------
//Includes
//-----------------------------
#if MCU_DVICE == __STM32F103C6
	#include "stm32f103x6_gpio.h"

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
	volatile DataType_Pins K_R1;
	volatile DataType_Pins K_R2;
	volatile DataType_Pins K_R3;
	volatile DataType_Pins K_R4;
	volatile DataType_Pins K_C1;
	volatile DataType_Pins K_C2;
	volatile DataType_Pins K_C3;
	volatile DataType_Pins K_C4;
}KEYPAD_PINS;
//-----------------------------
//Macros Configuration References
//-----------------------------
#define KEYPAD_GPIO_DATA               GPIOD



//-----------------------------
//GLOBAL VARIABLE DECLARATION
//-----------------------------	
//extern KEYPAD_PINS KEY_PAD;
//-----------------------------												 
/*
* ===============================================
* APIs Supported by "HAL KeyPad DRIVER"
* ===============================================
*/
void HAL_KEY_INIT(volatile DataType_Pins R1, volatile DataType_Pins R2, volatile DataType_Pins R3, volatile DataType_Pins R4, volatile DataType_Pins C1, volatile  DataType_Pins C2, volatile DataType_Pins C3, volatile DataType_Pins C4);
unsigned char HAL_KEY_READ_DATA();
//-----------------------------





#endif /* KEYPAD_H_ */
