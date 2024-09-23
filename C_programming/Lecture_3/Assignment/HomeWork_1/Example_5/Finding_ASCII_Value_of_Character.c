/*
 * Finding_ASCII_Value_of_Character.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

int main(){
	char User = '\0';
    printf("Enter a character: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%c", &User);
	printf("ASCII value of %c = %d ",User,User);
	return 0;
}
