/*
 * exti.c
 *
 *  Created on: May 27, 2025
 *      Author: Abdulrhman
 */
//---------------- Includes ---------------
#include <stm32f103x6_exti.h>
//-----------------------------------------
//----------------------------- GENARIC MACROS ------------------------------------------------
#define AFIO_EXTICR_POSITION(__GPIOx)									((__GPIOx == GPIOA)?0:\
																		 (__GPIOx == GPIOB)?1:\
																		 (__GPIOx == GPIOC)?2:\
																		 (__GPIOx == GPIOD)?3:0)
//------------------------- GENERAL VARIABLE ----------------------

void (* GP_Func_EXTI_IRQ[15])(void);

//---------------- Supported Functions ---------------
void NVIC_ENABLE(EXTI_CNFG_t* _CNFG)
{
//	if(_CNFG->PIN_CNFG->INPUT_LINE_POSITION < 32)
//	{
//		NVIC->ISER0 |= (1 << _CNFG->PIN_CNFG->INPUT_LINE_POSITION);
//	}
//	else if(_CNFG->PIN_CNFG->INPUT_LINE_POSITION < 64)
//	{
//		NVIC->ISER1 |= (1 << (_CNFG->PIN_CNFG->INPUT_LINE_POSITION - 32));
//	}
//	else
//	{
//		NVIC->ISER2 |= (1 << (_CNFG->PIN_CNFG->INPUT_LINE_POSITION - 64));
//	}
	uint8_t Index   	= (uint8_t)(_CNFG->PIN_CNFG->INPUT_LINE_POSITION / 32);
	uint8_t Positon 	= (uint8_t)(_CNFG->PIN_CNFG->INPUT_LINE_POSITION % 32);
	NVIC->ISERx[Index] &= ~(0x01 << Positon);
	NVIC->ISERx[Index] |= (0x01 << Positon);
}

void NVIC_DISABLE(EXTI_CNFG_t* _CNFG)
{
//	if(_CNFG->PIN_CNFG->INPUT_LINE_POSITION < 32)
//	{
//		NVIC->ICER0 &= ~(1 << _CNFG->PIN_CNFG->INPUT_LINE_POSITION);
//	}
//	else if(_CNFG->PIN_CNFG->INPUT_LINE_POSITION < 64)
//	{
//		NVIC->ICER1 &= ~(1 << (_CNFG->PIN_CNFG->INPUT_LINE_POSITION - 32));
//	}
//	else
//	{
//		NVIC->ICER2 &= ~(1 << (_CNFG->PIN_CNFG->INPUT_LINE_POSITION - 64));
//	}
	uint8_t Index   	= (uint8_t)(_CNFG->PIN_CNFG->INPUT_LINE_POSITION / 32);
	uint8_t Positon 	= (uint8_t)(_CNFG->PIN_CNFG->INPUT_LINE_POSITION % 32);
	NVIC->ICERx[Index] &= ~(0x01 << Positon);
	NVIC->ICERx[Index] |= (0x01 << Positon);
}

uint8_t POSIOTION_INDEX(volatile uint32_t *Position, uint8_t StartBit)
{
	uint8_t i;
	uint8_t INDEX = StartBit;
	uint8_t LOOP = (StartBit == 5)? 5 : 6;
	for(i = 0; i < LOOP; i++)
	{
		uint8_t Pos;
		Pos = (*Position >> INDEX);
		if(Pos == 0x01)
			break;
		else
			INDEX++;
	}
	return INDEX;
}
//==================================================================================
/*
* ===============================================
* APIs Supported by "MCAL EXTI DRIVER"
* ===============================================
*/
/**================================================================
* @Fn          - MCAL_EXTI_GPIO_INIT
* @brief       - Initialize pins of GPIOx according to 'EXTIx_POSITION'.
* @param [in]  - 'EXTI_CNFG_t *_CNFG'.
* @retval      - NONE
* Note         - ONLY PORTS Enabled are FULL PORT OF (A,B) and PARTIAL PINs from PORT(C,D) refer to stm32f103x6 reference.
*/
void MCAL_EXTI_GPIO_INIT(EXTI_CNFG_t* _CNFG)
{
	//Enable AFIO Clock.
	AFIO_CLOCK_ENABLE();

	//Set GPIO Configuration.
	PIN_CFG_TypeDef _PIN_CFG;
	_PIN_CFG.PIN_NUMBER = _CNFG->PIN_CNFG->_GPIO_PIN;
	_PIN_CFG.__PinMode  = INPUT_MODE;
	_PIN_CFG.CNF_INPUT_CASE = Floating_input;
	_PIN_CFG.MODE_CASE     = Input_mode;
	MCAL_GPIO_INIT(_CNFG->PIN_CNFG->_GPIO, &_PIN_CFG);

	//EXTERNAL INTERRUPT CONFIGURATION  [AFIO_EXTICRx].
	uint8_t Index   	= (uint8_t)(_CNFG->PIN_CNFG->EXTIx / 4);
	uint8_t Positon 	= (uint8_t)((_CNFG->PIN_CNFG->EXTIx % 4) * 4);
	AFIO->EXTICR[Index] &= ~(0x0F << Positon);
	AFIO->EXTICR[Index] |= ((AFIO_EXTICR_POSITION(_CNFG->PIN_CNFG->_GPIO) & 0x0F) << Positon);



	EXTI->RTSR &= ~(1 << _CNFG->PIN_CNFG->EXTIx);
	EXTI->FTSR &= ~(1 << _CNFG->PIN_CNFG->EXTIx);
	if(_CNFG->Trigger_INTR_LINE == EXTI_TRIGGER_RISSING)
	{
		EXTI->RTSR |= (1 << _CNFG->PIN_CNFG->EXTIx);
	}
	else if(_CNFG->Trigger_INTR_LINE == EXTI_TRIGGER_FALLING)
	{
		EXTI->FTSR |= (1 << _CNFG->PIN_CNFG->EXTIx);
	}
	else
	{
		EXTI->RTSR |= (1 << _CNFG->PIN_CNFG->EXTIx);
		EXTI->FTSR |= (1 << _CNFG->PIN_CNFG->EXTIx);
	}
	if(_CNFG->EXTIx_ENABLE_DISABLE == _EXTI_ENABLED)
	{
		EXTI->IMR |= (1 << _CNFG->PIN_CNFG->EXTIx);
		NVIC_ENABLE(_CNFG);
		GP_Func_EXTI_IRQ[_CNFG->PIN_CNFG->EXTIx] = _CNFG->P_Func_EXTI_IRQ;
	}
	else
	{
		EXTI->IMR &= ~(1 << _CNFG->PIN_CNFG->EXTIx);
		NVIC_DISABLE(_CNFG);
	}
}

/**================================================================
* @Fn          - MCAL_EXTI_GPIO_INIT
* @brief       - Initialize pins of GPIOx according to 'EXTIx_POSITION'.
* @param [in]  - 'EXTI_CNFG_t *_CNFG'.
* @retval      - NONE
* Note         - ONLY PORTS Enabled are FULL PORT OF (A,B) and PARTIAL PINs from PORT(C,D) refer to stm32f103x6 reference.
*/
void MCAL_EXTI_GPIO_UPDATE(EXTI_CNFG_t* _CNFG)
{
	MCAL_EXTI_GPIO_INIT(_CNFG);
}
/**================================================================
* @Fn          - MCAL_EXTI_GPIO_DeInit.
* @brief       - RESET EXTI REGISTER.
* @param [in]  - void.
* @retval      - NONE.
* Note         - NONE.
*/
void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR  	= 0x00000000;
	EXTI->EMR  	= 0x00000000;
	EXTI->RTSR 	= 0x00000000;
	EXTI->FTSR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR    = 0xFFFFFFFF;
	NVIC->ICERx[0] = (0x008007C0);
	NVIC->ICERx[1] = (0x00000100);
}

/**================================================================
* @Fn          - EXTI_IRQHandler [ISR FUNCTION].
* @brief       - Redefine EXTI Request Handler Function.
* @param [in]  - void.
* @retval      - NONE.
* Note         - NONE.
*/
void EXTI0_IRQHandler(void)			          			/* EXTI Line0 interrupt */
{
	EXTI->PR |= (1 << EXTI0);
	GP_Func_EXTI_IRQ[EXTI0]();
}
void EXTI1_IRQHandler(void)          					/* EXTI Line1 interrupt */
{
	EXTI->PR |= (1 << EXTI1);
	GP_Func_EXTI_IRQ[EXTI1]();
}
void EXTI2_IRQHandler(void)          					/* EXTI Line2 interrupt */
{
	EXTI->PR |= (1 << EXTI2);
	GP_Func_EXTI_IRQ[EXTI2]();
}
void EXTI3_IRQHandler(void)          					/* EXTI Line3 interrupt */
{
	EXTI->PR |= (1 << EXTI3);
	GP_Func_EXTI_IRQ[EXTI3]();
}
void EXTI4_IRQHandler(void)          					/* EXTI Line4 interrupt */
{
	EXTI->PR |= (1 << EXTI4);
	GP_Func_EXTI_IRQ[EXTI4]();
}
void EXTI9_5_IRQHandler(void)          					/* EXTI Line[9:5] interrupts */
{
	volatile uint32_t POSITION;
	POSITION = (volatile uint32_t)(EXTI->PR & (uint32_t)0x3E0);
	EXTI->PR |= POSITION;
	GP_Func_EXTI_IRQ[POSIOTION_INDEX(&POSITION, 5)]();
}
void EXTI15_10_IRQHandler(void)          				/* EXTI Line[15:10] interrupts */
{
	volatile uint32_t POSITION;
	POSITION = (volatile uint32_t)(EXTI->PR & 0xFC00);
	EXTI->PR |= POSITION;
	GP_Func_EXTI_IRQ[POSIOTION_INDEX(&POSITION, 10)]();
}
//================================================================
