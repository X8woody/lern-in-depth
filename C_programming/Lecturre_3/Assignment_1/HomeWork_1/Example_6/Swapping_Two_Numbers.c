/*
 * Swapping_Two_Numbers.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main(){
	float integer_1 = 0;
	float integer_2 = 0;
    printf("Enter value of a: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f", &integer_1);
    printf("Enter value of b: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f", &integer_2);
    if((0 != integer_1) && (0 != integer_2))
    {
		float Temp = integer_1;
		integer_1 = integer_2;
		integer_2 = Temp;
		printf("\nAfter swapping, value of a = %0.2f\n",integer_1);
		printf("After swapping, value of b = %0.1f\n",integer_2);
    }
    else
    {
    	printf("You entered a character value \n");
    }
	return 0;
}

