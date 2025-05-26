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
/*----------------------Helpful Functions--------------------*/
#if MCU_DVICE == __STM32F103C6

void _delay_ms(uint32_t __ms)
{
	uint32_t i,j;
	for(i = 0; i < __ms; i++)
		for(j = 0; j < 255; j++);
}
#endif
void LCD_GPIO_INIT()
{
	_delay_ms(20);
	PIN_CFG_TypeDef GPIO_CFG;
	GPIO_CFG.PIN_NUMBER 	 = (EN_PIN | RS_PIN | RW_PIN);
	GPIO_CFG.__PinMode 		 = OUTPUT_MODE;
#if MCU_DVICE == __STM32F103C6
	GPIO_CFG.CNF_OUTPUT_CASE = GPOutput_OpenDarain;
	GPIO_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
#endif
	MCAL_GPIO_INIT(LCD_GPIO_Signal, &GPIO_CFG);

	MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, (EN_PIN | RS_PIN | RW_PIN), GPIO_PIN_RESET);

	GPIO_CFG.PIN_NUMBER      = (DataType_Pins)0xFFFF;
	GPIO_CFG.__PinMode       = OUTPUT_MODE;
#if MCU_DVICE == __STM32F103C6
	GPIO_CFG.CNF_OUTPUT_CASE = GPOutput_OpenDarain;
	GPIO_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
#endif
	MCAL_GPIO_INIT(LCD_GPIO_DATA, &GPIO_CFG);
	_delay_ms(15);	
}
//--------------Enable LCD to start read and write signals.-------------------//
void LCD_lcd_kick(void){
	MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal,EN_PIN,GPIO_PIN_SET);
	_delay_ms(5);
	MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, EN_PIN, GPIO_PIN_RESET);
}
//--------------Select mode of signal.-------------------//
void MODE_RW(MODE_RW_T MODE){
	#ifdef LCD_BIT_DATA_WIDTH_8
		#define DATA  0xFF
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4
		#define DATA 0xF0
	#endif
	MCAL_GPIO_SET_DataDire(LCD_GPIO_DATA, OUTPUT_MODE, DATA);
	switch (MODE){
		case BF_MODE:
			MCAL_GPIO_SET_DataDire(LCD_GPIO_DATA, INPUT_MODE, DATA);
		    MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, RW_PIN, GPIO_PIN_SET);
			MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, RS_PIN, GPIO_PIN_RESET);
			break;
		case IR_MODE:
			MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, (RS_PIN | RW_PIN), GPIO_PIN_RESET);		
			break;
		case DR_WRITE_MODE:
			MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, RS_PIN, GPIO_PIN_SET);
			MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, RW_PIN, GPIO_PIN_RESET);		
			break;
		case DR_READ_MODE:
			MCAL_GPIO_WRITE_PIN(LCD_GPIO_Signal, (RS_PIN | RW_PIN), GPIO_PIN_SET);		
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
void HAL_LCD_SEND_COMMAND(uint8_t MODE){
	#ifdef LCD_BIT_DATA_WIDTH_8
		#if MCU_DVICE == __ATmega32
			CHK_FLG();
		#endif
		MCAL_GPIO_WRITE_PORT(LCD_GPIO_DATA, MODE);
		LCD_lcd_kick();
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4
		uint8_t SHIFT_DATA;
		#if MCU_DVICE == __ATmega32
			//CHK_FLG();
		#endif
		SHIFT_DATA = (uint8_t)(MODE >> 4);
		SHIFT_DATA = (uint8_t)(SHIFT_DATA << 4);
		MCAL_GPIO_WRITE_PORT(LCD_GPIO_DATA, SHIFT_DATA);
		MODE_RW(IR_MODE);
		LCD_lcd_kick();
		MCAL_GPIO_WRITE_PORT(LCD_GPIO_DATA, (uint8_t)(MODE << 4));
		MODE_RW(IR_MODE);
		LCD_lcd_kick();
	#endif		
}
//--------------LCD Initializations.-------------------//
void HAL_LCD_INIT()
{	
	LCD_GPIO_INIT();
	#ifdef LCD_BIT_DATA_WIDTH_8
		HAL_LCD_SEND_COMMAND(DLCD_CLEAR_DISP);
		HAL_LCD_SEND_COMMAND(DLCD_8_BIT_DATA);
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4
		HAL_LCD_SEND_COMMAND(0x02);			
		HAL_LCD_SEND_COMMAND(DLCD_4_BIT_DATA);
	#endif
	HAL_LCD_SEND_COMMAND(DLCD_ENTRY_MODE);	
	HAL_LCD_SEND_COMMAND(DLCD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_SEND_COMMAND(DLCD_DISP_ON);
}
//--------------Display single character.-------------------//
void HAL_LCD_Write_CHAR(uint8_t data){
	#ifdef LCD_BIT_DATA_WIDTH_8
		#if MCU_DVICE == __ATmega32
			CHK_FLG();
		#endif
		MCAL_GPIO_WRITE_PORT(LCD_GPIO_DATA, data);
		MODE_RW(DR_WRITE_MODE);
		LCD_lcd_kick();
	#endif
	#ifdef LCD_BIT_DATA_WIDTH_4	
		uint8_t SHIFT_DATA;
		#if MCU_DVICE == __ATmega32
			//CHK_FLG();
		#endif
		SHIFT_DATA = (uint8_t)(data >> 4);
		SHIFT_DATA = (uint8_t)(SHIFT_DATA << 4);
		MCAL_GPIO_WRITE_PORT(LCD_GPIO_DATA, SHIFT_DATA);
		MODE_RW(DR_WRITE_MODE);
		LCD_lcd_kick();
		MCAL_GPIO_WRITE_PORT(LCD_GPIO_DATA, (uint8_t)(data << 4));
		MODE_RW(DR_WRITE_MODE);
		LCD_lcd_kick();
	#endif	
}
//--------------Create custom pattern.-------------------//
__STATUS_FUNC HAL_LCD_Write_custom_CHAR(uint8_t* data, uint8_t Address){
	if(Address > 0x07)
		return ERROR;
	else
	{
		HAL_LCD_SEND_COMMAND(DLCD_SET_CGRAM_ADD + (uint8_t)(Address * 0x08));
		uint8_t i;
		for (i = 0; i < 8; i++)
			HAL_LCD_Write_CHAR(data[i]);	
		HAL_LCD_SEND_COMMAND(DLCD_BEGIN_AT_FIRST_ROW);
		return DONE;       
	}		
}
//--------------Control cursor or display shift.-------------------//
void HAL_LCD_SET_CURSOR(uint8_t LINE, uint8_t position)
{
	if(LINE == 0x01)
	{
		if (position < 16 && position >= 0)
			HAL_LCD_SEND_COMMAND(DLCD_BEGIN_AT_FIRST_ROW + position);
		else{}
	}
	else if(LINE == 0x02)
	{
		if (position < 16 && position >= 0)
			HAL_LCD_SEND_COMMAND(DLCD_BEGIN_AT_SECOND_ROW + position);
		else{}
	}
}
//--------------Display string.-------------------//
uint8_t HAL_LCD_Write_STR(char* STR)
{
	uint8_t count = 0;
	while(*STR != '\0')
	{
		HAL_LCD_Write_CHAR(*STR++);
		count++;
		if(count == 16)
			HAL_LCD_SET_CURSOR(2, 0);
		else if(count == 32)
		{
			HAL_LCD_SEND_COMMAND(DLCD_CLEAR_DISP);
			HAL_LCD_SET_CURSOR(1, 0);
			count = 0;
		}
	}
	return count;
}
//-------------------------------------------------------------------------------------------
