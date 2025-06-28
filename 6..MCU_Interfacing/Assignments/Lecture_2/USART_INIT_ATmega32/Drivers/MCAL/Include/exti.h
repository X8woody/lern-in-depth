/*
 * interrupt.h
 *
 *  Created on: Jun 2, 2025
 *      Author: Abdulrhman
 */

#ifndef MCAL__INCLUDE_EXTI_H_
#define MCAL__INCLUDE_EXTI_H_

#include "Atmega32_gpio.h"
#include <avr/interrupt.h>


typedef enum
{
 LowLevel_Generate_INT  =             	0b00,
 AnyLogic_Generate_INT  =             	0b01,
 FallEdge_Generate_INT  =             	0b10,
 RisEdge_Generate_INT   =             	0b11
}EXTI_Trigger_t;

typedef struct
{
	uint8_t PinNumber;                     // must be set EXTI0_PIN or EXTI1_PIN or EXTI2_PIN.
	uint8_t NUM_INT;
	EXTI_Trigger_t INT_Sense_CTRL;
	uint8_t EXTI_EnableDisable;
	void (*P_FUNC_IRQ)(void);
}EXTI_CONFIG_t;


//#define LowLevel_Generate_INT               	0b00
//#define AnyLogic_Generate_INT               	0b01
//#define FallEdge_Generate_INT               	0b10
//#define RisEdge_Generate_INT                	0b11

#define SNS_CTRL_INT1(x)						MCUCR  = (x != 0x00)? MCUCR   | (x << 0x02)        : MCUCR   & ~(0b11 << 0x02)
#define SNS_CTRL_INT0(x)						MCUCR  = (x != 0x00)? MCUCR   | (x << 0x00)        : MCUCR   & ~(0b11 << 0x00)
#define SNS_CTRL_INT2(x)						MCUCSR = (x != 0x02)? MCUCSR  | ((x >> 1) << 0x06) : MCUCSR  & ~(0x01 << 0x06)

#define EXTI_ENABLE								1UL
#define EXTI_DISABLE							0UL

#define EXTI_ReqEnable(x,b)                     GICR   = (b == EXTI_ENABLE)? GICR | (1 << x) : GICR & ~(1 << x)

#define EXTI_ClearFalg(x)						GIFR   &= ~(1 << x)

#define EXTI0_PIN                               GPIO_PIN_2
#define EXTI1_PIN                               GPIO_PIN_3
#define EXTI2_PIN                               GPIO_PIN_2


#define GPIOx_INTx(b)							(b == 0x05)? GPIOB : GPIOD





void MCAL_EXTI_INIT(EXTI_CONFIG_t* EXTI_CNFG);


#endif /* MCAL__INCLUDE_EXTI_H_ */
