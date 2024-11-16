/*
 * fifo.h
 *
 *  Created on: Nov 16, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */




#ifndef FIFO_H_
#define FIFO_H_

/*====================Includes========================*/

#include <stdint.h>

/*====================Macros========================*/

// Configurations from User.
// data type of each elements in the buffer.
#define DataType   uint32_t
//define width of the buffer
#define Length_Buf    5

//calculation of end address of buffer
#define EndAdd_Buff    (DataType*)(((DataType)PFIFO->Base) + (((DataType)PFIFO->width) * sizeof(DataType)))

#define NULL ((void *)0)

/*====================Global_Variables========================*/

//create a global buffer which compatible with data type in driver.
DataType Buffer[Length_Buf];

/*====================Type_Definitions========================*/

typedef struct
{
	uint32_t  width;
	DataType* Base ;
	DataType* Head ;
	DataType* tail ;
	uint32_t  count;
}FIFO_BASE_t;

typedef enum
{
	FIFO_noError,
	FIFO_Empty,
	FIFO_full,
	FIFO_Error
}FIFO_Status;

/*====================ProtoTypes========================*/

FIFO_Status FIFO_Init(FIFO_BASE_t* PFIFO, DataType* PBuff,  uint32_t width);		//Initiate a LIFO to point to a Buffer.
FIFO_Status FIFO_AddData(FIFO_BASE_t* PFIFO, DataType data);		//Add a data to a buffer by "LIFO Mechanism".
FIFO_Status FIFO_GetData(FIFO_BASE_t* PFIFO, DataType* data);		//Get a data from a buffer by "LIFO Mechanism".
FIFO_Status FIFO_chkFull(FIFO_BASE_t* PFIFO);										//check FIFO is Full or Not.

/*===============================================================*/

#endif /* FIFO_H_ */
