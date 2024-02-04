//===================================================================================*
//==============    Author   : Mustafa Hafez   ======================================*
//==============	Driver   : GPIO            ======================================*
//==============    Layer    : MCAL            ======================================*
//==============    Version  : V1.0            ======================================*
//===================================================================================*



#include "GPIO.h"


uint8_t Get_u8CRLH_Position(uint16_t PinNum)
{
	switch(PinNum)
	{
	case GPIO_PIN_0  : return  0  ; break;
	case GPIO_PIN_1  : return  4  ; break;
	case GPIO_PIN_2  : return  8  ; break;
	case GPIO_PIN_3  : return  12 ; break;
	case GPIO_PIN_4  : return  16 ; break;
	case GPIO_PIN_5  : return  20 ; break;
	case GPIO_PIN_6  : return  24 ; break;
	case GPIO_PIN_7  : return  28 ; break;
	case GPIO_PIN_8  : return  0  ; break;
	case GPIO_PIN_9  : return  4  ; break;
	case GPIO_PIN_10 : return  8  ; break;
	case GPIO_PIN_11 : return  12 ; break;
	case GPIO_PIN_12 : return  16 ; break;
	case GPIO_PIN_13 : return  20 ; break;
	case GPIO_PIN_14 : return  24 ; break;
	default			: return   28 ; break;

	}
}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */

void MCAL_GPIO_voidInit(GPIO_Typedef* GPIOx,Pin_Config_t* PinConfig)
{

	volatile uint32_t* Config_Reg = NULL;
	uint8_t Local_u8PinConfig;

	//Which CR will be selected according to the pin number, PIN0:PIN7 -> CRL , PIN8:PIN14->CRH
	Config_Reg = (PinConfig->GPIO_PinNum <8)? &(GPIOx->CRL): &(GPIOx->CRH);
	//First, get the Position:
	//	Clear MODE,CR.
	(*Config_Reg) &= ~(0x0f<<Get_u8CRLH_Position(PinConfig->GPIO_PinNum));

	//case Pin is output , MODE select speed
	if((PinConfig->GPIO_PinMode == GPIO_PIN_MODE_OUT_OD)||(PinConfig->GPIO_PinMode == GPIO_PIN_MODE_OUT_PP)||(PinConfig->GPIO_PinMode == GPIO_PIN_MODE_ALT_OD)||(PinConfig->GPIO_PinMode == GPIO_PIN_MODE_ALT_PP))
	{
		//Mode - 4 will equal the same number in Datasheet which have to be setted in the CR register
		Local_u8PinConfig = ((((PinConfig->GPIO_PinMode - 4)<<2)|(PinConfig->GPIO_Pin_Output_Speed)) &0x0F );
	}
	//case pin is input , MODE = 0
	else
	{
		// case pin is input GPIO_PIN_MODE_INP_ANALOG or GPIO_PIN_MODE_INP_FLO
		if ((PinConfig->GPIO_PinMode == GPIO_PIN_MODE_INP_ANALOG)||(PinConfig->GPIO_PinMode == GPIO_PIN_MODE_INP_FLO))
		{
			Local_u8PinConfig = (((PinConfig->GPIO_PinMode<<2)|(0)) &0x0F );
		}

		//case pin is input PU or PD
		else if ((PinConfig->GPIO_PinMode == GPIO_PIN_MODE_INP_PU)||(PinConfig->GPIO_PinMode == GPIO_PIN_MODE_INP_PD))
		{
			switch(PinConfig->GPIO_PinMode)
			{
			case GPIO_PIN_MODE_INP_PU:
				Local_u8PinConfig = (((PinConfig->GPIO_PinMode<<2)|(0)) &0x0F );
				GPIOx->ODR |= PinConfig->GPIO_PinNum; // equal to (1<<BitNum)
				break;

			case GPIO_PIN_MODE_INP_PD:
				Local_u8PinConfig = (((GPIO_PIN_MODE_INP_PU<<2)|(0)) &0x0F );
				GPIOx->ODR &= (~PinConfig->GPIO_PinNum);
				break;
			}
		}
		//case pin is Alternative input
		else
		{
			Local_u8PinConfig = (((GPIO_PIN_MODE_INP_FLO<<2)|(0)) &0x0F );
		}
	}

	(*Config_Reg) |= ( (Local_u8PinConfig) << Get_u8CRLH_Position(PinConfig->GPIO_PinNum)  );
}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */

void MCAL_GPIO_voidDeInit(GPIO_Typedef* GPIOx)
{
	//A system reset sets all registers to their reset values
	//7.3.4 APB2 peripheral reset register (RCC_APB2RSTR)
	if(GPIOx==GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx==GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);

	}
	else if(GPIOx==GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);

	}
	else if(GPIOx==GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);

	}


}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */

uint8_t  MCAL_GPIO_u8ReadPin(GPIO_Typedef* GPIOx,uint16_t copy_u16PinNumber)
{
	volatile uint8_t Local_u8State;
	// 0x01001000 -> IDR
	//		&
	// 0x00000100 ->pin2
	if((GPIOx->IDR & copy_u16PinNumber)!= GPIO_PIN_STATE_RESET)
	{
		//PIN is Set
		Local_u8State = GPIO_PIN_STATE_SET;
	}
	else
	{
		//PIN is Reset
		Local_u8State = GPIO_PIN_STATE_RESET;
	}

	return Local_u8State;
}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */

uint16_t MCAL_GPIO_u16ReadPort(GPIO_Typedef* GPIOx)
{
	return (uint16_t)GPIOx->IDR;
}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */


void MCAL_GPIO_voidWritePin(GPIO_Typedef* GPIOx,uint16_t copy_u16PinNumber,uint8_t copy_u8PinState)
{
	uint8_t Local_u8pin;


#if(GPIO_ACCESS_MODE==GPIO_NORMAL_ACCESS)
	if(copy_u8PinState==GPIO_PIN_STATE_SET)
	{
		GPIOx->ODR |= copy_u16PinNumber;
	}
	else if(copy_u8PinState==GPIO_PIN_STATE_RESET)
	{
		GPIOx->ODR &= ~(copy_u16PinNumber);

	}

	//For atomic access:
#elif(GPIO_ACCESS_MODE==GPIO_ATOMIC_ACCESS)

	//	Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Set the corresponding ODRx bit

	if(copy_u8PinState==GPIO_PIN_STATE_SET)
	{
		GPIOx->BSRR = (uint32_t) copy_u16PinNumber;
	}
	//	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Reset the corresponding ODRx bit
	else if(copy_u8PinState==GPIO_PIN_STATE_RESET)
	{
		GPIOx->BRR = (uint32_t) copy_u16PinNumber;
	}
#endif
}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */

void MCAL_GPIO_voidWritePort(GPIO_Typedef* GPIOx,uint16_t copy_u16PortState)
{
	GPIOx->ODR = (uint32_t)copy_u16PortState;
}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */

void MCAL_GPIO_voidTogglePin(GPIO_Typedef* GPIOx,uint16_t copy_u16PinNumber)
{


	GPIOx->ODR ^= copy_u16PinNumber;

}
/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */

void MCAL_GPIO_voidTogglePort(GPIO_Typedef* GPIOx)
{
	GPIOx->ODR ^= 0x0000FFFF;

}
