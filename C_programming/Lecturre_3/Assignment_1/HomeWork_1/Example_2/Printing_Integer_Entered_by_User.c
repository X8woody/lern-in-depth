/*
 * Printing_Integer_Entered_by_User.c
 *
 *  Created on: Sep 13, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main(){
	float integer = 0;
	int carrier = 1;
    printf("Enter an integer: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f", &integer);
    carrier = (int)integer;
    if(carrier == integer)
    {
    	if(carrier != 0)
    		printf("You entered: %d ",carrier);
    	else
    		printf("You didn't enter an integer number \n");
    }
    else
    {
    	printf("You didn't enter an integer number \n");
    }
	return 0;
}
