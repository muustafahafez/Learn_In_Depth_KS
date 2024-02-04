/*
 * main.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Mustafa Hafez
 */
#include <stdio.h>
#include "LAB2.h"


void main()
{





	/*PORTD pin5,pin6 and pin7 Output for LEDS  ,pin4 Output for Buzzer*/
	GPIO_DDRD = 0xF0;

	while(1)
	{

		/*Toggle 3 LEDs in Sequential way*/

		GPIO_PORTD = 0x20;
		DELAY(1000);

		for(int i =6; i<8; i++)
		{
			GPIO_PORTD &= ~(1<<(i-1));
			GPIO_PORTD |= (1<<i);
			DELAY(1000);

		}

		GPIO_PORTD = 0b00000000;
		GPIO_PORTD |=(1<<4);
		DELAY(4000);

		/*GPIO_PORTD |=(1<<5) ;
		GPIO_PORTD |=(1<<6) ;
		GPIO_PORTD |=(1<<7) ;*/

	}




}
