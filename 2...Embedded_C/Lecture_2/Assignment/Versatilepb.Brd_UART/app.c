#include <uart.h>

unsigned char string[32] = "learn-in-depth : <Abdulrhman>";

void main(void)
{
	uart_send_data(string);
}