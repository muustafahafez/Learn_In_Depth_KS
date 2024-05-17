/*
 * main.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
#include <string.h>
void Reverse_word(char st[100]);
int main()
{
	char str[100];
	printf("Enter your string: "); //mustafa hafez
	fflush(stdin);fflush(stdout);
	gets(str);
	Reverse_word(str);
	return 0;
}

void Reverse_word(char st[100]) //mohamed gamal.    ..14+1
{
	int i;
	char st2[50]={0},st1[50];
	for( i =0; i<strlen(st);i++) //14
		{

			st2[i]=st[i];//"mohamed " i=6
			if(st[i]==' ')
			{
				st2[i]='\0'; //i=7="0 "   mohamed
				break;
			}

		}

		for(int j=0;j<strlen(st);j++) //j=8
		{

			st1[j]=st[i+j+1]; //"gamal.13

			if(st[i+j+1]=='\0')
			{
				st1[j-1]='\0';
				break;
			}

		}
		printf("%s ",st1);
		printf("%s.",st2);

}
