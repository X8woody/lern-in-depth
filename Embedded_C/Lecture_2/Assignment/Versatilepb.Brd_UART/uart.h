#ifndef UART_H
#define UART_H

#define UART0DR     *((volatile unsigned int*)((unsigned int*)0x101F1000))

extern void uart_send_data(unsigned char* p_tx);

#endif