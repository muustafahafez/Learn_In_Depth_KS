/*
 * main.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Mustafa Hafez
 */

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

void main(void)
{

	/*Initialization*/
	RCC_APB2ENR|=(1<<2);
	GPIOA_CRH&=0xFF0FFFFF;
	GPIOA_CRH|=0x00200000;

	while(1)
	{
		/*Toggle led*/
		R_ODR->pin.p_13 =1;
		for(int i =0; i<6000;i++);
		R_ODR->pin.p_13 =0;
		for(int i =0; i<6000;i++);

	}
}
