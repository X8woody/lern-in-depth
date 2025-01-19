/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng/Abdulrhman Alaa-Eldin
 * @brief          : Clock Configuration
 *
 * @details        : Make APB1 Bus frequency 16MHZ, APB2 Bus frequency 8MHZ,
 	 	 	 	 	 AHB frequency 32 MHZ, SysClk 32 MHZ, Using internal HSI_RC.
 */

typedef volatile unsigned int vuint32_t ;

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define RCC_BASE       		0x40021000
#define RCC_CFGR			*((volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_CR				*((volatile uint32_t *)(RCC_BASE + 0x00))

void Clock_init();

int main(void)
{
	Clock_init();
	while(1)
	{

	}
}

void Clock_init()
{
	//Bits 1:0 SW: System clock switch
	//Set and cleared by software to select SYSCLK source.
	//Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	//failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	//System is enabled).
	//00: HSI selected as system clock
	//01: HSE selected as system clock
	//10: PLL selected as system clock
	//11: not allowed
	RCC_CFGR |= (0b10<<0);

	//	Bits 21:18 PLLMUL: PLL multiplication factor
	//	These bits are written by software to define the PLL multiplication factor. These bits can be
	//	written only when PLL is disabled.
	//	Caution: The PLL output frequency must not exceed 72 MHz.
	//	0000: PLL input clock x 2
	//	0001: PLL input clock x 3
	//	0010: PLL input clock x 4
	//	0011: PLL input clock x 5
	//	0100: PLL input clock x 6
	//	0101: PLL input clock x 7
	//	0110: PLL input clock x 8
	RCC_CFGR |= (0b0110<<18);


	//	Bit 24 PLLON: PLL enable
	//	Set and cleared by software to enable PLL.
	//	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	//	PLL clock is used as system clock or is selected to become the system clock.
	//	0: PLL OFF
	//	1: PLL ON
	RCC_CR |= (1<<24);

	//APB2 bus frequency 16MHz
	RCC_CFGR   |=  (0b100<<8);

	//APB2 bus frequency 8MHz
	RCC_CFGR   |=  (0b101<<11);
}
