/*
 * Factorial_Number_Recursion.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Abdulrahman Alaa-Eldin
 */

#include <stdio.h>

int x;

void factorial(int a,int b);

int main()
{
	printf("Enter a positive integer: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&x);
    if(x > 0 && x <= 19)
    {
    	printf("\nfactorial of %d is: ",x);
    	factorial(x,1);
    	printf("%d ",x);
    }
    else
    {
    	if(x < 19)
    		printf("\nYou didn't enter a positive number");
    	else
    		printf("\nThe factorial is larger than storage limitation");
    }
	return 0;
}

void factorial(int a,int b)
{
	int v = b;
    if(v != x)
    {
    	a= a*v;
		factorial(a,++v);
    }
    else
    {
    	x = a;
    }
}
