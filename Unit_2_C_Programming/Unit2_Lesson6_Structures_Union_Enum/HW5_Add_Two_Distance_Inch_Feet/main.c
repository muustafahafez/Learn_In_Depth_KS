/*
 * main.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>

/*Note: 1 feet = 12  inches*/
typedef struct {
	float inch;
	int feet;

}Distance;

int main(int argc, char **argv) {

Distance d1,d2,sum;
printf("Enter information of Distance-1\n");
printf("Enter feet ");
fflush(stdin);fflush(stdout);
scanf("%d",&d1.feet);

printf("Enter inch ");
fflush(stdin);fflush(stdout);
scanf("%f",&d1.inch);


printf("Enter information of Distance-2\n");
printf("Enter feet ");
fflush(stdin);fflush(stdout);
scanf("%d",&d2.feet);

printf("Enter inch ");
fflush(stdin);fflush(stdout);
scanf("%f",&d2.inch);

sum.feet=d1.feet+d2.feet;
sum.inch=d1.inch+d2.inch;
if(sum.inch>=12.0)
{
	++sum.feet;
	sum.inch-=12.0;
}
printf("Sum of distances = %d' -%.1f\" ",sum.feet,sum.inch);

	return 0;
}

