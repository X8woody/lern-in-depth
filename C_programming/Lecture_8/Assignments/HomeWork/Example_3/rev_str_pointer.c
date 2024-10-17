/*
 * demo_handle_pointer.c
 *
 *  Created on: Oct 17, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	printf("Input a string : ");
	fflush(stdin); fflush(stdout);
	gets(str);
	char* p_str = &(str[(strlen(str) - 1)]);
	printf("Reverse of the string is : ");
	while(p_str >= str)
	{
		printf("%c",*p_str);
		p_str--;
	}
	return 0 ;
}
