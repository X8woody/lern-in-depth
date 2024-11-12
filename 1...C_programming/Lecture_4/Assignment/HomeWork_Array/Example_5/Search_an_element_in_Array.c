/*
 * Search_an_element_in_Array.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

#define size    200
int main()
{
	int arr[size],i,no,ele;
	float sc;
	printf("Enter no of elements : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&sc);
	no =sc;
	if((no == sc && no > 0) && (no <= size))
	{
		printf("\n");
		for(i=0; i<no; i++)
		{
			arr[i] = ((i+1)*10)+(i+1);
			printf("%d ",arr[i]);
		}
		printf("\n\nEnter the element to be searched : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&sc);
		ele = sc;
		for(i=0; i<no; i++)
		{
			if(ele == arr[i])
			{
				break;
			}
			else
			{
			}
		}
		if(i == no)
		{
			printf("\nDidn't found number at any location of array");
		}
		else
		{
			printf("\nNumber found at the location : %d",i+1);
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


