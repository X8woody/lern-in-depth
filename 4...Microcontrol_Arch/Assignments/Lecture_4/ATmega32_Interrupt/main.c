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
#define IO_BASE       		0x20

#define SREG_Offset			0x3F
#define SREG				*((volatile unsigned int *)(IO_BASE + SREG_Offset))

#define MCUCR_Offset		0x35
#define MCUCR				*((volatile unsigned int *)(IO_BASE + MCUCR_Offset))

#define GICR_Offset			0x3B
#define GICR				*((volatile unsigned int *)(IO_BASE + GICR_Offset))

#define GIFR_Offset			0x3A
#define GIFR				*((volatile unsigned int *)(IO_BASE + GIFR_Offset))

#define DDRD_Offset			0x11
#define DDRD				*((volatile unsigned int *)(IO_BASE + DDRD_Offset))

#define PORTD_Offset		0x12
#define PORTD				*((volatile unsigned int *)(IO_BASE + PORTD_Offset))
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