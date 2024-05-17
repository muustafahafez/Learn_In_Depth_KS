/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>
int Power2(int);
float SQR_Root(int n);
int main()
{
	int num;
while(1){
printf("Enter a number to get its root square: ");
fflush(stdin);fflush(stdout);
scanf("%d",&num);
printf("%.3f\n",SQR_Root(num));
}
return 0;
}

int Power2(int copy_intBase)
{
	return copy_intBase*copy_intBase;
}
float SQR_Root(int n) //4
{


	float temp1,temp2;
	int k=n-1;//3
	if (n==1)
	{
		return 1.00;
	}
	while(Power2(k)>n)
		k--; //2
	temp2=k;
	temp1=1;
	for(int i =0;i<10;i++)
	{
		temp2=n/temp2; //  4/2.05=1.95

		temp2 = (temp2+temp1)/2; //  1.95+2.05=2
		temp1=temp2; //2.05
	}
	return temp2;
}
