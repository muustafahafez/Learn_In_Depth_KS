/*
 * *****************Author : Mustafa Hafez*************
 * ******************Component: CLCD*******************
 * *******************Version: V1.0********************
 * */


#ifndef CLCD_H
#define CLCD_H

#include "DIO_interface.h"

typedef unsigned char  uint8_t;


/*-------------CLCD PINS------------------*/

#define CLCD_DataPort	DIO_u8PORTC

#define CLCD_CTRLPort	DIO_u8PORTD
#define CLCD_RS_PIN		DIO_u8PIN0
#define CLCD_RW_PIN		DIO_u8PIN1
#define CLCD_E_PIN		DIO_u8PIN2

/*----------------------------------------*/


/*-------------CLCD OPTIONS------------------*/

#define CLCD_2Lines_F5x7		    0b00111000
#define CLCD_2Lines_F5x10		    0b00111100
#define CLCD_1Lines_F5x7		    0b00110000
#define CLCD_1Lines_F5x10		    0b00110100

#define CLCD_Cursor_ON_BLINK	    0b00001111
#define CLCD_Cursor_ON_No_BLINK	    0b00001110
#define CLCD_Cursor_OFF			    0b00001100


/*----------------------------------------*/




typedef enum {
	CLCD_NoError,
	CLCD_InitError,
	CLCD_CommendError,
	CLCD_DataError
}CLCD_State;


void CLCD_voidInit(void);
CLCD_State CLCD_uint8SendData(uint8_t copy_uint8Data);
CLCD_State CLCD_uint8SendCommand(uint8_t copy_uint8Commend);




#endif
