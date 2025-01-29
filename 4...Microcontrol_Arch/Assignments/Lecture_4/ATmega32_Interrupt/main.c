/*
 * ATmega32_Interrup
 *
 * Created: 1/27/2025 6:09:54 PM
 * Author : Abdulrhman
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>   

/*
#define SREG_Base		0x3F
#define SREG			*((volatile unsigned int *)(SREG_Base + 0x5F))

#define MCUCR_Base		0x35
#define MCUCR		*((volatile unsigned int *)(MCUCR_Base + 0x55))

#define GICR_Base		0x3B
#define GICR		*((volatile unsigned int *)(GICR_Base + 0x5B))

#define GIFR_Base		0x3A
#define GIFR		*((volatile unsigned int *)(GIFR_Base + 0x5A))

#define DDRD_Base		0x11
#define DDRD		*((volatile unsigned int *)(DDRD_Base + 0x31))

#define PORTD_Base		0x12
#define PORTD		*((volatile unsigned int *)(PORTD_Base + 0x32))
*/
	
void INT0_INIT(void);
void INT1_INIT(void);
void INT2_INIT(void);
void PORTD_INIT(void);
void PORTB_INIT(void);

ISR(INT0_vect)
{

	PORTD |= (1 << 4);      //PIN_4 @ PORTD is ON.
	_delay_ms(2000);
	PORTD &= ~(1 << 4);		//PIN_4 @ PORTD is OFF.
	_delay_ms(2000);
}

ISR(INT1_vect)
{

	PORTD |= (1 << 5);		//PIN_5 @ PORTD is ON.
	_delay_ms(2000);
	PORTD &= ~(1 << 5);		//PIN_5 @ PORTD is OFF.
	_delay_ms(2000);
}

ISR(INT2_vect)
{

	PORTD |= (1 << 6);		//PIN_6 @ PORTD is ON.
	_delay_ms(2000);
	PORTD &= ~(1 << 6);		//PIN_6 @ PORTD is OFF.
	_delay_ms(2000);
	GIFR &= ~(1 << 5);		//CLEAR FLAG of INTF2 @ GIFR Register.
}

int main(void)
{
    PORTD_INIT();
	PORTB_INIT();
	INT0_INIT();
	INT1_INIT();
	INT2_INIT();
    while (1) 
    {
    }
}


// Initialization of PIN_2,3,4,5,6 @ PORTD.
void PORTD_INIT(void)
{
	PORTD &= ~(0b11 << 2);
	DDRD  &= ~(0b11 << 2);
	DDRD  |=  (0b111 << 4);
}


// Initialization of PIN_2 @ PORTB. 
void PORTB_INIT(void)
{
	PORTB &= ~(1 << 2);
	DDRB  &= ~(1 << 2);
}


// Initialization of INT_0 @ PORTB PIN_2 occur at any logic.
void INT0_INIT(void)
{
	SREG	|= (1 << 7);
	MCUCR	|= (0b01 << 0);
	GICR	|= (1 << 6);
}

// Initialization of INT_1 @ PORTD PIN_3 occur at falling edge.
void INT1_INIT(void)
{
	SREG	|= (1 << 7);
	MCUCR	|= (0b10 << 2);
	GICR	|= (1 << 7);
}

// Initialization of INT_2 @ PORTB PIN_2 occur at rising edge.
void INT2_INIT(void)
{
	SREG	&= ~(1 << 7);
	MCUCSR	|= (1 << 6);
	SREG	|= (1 << 7);
	GICR	|= (1 << 5);
}