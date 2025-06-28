/*
 * uart.h
 *
 *  Created on: Jun 2, 2025
 *      Author: Abdulrhman
 */

#ifndef MCAL__INCLUDE_UART_H_
#define MCAL__INCLUDE_UART_H_

#include "Atmega32_gpio.h"
#include "service.h"

#define TX_PIN                     		GPIO_PIN_1
#define RX_PIN							GPIO_PIN_0

#define USART_GPIO						GPIOD
#define USART_REGISTER					(USART_REG_t *)(&UBRRL)

#define FOSC							8000000UL
#define BaudRate						9600UL

#define UBRR_Value(OP_Mode)             ((OP_Mode == AsynchNormalMode)? 16 : (OP_Mode == AsynchDoubleSpeedMode)? 8 : 2)

#define UBRRH_Reg                       (volatile unsigned char *)(&UBRRH)
#define USART							(USART_REG_t *)(&UBRRL)


#define USART_U2X_DoubleSpeed			0b1
#define USART_U2X_NormalSpeed			0b0

#define TX_ENABLE						0b1
#define RX_ENABLE						0b1

#define TX_DISABLE                      0b0
#define RX_DISABLE						0b0

#define UBRRH_SELECT					0b0

#define UCSRC_SELECT					0b1




typedef enum
{
	AsynchNormalMode       = 0u,
	AsynchDoubleSpeedMode,
	SynchMasterMode
}Operating_Mode_enum;

typedef enum
{
	AsynchMOde = 0b0,
	SynchMode  = 0b1
}AsynchMode_enum;

typedef enum
{
	Disable  = 0b00,
	Reserved = 0b01,
	EnableEvenParity = 0b10,
	EnableOddParity  = 0b11
}ParityMode_enum;

typedef enum
{
	OneBit = 0b0,
	TwoBit = 0b1
}StopBitSelect_enum;

typedef enum
{
	FiveBit      = 0b000,
	SixBit       = 0b001,
	SevenBit     = 0b010,
	EightBit     = 0b011,
	ReservedBit1 = 0b100,
	ReservedBit2 = 0b101,
	ReservedBit3 = 0b110,
	NineBit      = 0b111
}CharSize_enum;

typedef enum
{
	TxRising_RxFalling = 0b0,
	TxFalling_RxRising = 0b1
}ClockPolarity_enum;

typedef struct
{
	volatile unsigned char Multi_processor_Communication_Mode 					: 1;     	// MPCM bit.
	volatile unsigned char Double_USART_Transmission_Speed    					: 1;		// U2X bit.
	volatile unsigned char Parity_Error    										: 1;		// PE bit.
	volatile unsigned char Data_OverRun											: 1;		// DOR bit.
	volatile unsigned char Frame_Error						 					: 1;		// FE bit.
	volatile unsigned char USART_Data_Register_Empty		 					: 1;		// UDRE bit.
	volatile unsigned char USART_Transmit_Complete 								: 1;		// TXC bit.
	volatile unsigned char USART_Receive_Complete 								: 1;		// RXC bit.
}UCSRA_REG;

typedef struct
{
	volatile unsigned char Transmit_Data_Bit_8 									: 1;     	// TXB8 bit.
	volatile unsigned char Recieve_Data_Bit_8   			 					: 1;		// RXB8 bit.
	volatile unsigned char Character_Size_2    									: 1;		// UCSZ2 bit.
	volatile unsigned char Transmitter_Enable									: 1;		// TXEN bit.
	volatile unsigned char Reciever_Enable					 					: 1;		// RXEN bit.
	volatile unsigned char USART_Data_Register_Empty_Interrupt_Enable		 	: 1;		// UDRIE bit.
	volatile unsigned char TX_Complete_Interrupt_Enable 						: 1;		// TXCIE bit.
	volatile unsigned char RX_Complete_Interrupt_Enable 						: 1;		// RXCIE bit.
}UCSRB_REG;

typedef struct
{
	volatile unsigned char Clock_Polarity		 								: 1;     	// UCPOL bit.
	volatile unsigned char Character_Size_01		   			 				: 2;		// UCSZ0/UCSZ1 bit.
	volatile unsigned char Stop_Bit_Select										: 1;		// USBS bit.
	volatile unsigned char Parity_Mode_01			     		 				: 2;		// UPM0/UPM1 bit.
	volatile unsigned char Mode_Select										 	: 1;		// UMSEL bit.
	volatile unsigned char Register_Select				 						: 1;		// URSEL bit.
}UCSRC_REG;



typedef struct
{
	volatile unsigned char USART_Baud_Rate_Register_Low ;									//UBRRL Register.
	UCSRB_REG USART_STATUS_ENABLE;        													//UCSRB Register.
	UCSRA_REG USART_STATUS_FLAGS;															//UCSRA Register.
	volatile unsigned char USART_IO_DATA_REG;												//UDR   Register.
	unsigned char RESERVED_UrtReg[19];
	UCSRC_REG USART_STATUS_MODES;															//UCSRC/UBRRH Register.
}USART_REG_t;

typedef struct
{
	unsigned long int   BAUDRATE;
	Operating_Mode_enum Operation_Mode;
	ClockPolarity_enum  CLK_POL;
	CharSize_enum     	Size_data;
	StopBitSelect_enum 	Stopbit;
	ParityMode_enum		Parity;
}USART_CFG_t;

typedef enum
{
	USART_NotReady = 0u,
	USART_Ready
}MCAL_FLAGS_STATUS;

void MCAL_USART_INIT(USART_CFG_t *CONFIG_UART);

MCAL_STATUS_enum MCAL_USART_TRANSMIT(USART_REG_t *usart, uint8_t *data, uint32_t SIZE);
MCAL_STATUS_enum MCAL_USART_RECIEVER(USART_REG_t *usart, uint8_t *data);

#endif /* MCAL__INCLUDE_UART_H_ */
