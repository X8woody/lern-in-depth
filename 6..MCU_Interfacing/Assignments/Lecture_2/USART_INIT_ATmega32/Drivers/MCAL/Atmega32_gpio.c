/*
 * Atmega32_gpio.c
 *
 * Created: 5/21/2025 4:32:17 PM
 *  Author: Abdulrhman
 */ 
//---------------- Includes ---------------

#include "Atmega32_gpio.h"


void MCAL_GPIO_SET_DataDire(GPIOx_REG_typedef *GPIOx, MCAL_PIN_MODE_ENUM Dir, uint8_t PinNum)
{
	if(Dir == INPUT_MODE)
		GPIOx->_SET_PIN_Dir_I_O_Px &= ~(PinNum);
	else
		GPIOx->_SET_PIN_Dir_I_O_Px |= (PinNum);	
}


void MCAL_GPIO_INIT(GPIOx_REG_typedef *GPIOx, PIN_CFG_TypeDef *GPIO_PIN_CFG)
{
	if(GPIO_PIN_CFG->__PinMode == INPUT_MODE)
		GPIOx->_SET_PIN_Dir_I_O_Px &= ~(GPIO_PIN_CFG->PIN_NUMBER);
	else if(GPIO_PIN_CFG->__PinMode == OUTPUT_MODE)
		GPIOx->_SET_PIN_Dir_I_O_Px |= (GPIO_PIN_CFG->PIN_NUMBER);
}


void MCAL_GPIO_WRITE_PIN(GPIOx_REG_typedef *GPIOx, uint8_t PinNum, MCAL_GPIO_PIN_STATUS PinStatus)
{
	if(PinStatus == GPIO_PIN_SET)
	{
		GPIOx->_SET_PIN_H_L_Px |= (uint8_t)(PinNum);
	}
	else
	{
		GPIOx->_SET_PIN_H_L_Px &= ~(uint8_t)(PinNum);
	}
}


void MCAL_GPIO_WRITE_PORT(GPIOx_REG_typedef *GPIOx, uint8_t SpecPins)
{
	GPIOx->_SET_PIN_H_L_Px = SpecPins;
}


void MCAL_GPIO_TOGGLE_PIN(GPIOx_REG_typedef *GPIOx, uint8_t PinNum)
{
	GPIOx->_SET_PIN_H_L_Px ^= (uint8_t)(PinNum);
}


MCAL_GPIO_PIN_STATUS MCAL_GPIO_READ_PIN(GPIOx_REG_typedef *GPIOx, uint8_t PinNum)
{
	MCAL_GPIO_PIN_STATUS PinStatus;
	PinStatus = (((GPIOx->_Read_PIN_Px & (uint8_t)(PinNum)) != (uint8_t)(0x00)))? GPIO_PIN_SET : GPIO_PIN_RESET;
	return PinStatus;
}


uint8_t MCAL_GPIO_READ_PORT(GPIOx_REG_typedef *GPIOx)
{
	uint8_t PinStatus = GPIOx->_Read_PIN_Px;
	return PinStatus;
}
