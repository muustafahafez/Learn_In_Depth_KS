/*
 * DistanceToSpeed.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Mustafa Hafez
 */

#ifndef DISTANCETOSPEED_H_
#define DISTANCETOSPEED_H_

#include "stdint.h"
typedef struct{
	uint16_t copy_u16MinDistance;
	uint16_t copy_u16MaxDistance;
	uint8_t copy_u16MinSpeed;
	uint8_t copy_u16MaxSpeed;

}DisToSpd_Parameters_t;

uint8_t DistanceToSpeed(DisToSpd_Parameters_t* Parameters,uint16_t Copy_u16CurrentDistance);



#endif /* DISTANCETOSPEED_H_ */
