/*
 * finding_factorial_of_number.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	int number = 0;
	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	int check = (number >> 31);
	if(check == 0)
	{
		if(number != 0)
		{
			int loap = 0;
			int fac  = 1;
			for(loap=1; loap<=number; loap++)
			{
				fac*=loap;
			}
			printf("Factorial = %d",fac);
		}
		else
			printf("Factorial of 0 is 1");
	}
	else
	{
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	return 0;
}


