/*
 * Find_Transpose_of_matrix.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */
#include <stdio.h>

#define size 100

int main()
{
	int a[size][size];
	int T[size][size];
	float rw,clmn;
	int i,c;
	printf("Enter rows and columns of matrix: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f%f",&rw,&clmn);
    i = rw;
    c = clmn;
    if((i != rw || c != clmn) || (rw <= 0 || clmn <= 0))
    {
    	rw = 0;
    	printf("Error in number of elements.\nNumber must be upper than zero\nand not fractional number");
    }
    else if((i <= size) && (c <= size))
    {
    	unsigned char feed = 0;
    	printf("Enter elements of Matrix: \n");
    	while (feed < 3)
    	{
			for(i=0; i<rw; i++)
			{
				for(c=0; c<clmn; c++)
				{
					if(feed == 0)
					{
						printf("Enter elements a%d%d: ",(i+1),(c+1));
						fflush(stdin);
						fflush(stdout);
						scanf("%d",&a[i][c]);
						T[c][i] = a[i][c];
					}
					else if(feed == 1)
					{
						printf("%d  ",a[i][c]);
					}
					else if(feed == 2)
					{
						printf("%d  ",T[i][c]);
					}
				}
				if(feed == 1 || feed == 2)
				{
					printf("\n\n");
				}
				else
				{
				}
			}
			if(i == rw)
			{
				if(feed == 0)
				{
					printf("\nEntered Matrix:\n");
					feed =1;
				}
				else if(feed == 1)
				{
					printf("\n\nTranspose of Matrix:\n");
					rw  += clmn;
					clmn = rw-clmn;
					rw  -= clmn;
					feed =2;
				}
				else if(feed == 2)
				{
					feed =3;
				}
			}
			else
			{
			}
    	}
    }
    else if((i > size) || (c > size))
    {
    	printf("Error in number of elements.\nNumber must be lower than or equal %d : ",size);
    }
	return 0;
}


