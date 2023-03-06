/*
 * main.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>


typedef struct {

	char name[25];
	int roll;
	float mark;

}SStudent;


int main()
{


	 SStudent student_1;
	/*Get Data*/
	 printf("Enter information of students:\n\n");
	 printf("Enter name: ");
	 fflush(stdin);fflush(stdout);
	 fgets(student_1.name,25,stdin);

	 printf("Enter roll number: ");
	 fflush(stdin);fflush(stdout);
	 scanf("%d",&student_1.roll);

	 printf("Enter mark: ");
	 fflush(stdin);fflush(stdout);
	 scanf("%f",&student_1.mark);

		/*Display Data*/
	 printf("\n\nDisplaying information\n");

	 printf("name: %s",student_1.name);
	 printf("Roll: %d\n",student_1.roll);
	 printf("Marks: %.2f",student_1.mark);


}

