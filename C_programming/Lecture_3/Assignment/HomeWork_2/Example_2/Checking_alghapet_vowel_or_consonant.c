/*
 * Checking_alghapet_vowel_or_consonant.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	char alphabet = '\0';
	char check     = '\0';
	printf("Enter an alphabet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&alphabet);
    check = ((alphabet == 'a') || (alphabet == 'e') || (alphabet == 'o') || (alphabet == 'i') || (alphabet == 'u'))? '1' : '0' ;
	if(check == '1')
	{
		printf("%c is a vowel.",alphabet);
	}
	else
	{
		printf("%c is a consonant.",alphabet);
	}
    return 0;
}

