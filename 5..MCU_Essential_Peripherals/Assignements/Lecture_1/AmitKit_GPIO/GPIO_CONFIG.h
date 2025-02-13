#ifndef	__gpio_H
#define __gpio_H

#define PORTD_Base_Address							0x20
#define DDRD_OFFSET									0x11
#define PORTD_OFFSET								0x12
#define PIND_OFFSET									0x10
#define DDRD										*((volatile unsigned int*)(PORTD_Base_Address + DDRD_OFFSET))
#define PORTD										*((volatile unsigned int*)(PORTD_Base_Address + PORTD_OFFSET))
#define PIND										*((volatile unsigned int*)(PORTD_Base_Address + PIND_OFFSET))
#define GPIO_READ(PORT,PIN)							((PIN##PORT & (1 << PIN)) >> PIN)
#define PIN_D(NPIN)									GPIO_READ(D,NPIN)
#define GPIO_SET(Portt,PIN)							(PORT##Portt |= (1 << PIN))
#define GPIO_RESET(Portt,PIN)						(PORT##Portt &= ~(1 << PIN))
 																		
#endif