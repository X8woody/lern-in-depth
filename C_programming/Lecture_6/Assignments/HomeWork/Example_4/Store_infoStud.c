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
	float        mark;
};

void get_info(struct info us[])
{
	int i,c;
	char chk;
	for(i=0; i<10; i++)
	{
		printf("For roll number %d\n",i+1);
		printf("Enter name: ");
		fflush(stdin);
		fflush(stdout);
		gets(us[i].name);
		unsigned char q;
		for(q=0; q<50; q++)
		{
			if(us[i].name[q] != '\0')
			{
				if((us[i].name[q] < 65 || us[i].name[q] > 90) && (us[i].name[q] < 97 || us[i].name[q] > 122))
					q = 51;
			}
			else if(us[i].name[q] == '\0')
			{
				q = 52;
			}
		}
		if(q == 53 || q == 50)
		{
			printf("Enter marks: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%f",&us[i].mark);
			int k = us[i].mark;
			if(k != 0)
			{
				printf("\nplease press 'y' if you want to add info of other student,\nor any key to exit: ");
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
			else
			{
				i -= 1;
				printf("\nplease enter only numbers minimum '1'\n\n");
			}
		}
		else
		{
			i -= 1;
			printf("\nplease enter only character\n\n");
		}
	}
	printf("\n.\n.\n.\nDisplaying Information of students:\n\n");
	for(c=0; c<=i; c++)
	{
		printf("Information for roll number %d\n", c+1);
		printf("Name : %s\n",us[c].name);
		printf("Marks: %0.2f\n.\n.\n.\n",us[c].mark);
	}
}

int main()
{
	struct info data[10];
	printf("Enter information of students: \n\n");
	get_info(data);
	return 0;
}


