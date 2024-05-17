/*
 * main.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
void Unique(int arr[],int size);

int main()
{
	int arr1[7]={4,2,5,2,5,7,4};
	int arr2[3]={4,3,4};
    Unique(arr1,7);
    Unique(arr2,3);
 return 0;
}
void Unique(int arr[],int size)
{
	int temp =0;
	for( int i=0; i<size; i++)
	{
	temp=temp^arr[i];

	}


	printf("%d\n",temp);

}
