/*
 * stm32f103x6.h
 *
 *  Created on: May 18, 2025
 *      Author: Abdulrhman
 */

#ifndef MCU_DEVICE_CNFG_STM32F103X6_H_
#define MCU_DEVICE_CNFG_STM32F103X6_H_

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
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED_1;
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
//---------------------------------------------------------------------------------------
//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* MCU_DEVICE_CNFG_STM32F103X6_H_ */
