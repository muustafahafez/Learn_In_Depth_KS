/*
 * main.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>

typedef struct{

	char name[25];
	float mark;
	int roll;

}Students;


int main(int argc, char **argv) {


	Students student[10];
	printf("Enter information of students: \n");
	fflush(stdin);fflush(stdout);
	for(int i=0;i<10;i++)
	{

		student[i].roll=i+1;
		printf("\nFor roll number %d",student[i].roll);
		printf("\nEnter name:");
		fflush(stdin);fflush(stdout);
		fgets(student[i].name,25,stdin);
		printf("Enter marks:");
		scanf("%f",&student[i].mark);

	}

	printf("/nDisplaying information of students: ");
	for(int i=0;i<10;i++)
		{

			printf("Information for roll number %d\n",student[i].roll);
			printf("Name: %s\n",student[i].name);
			printf("Marks: %.1f\n",student[i].mark);

		}



	return 0;
}


