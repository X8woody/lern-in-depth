/*
 * interrupt.c
 *
 *  Created on: Jun 2, 2025
 *      Author: Abdulrhman
 */
#include <exti.h>

void (*GP_FUNC_IRQ[3])(void);

void MCAL_EXTI_INIT(EXTI_CONFIG_t* EXTI_CNFG)
{
	PIN_CFG_TypeDef GPIO_CONFIG;
	GPIO_CONFIG.PIN_NUMBER = EXTI_CNFG->PinNumber;
	GPIO_CONFIG.__PinMode  = INPUT_MODE;
	MCAL_GPIO_INIT(GPIOx_INTx(EXTI_CNFG->NUM_INT), &GPIO_CONFIG);
	if(EXTI_CNFG->NUM_INT == INT2)
		SREG &= ~(1 << 7);
	else
		SREG |= (1 << 7);
	if(EXTI_CNFG->NUM_INT == INT0)
	{
		SNS_CTRL_INT0(EXTI_CNFG->INT_Sense_CTRL);
	}
	else if(EXTI_CNFG->NUM_INT == INT1)
	{
		SNS_CTRL_INT1(EXTI_CNFG->INT_Sense_CTRL);
	}
	else
	{
		SNS_CTRL_INT2(EXTI_CNFG->INT_Sense_CTRL);
	}
	SREG |= (1 << 7);
	EXTI_ReqEnable(EXTI_CNFG->NUM_INT,EXTI_CNFG->EXTI_EnableDisable);
	GP_FUNC_IRQ[(EXTI_CNFG->NUM_INT - 5)] = EXTI_CNFG->P_FUNC_IRQ;

}

ISR(INT0_vect)
{
	GP_FUNC_IRQ[1]();
	//EXTI_ClearFalg(INT0);
}

ISR(INT1_vect)
{
	GP_FUNC_IRQ[2]();
	//EXTI_ClearFalg(INT1);
}

ISR(INT2_vect)
{
	GP_FUNC_IRQ[0]();
	EXTI_ClearFalg(INT2);
}
