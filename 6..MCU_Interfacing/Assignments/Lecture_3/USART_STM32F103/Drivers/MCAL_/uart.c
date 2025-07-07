/*
 * uart.c
 *
 *  Created on: Jul 1, 2025
 *      Author: Abdulrhman
 */

#include "stm32f103xx_uart.h"
#include "stm32f103xx_rcc.h"

void (*GP_USARTx_IRQ[3])(void);

//=====================================================================================================
//********************************
//----- Generic Functions -------
//********************************
void UART_GPIO_SETUP(USARTx_REG_typedef *uart)
{
	PIN_CFG_TypeDef UART_GPIO_CNFG;
	GPIOx_REG_typedef *UART_GPIO;
	if(uart == USART1 || uart == USART2)
	{
		UART_GPIO = GPIOA;

		UART_GPIO_CNFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
		UART_GPIO_CNFG.MODE_CASE       = Output_mode_max_speed_10MHz;
		UART_GPIO_CNFG.__PinMode       = OUTPUT_MODE;
		if(uart == USART1)
			UART_GPIO_CNFG.PIN_NUMBER  = GPIO_PIN_9;
		else
			UART_GPIO_CNFG.PIN_NUMBER  = GPIO_PIN_2;
		MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);

		UART_GPIO_CNFG.CNF_INPUT_CASE = Floating_input;
		UART_GPIO_CNFG.MODE_CASE       = Input_mode;
		UART_GPIO_CNFG.__PinMode       = INPUT_MODE;
		if(uart == USART1)
			UART_GPIO_CNFG.PIN_NUMBER = GPIO_PIN_10;
		else
			UART_GPIO_CNFG.PIN_NUMBER = GPIO_PIN_3;
		MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);

		if(uart->CR3.RTSE_CTSE == CTS_EnableOnly || uart->CR3.RTSE_CTSE == CTS_RTS_Enable)
		{
			UART_GPIO_CNFG.CNF_INPUT_CASE = Floating_input;
			UART_GPIO_CNFG.MODE_CASE       = Input_mode;
			UART_GPIO_CNFG.__PinMode       = INPUT_MODE;
			if(uart == USART1)
				UART_GPIO_CNFG.PIN_NUMBER = GPIO_PIN_11;
			else
				UART_GPIO_CNFG.PIN_NUMBER = GPIO_PIN_0;
			MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);
		}
		else{}
		if(uart->CR3.RTSE_CTSE == RTS_EnableOnly || uart->CR3.RTSE_CTSE == CTS_RTS_Enable)
		{
			UART_GPIO_CNFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			UART_GPIO_CNFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			UART_GPIO_CNFG.__PinMode       = OUTPUT_MODE;
			if(uart == USART1)
				UART_GPIO_CNFG.PIN_NUMBER  = GPIO_PIN_12;
			else
				UART_GPIO_CNFG.PIN_NUMBER  = GPIO_PIN_1;
			MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);
		}
		else{}
	}
	else if(uart == USART3)
	{
		UART_GPIO = GPIOB;

		UART_GPIO_CNFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
		UART_GPIO_CNFG.MODE_CASE       = Output_mode_max_speed_10MHz;
		UART_GPIO_CNFG.__PinMode       = OUTPUT_MODE;
		UART_GPIO_CNFG.PIN_NUMBER 	   = GPIO_PIN_10;
		MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);

		UART_GPIO_CNFG.CNF_INPUT_CASE  = Floating_input;
		UART_GPIO_CNFG.MODE_CASE       = Input_mode;
		UART_GPIO_CNFG.__PinMode       = INPUT_MODE;
		UART_GPIO_CNFG.PIN_NUMBER 	   = GPIO_PIN_11;
		MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);

		if(uart->CR3.RTSE_CTSE == CTS_EnableOnly || uart->CR3.RTSE_CTSE == CTS_RTS_Enable)
		{
			UART_GPIO_CNFG.CNF_INPUT_CASE = Floating_input;
			UART_GPIO_CNFG.MODE_CASE       = Input_mode;
			UART_GPIO_CNFG.__PinMode       = INPUT_MODE;
			UART_GPIO_CNFG.PIN_NUMBER = GPIO_PIN_13;
			MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);
		}
		else{}
		if(uart->CR3.RTSE_CTSE == RTS_EnableOnly || uart->CR3.RTSE_CTSE == CTS_RTS_Enable)
		{
			UART_GPIO_CNFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			UART_GPIO_CNFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			UART_GPIO_CNFG.__PinMode       = OUTPUT_MODE;
			if(uart == USART1)
			UART_GPIO_CNFG.PIN_NUMBER  = GPIO_PIN_14;
			MCAL_GPIO_INIT(UART_GPIO, &UART_GPIO_CNFG);
		}
		else{}
	}
}

void SetBaudRate(USARTx_REG_typedef *uart, uint32_t *BaudRate)
{
	uint16_t USARTDIV;
	uint16_t USART_Mantissa;
	uint16_t DIV_Fraction;
	uint32_t F_ck;
	if(uart == USART1)
		F_ck = MCAL_GET_PCLK2();
	else
		F_ck = MCAL_GET_PCLK1();
	USARTDIV               = (uint16_t)((double)(F_ck * 100) / (double)(16 * *BaudRate));
	USART_Mantissa         = (uint16_t)(USARTDIV / 100);
	DIV_Fraction   		   = (uint16_t)(((USARTDIV % 100) * 16) / 100);
	uart->BRR.DIV_Mantissa = USART_Mantissa;
	uart->BRR.DIV_Fractio  = DIV_Fraction;
}
//=====================================================================================================
//********************************
//------------ APIs -------------
//********************************
void MCAL_UART_INIT(USARTx_REG_typedef *uart, USARTx_CFG *uart_config)
{
	if(uart == USART1 || uart == USART2)
	{
		if(uart == USART1)
			USART1_CLOCK_ENABLE();
		else
			USART2_CLOCK_ENABLE();
	}
	else if(uart == USART3)
	{
		USART3_CLOCK_ENABLE();
	}

	uart->CR1.UE  = UART_Enable;
	uart->CR1.M   = uart_config->WordLengh;
	uart->CR2.STOP = uart_config->StopBit;
	if(uart_config->TX_RX_Enable == UART_TxEnableOnly)
		uart->CR1.TE = Tx_Enable;
	else if(uart_config->TX_RX_Enable == UART_RxEnableOnly)
		uart->CR1.RE = Rx_Enable;
	else
	{
		uart->CR1.TE = Tx_Enable;
		uart->CR1.RE = Rx_Enable;
	}
	if(uart_config->Parity != Parity_Disable)
	{
		uart->CR1.PCE = (Parity_Disable - 1);
		uart->CR1.PS  = uart_config->Parity;
	}
	else
		uart->CR1.PCE = (Parity_Disable - Parity_Disable);

	uart->CR3.RTSE_CTSE = uart_config->HwFlowCtrl;
	UART_GPIO_SETUP(uart);

	SetBaudRate(uart, &uart_config->BaudRate);

	if(uart_config->Interrupt_Condition != UARTx_IRQ_InterruptDisable)
	{
		if(uart == USART1)
		{
			GP_USARTx_IRQ[0] = uart_config->P_UART_IRQ;
			NVIC_UART1_IRQ_ENABLE();
		}
		else if(uart == USART2)
		{
			GP_USARTx_IRQ[1] = uart_config->P_UART_IRQ;
			NVIC_UART2_IRQ_ENABLE();
		}
		else
		{
			GP_USARTx_IRQ[2] = uart_config->P_UART_IRQ;
			NVIC_UART3_IRQ_ENABLE();
		}
		UARTx_IRQ_SourceEnable(uart,uart_config->Interrupt_Condition);

	}
	else{}
}

void MCAL_UART_DeINIT(USARTx_REG_typedef *uart)
{
	if(uart == USART1)
	{
		USART1_CLOCK_DISABLE();
		NVIC_UART1_IRQ_DISABLE();
	}
	else if(uart == USART2)
	{
		USART2_CLOCK_DISABLE();
		NVIC_UART1_IRQ_DISABLE();
	}
	else if(uart == USART3)
	{
		USART3_CLOCK_DISABLE();
		NVIC_UART1_IRQ_DISABLE();
	}
}

void MCAL_UART_Transmit(USARTx_REG_typedef *uart, uint16_t *data, enum uart_machanism PolingMechanism)
{
	if(PolingMechanism == PollingEnable)
		while(!(uart->SR.TXE));
	else{}
	if(uart->CR1.M == WordLength_8)
		uart->DR = (*data & (uint8_t)0xFF);
	else
		uart->DR = (*data & (uint16_t)0x01FF);
	if(PolingMechanism == PollingEnable)
		while(!uart->SR.TC);
	else{}
}

void MCAL_UART_Recieve(USARTx_REG_typedef *uart, uint16_t *data, enum uart_machanism PolingMechanism)
{
	if(PolingMechanism == PollingEnable)
		while(!(uart->SR.RXNE));
	else{}
	if(uart->CR1.M == WordLength_8)
	{
		if(uart->CR1.PCE != Parity_Disable)
			*data = (uart->DR & (uint8_t)0x7F);
		else
			*data = (uart->DR & (uint8_t)0xFF);
	}
	else
	{
		if(uart->CR1.PCE != Parity_Disable)
			*data = (uart->DR & (uint16_t)0x01FF);
		else
			*data = (uart->DR & (uint16_t)0xFF);
	}
}


//=====================================================================================================
//**************************************************************
//------------ INTERRUPT REQUEST HANDLER DUNCTION -------------
//**************************************************************
void USART1_IRQHandler(void)
{
	GP_USARTx_IRQ[0]();
}

void USART2_IRQHandler(void)
{
	GP_USARTx_IRQ[1]();
}

void USART3_IRQHandler(void)
{
	GP_USARTx_IRQ[2]();
}
