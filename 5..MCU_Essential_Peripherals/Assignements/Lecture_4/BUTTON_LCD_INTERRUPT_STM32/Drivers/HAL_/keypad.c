/*
 * Keypad.c
 *
 * Created: 4/29/2025 5:04:02 PM
 *  Author: Abdulrhman
 */ 
//-----------------------------
//Includes
#include "../Includes/keypad.h"

//-----------------------------
//GLOBAL VARIABLE DECLARATION
//-----------------------------
KEYPAD_PINS KEY_PAD;
//-----------------------------
#if MCU_DVICE == __STM32F103C6

void delay_ms(uint32_t __ms)
{
	uint32_t i,j;
	for(i = 0; i < __ms; i++)
		for(j = 0; j < 255; j++);
}
#endif


/*----------------------API's_decalarations--------------------*/
//--------------SET Columns and Rows of KEYPAD and initiate its pins.-------------------//
void HAL_KEY_INIT(volatile DataType_Pins R1, volatile DataType_Pins R2, volatile DataType_Pins R3, volatile DataType_Pins R4, volatile DataType_Pins C1, volatile DataType_Pins C2, volatile DataType_Pins C3, volatile DataType_Pins C4){
	//KEY_PIN_I_O &= ~((1 << C1) | (1 << C2) | (1 << C3) | (1 << C4));
	//KEY_PIN_I_O |= ((1 << R1) | (1 << R2) | (1 << R3) | (1 << R4));
	{
		KEY_PAD.K_R1 = (1 << R1);
		KEY_PAD.K_R2 = (1 << R2);
		KEY_PAD.K_R3 = (1 << R3);
		KEY_PAD.K_R4 = (1 << R4);
	}
	{
		KEY_PAD.K_C1 = (1 << C1);
		KEY_PAD.K_C2 = (1 << C2);
		KEY_PAD.K_C3 = (1 << C3);
		KEY_PAD.K_C4 = (1 << C4);
	}
	PIN_CFG_TypeDef GPIO_PIN_CFG;
	GPIO_PIN_CFG.PIN_NUMBER 	 = (KEY_PAD.K_R1 | KEY_PAD.K_R2 | KEY_PAD.K_R3 | KEY_PAD.K_R4);
	GPIO_PIN_CFG.__PinMode 		 = OUTPUT_MODE;
	#if MCU_DVICE == __STM32F103C6
		GPIO_PIN_CFG.CNF_OUTPUT_CASE = GPOutput_OpenDarain;
		GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
	#endif
	MCAL_GPIO_INIT(KEYPAD_GPIO_DATA, &GPIO_PIN_CFG);

	GPIO_PIN_CFG.PIN_NUMBER 	 = (KEY_PAD.K_C1 | KEY_PAD.K_C2 | KEY_PAD.K_C3 | KEY_PAD.K_C4);
	GPIO_PIN_CFG.__PinMode 		 = INPUT_MODE;
	#if MCU_DVICE == __STM32F103C6
		GPIO_PIN_CFG.CNF_INPUT_CASE  = Floating_input;
		GPIO_PIN_CFG.MODE_CASE       = Input_mode;
	#endif
	MCAL_GPIO_INIT(KEYPAD_GPIO_DATA, &GPIO_PIN_CFG);
	#if MCU_DVICE == __ATmega32
		MCAL_GPIO_WRITE_PORT(KEYPAD_GPIO_DATA, 0xFF);
	#endif
	//KEY_PORT = 0xFF;
}
//--------------Read inputs from Keypad.-------------------//
unsigned char HAL_KEY_READ_DATA(){
	volatile DataType_Pins* P_KEYPAD_R = &KEY_PAD.K_R1;
	volatile DataType_Pins* P_KEYPAD_C = &KEY_PAD.K_C1;
	uint8_t i,j;	
	for(i = 0; i < 4; i++)
	{
		#if MCU_DVICE == __ATmega32
			#define LOGIC_1					GPIO_PIN_SET
			#define LOGIC_2					GPIO_PIN_RESET
			#define CHECK_PIN_LOGIC()		!(MCAL_GPIO_READ_PIN(KEYPAD_GPIO_DATA, *P_KEYPAD_C))
		#else
			#define LOGIC_1					GPIO_PIN_RESET
			#define LOGIC_2					GPIO_PIN_SET
			#define CHECK_PIN_LOGIC()		(MCAL_GPIO_READ_PIN(KEYPAD_GPIO_DATA, *P_KEYPAD_C))
		#endif
		MCAL_GPIO_WRITE_PIN(KEYPAD_GPIO_DATA, ((KEY_PAD.K_R1) | (KEY_PAD.K_R2) | (KEY_PAD.K_R3) | (KEY_PAD.K_R4)), LOGIC_1);
		MCAL_GPIO_WRITE_PIN(KEYPAD_GPIO_DATA, *P_KEYPAD_R, LOGIC_2);
		#if MCU_DVICE == __STM32F103C6
			delay_ms(100);
		#endif
		for(j = 0; j < 4; j++)
		{					
			if(CHECK_PIN_LOGIC())
			{ 
 				while(CHECK_PIN_LOGIC());
				switch (j)
				{
					case 0:
						if(i == 0)
						{
							return '7';
						}
						else if(i == 1)
						{
							return '4';
						}
						else if(i == 2)
						{
							return '1';
						}
						else if(i == 3)
						{
							return 'N';
						}
						break;
					case 1:
						if(i == 0)
						{
							return '8';
						}
						else if(i == 1)
						{
							return '5';
						}
						else if(i == 2)
						{
							return '2';
						}
						else if(i == 3)
						{
							return '0';
						}
						break;
					case 2:
						if(i == 0)
						{
							return '9';
						}
						else if(i == 1)
						{
							return '6';
						}
						else if(i == 2)
						{
							return '3';
						}
						else if(i == 3)
						{
							return '=';
						}
							break;
					case 3:
						if(i == 0)
						{
							return '/';
						}
						else if(i == 1)
						{
							return '*';
						}
						else if(i == 2)
						{
							return '-';
						}
						else if(i == 3)
						{
							return '+';
						}
						break;					
				}
			}
			else
			{
			}
			P_KEYPAD_C++;
		}
		P_KEYPAD_R++;
		P_KEYPAD_C = &KEY_PAD.K_C1;		
	}
	return 'A';
}
//-------------------------------------------------------------------------------------------
