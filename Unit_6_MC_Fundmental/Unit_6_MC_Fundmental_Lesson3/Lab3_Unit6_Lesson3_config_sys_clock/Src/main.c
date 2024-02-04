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



/*Configure Board to run with the
Following rates:

	APB1 Bus frequency 4MHZ
 	APB2 Bus frequency 2MHZ
	AHB frequency 8 MHZ
	SysClk 8 MHZ

Use only internal HSI_RC

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef	volatile unsigned int vuint32_t;

#define GPIOA_BASE			0x40010800
#define GPIOA_CRH			*(volatile vuint32_t*)(GPIOA_BASE+ 0x04)
#define GPIOA_ODR			*(volatile vuint32_t*)(GPIOA_BASE+ 0x0c)

#define RCC_BASE			0x40021000
#define RCC_APB2ENR			*(volatile vuint32_t*)(RCC_BASE + 0x18)
#define RCC_CFGR		*(volatile vuint32_t*)(RCC_BASE + 0x04)
#define RCC_CR			*(volatile vuint32_t*)(RCC_BASE + 0x00)


int main(void)
{
		/*Initialization*/

	/*Make SW -> 10 in RCC_CFGR to select PLL as clock source which make SysClk = PLLCLK = 32 MHZ bit 0:1*/
	RCC_CFGR |= 0b10<<0;
	/*Select  HIS from PLLSRC by bit 16 == 0*/
//	RCC_CFGR &= ~(1<<16)
	/*PLLMUL by 8 to make PLLCLK = 32 MHZ by bit 18:21*/
		RCC_CFGR |= 0b0110<<18;
	/*Select prescaler not divided to make AHB bus 32MHZ. bit 4:7*/
	RCC_CFGR |= 0b0000<<4;
	/*Select prescaler divided by 2 to make APB1 bus 16MHZ. bit 8:10*/
	RCC_CFGR |= 0b100<<8;
	/*Select prescaler divided by 4 to make APB2 bus 8MHZ. bit 11:13*/
	RCC_CFGR |= 0b101<<11;
	/*Enable PLL*/
	RCC_CR|=1<<24;

		RCC_APB2ENR|=(1<<2);
		GPIOA_CRH&=0xFF0FFFFF;
		GPIOA_CRH|=0x00200000;

		while(1)
		{
			/*Toggle led*/
			GPIOA_ODR|=1<<13;
			for(int i =0; i<5000;i++);
			GPIOA_ODR&= ~(1<<13);
			for(int i =0; i<5000;i++);

		}
}