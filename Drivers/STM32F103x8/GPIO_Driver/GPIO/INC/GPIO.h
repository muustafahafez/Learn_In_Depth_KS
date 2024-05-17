/*
 * GPIO.h
 *
 *  Created on: Oct 8, 2023
 *      Author: Mustafa Hafez
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

//--------------------------------
//Includes------------------------
//--------------------------------
#include <stdint.h>
#include "stm32f10x8.h"


typedef volatile uint32_t vuint32_t;



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral instant: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32_t CRL;
	vuint32_t CRH;
	vuint32_t IDR;
	vuint32_t ODR;
	vuint32_t BSRR;
	vuint32_t BRR;
	vuint32_t LCKR;

}GPIOx_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral instant: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32_t EVCR;
	vuint32_t MAPR;
	vuint32_t EXTICR1;
	vuint32_t EXTICR2;
	vuint32_t EXTICR3;
	vuint32_t EXTICR4; // offset = 0x14
	vuint32_t RESERVED;  // As 14 + 4 = 18, and 18 + 4 = 1C
	vuint32_t MAPR2; //offset = 0x1C
}AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral instant: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct {

}EXTI_t;





void GPIO_voidInit();
void GPIO_voidSetPinDir();
void GPIO_voidSetPortDir();
void GPIO_voidSetPinDir();
void GPIO_voidWritePin();
void GPIO_voidWritePort();
uint8_t GPIO_uint8ReadPin();
uint16_t GPIO_uint8ReadPort();









#endif /* INC_GPIO_H_ */
