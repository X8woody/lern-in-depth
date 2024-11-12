/*
 * Checking_whether_number_is_even_or_odd.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	float number = 0;
	float div    = 0;
	printf("Enter an integer you want to check: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&number);
	div = (number/2.0);
	if((int)div == div)
	{
		float num = number;
		if (num != 0)
			printf("%0.0f is even",num);
		else
			printf("you entered a character value ");
	}
	else
	{
		int num = number;
		if (num == number)
			printf("%d is odd",num);
		else
			printf("you entered a fraction number ");
	}
	return 0;
}

