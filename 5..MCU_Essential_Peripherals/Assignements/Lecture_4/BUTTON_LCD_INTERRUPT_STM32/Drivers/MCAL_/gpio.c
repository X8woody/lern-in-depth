/*
 * gpio.c
 *
 *  Created on: May 18, 2025
 *      Author: Abdulrhman
 */

//---------------- Includes ---------------

#include "../MCAL_/Include/stm32f103x6_gpio.h"

//-----------------------------------------
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
/*=========== Helpful function =============*/
uint8_t Num_Pin(uint16_t pins)
{
	static uint8_t i = 0;
	uint16_t PINS;
	while(i != 0x10)
	{
		PINS = ((pins & (1 << i)) != (uint16_t)0x00)? (i + 1) : (uint16_t)0x00;
		i++;
		if(PINS != (uint16_t)0x00)
		{
			return (uint8_t)(PINS - 1);
		}
		else
		{
		}
	}
	i = 0;
	return 0xFF;
}

void MCAL_GPIO_CLOCK_ENABLE(GPIOx_REG_typedef *GPIOx)
{
	if(GPIOx == GPIOA)
		GPIOA_CLOCK_ENABLE();
	else if(GPIOx == GPIOB)
		GPIOB_CLOCK_ENABLE();
	else if(GPIOx == GPIOC)
		GPIOC_CLOCK_ENABLE();
	else if(GPIOx == GPIOD)
		GPIOD_CLOCK_ENABLE();
}
/**================================================================
* @Fn          - MCAL_GPIO_SET_DataDire
* @brief       - SET pins of GPIOx according to 'Dir' which may be Input or Output.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx'.
* @param [in]  - 'MCAL_PIN_MODE_ENUM Dir'.
* @param [in]  - 'uint16_t PinNum'.
* @retval      - NONE
* Note         - NONE
*/
void MCAL_GPIO_SET_DataDire(GPIOx_REG_typedef *GPIOx, MCAL_PIN_MODE_ENUM Dir, uint16_t PinNum)
{
	volatile uint32_t* __CR;
	uint8_t            CNF_MODE;
	uint8_t            MODE_CASE;
	PinNum    = Num_Pin(PinNum);
	if(PinNum != 0xFF)
	{
		uint8_t PNUM;
		PNUM      = PinNum;
		PinNum    = (PinNum <= 0x07)?  (uint8_t)(PinNum) : (uint8_t)(PinNum - 8);
		__CR      = (PNUM <= 0x07)?  &GPIOx->CRL : &GPIOx->CRH;
		CNF_MODE  = (Dir == INPUT_MODE)? (uint8_t)Floating_input : (uint8_t)GPOutput_OpenDarain;
		MODE_CASE = (Dir == INPUT_MODE)? (uint8_t)Input_mode : (uint8_t)Output_mode_max_speed_10MHz;
		*__CR  	 &= ~((uint32_t)(0x0F) << (uint8_t)(PinNum * (uint8_t)(4)));
		*__CR    |= ((uint32_t)(CNF_MODE | MODE_CASE) << (uint8_t)(PinNum * (uint8_t)(4)));
	}
	else
	{
	}
}
/**================================================================
* @Fn          - MCAL_GPIO_INIT
* @brief       - Initialize pins of GPIOx according to 'PIN_CFG_TypeDef' which may be Input or Output.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx', 'PIN_CFG_TypeDef *GPIO_PIN_CFG'.
* @retval      - NONE
* Note         - You must set Pin configuration before calling this function @ref PIN_CFG_TypeDef
*/
void MCAL_GPIO_INIT(GPIOx_REG_typedef *GPIOx, PIN_CFG_TypeDef *GPIO_PIN_CFG)
{
	volatile uint32_t* __CR;
	uint8_t            CNF_MODE;
	uint8_t            PinNum;
	MCAL_GPIO_CLOCK_ENABLE(GPIOx);
	while((PinNum    = Num_Pin(GPIO_PIN_CFG->PIN_NUMBER)) != 0xFF)
	{
		uint8_t PNUM;
		PNUM      = PinNum;
		PinNum    = (PinNum <= 0x07)?  (uint8_t)(PinNum) : (uint8_t)(PinNum - 8);
		__CR      = (PNUM   <= 0x07)?  &GPIOx->CRL : &GPIOx->CRH;
		CNF_MODE  = (GPIO_PIN_CFG->__PinMode == INPUT_MODE)? (uint8_t)GPIO_PIN_CFG->CNF_INPUT_CASE : (uint8_t)GPIO_PIN_CFG->CNF_OUTPUT_CASE;
		*__CR  	 &= ~((uint32_t)(0x0F) << (uint8_t)(PinNum * (uint8_t)(4)));
		*__CR    |= ((uint32_t)(CNF_MODE | GPIO_PIN_CFG->MODE_CASE) << (uint8_t)(PinNum * (uint8_t)(4)));
	}
}

/**================================================================
* @Fn          - MCAL_GPIO_WRITE_PIN
* @brief       - Write to pins of GPIOx according to 'MCAL_GPIO_PIN_STATUS' which may be HIGH or LOW.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx', 'uint16_t PinNum', 'MCAL_GPIO_PIN_STATUS PinStatus'.
* @retval      - NONE
*/
void MCAL_GPIO_WRITE_PIN(GPIOx_REG_typedef *GPIOx, uint16_t PinNum, MCAL_GPIO_PIN_STATUS PinStatus)
{
	if(PinStatus == GPIO_PIN_SET)
	{
		GPIOx->ODR |= (uint32_t)(PinNum);
	}
	else
	{
		GPIOx->ODR &= ~(uint32_t)(PinNum);
	}
}

/**================================================================
* @Fn          - MCAL_GPIO_WRITE_PORT
* @brief       - Write to all pins of GPIOx according to 'MCAL_GPIO_PIN_STATUS' which may be HIGH or LOW at the same time.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx', 'MCAL_GPIO_PIN_STATUS PinStatus'.
* @retval      - NONE
*/
void MCAL_GPIO_WRITE_PORT(GPIOx_REG_typedef *GPIOx, uint16_t SpecPins)
{
	GPIOx->ODR = (uint32_t)SpecPins;
}

/**================================================================
* @Fn          - MCAL_GPIO_TOGGLE_PIN
* @brief       - Toggle specific pin of GPIOx which it's status will be HIGH if it is LOW or vice versa.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx', 'uint16_t PinNum'.
* @retval      - NONE
*/
void MCAL_GPIO_TOGGLE_PIN(GPIOx_REG_typedef *GPIOx, uint16_t PinNum)
{
	GPIOx->ODR ^= (uint32_t)(PinNum);
}
/**================================================================
* @Fn          - MCAL_GPIO_READ_PIN
* @brief       - Read pins of GPIOx status according to 'PinNum' which may be HIGH or LOW.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx', 'uint16_t PinNum'.
* @retval - 'GPIO_PIN_RESET' or 'GPIO_PIN_SET' @ref MCAL_GPIO_PIN_STATUS typedef enumeration.
*/
MCAL_GPIO_PIN_STATUS MCAL_GPIO_READ_PIN(GPIOx_REG_typedef *GPIOx, uint16_t PinNum)
{
	MCAL_GPIO_PIN_STATUS PinStatus;
//	PinNum    = Num_Pin(PinNum);
	PinStatus = (((GPIOx->IDR & (uint32_t)(PinNum)) != (uint32_t)(0x00)))? GPIO_PIN_SET : GPIO_PIN_RESET;
	return PinStatus;
}

/**================================================================
* @Fn          - MCAL_GPIO_READ_PORT
* @brief       - Read pins of GPIOx status according to 'PinNum' which may be HIGH or LOW.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx'.
* @retval      - Status of All pins of PORTx with data type of unsigned short.
*/
uint16_t MCAL_GPIO_READ_PORT(GPIOx_REG_typedef *GPIOx)
{
	uint16_t PinStatus = GPIOx->IDR;
	return PinStatus;
}

/**================================================================
* @Fn          - MCAL_GPIO_PIN_LOCK
* @brief       - Lock pins of GPIOx ports, When the LOCK sequence has been applied on a port bit it is no longer possible to modify the value of
                 the port bit until the next reset.
* @param [in]  - 'GPIOx_REG_typedef *GPIOx'.
* @param [in]  - 'uint16_t PinNum'.
* @retval      - Status of lock operation.
*/
MCAL_STATUS_enum MCAL_GPIO_PIN_LOCK(GPIOx_REG_typedef *GPIOx, uint16_t PinNum)
{
	/*============ From data sheet ===========*/
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.
	GPIOx->LCKR |= (uint32_t)(PinNum);

	GPIOx->LCKR |= (uint32_t)(1 << 16);
	GPIOx->LCKR &= (uint32_t)(~(1 << 16));
	GPIOx->LCKR |= (uint32_t)(1 << 16);

	uint32_t STATUS = (uint32_t)(GPIOx->LCKR >> 16);

	STATUS = (uint32_t)(GPIOx->LCKR >> 16);
	if(STATUS)
		return MCAL_OK;
	else
		return MCAL_ERROR;

}
