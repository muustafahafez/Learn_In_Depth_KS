/*
 * DistanceToSpeed.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Mustafa Hafez
 */
#include "DistanceToSpeed.h"

#ifndef NULL
#define NULL	(void*)0
#endif


uint8_t DistanceToSpeed(DisToSpd_Parameters_t* Parameters,uint16_t Copy_u16CurrentDistance)
{

	uint8_t Local_u8Speed=0;
	if(Parameters!=NULL)
	{

		Local_u8Speed=(((Copy_u16CurrentDistance-Parameters->copy_u16MinDistance)*(Parameters->copy_u16MaxSpeed-Parameters->copy_u16MinSpeed))/(Parameters->copy_u16MaxDistance-Parameters->copy_u16MinDistance))+Parameters->copy_u16MinSpeed;

	}

	return Local_u8Speed;

}
