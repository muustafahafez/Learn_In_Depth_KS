#include "CLCD.h"
#include "DIO_interface.h"
#include <util/delay.h>



void CLCD_voidInit(void)
{
	_delay_ms(40);
	CLCD_uint8SendCommand(CLCD_2Lines_F5x7);
	CLCD_uint8SendCommand(CLCD_Cursor_OFF);
	CLCD_uint8SendCommand(1);



}
CLCD_State CLCD_uint8SendData(uint8_t copy_uint8Data)
{
	/*  RS ---> 1 to send data*/
	DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	/* CLR RW PIN*/
	DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*Display data on CGRAM*/
	DIO_u8SetPortValue(CLCD_DataPort,copy_uint8Data);
	/*Enable Pulse*/
//	DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_E_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_E_PIN,DIO_u8PIN_LOW);
	return CLCD_NoError;
}
CLCD_State CLCD_uint8SendCommand(uint8_t copy_uint8Commend)
{


	/*  RS ---> 0 to send data*/
		DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_RS_PIN,DIO_u8PIN_LOW);
		/* CLR RW PIN*/
		DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_RW_PIN,DIO_u8PIN_LOW);
		/*send commend on CGRAM*/
		DIO_u8SetPortValue(CLCD_DataPort,copy_uint8Commend);
		/*Enable Pulse*/
//		DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_E_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_E_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(CLCD_CTRLPort,CLCD_E_PIN,DIO_u8PIN_LOW);
		return CLCD_NoError;
}

