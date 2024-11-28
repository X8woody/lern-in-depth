/*
 * CA.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
/*====================Includes========================*/

#include "CA.h"

/*====================Macros========================*/



/*====================Global_Variables========================*/


int CA_speed = 0;
int CA_distance;
int CA_threshold = 50;

/*====================Declaration========================*/

void (*CA_state)();

/*====================Functions========================*/

void US_Set_distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state =  STATE(CA_waiting)) : (CA_state =  STATE(CA_driving));
}

Func_State(CA_waiting)
{
	CA_STATUS = CA_waiting;
	printf("CA_waiting...\n");
	CA_speed = 0;
	DC_Set_Speed(CA_speed);
}

Func_State(CA_driving)
{
	CA_STATUS = CA_driving;
	printf("CA_driving...\n");
	CA_speed = 30;
	DC_Set_Speed(CA_speed);
}

/*===============================================================*/

