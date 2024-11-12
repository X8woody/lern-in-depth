/*
 * Add_two_Distance.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdulrhman Alaa_Eldin
 */
#include <stdio.h>

struct add
{
	float feet;
	float inch_feet;
};

float Rounding_dec(float x)
{
	int y;
	float z;
	x = x * 100.00;
	y = x;
	z = x - y;
	if(z >= 0.5)
	{
		y += 1;
		z = y / 100.00;
	}
	else
		z = y / 100.00;
	return z;
}

float conv_inch_ft(float z)
{
	z /= 12.00;
	return z;
}

struct add sum_dist(struct add one, struct add two)
{
	struct add s;
	int temp;
	s.feet = one.feet + two.feet;
	one.inch_feet = Rounding_dec(conv_inch_ft(one.inch_feet));
	two.inch_feet = Rounding_dec(conv_inch_ft(two.inch_feet));
	s.inch_feet = one.inch_feet + two.inch_feet;
	temp = s.inch_feet/1.00;
	s.inch_feet = s.inch_feet - temp;
	s.feet = temp + s.feet;
	return s;
}
int main()
{
	struct add dist_1,dist_2,sum;
	printf("Enter information for 1st distance\n");
	printf("Enter feet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&dist_1.feet);
	printf("Enter inch: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&dist_1.inch_feet);
	printf("\nEnter information for 2nd distance\n");
	printf("Enter feet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&dist_2.feet);
	printf("Enter inch: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&dist_2.inch_feet);
	sum = sum_dist(dist_1,dist_2);
	printf("\nSum of distances = %0.0f'-%0.2f\"",sum.feet,sum.inch_feet);
	return 0;
}


