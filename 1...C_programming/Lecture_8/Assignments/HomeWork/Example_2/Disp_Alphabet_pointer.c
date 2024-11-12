/*
 * demo_handle_pointer.c
 *
 *  Created on: Oct 17, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	char alph    = 'A';
	char* p_alph = &alph ;
	printf("The Alphabets are : \n\n");
	while(alph <= 'Z')
	{
		printf("%c ", alph);
		(*p_alph)++;
	}
	return 0 ;
}
