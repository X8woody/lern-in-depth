/*
 * Keypad.c
 *
 * Created: 4/29/2025 5:04:02 PM
 *  Author: Abdulrhman
 */ 
//-----------------------------
//Includes
#include "keypad.h"
#include "lcd.h"
//-----------------------------
//GLOBAL VARIABLE DECLARATION
//-----------------------------
KEYPAD_PINS KEY_PAD;
//-----------------------------
/*----------------------API's_decalarations--------------------*/
//--------------SET Columns and Rows of KEYPAD and initiate its pins.-------------------//
void KEY_INIT(volatile uint8_t R1, volatile uint8_t R2, volatile uint8_t R3, volatile uint8_t R4, volatile uint8_t C1, volatile uint8_t C2, volatile uint8_t C3, volatile uint8_t C4){
	KEY_PIN_I_O &= ~((1 << C1) | (1 << C2) | (1 << C3) | (1 << C4));
	KEY_PIN_I_O |= ((1 << R1) | (1 << R2) | (1 << R3) | (1 << R4));
	{
		KEY_PAD.K_R1 = R1;
		KEY_PAD.K_R2 = R2;
		KEY_PAD.K_R3 = R3;
		KEY_PAD.K_R4 = R4;
	}
	{
		KEY_PAD.K_C1 = C1;
		KEY_PAD.K_C2 = C2;
		KEY_PAD.K_C3 = C3;
		KEY_PAD.K_C4 = C4;
	}
	KEY_PORT = 0xFF;	
}
//--------------Read inputs from Keypad.-------------------//
unsigned char KEY_READ_DATA(){
	volatile uint8_t* P_KEYPAD_R = &KEY_PAD.K_R1;
	volatile uint8_t* P_KEYPAD_C = &KEY_PAD.K_C1;
	uint8_t i,j;	
	for(i = 0; i < 4; i++)
	{
		KEY_PORT |= ((1 << (KEY_PAD.K_R1)) | (1 << (KEY_PAD.K_R2)) | (1 << (KEY_PAD.K_R3)) | (1 << (KEY_PAD.K_R4)));
		KEY_PORT &= ~(1 << (*P_KEYPAD_R));		
		for(j = 0; j < 4; j++)
		{					
			if(!(KEY_PIN_READ & (1 << (*P_KEYPAD_C))))
			{ 
 				while(!(KEY_PIN_READ & (1 << (*P_KEYPAD_C))));
				switch (j)
				{
					case 0:
						if(i == 0)
							return '7';
						else if(i == 1)
							return '4';
						else if(i == 2)
							return '1';
						else if(i == 3)
							return 'N';
						break;
					case 1:
						if(i == 0)
							return '8';
						else if(i == 1)
							return '5';
						else if(i == 2)
							return '2';
						else if(i == 3)
							return '0';
							break;	
					case 2:
						if(i == 0)
							return '9';
						else if(i == 1)
							return '6';
						else if(i == 2)
							return '3';
						else if(i == 3)
							return '=';
							break;
					case 3:
						if(i == 0)
							return '/';
						else if(i == 1)
							return '*';
						else if(i == 2)
							return '-';
						else if(i == 3)
							return '+';
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