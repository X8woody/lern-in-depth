/*
 * Checking_whether_number_is_positive_or_negative.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	float  number = 0;
	int    ex     = 0;
	int    check  = 0;
	printf("Enter a number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&number);
	ex = number;
	check = (ex >> 31);
	if(check == 0)
	{
		if(number != 0)
			printf("%0.2f is positive ",number);
		else
			printf("You entered zero");
	}
	else
	{
		printf("%0.2f is negative ",number);
	}
	return 0;
}

