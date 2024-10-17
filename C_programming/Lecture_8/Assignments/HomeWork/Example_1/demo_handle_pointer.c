/*
 * demo_handle_pointer.c
 *
 *  Created on: Oct 17, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	int m = 29;
	printf("Address of m : 0x%x\n",(unsigned int)&m);
	printf("Value   of m : %d\n\n",m);

	int* ab = &m;
	printf("Now ab is assigned with the address of m\n");
	printf("Address of pointer ab : 0x%x\n",(unsigned int)ab);
	printf("content of pointer ab : %d\n\n",*ab);

	m = 34;
	printf("The value of m assigned to %d now\n",m);
	printf("Address of pointer ab : 0x%x\n",(unsigned int)ab);
	printf("content of pointer ab : %d\n\n",*ab);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value %d now\n",*ab);
	printf("Address of m : 0x%x\n",(unsigned int)&m);
	printf("Value   of m : %d\n\n",m);

	return 0 ;
}
