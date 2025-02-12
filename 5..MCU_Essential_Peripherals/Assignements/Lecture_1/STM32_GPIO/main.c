/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng/Abdulrhman Alaa-Eldin
 * @brief          : GPIO Configuration
 *
 * @details        : Enable GPIOA,GPIOB and Make PORTA and PORTB ----> "Pin 13" as OUTPUT,
 * 					 "PIN 1" as INPUT.
 *
 **/

#include "stdio.h"
#include "stdint.h"


/******************************************************************************/
//RCC Register
#define RCC_BASE					0x40021000
#define RCC_APB2ENR		       		*(volatile uint32_t *)(RCC_BASE + 0x18)
/******************************************************************************/
//GPIOA Register
#define GPIOA_BASE					0x40010800
#define GPIOA_CRL	         		*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH	         		*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_IDR	          		*(volatile uint32_t *)(GPIOA_BASE + 0x08)
/******************************************************************************/
//GPIOB Register
#define GPIOB_BASE					0x40010C00
#define GPIOB_CRL	         		*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH	         		*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR	          		*(volatile uint32_t *)(GPIOB_BASE + 0x0C)
/******************************************************************************/
#define GPIO_Read(PORT,PIN)    		((GPIO##PORT##_IDR & (1<<PIN)) >> PIN)
#define GPIO_Toggle(PORT,PIN) 		(GPIO##PORT##_ODR ^= (1<<PIN))
#define TRUE						1UL
#define FALSE						0UL
/******************************************************************************/
void delay(uint32_t T);
void CLOCK_INIT(void);
void GPIOA_INIT(void);
/******************************************************************************/

int main(void)
{
	CLOCK_INIT();
	GPIOA_INIT();
	while(1)
	{
		if(GPIO_Read(A,1) == FALSE)
		{
			while(GPIO_Read(A,1) == FALSE);
			GPIO_Toggle(B,1);
		}
		if(GPIO_Read(A,13))
		{
			GPIO_Toggle(B,13);
			delay(50);
		}
	}
	return 0;
}

void CLOCK_INIT(void)
{
	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled
	RCC_APB2ENR |= (1<<2);


	//	Bit 3 IOPBEN: IO port B clock enable
	//	Set and cleared by software.
	//	0: IO port B clock disabled
	//	1: IO port B clock enabled
	RCC_APB2ENR |= (1<<3);
}

void GPIOA_INIT(void)
{
	//Configure PORTA PIN 1 as Floating INPUT.
	GPIOA_CRL |= (0b01<<6);

	//Configure PORTA PIN 13 as Floating INPUT.
	GPIOA_CRH |= (0b01<<22);

    //Configure PORTB PIN 13 as OUTPUT PUSH/PULL Mode.
	GPIOB_CRH |= 0xFF0FFFFF;
	GPIOB_CRH |= 0x00200000;

    //Configure PORTB PIN 1 as OUTPUT PUSH/PULL Mode.
	GPIOB_CRL |= 0xFFFFFF0F;
	GPIOB_CRL |= 0x00000020;
}

void delay(uint32_t T)
{
	uint32_t i;
	for(i = 0; i < (T*2500); i++);
}
