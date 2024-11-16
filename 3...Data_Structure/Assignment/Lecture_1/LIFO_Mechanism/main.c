/*
 * main.c
 *
 *  Created on: Nov 14, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

/*====================Includes========================*/

#include <stdio.h>
#include "lifo.h"

/*====================Global_Variables========================*/

DataType Buffer[Length_Buf];

/*====================MAIN_APPLICATION========================*/

int main()
{
	LIFO_BASE_t* P_LIFO_Buffer ;
	LIFO_Buf_Init(P_LIFO_Buffer,Buffer, Length_Buf);
	uint32_t i;
	DataType temp;
	for(i = 0; i < Length_Buf; i++)
	{
		if(LIFO_AddData(P_LIFO_Buffer, i) == LIFO_noError)
		{
			printf("%u\n",Buffer[i]);
			fflush(stdin);
			fflush(stdout);
		}
	}
	for(i = 0; i < Length_Buf; i++)
	{
		if(LIFO_GetData(P_LIFO_Buffer,&temp) == LIFO_noError)
		{
			printf("\t%u\n",temp);
			fflush(stdin);
			fflush(stdout);
		}
	}
	return 0;
}

/*===============================================================*/
