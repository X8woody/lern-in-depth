/*
 * Finding_theLargest_number_Among_three_numbers.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	float num_1 = 0.0;
	float num_2 = 0.0;
	float num_3 = 0.0;
	printf("Enter three numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f %f",&num_1,&num_2,&num_3);
	if(num_1 > num_2)
	{
		if(num_1 > num_3)
			printf("Largest number = %0.2f",num_1);
		else
			printf("Largest number = %0.2f",num_3);
	}
	else if(num_2 > num_1)
	{
		if(num_2 > num_3)
			printf("Largest number = %0.2f",num_2);
		else
			printf("Largest number = %0.2f",num_3);
	}
	else
	{
		printf("Largest number = %0.2f",num_3);
	}
	return 0;
}
