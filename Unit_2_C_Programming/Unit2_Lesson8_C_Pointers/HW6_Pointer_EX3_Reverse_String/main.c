/*
 * main.c
 *
 *  Created on: Mar 19, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>

int main(int argc, char **argv) {

	char str[] ="w3resource";
	char* ptr =str;
	for(int i = sizeof(str); i>0;i--)
	{
		printf("%c",*(ptr+(sizeof(str)-1)));
		ptr--;
	}

		return 0;
}


