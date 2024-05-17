/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
int Sum_Digit(int);
int main(void)
{
	int num;
	while(1)
	{
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	printf("The sum of all digits of %d is %d\n",num,Sum_Digit(num));
	}
	return 0;

}

int Sum_Digit(int n)
{

	int sum =0;
	while(n!=0){

		sum = sum+(n%10);
		n/=10;
	}
	return sum;
}
