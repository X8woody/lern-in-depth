/*
 * Area_circle.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdulrhman Alaa_Eldin
 */
#include <stdio.h>

float area (float x)
{
	float A = (22.00/7.00) * (x * x);
	return A;
}

#define __Area_Circle__(float)      area(float)

int main()
{
	float Ar;
	printf("Enter the radius: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&Ar);
	int k = Ar;
	if(k != 0)
		printf("Area = %0.2f",__Area_Circle__(Ar));
	else
		printf("Enter a number !! not Zero not characters");
	return 0;
}
