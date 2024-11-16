/*
 * lifo.c
 *
 *  Created on: Nov 14, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

/*====================Includes========================*/

#include "lifo.h"

/*====================Macros========================*/

#define NULL ((void *)0)

/*====================Functions========================*/

LIFO_Status LIFO_Buf_Init(LIFO_BASE_t* PLIFO, DataType* P_Buf, uint32_t length)
{
	//check if buffer is already exit or not.
	if(P_Buf == NULL)
		return LIFO_Error;

	PLIFO->width = length;
	PLIFO->Base  = P_Buf;
	PLIFO->Head  = P_Buf;
	PLIFO->count = 0;
	return LIFO_noError;
}

LIFO_Status LIFO_AddData(LIFO_BASE_t* PLIFO, DataType temp)
{
	//check if LIFO is already exit or not.
	if(!PLIFO->Base || !PLIFO->Head)
	{
		return LIFO_Error;
	}
	//check if LIFO is full or not.
	if (PLIFO->count == PLIFO->width)
	{
		return LIFO_full;
	}

	*(PLIFO->Head) = temp;
	PLIFO->Head++;
	PLIFO->count++;
	return LIFO_noError;
}

LIFO_Status LIFO_GetData(LIFO_BASE_t* PLIFO, DataType* temp)
{
	//check if LIFO is already exit or not.
	if(!PLIFO->Base || !PLIFO->Head)
	{
		return LIFO_Error;
	}
	//check if LIFO is Empty or not.
	if (PLIFO->count == 0)
	{
		return LIFO_Empty;
	}

	PLIFO->Head--;
	PLIFO->count--;
	*temp = *(PLIFO->Head);
	return LIFO_noError;
}

/*===============================================================*/

