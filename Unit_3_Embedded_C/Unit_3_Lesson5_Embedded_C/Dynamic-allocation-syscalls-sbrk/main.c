/*
 * main.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Mustafa Hafez
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//SysCalls
void* _sbrk(int size);

typedef	volatile unsigned int vuint32_t;

#define RCC_BASE			0x40021000
#define GPIOA_BASE			0x40010800
#define RCC_APB2ENR			*(volatile vuint32_t*)(RCC_BASE+ 0x18)
#define GPIOA_CRH			*(volatile vuint32_t*)(GPIOA_BASE+ 0x04)
#define GPIOA_ODR			*(volatile vuint32_t*)(GPIOA_BASE+ 0x0c)


typedef union{

	vuint32_t All_feilds;

	struct{
		vuint32_t Reserved:13;
		vuint32_t p_13:1;
	}pin;
}R_ODR_t;

/*pointer to union that hold the required address*/
volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE+ 0x0c);
char Global_Var[93]={1,2,3};


vuint32_t const const_Global_Var[11]={4};
vuint32_t Global_unitial_bss[98];



extern uint32_t _E_BSS;
extern uint32_t _E_HEAP;

void main(void)
{

	/*Initialization*/
	RCC_APB2ENR|=(1<<2);
	GPIOA_CRH&=0xFF0FFFFF;
	GPIOA_CRH|=0x00200000;

	char* ptr;
	ptr = (char*)malloc(5);
	free(ptr); 
	while(1)
	{
		/*Toggle led*/
		R_ODR->pin.p_13 =1;
		for(int i =0; i<6000;i++);
		R_ODR->pin.p_13 =0;
		for(int i =0; i<6000;i++);

	}
}

void* _sbrk(int size)
{
	static unsigned char* HeapPtr = NULL;
	unsigned char* Prev_HeapPtr = NULL;
	
	//First time allocated
	if(HeapPtr == NULL)
		HeapPtr = (unsigned char*)&_E_BSS;
	
	Prev_HeapPtr = HeapPtr;
	
	//Memory protected
	if((HeapPtr + size) > _E_HEAP)
		return (void*)NULL;
	
	//Reserve with size
	
	HeapPtr += size;
	
	return ((void*)Prev_HeapPtr);
	
	
}