/*
 * rcc.c
 *
 *  Created on: Jul 5, 2025
 *      Author: Abdulrhman
 */


#include "stm32f103xx_rcc.h"

RCC_REG_typedef *P_RCC = RCC;
uint8_t Prescaler_APB[8]   = {1,1,1,1,2,4,8,16};
uint16_t Prescaler_AHB[16] = {1,1,1,1,1,1,1,1,2,4,8,16,64,128,256,512};

uint32_t MCAL_GET_PCLK2(void)
{
	return ((MCAL_GET_HCLK()) / ((uint32_t)Prescaler_APB[RCC_CFGR_PPRE2(P_RCC->CFGR)]));
}
uint32_t MCAL_GET_PCLK1(void)
{
	return ((MCAL_GET_HCLK()) / ((uint32_t)Prescaler_APB[RCC_CFGR_PPRE1(P_RCC->CFGR)]));
}
uint32_t MCAL_GET_HCLK(void)
{
	return ((MCAL_GET_SYSCLK()) / ((uint32_t)Prescaler_AHB[RCC_CFGR_HPRE(P_RCC->CFGR)]));
}
uint32_t MCAL_GET_SYSCLK(void)
{
	switch (RCC_CFGR_SWS(P_RCC->CFGR))
	{
	case 0 :
		return RC_HSI;
		break;
	case 1 :
		return RC_HSE;
		break;
	case 2 :
		return RC_PLL;
		break;
	}
	return 0;
}
