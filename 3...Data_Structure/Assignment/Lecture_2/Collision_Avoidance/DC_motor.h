/*
 * DC_motor.h
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

#ifndef DC_motor__
#define DC_motor__
/*====================Includes========================*/

#include "STATE.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/

enum
{
	DC_init,
	DC_busy,
	DC_idle
}DC_STATUS;


/*====================Global_Variables========================*/

extern void (*DC_state)();

/*====================ProtoTypes========================*/

Func_State(DC_init);
Func_State(DC_idle);
Func_State(DC_busy);

/*===============================================================*/
#endif
