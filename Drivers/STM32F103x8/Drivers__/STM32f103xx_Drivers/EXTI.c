#include "GPIO.h"
#include "EXTI.h"


//===================================================================
//						Start-Global Variables
//===================================================================
void (*GP_EXTI[16])(void);
//===================================================================
//						End-Global Variables
//===================================================================



//===================================================================
//						Start-Generic Function
//===================================================================
void PEXTI_voidUpdate(EXTI_PinConfig_t* Pin_conf)
{

	Pin_Config_t GPIO_Pin_Conf;
	uint8_t EXTICR_Index;
	uint8_t EXTICR_Bit_Index;

	GPIO_Pin_Conf.GPIO_PinMode = GPIO_PIN_MODE_INP_FLO;
	GPIO_Pin_Conf.GPIO_PinNum =  Pin_conf->PinConfig.GPIO_PIN;

	EXTICR_Index = Pin_conf->PinConfig.EXTI_Line /4;
	EXTICR_Bit_Index = (Pin_conf->PinConfig.EXTI_Line %4) * 4 ;
	//=========================================
	//1- Configure the Pin to Input floating
	//=========================================
	MCAL_GPIO_voidInit(Pin_conf->PinConfig.GPIO_PORT, &GPIO_Pin_Conf);

	//=========================================
	//2- Configure the EXTICR, Route the AFIO
	//=========================================
	//Clear the specified Bits
	AFIO->EXTICR[EXTICR_Index] &= ~(0x0F<<EXTICR_Bit_Index);
	//Configure the specified Bits


	if(Pin_conf->PinConfig.GPIO_PORT == GPIOA)
	{
		AFIO->EXTICR[EXTICR_Index] |= (0<<EXTICR_Bit_Index);

	}
	else if(Pin_conf->PinConfig.GPIO_PORT == GPIOB)
	{
		AFIO->EXTICR[EXTICR_Index] |= (1<<EXTICR_Bit_Index);

	}
	else if(Pin_conf->PinConfig.GPIO_PORT == GPIOC)
	{
		AFIO->EXTICR[EXTICR_Index] |= (2<<EXTICR_Bit_Index);

	}
	else if(Pin_conf->PinConfig.GPIO_PORT == GPIOD)
	{
		AFIO->EXTICR[EXTICR_Index] |= (3<<EXTICR_Bit_Index);

	}

	//AFIO->EXTICR[EXTICR_Index] |= ( (EXTI_GET_GPIO_PIN(Pin_conf->PinConfig.GPIO_PORT)&0x0f ) << EXTICR_Bit_Index);


	//=========================================
	//3-Edge configuration
	//=========================================


	//	Bits 19:0 TRx: Rising trigger event configuration bit of line x
	//	0: Rising trigger disabled (for Event and Interrupt) for input line
	//	1: Rising trigger enabled (for Event and Interrupt) for input line.

	//	Bits 19:0 TRx: Falling trigger event configuration bit of line x
	//	0: Falling trigger disabled (for Event and Interrupt) for input line
	//	1: Falling trigger enabled (for Event and Interrupt) for input line.
	//	Note: Bit 19 used in connectivity line devices and is reserved otherwise.

	//Reset First
	EXTI->RTSR &= ~(1<<Pin_conf->PinConfig.EXTI_Line);
	EXTI->FTSR &= ~(1<<Pin_conf->PinConfig.EXTI_Line);

	switch(Pin_conf->SenseControl)
	{

	default:
	case EXTI_SENSE_RISING:
		EXTI->RTSR |= (1<<Pin_conf->PinConfig.EXTI_Line);
		break;
	case EXTI_SENSE_FALLING:
		EXTI->FTSR |= (1<<Pin_conf->PinConfig.EXTI_Line);
		break;
	case EXTI_SENSE_RISING_FALLING:
		EXTI->RTSR |= (1<<Pin_conf->PinConfig.EXTI_Line);
		EXTI->FTSR |= (1<<Pin_conf->PinConfig.EXTI_Line);
		break;

	}


	//=========================================
	//4-Call Back Function
	//=========================================

	GP_EXTI[Pin_conf->PinConfig.EXTI_Line] = Pin_conf->CallBackFunc;

	//=========================================
	//5-Enable/Disable
	//=========================================


	switch(Pin_conf->EXTI_State)
	{
	default:
	case EXTI_STATE_DISABLE:
		//Non mask the interrupt line
		EXTI->IMR &= ~(1<<Pin_conf->PinConfig.EXTI_Line);

		switch(Pin_conf->PinConfig.IRQ_Num)
		{
		case EXTI0_IRQ  : NVIC_IRQ6_EXTI0_DISABLE()        ;break;
		case EXTI1_IRQ  : NVIC_IRQ7_EXTI1_DISABLE()        ;break;
		case EXTI2_IRQ  : NVIC_IRQ8_EXTI2_DISABLE()        ;break;
		case EXTI3_IRQ  : NVIC_IRQ9_EXTI3_DISABLE()        ;break;
		case EXTI4_IRQ  : NVIC_IRQ10_EXTI4_DISABLE()       ;break;
		case EXTI9_IRQ  :  NVIC_IRQ23_EXTI9_5_DISABLE()    ;break;
		case EXTI15_IRQ :  NVIC_IRQ40_EXTI15_10_DISABLE()  ;break;

		}
		break;
		case EXTI_STATE_ENABLE:
			//Non mask the interrupt line
			EXTI->IMR |=(1<<Pin_conf->PinConfig.EXTI_Line);

			switch(Pin_conf->PinConfig.IRQ_Num)
			{
			case EXTI0_IRQ  : NVIC_IRQ6_EXTI0_ENABLE()        ;break;
			case EXTI1_IRQ  : NVIC_IRQ7_EXTI1_ENABLE()        ;break;
			case EXTI2_IRQ  : NVIC_IRQ8_EXTI2_ENABLE()        ;break;
			case EXTI3_IRQ  : NVIC_IRQ9_EXTI3_ENABLE()        ;break;
			case EXTI4_IRQ  : NVIC_IRQ10_EXTI4_ENABLE()       ;break;
			case EXTI9_IRQ  :  NVIC_IRQ23_EXTI9_5_ENABLE()    ;break;
			case EXTI15_IRQ :  NVIC_IRQ40_EXTI15_10_ENABLE()  ;break;

			}

			break;
	}


}




//===================================================================
//						End-Generic Function
//===================================================================
//===================================================================





//===================================================================
//						Start-APIs Supported by "MCAL EXTI DRIVER"
//===================================================================



/**================================================================
 * @Fn       MCAL_EXTI_voidDeInit    	      -
 * @brief	 Reset the Pin to the reset value -							 -
 * @param    Pin_conf            		      -
 * @param    None 						      -
 * @retval   None					          -
 * Note										  -
 */

void MCAL_EXTI_voidDeInit()
{

	//	Reset EXTI Registers
	EXTI->IMR   = 	0x00000000;
	EXTI->EMR   = 	0x00000000;
	EXTI->RTSR  = 	0x00000000;
	EXTI->FTSR  = 	0x00000000;
	EXTI->SWIER = 	0x00000000;
	//rc_w1,This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR    = 	0xFFFFFFFF;
	//	Reset NVIC Registers
	NVIC_IRQ6_EXTI0_DISABLE();
	NVIC_IRQ7_EXTI1_DISABLE();
	NVIC_IRQ8_EXTI2_DISABLE();
	NVIC_IRQ9_EXTI3_DISABLE();
	NVIC_IRQ10_EXTI4_DISABLE();
	NVIC_IRQ23_EXTI9_5_DISABLE();
	NVIC_IRQ40_EXTI15_10_DISABLE();

}

/**================================================================
 * @Fn       MCAL_EXTI_voidInit    	                 -
 * @brief	 Initialize the Pin to the desired value -							 -
 * @param    Pin_conf            		             -
 * @param    None 						             -
 * @retval   None					                 -
 * Note										         -
 */

void MCAL_EXTI_voidInit(EXTI_PinConfig_t* Pin_conf)
{
	PEXTI_voidUpdate(Pin_conf);

}

/**================================================================
 * @Fn       MCAL_EXTI_voidInit    	                 -
 * @brief	 Update the Pin to the desired value     -							 -
 * @param    Pin_conf            		             -
 * @param    None 						             -
 * @retval   None					                 -
 * Note										         -
 */

void MCAL_EXTI_voidUpdate(EXTI_PinConfig_t* Pin_conf)
{
	PEXTI_voidUpdate(Pin_conf);
}

//===================================================================
//						End-APIs Supported by "MCAL EXTI DRIVER"
//===================================================================
//===================================================================



//===================================================================
//						Start-EXTI_Handlers
//===================================================================

void EXTI0_IRQHandler(void){
	//Clear pending, write 1 to clear
	EXTI->PR |= (1<<0);
	//Call CallBack Function
	GP_EXTI[0]();

}
void EXTI1_IRQHandler(void){
	//Clear pending, write 1 to clear
	EXTI->PR |= (1<<1);
	//Call CallBack Function
	GP_EXTI[1]();

}
void EXTI2_IRQHandler(void){
	//Clear pending, write 1 to clear
	EXTI->PR |= (1<<2);
	//Call CallBack Function
	GP_EXTI[2]();
}
void EXTI3_IRQHandler(void){
	//Clear pending, write 1 to clear
	EXTI->PR |= (1<<3);
	//Call CallBack Function
	GP_EXTI[3]();
}
void EXTI4_IRQHandler(void){
	//Clear pending, write 1 to clear
	EXTI->PR |= (1<<4);
	//Call CallBack Function
	GP_EXTI[4]();
}
void EXTI9_5_IRQHandler(void){
	//check which EXTI occurs
	//Clear pending, write 1 to clear

	if( ((EXTI->PR>>5)&1) == 1  )
	{
		EXTI->PR |= (1<<5);GP_EXTI[5]();
	}
	if( ((EXTI->PR>>6)&1) == 1  )
	{
		EXTI->PR |= (1<<6);GP_EXTI[6]();
	}
	if( ((EXTI->PR>>7)&1) == 1  )
	{
		EXTI->PR |= (1<<7);GP_EXTI[7]();
	}
	if( ((EXTI->PR>>8)&1) == 1  )
	{
		EXTI->PR |= (1<<8);GP_EXTI[8]();
	}
	if( ((EXTI->PR>>9)&1) == 1  )
	{
		EXTI->PR |= (1<<9);GP_EXTI[9]();
	}


}
void EXTI15_10_IRQHandler(void){
	//check which EXTI occurs
	//Clear pending, write 1 to clear
	if( ((EXTI->PR>>10)&1) == 1  )
	{
		EXTI->PR |= (1<<10);GP_EXTI[10]();
	}
	if( ((EXTI->PR>>11)&1) == 1  )
	{
		EXTI->PR |= (1<<11);GP_EXTI[11]();
	}
	if( ((EXTI->PR>>12)&1) == 1  )
	{
		EXTI->PR |= (1<<12);GP_EXTI[12]();
	}
	if( ((EXTI->PR>>13)&1) == 1  )
	{
		EXTI->PR |= (1<<13);GP_EXTI[13]();
	}
	if( ((EXTI->PR>>14)&1) == 1  )
	{
		EXTI->PR |= (1<<14);GP_EXTI[14]();
	}
	if( ((EXTI->PR>>15)&1) == 1  )
	{
		EXTI->PR |= (1<<15);GP_EXTI[15]();
	}

}


//===================================================================
//						End-EXTI_Handlers
//===================================================================
//===================================================================
