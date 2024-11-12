/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ENG. ABDULRAHMAN ALAA-ELDIN
 * @brief          : Main program body
 ******************************************************************************
 */
#include "datatypes_t.h"

#define SYSCTL_R_BASE_Address	    	0x400FE000
#define SYSCTL_RCGC2_R					0x108
#define P_SYSCTL_RCGC2_R       			*((vuint32_t *)(SYSCTL_R_BASE_Address + SYSCTL_RCGC2_R))

#define PORTF3_R_BASE_Address        	0x40025000
#define GPIO_PORTF_DIR_R				0x400
#define GPIO_PORTF_DEN_R				0x51C
#define GPIO_PORTF_DATA_R				0x3FC

#define P_GPIO_PORTF_DIR_R				*((vuint32_t *)(PORTF3_R_BASE_Address + GPIO_PORTF_DIR_R))
#define P_GPIO_PORTF_DEN_R				*((vuint32_t *)(PORTF3_R_BASE_Address + GPIO_PORTF_DEN_R))
#define P_GPIO_PORTF_DATA_R				*((vuint32_t *)(PORTF3_R_BASE_Address + GPIO_PORTF_DATA_R))

#define SBIT 							(1<<3)
#define CBIT 							~(1<<3)


int main(void)
{
	vuint32_t _Delay; 
	P_SYSCTL_RCGC2_R = (uint32_t)0x20 ;
	for(_Delay=0; _Delay<200; _Delay++);
	P_GPIO_PORTF_DIR_R |= SBIT;
	P_GPIO_PORTF_DEN_R |= SBIT;

	while(1)
	{
		P_GPIO_PORTF_DATA_R |= SBIT;
		for(_Delay=0; _Delay<500000; _Delay++);
		P_GPIO_PORTF_DATA_R &= CBIT;
		for(_Delay=0; _Delay<500000; _Delay++);
	}
	return 0;
}

