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

//USART2
#define USART2_MEMORY_BASE												(PERIPHERALS_MEMORY_BASE + 0x00004400UL)

//USART3
#define USART3_MEMORY_BASE												(PERIPHERALS_MEMORY_BASE + 0x00004800UL)

//SPI2
#define SPI2_MEMORY_BASE												(PERIPHERALS_MEMORY_BASE + 0x00003800UL)

//---------------------------------------------------------------------------------------
/*-------- Base address for APB1 BUS Peripherals --------*/
//USART1
#define USART1_MEMORY_BASE												(PERIPHERALS_MEMORY_BASE + 0x00013800UL)

//SPI1
#define SPI1_MEMORY_BASE												(PERIPHERALS_MEMORY_BASE + 0x00013000UL)
//---------------------------------------------------------------------------------------



//=======================================================================================
#define NVIC_CMSIS_BASE													(CORTEX_M3_INTERNAL_PERIPHERALS_MEMORY_BASE + 0x0000E100UL)
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
//SPI Register map
typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;	
}SPIx_REG_typedef;
//---------------------------------------------------------------------------------------




//---------------------------------------------------------------------------------------
//USARTx bit field of Register
typedef struct
{
	volatile uint16_t PE  			: 1;
	volatile uint16_t FE  			: 1;
	volatile uint16_t NE  			: 1;
	volatile uint16_t ORE  			: 1;
	volatile uint16_t IDLE  		: 1;
	volatile uint16_t RXNE 	 		: 1;
	volatile uint16_t TC  			: 1;
	volatile uint16_t TXE  			: 1;
	volatile uint16_t LBD  			: 1;
	volatile uint16_t CTS  			: 1;
	volatile uint16_t RESERVED_0 	: 6;
	volatile uint16_t RESERVED_1;
}USARTx_SR_typdef;

typedef struct
{
	volatile uint16_t DR            : 9;
	volatile uint16_t RESERVED_0    : 7;
	volatile uint16_t RESERVED_1;
}USARTx_DR_typdef;

typedef struct
{
	volatile uint16_t DIV_Fractio  	: 4;
	volatile uint16_t DIV_Mantissa  : 12;
	volatile uint16_t RESERVED;
}USARTx_BRR_typdef;

typedef struct
{
	volatile uint16_t SBK  			: 1;
	volatile uint16_t RWU  			: 1;
	volatile uint16_t RE  			: 1;
	volatile uint16_t TE  			: 1;
	volatile uint16_t INT_CTRL  	: 5;
//	volatile uint16_t IDLEIE  		: 1;
//	volatile uint16_t RXNEIE 	 	: 1;
//	volatile uint16_t TCIE  		: 1;
//	volatile uint16_t TXEIE  		: 1;
//	volatile uint16_t PEIE  		: 1;
	volatile uint16_t PS  			: 1;
	volatile uint16_t PCE 			: 1;
	volatile uint16_t WAKE 			: 1;
	volatile uint16_t M 			: 1;
	volatile uint16_t UE 			: 1;
	volatile uint16_t RESERVED_0 	: 2;
	volatile uint16_t RESERVED_1;
}USARTx_CR1_typdef;

typedef struct
{
	volatile uint16_t ADD  			: 4;
	volatile uint16_t RESERVED_0  	: 1;
	volatile uint16_t LBDL 			: 1;
	volatile uint16_t LBDIE 		: 1;
	volatile uint16_t RESERVED_1	: 1;
	volatile uint16_t LBCL	 	 	: 1;
	volatile uint16_t CPHA  		: 1;
	volatile uint16_t CPOL  		: 1;
	volatile uint16_t CLKEN  		: 1;
	volatile uint16_t STOP  		: 2;
	volatile uint16_t LINEN 		: 1;
	volatile uint16_t RESERVED_2 	: 1;
	volatile uint16_t RESERVED_3;
}USARTx_CR2_typdef;


typedef struct
{
	volatile uint16_t EIE  			: 1;
	volatile uint16_t IREN 			: 1;
	volatile uint16_t IRLP  		: 1;
	volatile uint16_t HDSEL			: 1;
	volatile uint16_t NACK  		: 1;
	volatile uint16_t SCEN 	 		: 1;
	volatile uint16_t DMAR  		: 1;
	volatile uint16_t DMAT  		: 1;
	volatile uint16_t RTSE_CTSE  	: 2;
	volatile uint16_t CTSIE 		: 1;
	volatile uint16_t RESERVED_0 	: 5;
	volatile uint16_t RESERVED_1;
}USARTx_CR3_typdef;


typedef struct
{
	volatile uint8_t PSC;
	volatile uint8_t GT;
	volatile uint16_t RESERVED;
}USARTx_GTPR_typdef;
//USARTx Register map
typedef struct
{
	USARTx_SR_typdef   SR;
	volatile uint32_t  DR;
	USARTx_BRR_typdef  BRR;
	USARTx_CR1_typdef  CR1;
	USARTx_CR2_typdef  CR2;
	USARTx_CR3_typdef  CR3;
	USARTx_GTPR_typdef GTPR;
}USARTx_REG_typedef;
//---------------------------------------------------------------------------------------
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC															((NVIC_REG_typedef *)(NVIC_CMSIS_BASE))

#define RCC                                         					((RCC_REG_typedef *)(RCC_MEMORY_BASE))

#define AFIO                                         					((AFIO_REG_typedef *)(AFIO_MEMORY_BASE))

#define EXTI                                         					((EXTI_REG_typedef *)(EXTI_MEMORY_BASE))

#define GPIOA                                        					((GPIOx_REG_typedef *)(GPIOA_MEMORY_BASE))
#define GPIOB                                        					((GPIOx_REG_typedef *)(GPIOB_MEMORY_BASE))
#define GPIOC                                        					((GPIOx_REG_typedef *)(GPIOC_MEMORY_BASE))
#define GPIOD                                        					((GPIOx_REG_typedef *)(GPIOD_MEMORY_BASE))

#define USART1															((USARTx_REG_typedef *)(USART1_MEMORY_BASE))
#define USART2															((USARTx_REG_typedef *)(USART2_MEMORY_BASE))
#define USART3															((USARTx_REG_typedef *)(USART3_MEMORY_BASE))


#define SPI1															((SPIx_REG_typedef *)(SPI1_MEMORY_BASE))
#define SPI2															((SPIx_REG_typedef *)(SPI2_MEMORY_BASE))

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


#define INT_USART1_POSITION				37UL
#define INT_USART2_POSITION				38UL
#define INT_USART3_POSITION				39UL

#define INT_SPI1_POSITION				35UL
#define INT_SPI2_POSITION				36UL
//---------------------------------------------------------------------------------------
//Enable Interrupt Source of UART
#define UARTx_PEIE_Enable				0b10000
#define UARTx_TXEIE_Enable				0b01000
#define UARTx_TCIE_Enable				0b00100
#define UARTx_RXNEIE_Enable				0b00010
//Disable Interrupt Source of UART
#define UARTx_PEIE_Disable				0b01111
#define UARTx_TXEIE_Disable				0b10111
#define UARTx_TCIE_Disable				0b11011
#define UARTx_RXNEIE_Disable			0b11101


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
//Enable USART1_CLOCK
#define USART1_CLOCK_ENABLE()											(RCC->ABP2ENR |= 1 << 14)
//Enable USART2_CLOCK
#define USART2_CLOCK_ENABLE()											(RCC->ABP1ENR |= 1 << 17)
//Enable USART3_CLOCK
#define USART3_CLOCK_ENABLE()											(RCC->ABP1ENR |= 1 << 18)

//Enable SPI2_CLOCK
#define SPI2_CLOCK_ENABLE()												(RCC->ABP1ENR |= 1 << 14)
//Enable SPI1_CLOCK
#define SPI1_CLOCK_ENABLE()												(RCC->ABP2ENR |= 1 << 12)
//=======================================
//clock disable Macros:
//=======================================
//Disable USART1_CLOCK
#define USART1_CLOCK_DISABLE()											(RCC->ABP2RSTR |= 1 << 14)
//Disable USART2_CLOCK
#define USART2_CLOCK_DISABLE()											(RCC->APB1RSTR |= 1 << 17)
//Disable USART3_CLOCK
#define USART3_CLOCK_DISABLE()											(RCC->APB1RSTR |= 1 << 18)

//Disable SPI2_CLOCK
#define SPI2_CLOCK_DISABLE()											(RCC->APB1RSTR |= 1 << 14)
//Disable SPI1_CLOCK
#define SPI1_CLOCK_DISABLE()											(RCC->ABP2RSTR |= 1 << 12)

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
//===================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC_USART enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_UART1_IRQ_ENABLE()													(NVIC->ISERx[1] |= (1 << (INT_USART1_POSITION - 32)))
#define NVIC_UART2_IRQ_ENABLE()													(NVIC->ISERx[1] |= (1 << (INT_USART2_POSITION - 32)))
#define NVIC_UART3_IRQ_ENABLE()													(NVIC->ISERx[1] |= (1 << (INT_USART3_POSITION - 32)))
//===================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC_SPIx enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_SPI1_IRQ_ENABLE()													(NVIC->ISERx[1] |= (1 << (INT_SPI1_POSITION - 32)))
#define NVIC_SPI2_IRQ_ENABLE()													(NVIC->ISERx[1] |= (1 << (INT_SPI2_POSITION - 32)))
//===================================================================

//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//USART Enable Interrupt Source Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define UARTx_IRQ_SourceEnable(x,y)												(x->CR1.INT_CTRL  |= y)

//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC_USART Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_UART1_IRQ_DISABLE()												(NVIC->ICERx[1] |= (1 << (INT_USART1_POSITION - 32)))
#define NVIC_UART2_IRQ_DISABLE()												(NVIC->ICERx[1] |= (1 << (INT_USART2_POSITION - 32)))
#define NVIC_UART3_IRQ_DISABLE()												(NVIC->ICERx[1] |= (1 << (INT_USART3_POSITION - 32)))
//===================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC_SPIx Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_SPI1_IRQ_DISABLE()													(NVIC->ICERx[1] |= (1 << (INT_SPI1_POSITION - 32)))
#define NVIC_SPI2_IRQ_DISABLE()													(NVIC->ICERx[1] |= (1 << (INT_SPI2_POSITION - 32)))
//===================================================================

//===================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//USART Disable Interrupt Source Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define UARTx_IRQ_SourceDisable(x,y)											(x->CR1.INT_CTRL  &= y)


//=============================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


//=============================================================================================================
#endif /* MCU_DEVICE_CNFG__STM32F103X6_H_ */
