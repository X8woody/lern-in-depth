/*
 * US_sensor.h
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

#ifndef US_sens__
#define US_sens__

/*====================Includes========================*/

#include "STATE.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/

enum
{
	US_init,
	US_busy
}US_STATUS;


/*====================Global_Variables========================*/

extern void (*US_state)();

/*====================ProtoTypes========================*/

Func_State(US_init);
int US_random(int l, int r, int count);
Func_State(US_busy);

/*===============================================================*/


#endif

