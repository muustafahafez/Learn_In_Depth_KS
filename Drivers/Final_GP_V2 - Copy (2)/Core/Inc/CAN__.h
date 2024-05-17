/*
 * CAN__.h
 *
 *  Created on: Nov 26, 2023
 *      Author: Mustafa Hafez
 */

#ifndef INC_CAN___H_
#define INC_CAN___H_

#include "stdint.h"

void CAN_Tx(uint32_t ID, uint8_t DLC,uint8_t* Payload);

void CAN_Rx(uint16_t *ID, uint8_t* DLC,uint8_t* Payload);

#endif /* INC_CAN___H_ */
