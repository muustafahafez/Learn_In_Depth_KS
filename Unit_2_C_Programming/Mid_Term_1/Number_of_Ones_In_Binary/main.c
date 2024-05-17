/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
int OnesNum(char);

int main()
{

	char num;
	printf("Enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	printf("\n%d",OnesNum(num));
	return 0;
}


int OnesNum(char num)
{
//	(var&(1<<bit))>>bit
	char count=0;
	char BitVal;
	for(int bit=7;bit>=0;bit--)
	{

		BitVal=(num&(1<<bit))>>bit;
		if( BitVal==1 )

		{
		count++;
		}
	}
	return count;
}
