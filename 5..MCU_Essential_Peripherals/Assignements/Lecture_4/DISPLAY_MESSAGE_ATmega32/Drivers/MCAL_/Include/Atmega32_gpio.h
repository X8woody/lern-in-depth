/*
 * Atmega32_gpio.h
 *
 * Created: 5/21/2025 4:32:36 PM
 *  Author: Abdulrhman
 */ 


#ifndef ATMEGA32_GPIO_H_
#define ATMEGA32_GPIO_H_


#include <avr/io.h>





typedef enum
{
	MCAL_ERROR = 0u,
	MCAL_OK
}MCAL_STATUS_enum;

typedef enum
{
	GPIO_PIN_RESET = 0u,
	GPIO_PIN_SET
}MCAL_GPIO_PIN_STATUS;

typedef enum
{
	INPUT_MODE = 0u,
	OUTPUT_MODE
}MCAL_PIN_MODE_ENUM;

typedef struct
{
	volatile unsigned char  _Read_PIN_Px;
	volatile unsigned char  _SET_PIN_Dir_I_O_Px;
	volatile unsigned char  _SET_PIN_H_L_Px;
}GPIOx_REG_typedef;

typedef struct
{
	volatile uint8_t                 PIN_NUMBER;
	MCAL_PIN_MODE_ENUM               __PinMode;
}PIN_CFG_TypeDef;

#define GPIO_PIN_0                                        (uint8_t)0x01U   //(1 << 0);
#define GPIO_PIN_1                                        (uint8_t)0x02U   //(1 << 1);
#define GPIO_PIN_2                                        (uint8_t)0x04U   //(1 << 2);
#define GPIO_PIN_3                                        (uint8_t)0x08U   //(1 << 3);
#define GPIO_PIN_4                                        (uint8_t)0x10U   //(1 << 4);
#define GPIO_PIN_5                                        (uint8_t)0x20U   //(1 << 5);
#define GPIO_PIN_6                                        (uint8_t)0x40U   //(1 << 6);
#define GPIO_PIN_7                                        (uint8_t)0x80U   //(1 << 7);

#define GPIO_PIN_MASK                                     (uint8_t)0xFFU

#define GPIOA											  (GPIOx_REG_typedef *)(&PINA)
#define GPIOB											  (GPIOx_REG_typedef *)(&PINB)
#define GPIOC											  (GPIOx_REG_typedef *)(&PINC)
#define GPIOD											  (GPIOx_REG_typedef *)(&PIND)


void MCAL_GPIO_INIT(GPIOx_REG_typedef *GPIOx, PIN_CFG_TypeDef *GPIO_PIN_CFG);
void MCAL_GPIO_SET_DataDire(GPIOx_REG_typedef *GPIOx, MCAL_PIN_MODE_ENUM Dir, uint8_t PinNum);
void MCAL_GPIO_WRITE_PIN(GPIOx_REG_typedef *GPIOx, uint8_t PinNum, MCAL_GPIO_PIN_STATUS PinStatus);
void MCAL_GPIO_WRITE_PORT(GPIOx_REG_typedef *GPIOx, uint8_t SpecPins);
void MCAL_GPIO_TOGGLE_PIN(GPIOx_REG_typedef *GPIOx, uint8_t PinNum);

MCAL_GPIO_PIN_STATUS MCAL_GPIO_READ_PIN(GPIOx_REG_typedef *GPIOx, uint8_t PinNum);
uint8_t MCAL_GPIO_READ_PORT(GPIOx_REG_typedef *GPIOx);



#endif /* ATMEGA32_GPIO_H_ */
