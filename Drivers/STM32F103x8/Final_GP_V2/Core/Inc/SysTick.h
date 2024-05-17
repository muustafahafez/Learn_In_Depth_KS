/*
 * SysTick.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Mustafa Hafez
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "stdint.h"

#define SysTick_Base_Address	0xE000E010

#define STK_CTRL 		*((volatile  uint32_t*) (SysTick_Base_Address+0x00))
#define CLKSOURCE	2
#define TICKINT		1
#define _ENABLE		0


#define STK_LOAD 		*((volatile  uint32_t*) (SysTick_Base_Address+0x04))
#define STK_VAL 		*((volatile  uint32_t*) (SysTick_Base_Address+0x08))

void SysTick_voidInit();
void SysTick_voidStart();

#endif /* INC_SYSTICK_H_ */
