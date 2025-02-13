/*
 * AmitKit.c
 *
 * Created: 2/12/2025 3:26:08 PM
 * Author : Abdulrhman
 */ 

#include "GPIO_CONFIG.h"


#define BUZZER_ON				GPIO_SET(D,4)
#define BUZZER_OFF				GPIO_RESET(D,4)
#define LED1_ON					GPIO_SET(D,5)
#define LED1_OFF				GPIO_RESET(D,5)
#define LED2_ON					GPIO_SET(D,6)
#define LED2_OFF				GPIO_RESET(D,6)
#define LED3_ON					GPIO_SET(D,7)
#define LED3_OFF				GPIO_RESET(D,7)


void __delay(void);


int main(void)
{
	//Configure PORTD PIN_4,5,6 and 7 as output.
    DDRD |= (0b1111 << 4);
	
    while (1) 
    {
		LED1_ON;
		__delay();
		LED1_OFF;
		LED2_ON;
		__delay();
		LED2_OFF;
		LED3_ON;
		BUZZER_ON;
		__delay();
		LED3_OFF;
		BUZZER_OFF;
		__delay();
    }
}


void __delay(void)
{
	long unsigned int i;
	for(i = 0; i < 100000; i++);
}