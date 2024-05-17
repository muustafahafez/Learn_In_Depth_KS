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
#include "TIMER.h"
#include "A2Z_Engineering_Drone_ESC.h"
#include "BIT_MATH.h"
#include "STM32f103Cxx.h"



int main(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_AFIO_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_GPIOC_CLK_EN();
	RCC_TIM2_5_CLK_EN();


	TIM_Handler_t TIM2_PWM_Config;
	MCAL_TIM2_Init(&TIM2_PWM_Config);



//	MCAL_TIM2_SetDuty(TIM2_CHANNEL_4 , 80);


	//			for( volatile uint32_t i =0; i<10000;i++)
	//										for(volatile uint32_t j =0; j<10000;j++)
	//											__asm("NOP");

//	HAL_ESC_SetMotorSpeed(ESC_MOTOR_FR, ESC_MOTOR_DIR_CW, 1000);

	MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 5);
	MCAL_TIM2_SetDuty(TIM2_CHANNEL_2, 5);


			//	for( volatile uint32_t i =0; i<10000;i++)
							//				for(volatile uint32_t j =0; j<10000;j++)
						//						__asm("NOP");

	while(1)
	{

		//MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 5);
		MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 6);
		MCAL_TIM2_SetDuty(TIM2_CHANNEL_2, 6);

		MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 7);
		MCAL_TIM2_SetDuty(TIM2_CHANNEL_2, 7);

		MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 8);
		MCAL_TIM2_SetDuty(TIM2_CHANNEL_2, 8);

		MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 9);
		MCAL_TIM2_SetDuty(TIM2_CHANNEL_2, 9);

		MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 10);
		MCAL_TIM2_SetDuty(TIM2_CHANNEL_2, 10);

		MCAL_TIM2_SetDuty(TIM2_CHANNEL_1, 5);
		MCAL_TIM2_SetDuty(TIM2_CHANNEL_2, 5);


	}


}
