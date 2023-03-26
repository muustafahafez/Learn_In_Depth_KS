/*
 * main.c
 *
 *  Created on: Mar 19, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>

int main(int argc, char **argv) {

	int size;
	printf("Enter number of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);

	int arr[size];
	int*ptr=arr;

	for(char i=0;i<size;i++)//0->arr0 1arr1 2arr2 3arr3 4arr4
	{
		printf("element-%d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",ptr++);

	}

	printf("The elements of array in reverse order are : \n");

	for(char i=size;i>0;i--)
		{
			printf("element-%d : %d \n",i,*(--ptr));

		}


	return 0;
}


