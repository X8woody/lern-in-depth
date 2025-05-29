/*
 * 7seg.c
 *
 *  Created on: May 21, 2025
 *      Author: Abdulrhman
 */
//-----------------------------
//Includes
#include "../Includes/7seg.h"

//-----------------------------
//GLOBAL VARIABLE DECLARATION
//-----------------------------
SEG_PINS _7SEG;
//-----------------------------



/*----------------------API's_decalarations--------------------*/
//--------------SET PINS of 7Segment and initiate its pins.-------------------//
void HAL_7SEG_INIT(volatile DataType_Pins SEG_P1, volatile DataType_Pins SEG_P2, volatile DataType_Pins SEG_P3, volatile DataType_Pins SEG_P4, volatile DataType_Pins SEG_P5, volatile  DataType_Pins SEG_P6, volatile DataType_Pins SEG_P7)
{
	{
		_7SEG.SEG_P1 = (1 << SEG_P1);
		_7SEG.SEG_P2 = (1 << SEG_P2);
		_7SEG.SEG_P3 = (1 << SEG_P3);
		_7SEG.SEG_P4 = (1 << SEG_P4);
		_7SEG.SEG_P5 = (1 << SEG_P5);
		_7SEG.SEG_P6 = (1 << SEG_P6);
		_7SEG.SEG_P7 = (1 << SEG_P7);
	}
	PIN_CFG_TypeDef GPIO_PIN_CFG;
	GPIO_PIN_CFG.PIN_NUMBER 	 = (_7SEG.SEG_P1 | _7SEG.SEG_P2 | _7SEG.SEG_P3 | _7SEG.SEG_P4 | _7SEG.SEG_P5 | _7SEG.SEG_P6 | _7SEG.SEG_P7);
	GPIO_PIN_CFG.__PinMode 		 = OUTPUT_MODE;
	#if MCU_DVICE == __STM32F103C6
		GPIO_PIN_CFG.CNF_OUTPUT_CASE = GPOutput_OpenDarain;
		GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
	#endif
	MCAL_GPIO_INIT(SEG_GPIO_DATA, &GPIO_PIN_CFG);
	MCAL_GPIO_WRITE_PIN(SEG_GPIO_DATA, GPIO_PIN_CFG.PIN_NUMBER, _7SEG_GPIO_PIN_RESET);
}


//--------------Send Data to 7Segment-------------------//
void HAL_7SEG_SEND_DATA(uint8_t data)
{
#if COMMON_HW == COMMON_ANODE
	#define COMPARE             0x00
#else
	#define COMPARE             0x01
#endif
	uint8_t  DATA;
	volatile DataType_Pins *P_7SEG_PINS = &_7SEG.SEG_P1;
	uint8_t i;
	for(i = 0; i < 7; i++)
	{
		DATA = ((data & (1 << i)) >> i);
		if(DATA == COMPARE)
		{
			MCAL_GPIO_WRITE_PIN(SEG_GPIO_DATA, *P_7SEG_PINS, _7SEG_GPIO_PIN_SET);
		}
		else
		{
			MCAL_GPIO_WRITE_PIN(SEG_GPIO_DATA, *P_7SEG_PINS, _7SEG_GPIO_PIN_RESET);
		}
		P_7SEG_PINS++;
	}
}
