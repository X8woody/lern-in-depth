/*
 * stm32f103x6.h
 *
 *  Created on: May 18, 2025
 *      Author: Abdulrhman
 */

#ifndef MCU_DEVICE_CNFG__STM32F103X6_H_
#define MCU_DEVICE_CNFG__STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE												0x08000000UL
#define SRAM_MEMORY_BASE 												0x20000000UL

#define SYSTEM_MEMORY_BASE												0x1FFFF000UL
#define OptionBytes_MEMORY_BASE											0x1FFFF800UL

#define PERIPHERALS_MEMORY_BASE											0x40000000UL

#define CORTEX_M3_INTERNAL_PERIPHERALS_MEMORY_BASE  					0xE0000000UL
//---------------------------------------------------------------------------------------
//=============================================================================================================
//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------
/*-------- Base address for AHB BUS Peripherals --------*/
//Reset and clock control RCC
#define RCC_MEMORY_BASE 												(PERIPHERALS_MEMORY_BASE + 0x0021000UL)

//---------------------------------------------------------------------------------------
/*-------- Base address for APB2 BUS Peripherals --------*/
#define AFIO_MEMORY_BASE 												(PERIPHERALS_MEMORY_BASE + 0x00010000UL)
#define EXTI_MEMORY_BASE 												(PERIPHERALS_MEMORY_BASE + 0x00010400UL)
//A,B FULL PORT
#define GPIOA_MEMORY_BASE 												(PERIPHERALS_MEMORY_BASE + 0x00010800UL)
#define GPIOB_MEMORY_BASE 												(PERIPHERALS_MEMORY_BASE + 0x00010C00UL)
//C,D Partial port
#define GPIOC_MEMORY_BASE 												(PERIPHERALS_MEMORY_BASE + 0x00011000UL)
#define GPIOD_MEMORY_BASE 												(PERIPHERALS_MEMORY_BASE + 0x00011400UL)
//E unused port
#define GPIOE_MEMORY_BASE												(PERIPHERALS_MEMORY_BASE + 0x00011800UL)

#define NVIC_CMSIS_BASE													(CORTEX_M3_INTERNAL_PERIPHERALS_MEMORY_BASE + 0x0000E100UL)
//---------------------------------------------------------------------------------------
/*-------- Base address for APB2 BUS Peripherals --------*/

//---------------------------------------------------------------------------------------
//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
//RCC Register map
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t ABP2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AFPENR;
	volatile uint32_t ABP2ENR;
	volatile uint32_t ABP1ENR;
	volatile uint32_t BDCR;
}RCC_REG_typedef;
//---------------------------------------------------------------------------------------
//AFIO Register map
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
			 uint32_t RESERVED_1;
	volatile uint32_t MAPR2;
}AFIO_REG_typedef;
//---------------------------------------------------------------------------------------
//EXTI Register map
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_REG_typedef;
//---------------------------------------------------------------------------------------
//GPIOx Register map
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIOx_REG_typedef;
//---------------------------------------------------------------------------------------
//NVIC Register map
typedef struct
{
	volatile uint32_t ISERx[3];
			 uint32_t RESERVED_2[29];
	volatile uint32_t ICERx[3];
	 	 	 uint32_t RESERVED_3[29];
	volatile uint32_t ISPRx[3];
 	 	 	 uint32_t RESERVED_4[29];
 	volatile uint32_t ICPRx[3];
}NVIC_REG_typedef;
//---------------------------------------------------------------------------------------
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC                                         					((RCC_REG_typedef *)(RCC_MEMORY_BASE))
#define AFIO                                         					((AFIO_REG_typedef *)(AFIO_MEMORY_BASE))
#define EXTI                                         					((EXTI_REG_typedef *)(EXTI_MEMORY_BASE))
#define GPIOA                                        					((GPIOx_REG_typedef *)(GPIOA_MEMORY_BASE))
#define GPIOB                                        					((GPIOx_REG_typedef *)(GPIOB_MEMORY_BASE))
#define GPIOC                                        					((GPIOx_REG_typedef *)(GPIOC_MEMORY_BASE))
#define GPIOD                                        					((GPIOx_REG_typedef *)(GPIOD_MEMORY_BASE))

#define NVIC															((NVIC_REG_typedef *)(NVIC_CMSIS_BASE))
//---------------------------------------------------------------------------------------
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC register map:
//-*-*-*-*-*-*-*-*-*-*-*
//#define NVIC_ISER0													    *((volatile uint32_t)(NVIC_CMSIS_BASE + 0x00))
//#define NVIC_ISER1													    *((volatile uint32_t)(NVIC_CMSIS_BASE + 0x04))
//#define NVIC_ISER2													    *((volatile uint32_t)(NVIC_CMSIS_BASE + 0x08))
//#define NVIC_ICER0													    *((volatile uint32_t)(NVIC_CMSIS_BASE + 0x80))
//#define NVIC_ICER1													    *((volatile uint32_t)(NVIC_CMSIS_BASE + 0x84))
//#define NVIC_ICER2													    *((volatile uint32_t)(NVIC_CMSIS_BASE + 0x88))
//---------------------------------------------------------------------------------------
//Position of External interrupt refer to vector table for connectivity line.
#define EXTI0_POSITION					6UL
#define EXTI1_POSITION					7UL
#define EXTI2_POSITION					8UL
#define EXTI3_POSITION					9UL
#define EXTI4_POSITION					10UL
#define EXTI5_POSITION					23UL
#define EXTI6_POSITION					23UL
#define EXTI7_POSITION					23UL
#define EXTI8_POSITION					23UL
#define EXTI9_POSITION					23UL
#define EXTI10_POSITION					40UL
#define EXTI11_POSITION					40UL
#define EXTI12_POSITION					40UL
#define EXTI13_POSITION					40UL
#define EXTI14_POSITION					40UL
#define EXTI15_POSITION					40UL

#define EXTI9_5_POSITION				23UL
#define EXTI15_10_POSITION				40UL
//---------------------------------------------------------------------------------------
//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//Enable AFIO_CLOCK
#define AFIO_CLOCK_ENABLE()												(RCC->ABP2ENR |= 1 << 0)
//Enable GPIOA_CLOCK
#define GPIOA_CLOCK_ENABLE()											(RCC->ABP2ENR |= 1 << 2)
//Enable GPIOB_CLOCK
#define GPIOB_CLOCK_ENABLE()											(RCC->ABP2ENR |= 1 << 3)
//Enable GPIOC_CLOCK
#define GPIOC_CLOCK_ENABLE()											(RCC->ABP2ENR |= 1 << 4)
//Enable GPIOD_CLOCK
#define GPIOD_CLOCK_ENABLE()											(RCC->ABP2ENR |= 1 << 5)
//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//#define NVIC_EXTI0_IRQ_ENABLE()													(NVIC_ISER0 |= (1 << EXTI0_POSITION))
//#define NVIC_EXTI1_IRQ_ENABLE()													(NVIC_ISER0 |= (1 << EXTI1_POSITION))
//#define NVIC_EXTI2_IRQ_ENABLE()													(NVIC_ISER0 |= (1 << EXTI2_POSITION))
//#define NVIC_EXTI3_IRQ_ENABLE()													(NVIC_ISER0 |= (1 << EXTI3_POSITION))
//#define NVIC_EXTI4_IRQ_ENABLE()													(NVIC_ISER0 |= (1 << EXTI4_POSITION))
//#define NVIC_EXTI9_5_IRQ_ENABLE()												(NVIC_ISER0 |= (1 << EXTI5_POSITION))
//#define NVIC_EXTI15_10_IRQ_ENABLE()												(NVIC_ISER1 |= (1 << (EXTI10_POSITION - 32)))
//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


//=============================================================================================================
#endif /* MCU_DEVICE_CNFG__STM32F103X6_H_ */
