/*
 * ATmega32_Interrup
 *
 * Created: 1/27/2025 6:09:54 PM
 * Author : Abdulrhman
 */

#include "uart.h"
#include "lcd.h"

void SEND_STATUS(MCAL_STATUS_enum CHK)
{
	if (CHK == MCAL_OK)
	{
		HAL_LCD_Write_STR("MCAL_OK");
	}
	else
	{
		HAL_LCD_Write_STR("MCAL_ERROR");
	}
}

int main(void)
{
	HAL_LCD_INIT();
	USART_CFG_t USART_CONFIG;
	USART_CONFIG.BAUDRATE = BaudRate;
	USART_CONFIG.Operation_Mode = AsynchNormalMode;
	USART_CONFIG.Size_data      = EightBit;
	USART_CONFIG.Stopbit      	= OneBit;
	USART_CONFIG.Parity         = Disable;
	MCAL_USART_INIT(&USART_CONFIG);
	uint8_t str[6] = "HAMADA";
	uint8_t buff; 
	MCAL_USART_TRANSMIT(USART, str, sizeof(str));
	while(1)
	{
		MCAL_USART_RECIEVER(USART, &buff);
		HAL_LCD_Write_CHAR(buff);
	}
	return 0;
}