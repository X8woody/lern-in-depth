#include <uart.h>



void uart_send_data(unsigned char* p_tx)
{
	while(*p_tx != '\0')
	{
		UART0DR =  (unsigned int)*p_tx;
		*p_tx++;
	}
}