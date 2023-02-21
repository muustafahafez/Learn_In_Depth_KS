/*
 * main.c
 *
 *  Created on: Feb 20, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>

int Power_num(int,int);




void main()
{

int num,power;
printf("Enter Base number: ");
fflush(stdin);fflush(stdout);
scanf("%d",&num);
printf("\nEnter Power number (positive integer): ");
fflush(stdin);fflush(stdout);
scanf("%d",&power);

printf("\n%d^%d = %d \n",num,power,Power_num(num,power));

}

int Power_num(int copy_intBase ,int copy_intPower)
{

	while(copy_intPower!=0)
	{
		return copy_intBase*Power_num(copy_intBase,copy_intPower-1);

	}

	return 1;
}
