/*
 * Prime_Between_twoIntervals.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Abdulrahman Alaa-Eldin
 */

#include <stdio.h>

void Prime_Num(int a,int b);

int main()
{
	int x,y;
	printf("Enter two numbers(Intervals): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d%d",&x,&y);
	if(x > y)
	{
		x += y;
		y  = x - y;
		x -= y;
	}
	else
	{
	}
	printf("Prime numbers between %d and %d is: ",x,y);
	Prime_Num(x,y);
	return 0;
}
void Prime_Num(int a,int b)
{
	int x = 0;
	int i;
	for(x=a; x<=b; x++)
	{
		if(x != 2){
			for(i=2; i<=9; i++)
			{
				if(((x%i) == 0) && (x != i))
					break;
				else
				{
				}
			}
			if(i == 10)
				printf("%d ",x);
			else
			{
			}
		}
		else
		{
		}
	}
}
