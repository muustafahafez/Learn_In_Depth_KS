/**
 ******************************************************************************
 * @author         : Mustafa Hafez
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "GPIO.h"
#include "STM32f103Cxx.h"

int main(void)
{
	uint32_t i,j;

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_GPIOC_CLK_EN();

	Pin_Config_t Pin_config = {GPIO_PIN_2,GPIO_PIN_MODE_OUT_PP,GPIO_PIN_SPEED_10M};
	//Init PINA
	MCAL_GPIO_voidInit(GPIOA, &Pin_config);
	//Init PINB
	Pin_config.GPIO_PinNum = GPIO_PIN_0;
	MCAL_GPIO_voidInit(GPIOB, &Pin_config);
	//Init PINC -> input float
	Pin_config.GPIO_PinNum = GPIO_PIN_14;
	Pin_config.GPIO_PinMode = GPIO_PIN_MODE_INP_FLO;
	MCAL_GPIO_voidInit(GPIOC, &Pin_config);
	/* Loop forever */
	while(1)
	{
		{
//		//Toggle every 1 second;

		MCAL_GPIO_voidWritePort(GPIOB, 0x0f);
		//delay
		for(i=0;i<1000;i++)
			for(j=0;j<1000;j++);
		MCAL_GPIO_voidWritePort(GPIOB, 0x00);
		//delay
		for(i=0;i<1000;i++)
			for(j=0;j<1000;j++);
		}
//		if(1)
		if(MCAL_GPIO_u8ReadPin(GPIOC, GPIO_PIN_14)==GPIO_PIN_STATE_SET)

		{
			MCAL_GPIO_voidWritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_STATE_SET);
		}
		else
		{
			MCAL_GPIO_voidWritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_STATE_RESET);
		}

		//		MCAL_GPIO_voidTogglePin(GPIOA, GPIO_PIN_2);
	}


}
