#include <stdio.h>
#include <stdlib.h>
#include "LIFO_h.h"

void main(void){

	unsigned temp,i;
	//create two LIFO
	LIFO_t UART_Lifo,I2C_Lifo;

	//static allocation
	unsigned int buffer1[5];

	//dynamic allocation
	unsigned int* buffer2 = (unsigned int*) malloc(5*sizeof(unsigned int));

	LIFO_Init(&UART_Lifo,buffer1,5);

	LIFO_Init(&I2C_Lifo,buffer2,5);

	for(i=0;i<7;i++)
	{

		if(LIFO_PUSH(&UART_Lifo,i)== LIFO_NoError)

			printf("push: %d\n",i);

	}


	for(i=0;i<7;i++)
	{

		if(LIFO_POP(&UART_Lifo,&temp)==LIFO_NoError)
			printf("\nPop: %d  \n",temp);

	}

}
