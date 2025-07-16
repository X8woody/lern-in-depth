/*
 * stm32f103xx_rcc.h
 *
 *  Created on: Jul 5, 2025
 *      Author: Abdulrhman
 */

#ifndef MCAL__INCLUDE_STM32F103XX_RCC_H_
#define MCAL__INCLUDE_STM32F103XX_RCC_H_

#include "stm32f103x6.h"

#define F_CPU										16000000UL

#define RC_HSI										8000000UL
#define RC_HSE										F_CPU
#define RC_PLL										16000000UL

#define RCC_CFGR_SW(x)								(uint32_t)(x & 0x3)
#define RCC_CFGR_SWS(x)								(uint32_t)((x & 0xC)    >> 2)
#define RCC_CFGR_HPRE(x)							(uint32_t)((x & 0xF0)   >> 4)
#define RCC_CFGR_PPRE1(x)							(uint32_t)((x & 0x700)  >> 8)
#define RCC_CFGR_PPRE2(x)							(uint32_t)((x & 0x3800) >> 11)



enum MCU_CLOCK_SOURCE
{
	HSI,
	HSE,
	PLL_Source,
	NotApplicable
};



uint32_t MCAL_GET_PCLK2(void);
uint32_t MCAL_GET_PCLK1(void);
uint32_t MCAL_GET_HCLK(void);
uint32_t MCAL_GET_SYSCLK(void);

#endif /* MCAL__INCLUDE_STM32F103XX_RCC_H_ */
