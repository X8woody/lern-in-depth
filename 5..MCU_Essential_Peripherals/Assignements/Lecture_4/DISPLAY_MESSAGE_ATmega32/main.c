/*
 * main.c
 *
 *  Created on: May 31, 2025
 *      Author: Abdulrhman
 */

#include "lcd.h"

int main(void)
{
	HAL_LCD_INIT();
	HAL_LCD_SEND_COMMAND(DLCD_CLEAR_DISP);
	HAL_LCD_Write_STR("Learn In Depth");
	while(1)
	{
	}
	return 0;
}
