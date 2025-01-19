/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng/Abdulrhman Alaa-Eldin
 * @brief          : Clock Configuration
 *
 * @details        : Make APB1 Bus frequency 4MHZ, APB2 Bus frequency 2MHZ,
 	 	 	 	 	 AHB frequency 8 MHZ, SysClk 8 MHZ, Using internal HSI_RC.
 */

typedef volatile unsigned int vuint32_t ;

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define RCC_BASE       		0x40021000
#define RCC_CFGR			*((volatile uint32_t *)(RCC_BASE + 0x04))

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
	/*
	 * By default :
	 * Internal HSI_RC is selected.
	 * AHB frequency is divided by 1.
	 * SysClk is 8 MHZ by SW selector.
	 */

	//APB2 bus frequency 4MHz
	RCC_CFGR   |=  (4<<8);

	//APB2 bus frequency 2MHz
	RCC_CFGR   |=  (5<<11);
}
