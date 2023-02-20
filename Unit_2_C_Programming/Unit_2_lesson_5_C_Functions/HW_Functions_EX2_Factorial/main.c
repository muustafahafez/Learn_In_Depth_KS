/*
 * main.c
 *
 *  Created on: Feb 20, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>

int factorial(int);
int ans =1;

void main()
{

	int number;

	while(1)
	{
	  printf("Enter a number: ");
	  fflush(stdin); fflush(stdout);
	  scanf("%d",&number);
	  printf("The factorial of %d is %d\n",number,factorial(number));

	}
}



int factorial(int num)
{


	if(num>=1)
	 {
		return num*factorial(num-1);

	 }

	else
		return 1;
}
