/*
 * Multidimensional_Array.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	float a[2][2];
	float b[2][2];
	float x[2][2];
	int i,c;
	printf("Enter the elements of 1st Matrix\n");
	fflush(stdin);
	fflush(stdout);
	for(i=0; i<2; i++)
	{
		for(c =0; c<2; c++)
		{
			printf("Enter a%d%d : ",(i+1),(c+1));
			fflush(stdin);
			fflush(stdout);
			scanf("%f",&a[i][c]);
		}
	}
	printf("Enter the elements of 2nd Matrix\n");
	fflush(stdin);
	fflush(stdout);
	for(i =0; i<2; i++)
	{
		for(c =0; c<2; c++)
		{
			printf("Enter b%d%d : ",(i+1),(c+1));
			fflush(stdin);
			fflush(stdout);
			scanf("%f",&b[i][c]);
		}
	}
	for(i=0; i<2; i++)
	{
		for(c=0; c<2; c++)
		{
			x[i][c]=a[i][c]+b[i][c];
		}
	}
	printf("\n\nSum Of Matix:\n");
	for(i=0; i<2; i++)
	{
		if(i == 1)
			printf("\n");
		else
		{
		}
		for(c=0; c<2; c++)
		{
			if(c == 1)
				printf("  ");
			else
			{
			}
			printf("%0.1f",x[i][c]);

		}
	}
	return 0;
}

