/*
 * Calculator.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main()
{
	char  operand ='\0';
	float number_1 = 0;
	float number_2 = 0;
	printf("Enter operator either + or - or * or divide: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&operand);
	printf("Enter two operands: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&number_1,&number_2);
	switch(operand)
	{
	case '+' :
	{
		float Sum = number_1 + number_2;
		printf("%0.1f + %0.1f = %0.1f",number_1,number_2,Sum);
		break;
	}
	case '-' :
	{
		float Sub = number_1 - number_2;
		printf("%0.1f - %0.1f = %0.1f",number_1,number_2,Sub);
		break;
	}
	case '*' :
	{
		float Multi = number_1 * number_2;
		printf("%0.1f * %0.1f = %0.1f",number_1,number_2,Multi);
		break;
	}
	case '/' :
	{
		float Div = number_1 / number_2;
		printf("%0.1f / %0.1f = %0.1f",number_1,number_2,Div);
		break;
	}
	default :
		{
			printf("You entered an exist operator");
			break;
		}
	}
	return 0;
}


