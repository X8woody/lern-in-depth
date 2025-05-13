/*
 * KEYPAD_LCD.c
 *
 * Created: 4/29/2025 4:48:35 PM
 * Author : Abdulrhman
 */ 
//-----------------------------
//Includes
//-----------------------------
#include "lcd.h"
#include "keypad.h"
//-----------------------------
//Macros Data References
//-----------------------------
#define Bell							0x00
#define HEART							0x01

//-----------------------------
//GLOBAL VARIABLE DECLARATION
//-----------------------------
uint8_t char_1[8] = {0x04,0x0E,0x0E,0x0E,0x1F,0x00,0x04,0x00};
uint8_t char_2[8] = {0b00000,0b11011,0b11111,0b11111,0b01110,0b00100,0b00000,0b00000};
char char_3[]     = "Abdulrhman Alaa-Eldin";

//-----------------------------
int main(void)
{
	KEY_INIT(0,1,2,3,4,5,6,7);
    FLCD_INIT();
	FLCD_Write_custom_CHAR(char_1, Bell);
	FLCD_Write_custom_CHAR(char_2, HEART);
	FLCD_Write_STR(char_3);
	FLCD_Write_CHAR(' ');
	FLCD_Write_CHAR(Bell); 
	FLCD_Write_CHAR(HEART);
	_delay_ms(1500);
	FLCD_SEND_COMMAND(DLCD_CLEAR_DISP);
	FLCD_SET_CURSOR(1,0);	
    while (1) 
    {
		unsigned char data = KEY_READ_DATA();
		switch(data)
		{
			case 'A':
				break;
			case 'N':
				FLCD_SEND_COMMAND(DLCD_CLEAR_DISP);
				FLCD_SET_CURSOR(1,0);
				break;
			default:
				FLCD_Write_CHAR(data);
				break;
		}
    }
}

