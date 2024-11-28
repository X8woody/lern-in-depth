/*
 * US_sensor.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

/*====================Includes========================*/

#include "US_sensor.h"

/*====================Macros========================*/



/*====================Global_Variables========================*/

int US_distance;

/*====================Declaration========================*/

void (*US_state)();

/*====================Functions========================*/


Func_State(US_init)
{
	US_STATUS = US_init;
	printf("US_init...\n");
	//US_state = STATE(US_busy);
	STATE(US_busy)();
}

Func_State(US_busy)
{
	US_STATUS = US_busy;
	printf("US_busy...\n");
	US_distance = US_random(450,550,1);
	printf("US_Distance ----> %d\n",US_distance);
	US_Set_distance(US_distance);
	US_state = STATE(US_busy);
}

int US_random(int l, int r, int count)
{
	int i,dist;
	for(i = 0; i < count; i++)
	{
		dist = ((rand() % (r-l+1)) +1);

	}
	return dist;
}
/*===============================================================*/
