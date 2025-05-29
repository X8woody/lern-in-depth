/*
 * stm32f103x6_gpio.h
 *
 *  Created on: May 18, 2025
 *      Author: Abdulrhman
 */

#ifndef MCAL__INCLUDE_STM32F103X6_GPIO_H_
#define MCAL__INCLUDE_STM32F103X6_GPIO_H_
//-----------------------------
//Includes
//-----------------------------

#include "../../../MCU_DEVICE_CNFG_/stm32f103x6.h"

//-----------------------------


//=================================================================================================
//-----------------------------
//User type definitions
//-----------------------------

typedef enum
{
	MCAL_ERROR = 0u,
	MCAL_OK
}MCAL_STATUS_enum;
//--------------------------------------------------------------------------
// @ref MCAL_GPIO_PIN_STATUS typedef enumeration.
typedef enum
{
	GPIO_PIN_RESET = 0u,
	GPIO_PIN_SET
}MCAL_GPIO_PIN_STATUS;
//--------------------------------------------------------------------------
typedef enum
{
	INPUT_MODE = 0u,
	OUTPUT_MODE
}MCAL_PIN_MODE_ENUM;
//--------------------------------------------------------------------------
//CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
typedef enum
{
	Analog_mode     = 0b0000,
	Floating_input  = 0b0100,
	Input_PULL_UD   = 0b1000,
	Reserved_1      = 0b1100
}MCAL_CNFy_INPUT_PIN_MODE_ENUM;
//--------------------------------------------------------------------------
//CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
typedef enum
{
	GPOutput_Push_pull  = 0b0000,
	GPOutput_OpenDarain = 0b0100,
	AFOutput_Push_pull  = 0b1000,
	AFOutput_OpenDarain = 0b1100
}MCAL_CNFy_OUTPUT_PIN_MODE_ENUM;
//--------------------------------------------------------------------------
//MODEy[1:0]: Port x mode bits (y= 0 .. 7)
typedef enum
{
	Input_mode                  = 0b0000,
	Output_mode_max_speed_10MHz = 0b0001,
	Output_mode_max_speed_2MHz  = 0b0010,
	Output_mode_max_speed_50MHz = 0b0011
}MCAL_MODEy_PIN_MODE_ENUM;
//--------------------------------------------------------------------------

// @ref PIN_CFG_TypeDef.
typedef struct
{
	volatile uint16_t                 PIN_NUMBER;
	MCAL_PIN_MODE_ENUM               __PinMode;
	MCAL_CNFy_INPUT_PIN_MODE_ENUM    CNF_INPUT_CASE;
	MCAL_CNFy_OUTPUT_PIN_MODE_ENUM   CNF_OUTPUT_CASE;
	MCAL_MODEy_PIN_MODE_ENUM         MODE_CASE;
}PIN_CFG_TypeDef;
//-------------------------------------------------------------------------
//=================================================================================================
//-----------------------------
//Macros Configuration References
//-----------------------------
#define GPIO_PIN_0                                        (uint16_t)0x0001U   //(1 << 0);
#define GPIO_PIN_1                                        (uint16_t)0x0002U   //(1 << 1);
#define GPIO_PIN_2                                        (uint16_t)0x0004U   //(1 << 2);
#define GPIO_PIN_3                                        (uint16_t)0x0008U   //(1 << 3);
#define GPIO_PIN_4                                        (uint16_t)0x0010U   //(1 << 4);
#define GPIO_PIN_5                                        (uint16_t)0x0020U   //(1 << 5);
#define GPIO_PIN_6                                        (uint16_t)0x0040U   //(1 << 6);
#define GPIO_PIN_7                                        (uint16_t)0x0080U   //(1 << 7);
#define GPIO_PIN_8                                        (uint16_t)0x0100U   //(1 << 8);
#define GPIO_PIN_9                                        (uint16_t)0x0200U   //(1 << 9);
#define GPIO_PIN_10                                       (uint16_t)0x0400U   //(1 << 10);
#define GPIO_PIN_11                                       (uint16_t)0x0800U   //(1 << 11);
#define GPIO_PIN_12                                       (uint16_t)0x1000U   //(1 << 12);
#define GPIO_PIN_13                                       (uint16_t)0x2000U   //(1 << 13);
#define GPIO_PIN_14                                       (uint16_t)0x4000U   //(1 << 14);
#define GPIO_PIN_15                                       (uint16_t)0x8000U   //(1 << 15);

#define GPIO_PIN_MASK                                     0xFFFFU
/*
 * @ref Module_REF_NAME_define
*/
//=================================================================================================
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_INIT(GPIOx_REG_typedef *GPIOx, PIN_CFG_TypeDef *GPIO_PIN_CFG);
void MCAL_GPIO_SET_DataDire(GPIOx_REG_typedef *GPIOx, MCAL_PIN_MODE_ENUM Dir, uint16_t PinNum);
void MCAL_GPIO_WRITE_PIN(GPIOx_REG_typedef *GPIOx, uint16_t PinNum, MCAL_GPIO_PIN_STATUS PinStatus);
void MCAL_GPIO_WRITE_PORT(GPIOx_REG_typedef *GPIOx, uint16_t SpecPins);
void MCAL_GPIO_TOGGLE_PIN(GPIOx_REG_typedef *GPIOx, uint16_t PinNum);

MCAL_GPIO_PIN_STATUS MCAL_GPIO_READ_PIN(GPIOx_REG_typedef *GPIOx, uint16_t PinNum);
uint16_t MCAL_GPIO_READ_PORT(GPIOx_REG_typedef *GPIOx);

MCAL_STATUS_enum MCAL_GPIO_PIN_LOCK(GPIOx_REG_typedef *GPIOx, uint16_t PinNum);

#endif /* MCAL__INCLUDE_STM32F103X6_GPIO_H_ */
