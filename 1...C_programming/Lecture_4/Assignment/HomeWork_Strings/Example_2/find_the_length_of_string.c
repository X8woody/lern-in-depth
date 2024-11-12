/*
 * find_the_length_of_string.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>


#define size 200

int main()
{
	char arr[size];
	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
    gets(arr);
    int i = 0;
    for(i=0; i<size; i++)
    {
    	if(arr[i] == '\0')
    	{
    		break;
    	}
    	else
    	{
    	}
    }
    printf("\nLength of string: %d",i);
	return 0;
}


