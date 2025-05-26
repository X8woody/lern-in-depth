/*
 * main.c
 *
 *  Created on: May 24, 2025
 *      Author: Abdulrhman
 */

#include "lcd.h"
#include "keypad.h"
#include "7seg.h"

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
uint8_t NUMBERS[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,A_LETT,B_LETT,C_LETT,D_LETT,E_LETT,F_LETT,H_LETT,G_LETT,L_LETT,O_LETT,P_LETT};
//-----------------------------
int main(void)
{
	HAL_KEY_INIT(0,1,2,3,4,5,6,7);
    HAL_LCD_INIT();
    HAL_7SEG_INIT(0, 1, 2, 3, 4, 5, 6);
	HAL_LCD_Write_custom_CHAR(char_1, Bell);
	HAL_LCD_Write_custom_CHAR(char_2, HEART);
	HAL_LCD_Write_STR(char_3);
	HAL_LCD_Write_CHAR(' ');
	HAL_LCD_Write_CHAR(Bell);
	HAL_LCD_Write_CHAR(HEART);
	_delay_ms(1500);
	HAL_LCD_SEND_COMMAND(DLCD_CLEAR_DISP);
	HAL_LCD_SET_CURSOR(1,0);
	uint8_t i;
	for(i = 0; i < (sizeof(NUMBERS)/sizeof(uint8_t)); i++)
	{
		HAL_7SEG_SEND_DATA(NUMBERS[i]);
		_delay_ms(1000);
	}
	while(1)
	{
		unsigned char data = HAL_KEY_READ_DATA();
		switch(data)
		{
			case 'A':
				break;
			case 'N':
				HAL_LCD_SEND_COMMAND(DLCD_CLEAR_DISP);
				HAL_LCD_SET_CURSOR(1,0);
				break;
			default:
				HAL_LCD_Write_CHAR(data);
				break;
		}
	}
	return 0;
}
