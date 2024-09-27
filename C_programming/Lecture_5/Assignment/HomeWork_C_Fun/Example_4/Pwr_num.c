/*
 * Pwr_num.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Abdulrahman Alaa-Eldin
 */

#include <stdio.h>


int x,y;
int z = 1;
void pwr_num(int a ,int b);

int main()
{
	printf("Enter base number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&x);
	printf("Enter power number (positive integer): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&y);
	if(y > 0)
	{
		pwr_num(x,y);
		printf("%d^%d = %d",x,y,z);
	}
	else
	{
		printf("\nYou should enter a positive number");
	}
	return 0;
}

void pwr_num(int a ,int b)
{
    if(b != 0)
    {
    	z *= a;
    	pwr_num(a,--b);
    }
    else
    {
    }
}
