/*
 * Reverse string without using function Library.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>


#define size 200

int main()
{
	char arr[size];
	printf("Enter a string    : ");
	fflush(stdin);
	fflush(stdout);
    gets(arr);
    int i = 0;
    unsigned char feed =0,len;
    for(i=0; i<size; i++)
    {
    	if(arr[i] == '\0' && feed == 0)
    	{
    		len  = i;
    		i    = 0;
    		feed = 1;
    	}
    	else if(arr[i-1] == '\0' && feed == 1)
    	{
    		arr[size-1] = '\0';
    		feed = 2;
    		break;
    	}
    	else
    	{
    		if((arr[(size-1)] != '\0') && feed == 0)
    			arr[(size-1)-i] = arr[i];
    		else if((arr[(size-1)] != '\0') && feed == 1)
    			arr[i-1] = arr[(size-len)+(i-1)];
    	}
    }
    printf("Reverse string is : %s\r\n",arr);
    return 0;
}


