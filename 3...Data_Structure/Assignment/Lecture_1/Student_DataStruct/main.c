/*
 * main.c
 *
 *  Created on: Nov 18, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */


/*====================Includes========================*/

#include <stdio.h>
#include "student.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

extern LLS_BaseNode* gp_BaseStudent;
extern uint32_t Count;

/*====================ProtoTypes/Declarations========================*/



/*====================MAIN_APPLICATION========================*/

int main()
{
	while(1)
	{
		DPRINTF("===============================\n");
		uint32_t opt;
		DPRINTF("01.Add Student.\n");
		DPRINTF("02.Delete Student.\n");
		DPRINTF("03.View Students.\n");
		DPRINTF("04.Delete All.\n");
		DPRINTF("05.View Data with arrange of Students.\n");
		DPRINTF("06.Number of Students.\n");
		DPRINTF("07.Display data of member locate at middle of the list.\n");
		DPRINTF("\n=======Advanced Options=======\n");
		DPRINTF("08.Detect Loop in list.\n");
		DPRINTF("09.Reverse the list.\n");
		DPRINTF("===============================\n\n");
		DPRINTF("Enter your option: ");
		scanf("%u",&opt);
		switch(opt)
		{
		case 1:
			AddStudent();
			break;
		case 2:
			DelStud();
			break;
		case 3:
			ViewStudent();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			VPos_Index();
			break;
		case 6:
			Num_Student_L(gp_BaseStudent);
			DPRINTF("\nThe number of student by \"Recursive Method\" is: %u\n",Num_Student_R(gp_BaseStudent));
			Count = 0;
			break;
		case 7:
			Mid_List(gp_BaseStudent);
			break;
		case 8:
			Detect_LoapList(gp_BaseStudent);
			break;
		case 9:
			Rev_List(&gp_BaseStudent);
			break;
		default:
			DPRINTF("\nSelection Error!!\n");
			break;
		}
		DPRINTF("\n===============================\n");
		DPRINTF("\nTo Continue press 'Y': ");
		char Y;
		scanf("%c",&Y);
		if(Y != 'Y' && Y != 'y')
		{
			DPRINTF("\n-----Program End-----\n");
			DPRINTF("\n===============================\n");
			uint32_t i;
			for(i = 0; i<500000000; i++);
			break;
		}
	}
	return 0;
}

/*====================Definitions/Functions========================*/



/*===============================================================*/
