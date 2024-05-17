/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>

void Reverse_Arr(int arr[], int size);


int main()
{

	int size;
	printf("Enter array size: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);
	int arr[size];
	for(int i =0; i<size;i++)
	{
		printf("Enter num%d:\n",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&arr[i]);
	}

	Reverse_Arr(arr,size);

	return 0;
}
void Reverse_Arr(int arr[], int size)
{

	for(int i =size-1;i>=0;i--)
	{

		printf("%d ",arr[i]);
	}

}
