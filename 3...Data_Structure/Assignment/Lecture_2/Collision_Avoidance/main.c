/*
 * main.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Abdurlhman Alaa-Eldin
 */
/*====================Includes========================*/

#include "CA.h"
#include "DC_motor.h"
#include "US_sensor.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/



/*====================ProtoTypes========================*/

void setup();

/*====================MAIN_APPLICATION========================*/

int main()
{
	setup();
	while(1)
	{
		CA_state();						//Handling between DC_motor and Ultra_Sonic
		DC_state();
		US_state();
		CA_state();
		DC_state();
		US_state();
		CA_state();
		DC_state();
	}
	return 0;
}

/*====================Functions========================*/

void setup()
{
	CA_state = STATE(CA_waiting);
	DC_state = STATE(DC_init);
	US_state = STATE(US_init);
	DC_state();      									//Calling DC_motor for initialization
	US_state();											//Calling Ultra_Sonic sensor for initialization
}

/*===============================================================*/

