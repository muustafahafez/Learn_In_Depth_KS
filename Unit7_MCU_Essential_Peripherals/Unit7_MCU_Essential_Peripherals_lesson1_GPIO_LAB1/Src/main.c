/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define DELAY(n)	for(int i =0; i<n;i++)\
		for(int j = 0; j<255;j++);


typedef	volatile unsigned int vuint32_t;

#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))


#define RCC_BASE			0x40021000
#define RCC_APB2ENR			*(volatile vuint32_t*)(RCC_BASE+ 0x18)



#define GPIOA_BASE			0x40010800
#define GPIOA_CRH			*(volatile vuint32_t*)(GPIOA_BASE+ 0x04)
#define GPIOA_CRL			*(volatile vuint32_t*)(GPIOA_BASE+ 0x00)
#define GPIOA_ODR			*(volatile vuint32_t*)(GPIOA_BASE+ 0x0c)
#define GPIOA_IDR			*(volatile vuint32_t*)(GPIOA_BASE+ 0x08)


#define GPIOB_BASE			0x40010C00
#define GPIOB_CRH			*(volatile vuint32_t*)(GPIOB_BASE+ 0x04)
#define GPIOB_CRL			*(volatile vuint32_t*)(GPIOB_BASE+ 0x00)
#define GPIOB_ODR			*(volatile vuint32_t*)(GPIOB_BASE+ 0x0c)
#define GPIOB_IDR			*(volatile vuint32_t*)(GPIOB_BASE+ 0x08)


void Clock_Init()
{
	/*IO port A clock enable*/
	RCC_APB2ENR |=(1<<2);
	/*IO port B clock enable*/
	RCC_APB2ENR |=(1<<3);


}

void GPIO_Init()
{
	GPIOA_CRL=0;
	GPIOA_CRH=0;
	GPIOA_ODR=0;

	/*Make PA1 Input floating, in GPIOA_CRL  CNF1: 0 1  and MODE1: 0 0*/
	GPIOA_CRL |= (0b01<<6); //CNF1
	GPIOA_CRL &= ~(0b11<<4); //CNF1


	/*Make PA13 Input floating, in GPIOA_CRH  CNF13: 0 1  and MODE13: 0 0*/
	GPIOA_CRH |= (0b01<<22); //CNF13
	GPIOA_CRH &= ~(0b11<<20); //MODE13


	/*Make PB1  OUTPUT Push-Pull, in GPIOB_CRL  CNF1: 0 0  and MODE1: 0 1 10 MHZ slew rate*/
	GPIOB_CRL &= ~(0b11<<6); //CNF1
	GPIOB_CRL |= (0b01<<4); //MODE1


	/*Make PB13 OUTPUT Push-Pull, in GPIOB_CRH  CNF13: 0 0  and MODE13: 0 1  10MHZ slew rate*/
	GPIOB_CRH &= ~(0b11<<22); //CNF13
	GPIOB_CRH |= (0b01<<20); //MODE13



}
void delay(vuint32_t t)
{
	for(int i =0; i<t;i++)\
			for(int j = 0; j<255;j++);
}

int main(void)
{
	/*Initialization*/
	Clock_Init();
	GPIO_Init();


	while(1)
	{

		/*Single press*/
		if(GET_BIT(GPIOA_IDR,1)==0) //pressed
		{
			TOG_BIT(GPIOB_ODR,1);
			while(GET_BIT(GPIOA_IDR,1)==0);


		}

		/*Multi Press*/
		if( GET_BIT(GPIOA_IDR,13)==1) //pressed
		{

			TOG_BIT(GPIOB_ODR,13);
			delay(1);


		}
	}
}

