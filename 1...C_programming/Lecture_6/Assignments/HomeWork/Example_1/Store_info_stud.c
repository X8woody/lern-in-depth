/*
 * Store_info_stud.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdulrhman Alaa_Eldin
 */
#include <stdio.h>

struct info
{
	char 		 name[50];
	unsigned int roll;
	float        mark;
};

void get_info(struct info us[])
{
	int i,c;
	char chk;
	for(i=0; i<100; i++)
	{
		printf("Enter name: ");
		fflush(stdin);
		fflush(stdout);
		gets(us[i].name);
		printf("Enter roll number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&us[i].roll);
		printf("Enter marks: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&us[i].mark);
		printf("\nDo you want to add info of other student\nplease press 'y' for continue or any key to exit: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&chk);
		if((chk != 'y') && (chk != 'Y'))
			break;
		else
		{
			printf("\n");
		}
	}
	for(c=0; c<=i; c++)
	{
		printf("\nDisplaying Information\n");
		printf("name : %s\n",us[c].name);
		printf("Roll : %d\n",us[c].roll);
		printf("Marks: %0.2f\n\n\n",us[c].mark);
	}
}

int main()
{
	struct info data[100];
	printf("Enter information of students: \n\n");
	get_info(data);
	return 0;
}


