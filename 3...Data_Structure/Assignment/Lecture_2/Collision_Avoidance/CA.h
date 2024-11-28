/*
 * CA.h
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */


#ifndef CA__
#define CA__
/*====================Includes========================*/

#include "STATE.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/

enum
{
	CA_waiting,
	CA_driving
}CA_STATUS;

/*====================Global_Variables========================*/

extern void (*CA_state)();

/*====================ProtoTypes========================*/

Func_State(CA_waiting);
Func_State(CA_driving);

/*===============================================================*/
#endif
