/*
 * DC_motor.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
/*====================Includes========================*/

#include "DC_motor.h"

/*====================Macros========================*/



/*====================Global_Variables========================*/

int DC_speed;

/*====================Declaration========================*/

void (*DC_state)();

/*====================Functions========================*/

void DC_Set_Speed(int s)
{

	DC_speed = s;
	printf("CA ----- speed = %d -----> DC_motor\n",DC_speed);
	DC_state = STATE(DC_busy);
}

Func_State(DC_init)
{
	DC_STATUS = DC_init;
	printf("DC_init...\n");
	//DC_state = STATE(DC_idle);
	STATE(DC_idle)();
}

Func_State(DC_idle)
{
	DC_STATUS = DC_idle;
	printf("DC_idle...\n");
	DC_state = STATE(DC_idle);
}

Func_State(DC_busy)
{
	DC_STATUS = DC_busy;
	printf("DC_busy...\n");
	printf("DC_speed is --------> %d\n",DC_speed);
	DC_state = STATE(DC_idle);
}

/*===============================================================*/

