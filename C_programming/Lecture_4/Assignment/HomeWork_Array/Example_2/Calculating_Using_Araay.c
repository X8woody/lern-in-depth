/*
 * Calculating_Using_Araay.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

#define size    200

int main()
{
	float a[size],sum =0,avg;
	float n;
	int i  ;
	printf("Enter the numbers of data: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&n);
    i = n;
    if((i != n) || (n <= 0))
    {
    	n = 0;
    }
    else if(i <= size)
    {
		for(i =0; i<n; i++)
		{
			printf("Enter Nubmber: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%f: ",&a[i]);
			sum += a[i];
		}
    }
	if(n > 0 && i <= size)
	{
		avg = (sum/n);
		printf("Average = %0.2f",avg);
	}
	else
	{
		if((i != n) || (n <= 0))
			printf("Error in number of data.\nNumber must be upper than zero\nand not fractional number");
		else
			printf("Error in number of elements.\nNumber must be lower than or equal %d : ",size);
	}
	return 0;
}
