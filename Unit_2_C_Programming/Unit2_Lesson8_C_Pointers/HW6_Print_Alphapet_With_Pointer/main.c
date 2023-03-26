/*
 * main.c
 *
 *  Created on: Mar 18, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
#define Alpha_No		27
#define Start_Address	(char*)'A'

/*The address of ASCII code of A is 41, so we store it in an address,
 * print the character which equal this ASCII
 * Iterate the address to point the next character
 * */
int main(int argc, char **argv) {

char* ch = Start_Address;
for(int i = 0; i<Alpha_No-1;i++)
{
	printf("%c  ",ch);
	ch++;

}

	return 0;
}

