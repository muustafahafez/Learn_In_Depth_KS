/*
 * main.c
 *
 *  Created on: Feb 20, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>


void Sentance_Reverse(char text[],int size);
char Reversed_Text[100];
/*margorp emosewa*/
int i=0;
int length=0;
void main()
{

	char sentance[100];
	printf("Enter a sentence: ");
	fflush(stdin);fflush(stdout);
	gets(sentance);
	Sentance_Reverse(sentance,100);
	printf("The sentence: %s ",Reversed_Text);



}

void Sentance_Reverse(char text[],int size)
{


	while(text[i]!=0)
	{

		i++;
	}
	length=i;
	i--;
	for(int j=0;j<length;j++)
	{
		Reversed_Text[j]=text[i];
		i--;
	}

}

