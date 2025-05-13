/*
 * lcd.h
 *
 * Created: 4/29/2025 5:03:47 PM
 *  Author: Abdulrhman
 */ 


#ifndef LCD_H_
#define LCD_H_
//-----------------------------
//Includes
//-----------------------------
#include <avr/io.h>
#include <util/delay.h>
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

//------- HERE YOU CAN SELECT WIDTH OF DATA !! -------//


//#define LCD_BIT_DATA_WIDTH_8
#define LCD_BIT_DATA_WIDTH_4


                 
//-----------------------------
//You can change PORT & PINs at below configurations.
//CONFIGURATION PINs.
#define DLCD_DATA_OUT          PORTA
#define DLCD_DATA_DIRE         DDRA
#define DLCD_Signal_PORT       PORTB
#define DLCD_Signal_OUT        DDRB
#define DLCD_READ_PORT         PINA
//-----------------------------
#define PIN_0				  (uint8_t)(0x01 << 0x00)
#define PIN_1				  (uint8_t)(0x01 << 0x01)
#define PIN_2				  (uint8_t)(0x01 << 0x02)
#define PIN_3                 (uint8_t)(0x01 << 0x03)
#define PIN_4                 (uint8_t)(0x01 << 0x04)
#define PIN_5                 (uint8_t)(0x01 << 0x05)
#define PIN_6                 (uint8_t)(0x01 << 0x06)
#define PIN_7                 (uint8_t)(0x01 << 0x07)
//-----------------------------
#define RS_PIN                PIN_1
#define RW_PIN                PIN_2
#define EN_PIN                PIN_3
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
void FLCD_INIT(void);
void FLCD_SEND_COMMAND(uint8_t MODE);
void FLCD_Write_CHAR(uint8_t data);
__STATUS_FUNC FLCD_Write_custom_CHAR(uint8_t* data, uint8_t Address);
void FLCD_SET_CURSOR(uint8_t LINE, uint8_t position);
uint8_t FLCD_Write_STR(char* STR);
//-----------------------------
#endif /* LCD_H_ */