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
	struct info
	{
		char name[20];
		unsigned int  Id ;
	}Employee[3] = {{"Alex",1002},
					{"Emy",1003},
					{"Tony",1004}
								};
	struct info* p__arr[3];
	unsigned char i;
	for(i=0; i<3; i++)
	{
		p__arr[i] = &Employee[i];
	}
	struct info* pArr = p__arr[0];
	printf("Employee Name : %s\n\n", pArr->name);
	printf("Employee ID   : %d\n",pArr->Id);
	return 0 ;
}
