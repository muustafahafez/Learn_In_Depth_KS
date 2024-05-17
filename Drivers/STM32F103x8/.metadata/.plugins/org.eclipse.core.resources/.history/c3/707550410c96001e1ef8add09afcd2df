/*
 * SysTick.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Mustafa Hafez
 */
#include "stdint.h"
#include "SysTick.h"
#include "BIT_MATH.h"




void SysTick_voidInit()
{
	//set pre-scaler: CLR for AHB/8 or SET for Processor clock (AHB)
	CLR_BIT(STK_CTRL,CLKSOURCE); // CLC = 1MHZ, Tick = 1 microsecond
	//Enable SysTick Exception
	SET_BIT(STK_CTRL,TICKINT);
	//set preload value
	STK_LOAD=1000; //1ms


}

void SysTick_voidStart()
{
	//enable systick
	SET_BIT(STK_CTRL,ENABLE);
}

