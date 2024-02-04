#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD.h"
#include "PORT_interface.h"


void CLCD_voidGoToRowCol(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 Local_u8Address;
	if (copy_u8Row==0)  /*This mean you are in first line*/
	{
		Local_u8Address =copy_u8Col;
	}
	else if (copy_u8Row==1) /*This mean you are in second line*/
	{
		Local_u8Address = 	copy_u8Col + 0x40;
	}
	/*Send command to MC to write instructions*/
	CLCD_uint8SendCommand(Local_u8Address+128);/*+128 because we want to set the 2^7 bit and 128 equal to 10000000 by binary*/
}

void main(void)
{

	PORT_voidInit();
	CLCD_voidInit();

	CLCD_voidGoToRowCol(0,0);
	CLCD_uint8SendData('M');


	while(1)
	{

	}





}
