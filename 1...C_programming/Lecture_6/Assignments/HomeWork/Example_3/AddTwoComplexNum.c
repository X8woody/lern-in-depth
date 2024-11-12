/*
 * AddTwoComplexNum.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdulrhman Alaa_Eldin
 */
#include <stdio.h>

struct complex
{
	float real;
	float imaginary;
};

struct complex add(struct complex x,struct complex y)
{
	struct complex sum;
	sum.real = x.real + y.real;
	sum.imaginary = x.imaginary + y.imaginary;
	return sum;
}

int main()
{
	struct complex num_1,num_2,sum;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&num_1.real,&num_1.imaginary);
	printf("\nFor 2nd complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&num_2.real,&num_2.imaginary);
	sum = add(num_1,num_2);
	printf("\nSum = %0.1f + %0.1fi",sum.real,sum.imaginary);
	return 0;
}

