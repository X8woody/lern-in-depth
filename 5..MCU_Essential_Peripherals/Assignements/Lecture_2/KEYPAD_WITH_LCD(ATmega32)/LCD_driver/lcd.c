/*
 * lcd.c
 *
 * Created: 4/29/2025 5:03:23 PM
 *  Author: Abdulrhman
 */ 
//-----------------------------
//Includes
#include "lcd.h"


//-----------------------------
/*----------------------API's_decalarations--------------------*/

//--------------Enable LCD to start read and write signals.-------------------//
void LCD_lcd_kick(void){
	DLCD_Signal_PORT |= EN_PIN;
	_delay_ms(1);
	DLCD_Signal_PORT &= ~EN_PIN;
}
//--------------Select mode of signal.-------------------//
void MODE_RW(MODE_RW_T MODE){
	#ifdef LCD_BIT_DATA_WIDTH_8
		#define DATA  0xFF
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4
		#define DATA 0xF0
	#endif
	DLCD_DATA_DIRE = (uint8_t)(DATA);	
	switch (MODE){
		case BF_MODE:
		    DLCD_DATA_DIRE &= ~((uint8_t)(DATA));
			DLCD_Signal_PORT |= RW_PIN;
			DLCD_Signal_PORT &= ~RS_PIN;
			break;
		case IR_MODE:
	    	DLCD_Signal_PORT &= ~(RS_PIN | RW_PIN);
			break;
		case DR_WRITE_MODE:
			DLCD_Signal_PORT |= RS_PIN;
			DLCD_Signal_PORT &= ~RW_PIN;		
			break;
		case DR_READ_MODE:
			DLCD_Signal_PORT |= (RS_PIN | RW_PIN);
		    break;			
	}
}
//--------------Check if LCD is busy or not.-------------------//
void CHK_FLG(void)
{
	MODE_RW(BF_MODE);
	LCD_lcd_kick();
	MODE_RW(IR_MODE);		
}
//--------------Send Internal code to control LCD.-------------------//
void FLCD_SEND_COMMAND(uint8_t MODE){	
	#ifdef LCD_BIT_DATA_WIDTH_8
		CHK_FLG();
		DLCD_DATA_OUT = MODE;
		LCD_lcd_kick();
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4
		uint8_t SHIFT_DATA;
		//CHK_FLG();
		SHIFT_DATA = (uint8_t)(MODE >> 4);
		SHIFT_DATA = (uint8_t)(SHIFT_DATA << 4);
		DLCD_DATA_OUT = (SHIFT_DATA);
		MODE_RW(IR_MODE);
		LCD_lcd_kick();	
		DLCD_DATA_OUT = (uint8_t)(MODE << 4);
		MODE_RW(IR_MODE);
		LCD_lcd_kick();
	#endif		
}
//--------------LCD Initializations.-------------------//
void FLCD_INIT()
{	
	_delay_ms(20);
	DLCD_Signal_OUT |= (EN_PIN | RS_PIN | RW_PIN);
	DLCD_Signal_PORT &= ~ (EN_PIN | RS_PIN | RW_PIN);
	DLCD_DATA_DIRE = 0xFF;
	_delay_ms(15);
	#ifdef LCD_BIT_DATA_WIDTH_8
		FLCD_SEND_COMMAND(DLCD_CLEAR_DISP);
		FLCD_SEND_COMMAND(DLCD_8_BIT_DATA);
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4
		FLCD_SEND_COMMAND(0x02);			
		FLCD_SEND_COMMAND(DLCD_4_BIT_DATA);
	#endif
	FLCD_SEND_COMMAND(DLCD_ENTRY_MODE);	
	FLCD_SEND_COMMAND(DLCD_BEGIN_AT_FIRST_ROW);
	FLCD_SEND_COMMAND(DLCD_DISP_ON);
}
//--------------Display single character.-------------------//
void FLCD_Write_CHAR(uint8_t data){
	#ifdef LCD_BIT_DATA_WIDTH_8
		CHK_FLG();
		DLCD_DATA_OUT = data;
		MODE_RW(DR_WRITE_MODE);
		LCD_lcd_kick();
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4	
		uint8_t SHIFT_DATA;
		//CHK_FLG();
		SHIFT_DATA = (uint8_t)(data >> 4);
		SHIFT_DATA = (uint8_t)(SHIFT_DATA << 4);
		DLCD_DATA_OUT = (SHIFT_DATA);
		MODE_RW(DR_WRITE_MODE);
		LCD_lcd_kick();
		DLCD_DATA_OUT = (uint8_t)(data << 4);
		MODE_RW(DR_WRITE_MODE);
		LCD_lcd_kick();
	#endif	
}
//--------------Create custom pattern.-------------------//
__STATUS_FUNC FLCD_Write_custom_CHAR(uint8_t* data, uint8_t Address){
	if(Address > 0x07)
		return ERROR;
	else
	{
		FLCD_SEND_COMMAND(DLCD_SET_CGRAM_ADD + (uint8_t)(Address * 0x08));
		uint8_t i;
		for (i = 0; i < 8; i++)
			FLCD_Write_CHAR(data[i]);	
		FLCD_SEND_COMMAND(DLCD_BEGIN_AT_FIRST_ROW);
		return DONE;       
	}		
}
//--------------Control cursor or display shift.-------------------//
void FLCD_SET_CURSOR(uint8_t LINE, uint8_t position)
{
	if(LINE == 0x01)
	{
		if (position < 16 && position >= 0)
			FLCD_SEND_COMMAND(DLCD_BEGIN_AT_FIRST_ROW + position);
		else{}
	}
	else if(LINE == 0x02)
	{
		if (position < 16 && position >= 0)
			FLCD_SEND_COMMAND(DLCD_BEGIN_AT_SECOND_ROW + position);
		else{}
	}
}
//--------------Display string.-------------------//
uint8_t FLCD_Write_STR(char* STR)
{
	uint8_t count = 0;
	while(*STR != '\0')
	{
		FLCD_Write_CHAR(*STR++);
		count++;
		if(count == 16)
			FLCD_SET_CURSOR(2, 0);
		else if(count == 32)
		{
			FLCD_SEND_COMMAND(DLCD_CLEAR_DISP);
			FLCD_SET_CURSOR(1, 0);
			count = 0;
		}
	}
	return count;
}
//-------------------------------------------------------------------------------------------