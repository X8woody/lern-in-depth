/*
 * Reverse_sentence.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Abdulrahman Alaa-Eldin
 */

#include <stdio.h>
#include <string.h>

char x[200];
char st[200];
int  i = 0;

void rev_sen(char ar[] , int S);

int main ()
{
	printf("Enter a sentence: ");
    fflush(stdin);
    fflush(stdout);
    gets(x);
    int s = strlen(x);
    s -= 1;
    strcpy(st,x);
    rev_sen(x,s);
    printf("\n%s",x);
	return 0;
}

void rev_sen(char ar[] , int S)
{
	int v = S;
	if(v >= 0)
	{
		ar[i++] = st[v--];
		rev_sen(ar,v);
	}
	else
	{
	}
}
