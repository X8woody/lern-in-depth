/*
 * main.c
 *
 *  Created on: Nov 16, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

/*====================Includes========================*/

#include <stdio.h>
#include "fifo.h"

/*====================Macros========================*/


/*====================Global_Variables========================*/


/*====================MAIN_APPLICATION========================*/

int main()
{
	FIFO_BASE_t* P_LIFO_Buffer ;
	FIFO_Init(P_LIFO_Buffer,Buffer, Length_Buf);
	uint32_t i;
	DataType temp;
	for(i = 0; i < Length_Buf+1; i++)
	{
		if(FIFO_AddData(P_LIFO_Buffer, i+1) == FIFO_noError)
		{
			printf("Added Data: %u\n",Buffer[i]);
			fflush(stdin);
			fflush(stdout);
		}
		else
			printf("\nAdded Data: Failed\n\n");
	}
	for(i = 0; i < Length_Buf+1; i++)
	{
		if(FIFO_GetData(P_LIFO_Buffer,&temp) == FIFO_noError)
		{
			printf("\tGetting Data: %u\n",temp);
			fflush(stdin);
			fflush(stdout);
		}
		else
		{
			printf("\n\tGetting Data: Failed\n");
			fflush(stdin);
			fflush(stdout);
		}
	}
	return 0;
}

/*====================Functions========================*/



/*===============================================================*/
