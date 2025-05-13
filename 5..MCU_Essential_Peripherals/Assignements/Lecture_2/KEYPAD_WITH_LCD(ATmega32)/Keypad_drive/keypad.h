/*
 * keypad.h
 *
 * Created: 4/29/2025 5:04:19 PM
 *  Author: Abdulrhman
 */ 


//[NOTE]: This driver is compatible with KEYPADs have size 4*4 only. !!  



#ifndef KEYPAD_H_
#define KEYPAD_H_
//-----------------------------
//Includes
//-----------------------------
#include <avr/io.h>
#include <util/delay.h>
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct {
	volatile uint8_t K_R1;
	volatile uint8_t K_R2;
	volatile uint8_t K_R3;
	volatile uint8_t K_R4;
	volatile uint8_t K_C1;
	volatile uint8_t K_C2;
	volatile uint8_t K_C3;
	volatile uint8_t K_C4;
}KEYPAD_PINS;
//-----------------------------
//Macros Configuration References
//-----------------------------
#ifndef KEY_SELECTED_GROUP
#define KEY_SELECTED_GROUP                                         'D' 
# warning "[NOTE]: YOU MUST DEFINE "KEY_SELECTED_GROUP" as 'A' or 'B' or 'C' or 'D' before including "keypad.h""     
#endif  
//-----------------------------                       
#if KEY_SELECTED_GROUP == 'A'
	#define KEY_PORT       PORTA
	#define KEY_PIN_I_O    DDRA
	#define KEY_PIN_READ   PINA
#elif KEY_SELECTED_GROUP == 'B'
	#define KEY_PORT       PORTB
	#define KEY_PIN_I_O    DDRB
	#define KEY_PIN_READ   PINB
#elif KEY_SELECTED_GROUP == 'C'
	#define KEY_PORT       PORTC
	#define KEY_PIN_I_O    DDRC
	#define KEY_PIN_READ   PINC
#else
	#define KEY_PORT       PORTD
	#define KEY_PIN_I_O    DDRD
	#define KEY_PIN_READ   PIND
#endif	
//-----------------------------
//GLOBAL VARIABLE DECLARATION
//-----------------------------	
//extern KEYPAD_PINS KEY_PAD;
//-----------------------------												 
/*
* ===============================================
* APIs Supported by "HAL KeyPad DRIVER"
* ===============================================
*/
void KEY_INIT(volatile uint8_t R1, volatile uint8_t R2, volatile uint8_t R3, volatile uint8_t R4, volatile uint8_t C1, volatile  uint8_t C2, volatile uint8_t C3, volatile uint8_t C4);
unsigned char KEY_READ_DATA();
//-----------------------------





#endif /* KEYPAD_H_ */