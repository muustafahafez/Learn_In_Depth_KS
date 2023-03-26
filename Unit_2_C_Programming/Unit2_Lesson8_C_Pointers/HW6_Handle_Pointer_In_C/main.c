/*
 * main.c
 *
 *  Created on: Mar 18, 2023
 *      Author: Mustafa Hafez
 */


#include <stdio.h>
#define MAIN	m##a##i##n


int MAIN(int argc, char **argv) {

int m = 29;
int* ab =&m;
printf("Address of m : 0X%p\n",&m);
printf("Value of m : %d\n\n\n",m);

printf(" Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0X%p\n",ab);
	printf("content of pointer ab : %d\n\n\n",*ab);

printf(" The value of m assigned to 34 now.\n");
	m =34;
	printf("Address of pointer ab : 0X%p\n",ab);
	printf("content of pointer ab : %d\n\n\n",*ab);

printf(" The pointer variable ab is assigned with the value 7 now.\n");

	*ab =7;
	printf("Address of m : 0X%p\n",&m);
	printf("Value of m : %d\n",m);

	return 0;
}

