/*
 * uart.c
 *
 *  Created on: Jun 2, 2025
 *      Author: Abdulrhman
 */

#include "uart.h"



void MCAL_USART_INIT(USART_CFG_t *CONFIG_UART)
{
/*
	PIN_CFG_TypeDef GPIO_CONFIG;
	GPIO_CONFIG.PIN_NUMBER = (TX_PIN | RX_PIN);
	GPIO_CONFIG.__PinMode  = OUTPUT_MODE;
	MCAL_GPIO_INIT(USART_GPIO, &GPIO_CONFIG);*/

	USART_REG_t *USART_REG = USART;
	uint16_t UBRR_Value = (uint16_t)(((FOSC) / ((UBRR_Value(CONFIG_UART->Operation_Mode)) * (CONFIG_UART->BAUDRATE))) - 1);
	*UBRRH_Reg = (UBRRH_SELECT << 7) | ((uint8_t)((UBRR_Value >> 8) & 0x0F));	
	USART_REG->USART_Baud_Rate_Register_Low = (uint8_t)(UBRR_Value);


	if(CONFIG_UART->Operation_Mode == AsynchDoubleSpeedMode)
		USART_REG->USART_STATUS_FLAGS.Double_USART_Transmission_Speed = USART_U2X_DoubleSpeed;
	else
		USART_REG->USART_STATUS_FLAGS.Double_USART_Transmission_Speed = USART_U2X_NormalSpeed;

	USART_REG->USART_STATUS_ENABLE.Character_Size_2 = (uint8_t)(CONFIG_UART->Size_data >> 2);

	USART_REG->USART_STATUS_ENABLE.Transmitter_Enable = TX_ENABLE;

	USART_REG->USART_STATUS_ENABLE.Reciever_Enable = RX_ENABLE;

	USART_REG->USART_STATUS_MODES.Register_Select = UCSRC_SELECT;

	if(CONFIG_UART->Operation_Mode != SynchMasterMode)
	{
		USART_REG->USART_STATUS_MODES.Mode_Select    = AsynchMOde;
		USART_REG->USART_STATUS_MODES.Clock_Polarity = AsynchMOde;
	}
	else
	{
		USART_REG->USART_STATUS_MODES.Mode_Select    = SynchMode;
		USART_REG->USART_STATUS_MODES.Clock_Polarity = CONFIG_UART->CLK_POL;
	}

	USART_REG->USART_STATUS_MODES.Parity_Mode_01 = CONFIG_UART->Parity;

	USART_REG->USART_STATUS_MODES.Stop_Bit_Select = CONFIG_UART->Stopbit;

	USART_REG->USART_STATUS_MODES.Character_Size_01 = CONFIG_UART->Size_data;
}


MCAL_STATUS_enum MCAL_USART_TRANSMIT(USART_REG_t *usart, uint8_t *data, uint32_t SIZE)
{
	while(SIZE--)
	{
		while(usart->USART_STATUS_FLAGS.USART_Data_Register_Empty == USART_NotReady);
		usart->USART_IO_DATA_REG = data[SIZE];
		while(!usart->USART_STATUS_FLAGS.USART_Transmit_Complete);		
	}
	return MCAL_OK;
}
MCAL_STATUS_enum MCAL_USART_RECIEVER(USART_REG_t * usart, uint8_t *data)
{
	while(!usart->USART_STATUS_FLAGS.USART_Receive_Complete);
	*data = (usart->USART_IO_DATA_REG);
	return MCAL_OK;
}