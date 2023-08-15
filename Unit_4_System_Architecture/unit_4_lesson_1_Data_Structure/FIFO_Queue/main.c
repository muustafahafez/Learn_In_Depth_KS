/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mustafa Hafez
 */
#include <stdint.h>
#include <stdio.h>
#include "FIFO.h"

void main(void)
{

	DataType i,temp;
	DataType UART_Buffer[5];
	FIFO_t UART_FIFO;
	FIFO_Init(&UART_FIFO,UART_Buffer,5);

	printf("================================================\n\n");

	for(i=0;i<7;i++)
	{

		if(FIFO_Enqueue(&UART_FIFO,i)==FIFO_NoError)
		{
			printf("\t\tEnqueue %d\n",i);

		}
		else
			printf("\t\tInvalid Enqueue %d\n",i);

	}

	printf("================================================\n\n");

	FIFO_PrintAll(&UART_FIFO); //print the Fifo Data to make sure the only five elements are enqueued.


	/**************Dequeue*********************/
	for(i=0;i<7;i++)  //the  5 6 will not be enqueued as the size of Fifo is 5 element
	{

		if(FIFO_Dequeue(&UART_FIFO,&temp)==FIFO_NoError)
		{
			printf("\t\tDequeue %d\n",temp);
		}
		else
			printf("\t\tInvalid Dequeue %d\n",temp);

	}

	printf("================================================\n\n");

	FIFO_PrintAll(&UART_FIFO);  //print the Fifo Data after Dequeued all data to make sure that Fifo is empty.
}

