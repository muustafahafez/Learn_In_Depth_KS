/*
Startup.c 
Author: Eng.Mustafa Hafez Eldeep
Date:	30/7/2023
Family: Cortex-m
*/

/* This Family has a wonderful features, The addresse at the entry point of the processor will bee used to initiate the stack pointer (sp).
so, we can write the startup file by C-language as the stack will be intiated.
*/

/* Imagine with me that we have the ability to make an array  of type uint_32 as each elelment will take a 4 byte , as we know the array elements
are arranged squantily in the memory, so if we make the first element of our array equal to the address of SP, and by someway but this array at the entry point of
processor, so we can make the startup file and the next element will be next to the SP addresse.*/



#include <stdint.h>

extern void main(void);
void _Reset_Handler(void);

void Default_Handler(void){
	
	_Reset_Handler();
}
void _NMI_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;
void _Hard_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;
void _MM_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;
void _Bus_Fault(void) __attribute__ ((weak,alias("Default_Handler")));;
void _Usage_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;

//__attribute__(section(".vectors"))   put the array at vector section

// .vectors we will be at the begining of .text section which will be at the entry point of processor 
extern uint32_t _stack_top;

//Array of pointer to functions that take  no arguments and return void.

	void (* const G_PFun_Vectors[])()__attribute__ ((section(".vectors")))  = {
		
	(void (*)())&_stack_top,
	_Reset_Handler,
	_NMI_Handler,
	_Hard_Fault_Handler,
	_MM_Fault_Handler,
	_Bus_Fault,
	_Usage_Fault_Handler
		
	};
	

/*Extern the symbol from linker file so that the linker dosen't give an error while 
compilng the startup.c*/
extern uint32_t _S_TEXT;
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;
extern uint32_t _E_HEAP;

void _Reset_Handler(void)
{
	
	/* 1- Copy Data from ROM to SRAM.*/
	uint32_t DATA_SIZE 				= (unsigned char*)&_E_DATA-(unsigned char*)&_S_DATA;
	unsigned char* P_SOURCE 		= (unsigned char*)&_E_TEXT;
	unsigned char* P_DISTINATION 	= (unsigned char*)&_S_DATA;
	
	for(uint32_t i = 0; i<DATA_SIZE;i++)
	{
		*((unsigned char*)P_DISTINATION++) = *((unsigned char*)P_SOURCE++);

	}
	
	/* 2- Reserve a .bss with its size in the SRAM.*/
	uint32_t BSS_SIZE 				= (unsigned char*)&_E_BSS - (unsigned char*)(&_S_BSS);
	unsigned char* P_BSS			= (unsigned char*)&_S_BSS;
	for(uint32_t i = 0; i<BSS_SIZE;i++)
	{
		*((unsigned char*)P_BSS++)= (unsigned char)0;

	}

	/* 3- Jump to the main function.*/
	main();
	
}
