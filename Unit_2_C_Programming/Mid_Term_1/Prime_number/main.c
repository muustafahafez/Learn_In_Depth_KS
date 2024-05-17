/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
int PrimeNumber(int);
int main()
{

	int num1,num2;
	char flag;
	printf("Enter two intervals: ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&num1,&num2);

	printf("Prime numbers between the two intervals are: ");
	for(int i =num1; i<=num2;i++)
	{
		flag = PrimeNumber(i);
		if (flag ==1)
		{
			printf("%d ",i);
		}
	}

	return 0;
}

int PrimeNumber(int n)
{
/* A flag that will be set for any prime number*/
char flag = 1;
for(int i =2;i<=n/2;i++)
	{

	if((n%i)==0)     //not prime number
		{
			flag=0;
			break;
		}

	}
return flag;
}
