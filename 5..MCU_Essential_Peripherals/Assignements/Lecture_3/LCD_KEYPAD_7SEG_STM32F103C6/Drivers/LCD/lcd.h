/*
 * lcd.h
 *
 * Created: 4/29/2025 5:03:47 PM
 *  Author: Abdulrhman
 */ 


#ifndef LCD_H_
#define LCD_H_

#define __STM32F103C6                   0UL
#define __ATmega32						1UL

#define MCU_DVICE						__STM32F103C6

//-----------------------------
//Includes
//-----------------------------
#if MCU_DVICE == __STM32F103C6
	#include "stm32f103x6_gpio.h"
#else
	#include "Atmega32_gpio.h"
	#include <util/delay.h>
#endif
//-----------------------------
//User type definitions (structures)
typedef enum{
  IR_MODE = 0u,
  BF_MODE,
  DR_WRITE_MODE,
  DR_READ_MODE	
}MODE_RW_T;

typedef enum{
  ERROR = 0u,
  DONE	
}__STATUS_FUNC;
//-----------------------------
//Macros Configuration References
//-----------------------------
#if MCU_DVICE == __STM32F103C6

#define DataType_Pins            		 uint16_t

void _delay_ms(uint32_t __ms);

#else
#define DataType_Pins          uint8_t
#endif
//------- HERE YOU CAN SELECT WIDTH OF DATA !! -------//


//#define LCD_BIT_DATA_WIDTH_8
#define LCD_BIT_DATA_WIDTH_8


                 
//-----------------------------
//You can change PORT & PINs at below configurations.
//CONFIGURATION PINs.
#define LCD_GPIO_DATA           GPIOA
#define LCD_GPIO_Signal         GPIOA

//-----------------------------
#define PIN_0				  (DataType_Pins)0x01          //(0x01 << 0x00)
#define PIN_1				  (DataType_Pins)0x02          //(0x01 << 0x01)
#define PIN_2				  (DataType_Pins)0x04          //(0x01 << 0x02)
#define PIN_3                 (DataType_Pins)0x08          //(0x01 << 0x03)
#define PIN_4                 (DataType_Pins)0x10          //(0x01 << 0x04)
#define PIN_5                 (DataType_Pins)0x20          //(0x01 << 0x05)
#define PIN_6                 (DataType_Pins)0x40          //(0x01 << 0x06)
#define PIN_7                 (DataType_Pins)0x80          //(0x01 << 0x07)
//------------------------------
#if MCU_DVICE == ___STM32F103C6
#define PIN_8                 (DataType_Pins)(0x01 << 0x08)
#define PIN_9                 (DataType_Pins)(0x01 << 0x09)
#define PIN_10                (DataType_Pins)(0x01 << 0x0A)
#define PIN_11                (DataType_Pins)(0x01 << 0x0B)
#define PIN_12                (DataType_Pins)(0x01 << 0x0C)
#define PIN_13                (DataType_Pins)(0x01 << 0x0D)
#define PIN_14                (DataType_Pins)(0x01 << 0x0E)
#define PIN_15                (DataType_Pins)(0x01 << 0x0F)
#endif
//-----------------------------
//-----------------------------
#define RS_PIN                PIN_8
#define RW_PIN                PIN_9
#define EN_PIN                PIN_10
#define D0_PIN                PIN_0
#define D1_PIN                PIN_1
#define D2_PIN                PIN_2
#define D3_PIN                PIN_3
#define D4_PIN                PIN_4
#define D5_PIN                PIN_5
#define D6_PIN                PIN_6
#define D7_PIN                PIN_7
/*------------COMAND_LCD-----------------*/
#define DLCD_FUNC_SET              0x30
#define DLCD_8_BIT_DATA            0x38
#define DLCD_4_BIT_DATA            0x28
#define DLCD_DISP_OFF              0x08
#define DLCD_DISP_ON               0x0F
#define DLCD_CLEAR_DISP            0x01
#define DLCD_ENTRY_MODE            0x06
#define DLCD_RETURN_HOME           0x02
#define DLCD_MOVE_DISP_RIGHT       0x1C
#define DLCD_MOVE_DISP_LEFT   	   0x18
#define DLCD_MOVE_CURSOR_RIGHT     0x14
#define DLCD_MOVE_CURSOR_LEFT 	   0x10
#define DLCD_ENTRY_DEC   		   0x04
#define DLCD_ENTRY_DEC_SHIFT   	   0x05
#define DLCD_ENTRY_INC_   		   0x06
#define DLCD_ENTRY_INC_SHIFT   	   0x07
#define DLCD_BEGIN_AT_FIRST_ROW	   0x80
#define DLCD_BEGIN_AT_SECOND_ROW   0xC0
#define DLCD_SET_CGRAM_ADD    	   0x40
//-----------------------------
/*
* ===============================================
* APIs Supported by "HAL LCD DRIVER"
* ===============================================
*/
void HAL_LCD_INIT(void);
void HAL_LCD_SEND_COMMAND(uint8_t MODE);
void HAL_LCD_Write_CHAR(uint8_t data);
__STATUS_FUNC HAL_LCD_Write_custom_CHAR(uint8_t* data, uint8_t Address);
void HAL_LCD_SET_CURSOR(uint8_t LINE, uint8_t position);
uint8_t HAL_LCD_Write_STR(char* STR);
//-----------------------------
#endif /* LCD_H_ */
