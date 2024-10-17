/*
 * demo_handle_pointer.c
 *
 *  Created on: Oct 17, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char str[15];
	lable_1:
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin); fflush(stdout);
	unsigned int size;
	scanf("%d",&size);
	if(size > 15 || size == 0)
	{
		goto lable_1;
	}
	printf("\nInput %d number of elements in the array : \n\n",size);
	unsigned char i ;
	for(i=0; i<size; i++)
	{
		printf("element - %d : ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%c",&str[i]);
	}
	i--;
	char* p_str = &(str[i]);
	printf("\nThe elements of array in reverse order are : \n\n");
	while(p_str >= str)
	{
		printf("element - %d : %c\n\n",i--+1,*p_str);
		p_str--;
	}
	return 0 ;
}
