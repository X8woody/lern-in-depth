/*
 * stm32f103cx_exti.h
 *
 *  Created on: May 27, 2025
 *      Author: Abdulrhman
 */

#ifndef MCAL__INCLUDE_STM32F103X6_EXTI_H_
#define MCAL__INCLUDE_STM32F103X6_EXTI_H_

//-----------------------------
//Includes
//-----------------------------
#include "stm32f103x6_gpio.h"

//=================================================================================================
//-----------------------------
//User type definitions
//-----------------------------
typedef struct
{
	volatile uint8_t        EXTIx;
	volatile uint8_t        INPUT_LINE_POSITION;
	volatile uint16_t       _GPIO_PIN;
	GPIOx_REG_typedef *     _GPIO;
}EXTI_PIN_CNFG_t;

typedef struct
{
	EXTI_PIN_CNFG_t*        PIN_CNFG;
	volatile uint8_t        Trigger_INTR_LINE;
	volatile uint8_t        EXTIx_ENABLE_DISABLE;
	void (*P_Func_EXTI_IRQ)(void);

}EXTI_CNFG_t;
//=================================================================================================
//-----------------------------
//Macros Configuration References
//-----------------------------

//Number of External Interrupt that you want to select (Acronym).
#define EXTI0					0U
#define EXTI1					1U
#define EXTI2					2U
#define EXTI3					3U
#define EXTI4					4U
#define EXTI5					5U
#define EXTI6					6U
#define EXTI7					7U
#define EXTI8					8U
#define EXTI9					9U
#define EXTI10					10U
#define EXTI11					11U
#define EXTI12					12U
#define EXTI13					13U
#define EXTI14					14U
#define EXTI15					15U
//-----------------------------
//EXTI0 define
#define EXTIA0					{EXTI0, EXTI0_POSITION, GPIO_PIN_0,GPIOA}
#define EXTIB0					{EXTI0, EXTI0_POSITION, GPIO_PIN_0,GPIOB}
#define EXTIC0					{EXTI0, EXTI0_POSITION, GPIO_PIN_0,GPIOC}
#define EXTID0					{EXTI0, EXTI0_POSITION, GPIO_PIN_0,GPIOD}
//-----------------------------------------------------------------------------
//EXTI1 define
#define EXTIA1					{EXTI1, EXTI1_POSITION, GPIO_PIN_1,GPIOA}
#define EXTIB1					{EXTI1, EXTI1_POSITION, GPIO_PIN_1,GPIOB}
#define EXTIC1					{EXTI1, EXTI1_POSITION, GPIO_PIN_1,GPIOC}
#define EXTID1					{EXTI1, EXTI1_POSITION, GPIO_PIN_1,GPIOD}
//-----------------------------------------------------------------------------
//EXTI2 define
#define EXTIA2					{EXTI2, EXTI2_POSITION, GPIO_PIN_2,GPIOA}
#define EXTIB2					{EXTI2, EXTI2_POSITION, GPIO_PIN_2,GPIOB}
#define EXTIC2					{EXTI2, EXTI2_POSITION, GPIO_PIN_2,GPIOC}
#define EXTID2					{EXTI2, EXTI2_POSITION, GPIO_PIN_2,GPIOD}
//-----------------------------------------------------------------------------
//EXTI3 define
#define EXTIA3					{EXTI3, EXTI3_POSITION, GPIO_PIN_3,GPIOA}
#define EXTIB3					{EXTI3, EXTI3_POSITION, GPIO_PIN_3,GPIOB}
#define EXTIC3					{EXTI3, EXTI3_POSITION, GPIO_PIN_3,GPIOC}
#define EXTID3					{EXTI3, EXTI3_POSITION, GPIO_PIN_3,GPIOD}
//-----------------------------------------------------------------------------
//EXTI4 define
#define EXTIA4					{EXTI4, EXTI4_POSITION, GPIO_PIN_4,GPIOA}
#define EXTIB4					{EXTI4, EXTI4_POSITION, GPIO_PIN_4,GPIOB}
#define EXTIC4					{EXTI4, EXTI4_POSITION, GPIO_PIN_4,GPIOC}
#define EXTID4					{EXTI4, EXTI4_POSITION, GPIO_PIN_4,GPIOD}
//-----------------------------------------------------------------------------
//EXTI5 define
#define EXTIA5					{EXTI5, EXTI5_POSITION, GPIO_PIN_5,GPIOA}
#define EXTIB5					{EXTI5, EXTI5_POSITION, GPIO_PIN_5,GPIOB}
#define EXTIC5					{EXTI5, EXTI5_POSITION, GPIO_PIN_5,GPIOC}
#define EXTID5					{EXTI5, EXTI5_POSITION, GPIO_PIN_5,GPIOD}
//-----------------------------------------------------------------------------
//EXTI6 define
#define EXTIA6					{EXTI6, EXTI6_POSITION, GPIO_PIN_6,GPIOA}
#define EXTIB6					{EXTI6, EXTI6_POSITION, GPIO_PIN_6,GPIOB}
#define EXTIC6					{EXTI6, EXTI6_POSITION, GPIO_PIN_6,GPIOC}
#define EXTID6					{EXTI6, EXTI6_POSITION, GPIO_PIN_6,GPIOD}
//-----------------------------------------------------------------------------
//EXTI7 define
#define EXTIA7					{EXTI7, EXTI7_POSITION, GPIO_PIN_7,GPIOA}
#define EXTIB7					{EXTI7, EXTI7_POSITION, GPIO_PIN_7,GPIOB}
#define EXTIC7					{EXTI7, EXTI7_POSITION, GPIO_PIN_7,GPIOC}
#define EXTID7					{EXTI7, EXTI7_POSITION, GPIO_PIN_7,GPIOD}
//-----------------------------------------------------------------------------
//EXTI8 define
#define EXTIA8					{EXTI8, EXTI8_POSITION, GPIO_PIN_8,GPIOA}
#define EXTIB8					{EXTI8, EXTI8_POSITION, GPIO_PIN_8,GPIOB}
#define EXTIC8					{EXTI8, EXTI8_POSITION, GPIO_PIN_8,GPIOC}
#define EXTID8					{EXTI8, EXTI8_POSITION, GPIO_PIN_8,GPIOD}
//-----------------------------------------------------------------------------
//EXTI9 define
#define EXTIA9					{EXTI9, EXTI9_POSITION, GPIO_PIN_9,GPIOA}
#define EXTIB9					{EXTI9, EXTI9_POSITION, GPIO_PIN_9,GPIOB}
#define EXTIC9					{EXTI9, EXTI9_POSITION, GPIO_PIN_9,GPIOC}
#define EXTID9					{EXTI9, EXTI9_POSITION, GPIO_PIN_9,GPIOD}
//-----------------------------------------------------------------------------
//EXTI10 define
#define EXTIA10					{EXTI10, EXTI10_POSITION, GPIO_PIN_10,GPIOA}
#define EXTIB10					{EXTI10, EXTI10_POSITION, GPIO_PIN_10,GPIOB}
#define EXTIC10					{EXTI10, EXTI10_POSITION, GPIO_PIN_10,GPIOC}
#define EXTID10					{EXTI10, EXTI10_POSITION, GPIO_PIN_10,GPIOD}
//-----------------------------------------------------------------------------
//EXTI11 define
#define EXTIA11					{EXTI11, EXTI11_POSITION, GPIO_PIN_11,GPIOA}
#define EXTIB11					{EXTI11, EXTI11_POSITION, GPIO_PIN_11,GPIOB}
#define EXTIC11					{EXTI11, EXTI11_POSITION, GPIO_PIN_11,GPIOC}
#define EXTID11					{EXTI11, EXTI11_POSITION, GPIO_PIN_11,GPIOD}
//-----------------------------------------------------------------------------
//EXTI12 define
#define EXTIA12					{EXTI12, EXTI12_POSITION, GPIO_PIN_12,GPIOA}
#define EXTIB12					{EXTI12, EXTI12_POSITION, GPIO_PIN_12,GPIOB}
#define EXTIC12					{EXTI12, EXTI12_POSITION, GPIO_PIN_12,GPIOC}
#define EXTID12					{EXTI12, EXTI12_POSITION, GPIO_PIN_12,GPIOD}
//-----------------------------------------------------------------------------
//EXTI13 define
#define EXTIA13					{EXTI13, EXTI13_POSITION, GPIO_PIN_13,GPIOA}
#define EXTIB13					{EXTI13, EXTI13_POSITION, GPIO_PIN_13,GPIOB}
#define EXTIC13					{EXTI13, EXTI13_POSITION, GPIO_PIN_13,GPIOC}
#define EXTID13					{EXTI13, EXTI13_POSITION, GPIO_PIN_13,GPIOD}
//-----------------------------------------------------------------------------
//EXTI14 define
#define EXTIA14					{EXTI14, EXTI14_POSITION, GPIO_PIN_14,GPIOA}
#define EXTIB14					{EXTI14, EXTI14_POSITION, GPIO_PIN_14,GPIOB}
#define EXTIC14					{EXTI14, EXTI14_POSITION, GPIO_PIN_14,GPIOC}
#define EXTID14					{EXTI14, EXTI14_POSITION, GPIO_PIN_14,GPIOD}
//-----------------------------------------------------------------------------
//EXTI15 define
#define EXTIA15					{EXTI15, EXTI15_POSITION, GPIO_PIN_15,GPIOA}
#define EXTIB15					{EXTI15, EXTI15_POSITION, GPIO_PIN_15,GPIOB}
#define EXTIC15					{EXTI15, EXTI15_POSITION, GPIO_PIN_15,GPIOC}
#define EXTID15					{EXTI15, EXTI15_POSITION, GPIO_PIN_15,GPIOD}
//-----------------------------------------------------------------------------
#define EXTI_TRIGGER_RISSING					0U
#define EXTI_TRIGGER_FALLING					1U
#define EXTI_TRIGGER_RISSING_FALLING			2U
#define EXTI_TRIGGER_RESET						3U
//-----------------------------------------------------------------------------
//NVIC STATUS
#define _EXTI_ENABLED        					1U
#define _EXTI_DISABLED							0U

//=================================================================================================
/*
* ===============================================
* APIs Supported by "MCAL EXTI DRIVER"
* ===============================================
*/
void MCAL_EXTI_GPIO_INIT(EXTI_CNFG_t* _CNFG);
void MCAL_EXTI_GPIO_UPDATE(EXTI_CNFG_t* _CNFG);

void MCAL_EXTI_GPIO_DeInit(void);
//=================================================================================================


//=================================================================================================

#endif /* MCAL__INCLUDE_STM32F103X6_EXTI_H_ */
