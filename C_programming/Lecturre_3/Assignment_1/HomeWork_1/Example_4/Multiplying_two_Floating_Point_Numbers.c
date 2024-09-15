/*
 * Multiplying_two_Floating_Point_Numbers.c
 *
 *  Created on: Sep 13, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main(){
	float integer_1 = 0;
	float integer_2 = 0;
	int carrier_1   = 1;
	int carrier_2   = 1;
    printf("Enter two numbers: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f %f", &integer_1,&integer_2);
    carrier_1 = (int)integer_1;
    carrier_2 = (int)integer_2;
    if((carrier_1 != integer_1) && (carrier_2 != integer_2))
    {
    	float  multiply = integer_1 * integer_2;
    	if(multiply != 0)
    		printf("Product: %f ",multiply);
    	else
    		printf("You didn't enter an float number \n");
    }
    else
    {
    	printf("You didn't enter an float number \n");
    }
	return 0;
}
