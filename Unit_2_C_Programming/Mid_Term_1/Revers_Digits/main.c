/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
int Reverse(int);
int main(void)
{
	int num;
	while(1)
	{
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	printf("The Reverse of %d is %d\n",num,Reverse(num));
	}
	return 0;

}

int Reverse(int n)
{

	int Reverse =0;
	int reminder;

	while(n!=0){
		reminder = n%10;
		Reverse = Reverse*10+reminder;
		n/=10;
	}
	return Reverse;
}
