/*
 * Checking_whether_character_is_alphabet_or_not.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	char alphabet = '\0';
	printf("Enter a character: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&alphabet);
	if(((alphabet >= 'A') && (alphabet <= 'Z')) || ((alphabet >= 'a') && (alphabet <= 'z')))
	{
		printf("%c is an alphabet",alphabet);
	}
	else
	{
		printf("%c is not an alphabet",alphabet);
	}
	return 0;
}

