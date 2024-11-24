/*
 * Student.h
 *
 *  Created on: Nov 18, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

#ifndef STUDENT_H_
#define STUDENT_H_

/*====================Includes========================*/

#include <stdio.h>
#include <conio.h>
#include "linkedlist.h"

/*====================Macros========================*/

#define DPRINTF(...)        {fflush(stdout);\
							fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);\
							fflush(stdin);}

/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/



/*====================ProtoTypes========================*/

void DelStud();
void AddStudent();
void ViewStudent();
void Delete_All();
LLS_BaseNode* GetNth(LLS_BaseNode* P_gp_BaseStudent,uint32_t* Index);
void VPos_Index();
void Num_Student_L(LLS_BaseNode* P_gp_BaseStudent);
uint32_t Num_Student_R(LLS_BaseNode* P_gp_BaseStudent);
LLS_BaseNode* GetNth_FromLast(LLS_BaseNode* P_gp_BaseStudent,uint32_t* Index);
void Mid_List(LLS_BaseNode* P_gp_BaseStudent);
void Detect_LoapList(LLS_BaseNode* P_gp_BaseStudent);
void Rev_List(LLS_BaseNode** PP_gp_BaseStudent);

/*===============================================================*/

#endif /* STUDENT_H_ */
