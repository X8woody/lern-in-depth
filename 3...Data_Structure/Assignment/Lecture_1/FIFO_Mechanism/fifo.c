/*
 * fifo.c
 *
 *  Created on: Nov 16, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

/*====================Includes========================*/

#include "fifo.h"

/*====================Functions========================*/

FIFO_Status FIFO_Init(FIFO_BASE_t* PFIFO, DataType* PBuff, uint32_t width)
{
	//check if the buffer is already exist or not.
	if(!PBuff)
		return FIFO_Error;
	PFIFO->width = width;
	PFIFO->Base  = PBuff;
	PFIFO->Head  = PBuff;
	PFIFO->tail  = PBuff;
	PFIFO->count = 0;
	return FIFO_noError;
}
FIFO_Status FIFO_AddData(FIFO_BASE_t* PFIFO, DataType data)
{
	//check if FIFO is already pointing to a buffer or not.
	if(!PFIFO->Base || !PFIFO->Head || !PFIFO->tail)
		return FIFO_Error;
	//check if FIFO is full or not.
	else if(PFIFO->count == PFIFO->width)
		return FIFO_full;
	//*(PFIFO->Head) = data;
	//check if Head pointer is at head of buffer or not.
	if(PFIFO->Head == EndAdd_Buff)
	{
		PFIFO->Head = PFIFO->Base;
	}
	*(PFIFO->Head) = data;
	PFIFO->Head++;
	PFIFO->count++;
	return FIFO_noError;
}
FIFO_Status FIFO_GetData(FIFO_BASE_t* PFIFO, DataType* data)
{
	//check if FIFO is already pointing to a buffer or not.
	if(!PFIFO->Base || !PFIFO->Head || !PFIFO->tail)
		return FIFO_Error;
	//check if FIFO is Empty or not.
	else if(PFIFO->count == 0)
		return FIFO_Empty;
	//check if there is a data or not.

	//check if tail pointer is at head of buffer or not.
	if(PFIFO->tail == EndAdd_Buff)
	{
		PFIFO->tail = PFIFO->Base;
	}
	*data = *(PFIFO->tail);
	*(PFIFO->tail) = (DataType)NULL;
	PFIFO->tail++;
	PFIFO->count--;
	return FIFO_noError;
}


/*===============================================================*/
