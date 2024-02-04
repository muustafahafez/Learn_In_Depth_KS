/*
 * LAB2.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Mustafa Hafez
 */

#ifndef LAB2_H_
#define LAB2_H_



#define DELAY(n)	for(int i =0; i<n;i++)\
					for(int j = 0; j<255;j++);


typedef unsigned char  uint8_t;


#define GPIO_DDRA		*((volatile uint32_t*) 0x3A)
#define GPIO_DDRB		*((volatile uint32_t*) 0x37)
#define GPIO_DDRC		*((volatile uint32_t*) 0x34)
#define GPIO_DDRD		*((volatile uint32_t*) 0x31)


#define GPIO_PINA		*((volatile uint32_t*) 0x39)
#define GPIO_PINB		*((volatile uint32_t*) 0x36)
#define GPIO_PINC		*((volatile uint32_t*) 0x33)
#define GPIO_PIND		*((volatile uint32_t*) 0x30)



#define GPIO_PORTA		*((volatile uint32_t*) 0x3B)
#define GPIO_PORTB		*((volatile uint32_t*) 0x38)
#define GPIO_PORTC		*((volatile uint32_t*) 0x35)
#define GPIO_PORTD		*((volatile uint32_t*) 0x32)



#define GPIO_PIN7		7
#define GPIO_PIN6		6
#define GPIO_PIN5		5
#define GPIO_PIN4		4
#define GPIO_PIN3		3
#define GPIO_PIN2		2
#define GPIO_PIN1		1
#define GPIO_PIN0		0


#endif /* LAB2_H_ */
