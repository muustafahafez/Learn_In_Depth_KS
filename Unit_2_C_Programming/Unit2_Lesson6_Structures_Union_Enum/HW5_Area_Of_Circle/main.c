/*
 * main.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>

#define AREA(R)			3.14*R*R

int main(int argc, char **argv) {
	float r;
	printf("Enter radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&r);
	printf("The area of Circle which has a radius = %.2f is %.2f",r,AREA(r));

	return 0;
}

