/*
 * Calculatting_sum_of_natural_number.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	unsigned int number = 0;
	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u",&number);
	unsigned int loap = 0;
	unsigned int Sum  = 0;
	for (loap=1; loap<=number; loap++)
	{
       Sum+=loap;
	}
	printf("Sum = %u",Sum);
	return 0;
}

