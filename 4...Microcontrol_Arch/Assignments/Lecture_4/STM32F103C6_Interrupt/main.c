/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng/Abdulrhman Alaa-Eldin
 * @brief          : Interrupt Configuration
 *
 * @details        : Enable EXTI0 and Make PORTA ----> "Pin 13" toggling when IRQ0 occur.
 *
 **/

#include "stdio.h"
#include "stdint.h"


/******************************************************************************/
//NVIC modules' register
#define NVIC_BASE 				0xE000E100
#define NVIC_ISER0				*(volatile uint32_t *)(NVIC_BASE + 0x00)
/******************************************************************************/
//RCC Register
#define RCC_BASE				0x40021000
#define RCC_APB2ENR		       	*(volatile uint32_t *)(RCC_BASE + 0x18)
/******************************************************************************/
//GPIOA Register
#define GPIOA_BASE				0x40010800
#define GPIOA_CRL	         	*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH	         	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	          	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
/******************************************************************************/
//EXTI0 Register
#define EXTI_BASE				0x40010400
#define EXTI_IMR                *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR               *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR	                *(volatile uint32_t *)(EXTI_BASE + 0x14)
/******************************************************************************/
//AFIO Register
#define AFIO_BASE				0x40010000
#define AFIO_EXTICR1            *(volatile uint32_t *)(AFIO_BASE + 0x08)

/******************************************************************************/
void CLOCK_INIT(void);
void GPIOA_INIT(void);
void EXTI_INIT(void);
/******************************************************************************/

int main(void)
{
	CLOCK_INIT();
	GPIOA_INIT();
	EXTI_INIT();
	while(1)
	{
	}
	return 0;
}



void CLOCK_INIT(void)
{
	//	Bit 0 AFIOEN: Alternate function IO clock enable
	//	Set and cleared by software.
	//	0: Alternate Function IO clock disabled
	//	1: Alternate Function IO clock enabled
	RCC_APB2ENR |= (1<<0);


	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled
	RCC_APB2ENR |= (1<<2);
}

void GPIOA_INIT(void)
{
	//	EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
	//	These bits are written by software to select the source input for EXTIx external interrupt.s
	//	0000: PA[x] pin
	//	0001: PB[x] pin
	//	0010: PC[x] pin
	//	0011: PD[x] pin
	//	0100: PE[x] pin
	//	0101: PF[x] pin
	//	0110: PG[x] pin
	AFIO_EXTICR1 &= ~(0b0000<<0);

	//Configure PORTA PIN 0 as Floating INPUT.
	GPIOA_CRL |= (0b01<<2);

    //Configure PORTA PIN 13 as OUTPUT.
	GPIOA_CRH |= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

}

void EXTI_INIT(void)
{
	//	Bits 31:0 SETENA[31:0]: Interrupt set-enable bits.
	//	Write:
	//	0: No effect
	//	1: Enable interrupt
	//	Read:
	//	0: Interrupt disabled
	//	1: Interrupt enabled.
	NVIC_ISER0 |= (1<<6);


	//	MRx: Interrupt Mask on line x
	//	0: Interrupt request from Line x is masked
	//	1: Interrupt request from Line x is not masked
	EXTI_IMR |= (1<<0);


	//	TRx: Rising trigger event configuration bit of line x
	//	0: Rising trigger disabled (for Event and Interrupt) for input line
	//	1: Rising trigger enabled (for Event and Interrupt) for input line.
	EXTI_RTSR |= (1<<0);

	//	PRx: Pending bit
	//	0: No trigger request occurred
	//	1: selected trigger request occurred
	//	This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//	cleared by writing a ‘1’ into the bit
	EXTI_PR |= (1<<0);
}

void EXTI0_IRQHandler(void)
{
	//Toggling PORTA >>> PIN 13.
	GPIOA_ODR ^= (1<<13);


	//	PRx: Pending bit
	//	0: No trigger request occurred
	//	1: selected trigger request occurred
	//	This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//	cleared by writing a ‘1’ into the bit.
	EXTI_PR |= (1<<0);
}
