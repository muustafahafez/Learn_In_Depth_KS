/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>

int sum_100();

int main()
{

	printf("%d\n",sum_100(100));
	return 0;
}


int sum_100()
{

	static int n =100;
	static int sum =1;
	sum=sum + (n--);
	if(n!=0)
	{
	sum_100(n);
	}
return sum-1;
}

