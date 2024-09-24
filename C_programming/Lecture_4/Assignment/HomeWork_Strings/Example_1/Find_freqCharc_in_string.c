/*
 * Find_freqCharc_in_string.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>
#include <string.h>


#define size 200
int main()
{
	char arr[size],ch;
	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
    gets(arr);
	printf("\nEnter a character to find frequency: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&ch);
	int i   = 0;
	int len = strlen(arr);
	int inc = 0;
	for(i=0; i<len; i++)
	{
		if(ch == arr[i])
		{
			++inc;
		}
		else
		{
		}
	}
	if(inc == 0)
	{
		printf("\nThe character not found !!");
	}
	else
	{
		printf("\nFrequency of %c = %d",ch,inc);
	}
	return 0;
}

