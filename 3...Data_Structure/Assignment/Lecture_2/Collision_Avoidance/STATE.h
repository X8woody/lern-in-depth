/*
 * STATE.h
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

#ifndef STATE_H_
#define STATE_H_

/*====================Includes========================*/

#include <stdio.h>
#include <stdlib.h>

/*====================Macros========================*/

#define Func_State(_Name_func_)     void State_##_Name_func_()
#define STATE(__func_)				State_##__func_

/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/



/*====================ProtoTypes========================*/

void US_Set_distance(int d);
void DC_Set_Speed(int s);

/*===============================================================*/

#endif /* STATE_H_ */
