/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mustafa Hafez
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>
#include "Data_Student.h"



void main(void)
{
	uint8_t tmp_text[40];
	while(1)
	{
		DPRINT("================Enter Your Choice===============\n\n");
		DPRINT("\t\t1-Add New Student\n");
		DPRINT("\t\t2-Delete all Student\n");
		DPRINT("\t\t3-Delete ID Student\n");
		DPRINT("\t\t4-Print All Student\n");
		DPRINT("===============================================\n\n");

		gets(tmp_text);

		switch(atoi(tmp_text))
		{

		case 1 : AddStudent();  break;
		case 2 : DeleteAll();   break;
		case 3 :
			DPRINT("\t\t Enter Student ID\n");
			gets(tmp_text);
			DeleteID(atoi(tmp_text));	break;

		case 4 : PrintAll();	break;


		default: DPRINT("Wrong Choice\n");	break;

		}

	}
}




