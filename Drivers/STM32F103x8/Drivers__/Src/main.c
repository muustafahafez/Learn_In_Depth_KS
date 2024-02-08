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
#include "EXTI.h"
#include "STM32f103Cxx.h"


void TOG_LED()
{
	MCAL_GPIO_voidTogglePin(GPIOC, GPIO_PIN_13);
}



int main(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_GPIOC_CLK_EN();
	RCC_GPIOD_CLK_EN();
	RCC_AFIO_CLK_EN();

	//Configuration of Interrupts,PC0->Rising Edge
	EXTI_PinConfig_t Local_tButton;
	Local_tButton.CallBackFunc = TOG_LED;
	Local_tButton.PinConfig = EXTI2PA2;
	Local_tButton.SenseControl = EXTI_SENSE_RISING_FALLING;
	Local_tButton.EXTI_State = EXTI_STATE_ENABLE;

	MCAL_EXTI_voidInit(&Local_tButton);

	//Configuration of PINs
	//Init PINC13
	Pin_Config_t Pin_config = {GPIO_PIN_13,GPIO_PIN_MODE_OUT_PP,GPIO_PIN_SPEED_10M};
	MCAL_GPIO_voidInit(GPIOC, &Pin_config);
	//Init PINB0
	Pin_config.GPIO_PinNum = GPIO_PIN_0;
	MCAL_GPIO_voidInit(GPIOB, &Pin_config);
	/* Loop forever */

	while(1)
	{

	}


}
