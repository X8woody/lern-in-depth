/*
 * uart.h
 *
 *  Created on: Jul 1, 2025
 *      Author: Abdulrhman
 */

#ifndef MCAL__INCLUDE_STM32F103XX_UART_H_
#define MCAL__INCLUDE_STM32F103XX_UART_H_

#include "stm32f103x6_gpio.h"

#define uart1																USART1
#define uart2																USART2
#define uart3																USART3

#define WordLength_8														(uint8_t)(0x0)
#define WordLength_9														1u

#define StopBit_1															0u
#define StopBit_Half														1u
#define StopBit_2															2u
#define StopBit_OneHalf														3u

#define Parity_Disable														2u
#define Parity_Even															0u
#define Parity_Odd															1u

#define	UART_TxEnableOnly													0u
#define UART_RxEnableOnly													1u
#define UART_TxRxEnable														2u

#define Tx_Disable															0u
#define Tx_Enable															1u

#define Rx_Disable															0u
#define Rx_Enable															1u


#define RTS_EnableOnly														0b01
#define CTS_EnableOnly														0b10
#define CTS_RTS_Enable														0b11
#define CTS_RTS_Disable														0b00


#define UART_Enable															1u
#define UART_Disable														0u


//Interrupt Event
#define UARTx_IRQ_InterruptDisable											0u

#define UARTx_IRQ_Tx_dataRegEmpty_Enable									UARTx_TXEIE_Enable
#define UARTx_IRQ_DataTransmitComplete_Enable								UARTx_TCIE_Enable
#define UARTx_IRQ_Rx_dataReady_Enable										UARTx_RXNEIE_Enable
#define UARTx_IRQ_ParityError_Enable										UARTx_PEIE_Enable

#define UARTx_IRQ_Tx_dataRegEmpty_Disable									UARTx_TXEIE_Disable
#define UARTx_IRQ_DataTransmitComplete_Disable								UARTx_TCIE_Disable
#define UARTx_IRQ_Rx_dataReady_Disable										UARTx_RXNEIE_Disable
#define UARTx_IRQ_ParityError_Disable										UARTx_PEIE_Disable
//----------------------------------------------------------------------

#define UARTx_BAUDRATE_2400													2400U
#define UARTx_BAUDRATE_4800													4800U
#define UARTx_BAUDRATE_9600													9600U
#define UARTx_BAUDRATE_19200												19200U
#define UARTx_BAUDRATE_38400												38400U
#define UARTx_BAUDRATE_57600												57600U
#define UARTx_BAUDRATE_115200												115200U

//====================================================================================================
typedef struct
{
	uint32_t BaudRate;
	uint8_t  WordLengh;
	uint8_t  StopBit;
	uint8_t  Parity;
	uint8_t  TX_RX_Enable;
	uint8_t  Interrupt_Condition;
	uint8_t  HwFlowCtrl;
	void (*P_UART_IRQ)(void);
}USARTx_CFG;

enum uart_machanism
{
	PollingDisable,
	PollingEnable
};


void MCAL_UART_INIT(USARTx_REG_typedef *uart, USARTx_CFG *uart_config);
void MCAL_UART_DeINIT(USARTx_REG_typedef *uart);

void MCAL_UART_Transmit(USARTx_REG_typedef *uart, uint16_t *data, enum uart_machanism PolingMechanism);
void MCAL_UART_Recieve(USARTx_REG_typedef *uart, uint16_t *data, enum uart_machanism PolingMechanism);

#endif /* MCAL__INCLUDE_STM32F103XX_UART_H_ */
