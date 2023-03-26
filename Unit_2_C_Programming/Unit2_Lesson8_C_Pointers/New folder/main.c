/*
 * main.c
 *
 *  Created on: Mar 19, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>

struct Semployee{
	char name[20];
	int id;
};

int main(int argc, char **argv) {

	struct Semployee emp1={"Alex",1002};


	struct Semployee   (*ptr)[]={&emp1};
	ptr[0] = emp1;


	**ptr->name="Alex";

	printf("Exmployee Name : %s\n",ptr[0]->name);
	printf("Exmployee ID : %s\n",ptr[0]->id);

	return 0;
}


