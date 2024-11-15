/*
 * lifo.h
 *
 *  Created on: Nov 14, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

#ifndef LIFO_H_
#define LIFO_H_
/*====================Includes========================*/
#include "stdint.h"
/*====================Macros========================*/

// Configurations from User.
#define DataType   uint32_t
#define Length_Buf    5

/*====================Type_Definitions========================*/

typedef struct
{
	uint32_t  width;
	DataType* Base ;
	DataType* Head ;
	uint32_t  count;
}LIFO_BASE_t;

typedef enum
{
	LIFO_noError,
	LIFO_Empty,
	LIFO_full,
	LIFO_Error
}LIFO_Status;

/*====================ProtoTypes========================*/

LIFO_Status LIFO_Buf_Init(LIFO_BASE_t* PLIFO, DataType* P_Buf, uint32_t length);		//Initiate a LIFO to point to a Buffer which the size of the buf's element is 32 Bytes.
LIFO_Status LIFO_AddData(LIFO_BASE_t* PLIFO, DataType temp);		//Add a data to a buffer by "LIFO Mechanism" which the size of data is 32 Bytes.
LIFO_Status LIFO_GetData(LIFO_BASE_t* PLIFO, DataType* temp);		//Get a data from a buffer by "LIFO Mechanism" which the size of data is 32 Bytes.

/*===============================================================*/
#endif /* LIFO_H_ */
