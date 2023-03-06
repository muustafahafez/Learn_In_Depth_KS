/*
 * main.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>

typedef struct{

	float real,img;

}Complex;

Complex SAdd_Complex(Complex,Complex);


int main(int argc, char **argv) {

	Complex SNum1,SNum2,SResult;
	printf("For 1st complex number\nEnter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&SNum1.real,&SNum1.img);

	printf("For 2nd complex number\nEnter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&SNum2.real,&SNum2.img);

	SResult = SAdd_Complex(SNum1,SNum2);

	printf("sum=%.1f+%.1fi",SResult.real,SResult.img);



	return 0;

}


Complex SAdd_Complex(Complex Snum1,Complex Snum2)
{
	Complex sSum;
	sSum.real = Snum1.real + Snum2.real;
	sSum.img = Snum1.img + Snum2.img;

	return sSum;
}
