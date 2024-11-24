/*
 * Studen.c
 *
 *  Created on: Nov 18, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */


/*====================Includes========================*/

#include "student.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

LLS_BaseNode* gp_BaseStudent = (LLS_BaseNode*)NULL;
uint32_t Count;

/*====================Functions========================*/


void AddStudent()
{
	LLS_BaseNode* lp_Stud;
	lp_Stud = (LLS_BaseNode*)NULL;
	if(LLS_CreatNode(&gp_BaseStudent, &lp_Stud))
	{
		DPRINTF("\n===============================\n");
		AGAIN:
		DPRINTF("Enter the ID: ");
		scanf("%u",&lp_Stud->Student.ID);
		LLS_BaseNode* check_List = gp_BaseStudent;
		while(check_List->P_NextNode)
		{
			if(lp_Stud->Student.ID == check_List->Student.ID)
			{
				DPRINTF("The ID you entered is already exist\n\n");
				goto AGAIN;
			}
			else
				check_List = check_List->P_NextNode;
		}
		DPRINTF("Enter the Student full name: ");
		gets(lp_Stud->Student.name);

		DPRINTF("Enter the height of the student: ");
		scanf("%f",&lp_Stud->Student.height);

		DPRINTF("Done Creation\n");
	}
	else
		DPRINTF("Failed !! Cannot create student data \n");
}

void DelStud()
{
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	DPRINTF("\n===============================\n");
	if(P_gp_BaseStudent)
	{
		uint32_t id;
		DPRINTF("Enter the ID: ");
		scanf("%u",&id);
		while(P_gp_BaseStudent->Student.ID != id && P_gp_BaseStudent != (LLS_BaseNode*)NULL)
		{
			if((P_gp_BaseStudent->P_NextNode))
				P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
			else if((!P_gp_BaseStudent) || (!P_gp_BaseStudent->P_NextNode))
				break;
		}
		if(P_gp_BaseStudent->Student.ID == id)
		{
			if(LLS_RemoveNode(&gp_BaseStudent, &P_gp_BaseStudent))
			{
				DPRINTF("Done\n");
			}
		}
		else
		{
			DPRINTF("Failed...!!\n");
		}
	}
	else
	{
		DPRINTF("Empty list\n");
	}
}

void ViewStudent()
{
	DPRINTF("\n===============================\n");
	uint32_t i = 0;
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("Empty list\n");
	}
	else
	{
		while(P_gp_BaseStudent)
		{
			DPRINTF("Record Number %u\n",++i);
			DPRINTF("ID:      %u\n",P_gp_BaseStudent->Student.ID);
			DPRINTF("Name:    %s\n",P_gp_BaseStudent->Student.name);
			DPRINTF("Height:  %0.1f\n\n",P_gp_BaseStudent->Student.height);
			P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
		}
	}
}

void Delete_All()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	LLS_BaseNode* P_Temp;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("Empty list\n");
	}
	else
	{
		while(P_gp_BaseStudent)
		{
			P_Temp = P_gp_BaseStudent->P_NextNode;
			free(P_gp_BaseStudent);
			P_gp_BaseStudent = P_Temp;
		}
		if(!P_gp_BaseStudent)
			gp_BaseStudent = P_gp_BaseStudent;
		DPRINTF("Now the list is Empty\n");
	}
}

void VPos_Index()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	LLS_BaseNode*Carriage_Data;
	if(P_gp_BaseStudent)
	{
		uint32_t pos;
		DPRINTF("Enter the Position of Index: ");
		scanf("%u",&pos);

		//Carriage_Data = GetNth(P_gp_BaseStudent,&pos);
		Carriage_Data = GetNth_FromLast(P_gp_BaseStudent,&pos);

		if(Carriage_Data && pos != 0)
		{
			//DPRINTF("Display data normally.\n");
			DPRINTF("Display data from the last member position.\n");
			DPRINTF("ID:      %u\n",Carriage_Data->Student.ID);
			DPRINTF("Name:    %s\n",Carriage_Data->Student.name);
			DPRINTF("Height:  %0.1f\n\n",Carriage_Data->Student.height);
		}
		else
			DPRINTF("There is no data matching with your Index\n\n");
	}
	else
	{
		DPRINTF("The list is Empty\n");
	}
}

LLS_BaseNode* GetNth(LLS_BaseNode* P_gp_BaseStudent,uint32_t* Index)
{
	if(!P_gp_BaseStudent)
		return (LLS_BaseNode*)NULL;
	else
	{
		LLS_BaseNode* P_Node = P_gp_BaseStudent;
		uint32_t i;
		for(i = 0; i < (*Index)-1; i++)
		{
			if((P_Node->P_NextNode) || ((!P_Node->P_NextNode) && i <((*Index)-1)))
				P_Node = P_Node->P_NextNode;
			else if((!P_Node->P_NextNode) && (i == ((*Index)-1)))
			{

			}
		}
		return P_Node;
	}
}

void Num_Student_L(LLS_BaseNode* P_gp_BaseStudent)
{
	uint32_t count = 0;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("\nEmpty list\n");
	}
	else
	{
		while(P_gp_BaseStudent)
		{
			count++;
			P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
		}
		DPRINTF("\nThe number of student with \"Iterative Method\" is: %u\n",count);
	}
}

uint32_t Num_Student_R(LLS_BaseNode* P_gp_BaseStudent)
{
	if((!P_gp_BaseStudent) && Count == 0)
	{
		DPRINTF("\nEmpty list\n");
	}
	else
	{
		if(P_gp_BaseStudent)
		{
			Count++;
			P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
			Count = Num_Student_R(P_gp_BaseStudent);
		}
	}
	return	Count;
}

LLS_BaseNode* GetNth_FromLast(LLS_BaseNode* P_gp_BaseStudent,uint32_t* Index)
{
	LLS_BaseNode* C_P_gp_BaseStudent = P_gp_BaseStudent;
	if(C_P_gp_BaseStudent)
	{
		uint32_t count = 0;
		if(C_P_gp_BaseStudent->P_NextNode)
		{
			while(C_P_gp_BaseStudent->P_NextNode)
			{
				count++;
				C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
			}
			count +=1;
		}
		else
			count = 1;
		if(*Index <= count)
		{
			uint32_t i;
			C_P_gp_BaseStudent = P_gp_BaseStudent;
			for(i = count; i > (*Index); i--)
				C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
		}
		else
			return (LLS_BaseNode*)NULL;
	}
	else
		return (LLS_BaseNode*)NULL;
	return C_P_gp_BaseStudent;
}

void Mid_List(LLS_BaseNode* P_gp_BaseStudent)
{
	if(!P_gp_BaseStudent)
	{
		DPRINTF("\nThe list is Empty\n");
	}
	else
	{
		LLS_BaseNode* C_P_gp_BaseStudent = P_gp_BaseStudent;
		uint32_t count = 1;
		while(C_P_gp_BaseStudent->P_NextNode)
		{
			count++;
			C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
		}
		uint32_t i;
		C_P_gp_BaseStudent = P_gp_BaseStudent;
		count = (count/2) + 1;
		for(i = 1; i < count; i++)
		{
			C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
		}
		DPRINTF("ID:      %u\n",C_P_gp_BaseStudent->Student.ID);
		DPRINTF("Name:    %s\n",C_P_gp_BaseStudent->Student.name);
		DPRINTF("Height:  %0.1f\n\n",C_P_gp_BaseStudent->Student.height);
	}
}

void Detect_LoapList(LLS_BaseNode* P_gp_BaseStudent)
{
	LLS_BaseNode* CP_gp_BaseStudent = P_gp_BaseStudent;
	if(!CP_gp_BaseStudent)
	{
		DPRINTF("\nThe list is Empty\n");
	}
	else
	{
		while(CP_gp_BaseStudent->P_NextNode)
		{
			CP_gp_BaseStudent = CP_gp_BaseStudent->P_NextNode;
			if(CP_gp_BaseStudent->P_NextNode == P_gp_BaseStudent)
			{
				break;
			}
		}
		if(!CP_gp_BaseStudent->P_NextNode)
		{
			DPRINTF("\nNo Looping\n");
		}
		else
		{
			DPRINTF("\nFined Looping\n");
		}
	}
}

void Rev_List(LLS_BaseNode** PP_gp_BaseStudent)
{
	LLS_BaseNode* PC = (*PP_gp_BaseStudent);
	LLS_BaseNode* PTail = (*PP_gp_BaseStudent);
	LLS_BaseNode* Base_Head = (*PP_gp_BaseStudent);
	LLS_BaseNode** SavedTail;
	if(!PC)
	{
		DPRINTF("\nThe list is Empty\n");
	}
	else
	{
		while(PTail->P_NextNode)
		{
			PTail = PTail->P_NextNode;
		}
		(*PP_gp_BaseStudent) = PTail;
		SavedTail = &PTail;
		while (PC != PTail)
		{
			while(PC->P_NextNode != PTail)
			{
				PC = PC->P_NextNode;
			}
			(*SavedTail)->P_NextNode = PC;
			SavedTail = &((*SavedTail)->P_NextNode);
			PTail = PC;
			PC = Base_Head;
		}
		if(PTail == PC)
		{
			(*SavedTail)->P_NextNode = (LLS_BaseNode*)NULL;
		}
		DPRINTF("\n REVERSE DONE \n");
	}
}



/*===============================================================*/
