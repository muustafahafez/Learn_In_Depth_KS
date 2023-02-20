/*
 * main.c
 *
 *  Created on: Feb 20, 2023
 *      Author: Mustafa Hafez
 */

/*margorp emosewa*/

#include <stdio.h>
void Sentance_Reverse(char *text);
void main()
{

	char sentance[100];
	printf("Enter a sentence: ");
	fflush(stdin);fflush(stdout);
	gets(sentance);
	Sentance_Reverse(sentance);
}

void Sentance_Reverse(char *text)
{

if(*text)
	{
		Sentance_Reverse(text+1);
		printf("%c",*text);
	}

}

