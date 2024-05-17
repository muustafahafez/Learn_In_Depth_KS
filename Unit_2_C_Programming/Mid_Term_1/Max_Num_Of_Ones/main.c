/*
 * main.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>
int OnesNum(char num);

int main()
{

	char num;
	while(1){
	printf("Enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	printf("\n%d\n",OnesNum(num));}

	return 0;
}

int OnesNum(char num)
{
//	(var&(1<<bit))>>bit
	int ones=0,temp=0;
	char BitVal;
	for(int bit=7;bit>=0;bit--) /*01101110*/
	{

		BitVal=(num&(1<<bit))>>bit;
		if( BitVal==1 )

		{
			ones++;
		}
		else if(BitVal==0)
		{
			if(temp<ones)
			{
			temp=ones;
			ones=0;
			}
		}
	}
	return temp;
}
