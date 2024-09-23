/*
 * Insert_an_element_in_array.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

#define size    200

int main()
{
	int arr[size],i,no,ele,loca;
	float sc;
	printf("Enter no of elements : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&sc);
	no =sc;
	if((no == sc && no > 0) && (no <= size))
	{
		printf("\n");
		for(i = 0; i<no; i++)
		{
			arr[i] = i+1;
			printf("%d ",arr[i]);
		}
		printf("\n\nEnter the element to be inserted : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&sc);
		ele = sc;
		printf("\nEnter the location : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&sc);
		loca = sc;
		if(loca > 0)
		{
			printf("\n");
			arr[loca-1] = ele;
			for(i=0; i<(no+1); i++)
			{
				arr[i+loca] = loca+i;
				printf("%d ",arr[i]);
			}
		}
		else
		{
			printf("Error in address of location.\nAddress must be upper than zero\nand not fractional number");
		}
	}
	else
	{
		if((no != sc && no <= 0))
			printf("Error in number of elements.\nNumber must be upper than zero\nand not fractional number");
		else
			printf("Error in number of elements.\nNumber must be lower than or equal %d : ",size);
	}
	return 0;
}


