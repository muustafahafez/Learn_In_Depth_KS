//============================================================================================*
//==============    Author   	: Eng.Mustafa Hafez     ======================================*
//==============	Company   	: A2Z Engineering       ======================================*
//==============	Driver   	: TIMER2-PWM            ======================================*
//==============    Layer    	: MCAL                  ======================================*
//==============    Version  	: V1.0                  ======================================*
//============================================================================================*


//===================================================================
//					    	Start-Includes
//===================================================================
#include "TIMER.h"
#include "GPIO.h"
#include "BIT_MATH.h"
//===================================================================
//					    	End-Includes
//===================================================================
//===================================================================



/**================================================================
 * @Fn    			- _TIM2_5_PWM_GPIO_MAPPING
 * @brief 			- This function is used internally inside the " MCAL_TIM2_5_Init " function
 * 					  to map PINA 0,1,2,3 to PWM Pins (Configure PA0->PA3 to Alternative Function Push Pull).
 * @param [in] 		- None
 * @param [out] 	- None
 * @retval 			- None
 * Note				- This function is build specially to use PA0,A1,PA2,PA3 as PWM  pins
 */
void _TIM2_PWM_GPIO_MAPPING()
{
	//Enable GPIOA Clock
	RCC_GPIOA_CLK_EN();

	//Initialize PA0 to Alternative Function Push Pull
	Pin_Config_t Pin_config = {GPIO_PIN_0,GPIO_PIN_MODE_ALT_PP,GPIO_PIN_SPEED_2M};
	MCAL_GPIO_voidInit(GPIOA, &Pin_config);
	//Initialize PA1 to Alternative Function Push Pull
	Pin_config.GPIO_PinNum = GPIO_PIN_1;
	MCAL_GPIO_voidInit(GPIOA, &Pin_config);
	//Initialize PA2 to Alternative Function Push Pull
	Pin_config.GPIO_PinNum = GPIO_PIN_2;
	MCAL_GPIO_voidInit(GPIOA, &Pin_config);
	//Initialize PA3 to Alternative Function Push Pull
	Pin_config.GPIO_PinNum = GPIO_PIN_3;
	MCAL_GPIO_voidInit(GPIOA, &Pin_config);

}




/**================================================================
 * @Fn    			- MCAL_TIM2_Init
 * @brief 			- This function is used to intialize the TIMER2 Peripheral to work in PWM mode 1 (Non inverted)
 * 					  with the configuration: Period time = 20ms (50hz) and four Channel CH1 to CH4 (PA0 to PA3).
 *
 * @param [in] 		- TIMER : for future update to choose different config.
 * @param [out] 	- None
 * @retval 			- None
 * Note				- This function is build with consideration :  HSE clock = 8MHZ , Timer CLk 8MHZ , Prescaler 8
 * 					  and ARR 20000.
 */
void MCAL_TIM2_Init(TIM_Handler_t* TIMER)
{

	//Depending on 8 MHZ High speed External clock, the final clock reach the Timer2 peripheral is 8 MHZ.
	//We used a prescaler 8 so , the Timer tick is 8/8MHZ = 1 microsecond.
	//The desired frequancy is 50 Hz " 20 ms ".


	//period time in microsecond = (ARR Value+1) * Tick Time
	//period time in microsecond = (ARR Value+1) * (pre-scaler/TimerCLK)
	//20000  = (ARR Value + 1) * (8/8)
	// ARR Value = 20000 -1


	TIMER->Instance = TIM2;//Select Timer instance
	TIMER->Prescaler = TIM_Prescaler_Eight;//Select Pre-Scaler
	TIMER->Period = TIM_Period_20MS;//Period time
	TIMER->CounterMode = TIM_COUNTERMODE_UP; // count up from zero to ARR Value
	TIMER->ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TIMER->AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;



	if(TIMER->AutoReloadPreload== TIM_AUTORELOAD_PRELOAD_DISABLE)
	{
		//		Bit 7 ARPE: Auto-reload preload enable
		//		0: TIMx_ARR register is not buffered
		//		1: TIMx_ARR register is buffered
		CLEAR_BIT(TIM2->TIMx_CR1,7);
	}



	//Edge Align mode 00: Edge-aligned mode. The counter counts up or down depending on the direction bit (DIR).
	CLEAR_BIT(TIM2->TIMx_CR1,5);
	CLEAR_BIT(TIM2->TIMx_CR1,6);



	//	Bit 4 DIR: Direction
	//	0: Counter used as upcounter
	//	1: Counter used as downcounter
	//Count Up Mode
	if(TIMER->CounterMode ==TIM_COUNTERMODE_UP)
	{CLEAR_BIT(TIM2->TIMx_CR1,4);}
	else if (TIMER->CounterMode ==TIM_COUNTERMODE_DOWN)
	{SET_BIT(TIM2->TIMx_CR1,4);}

	//	Bits 2:0 SMS: Slave mode selection
	//	000: Slave mode disabled - if CEN = ‘1 then the prescaler is clocked directly by the internal
	//	clock
	//Slave Mode Disable
	CLEAR_BIT(TIM2->TIMx_SMCR,0);
	CLEAR_BIT(TIM2->TIMx_SMCR,1);
	CLEAR_BIT(TIM2->TIMx_SMCR,2);
	//-------------------------------------------------------------



	//	Bits 9:8 CC2S[1:0]: Capture/Compare 2 selection
	//	This bit-field defines the direction of the channel (input/output) as well as the used input.
	//	00: CC2 channel is configured as output

	//	Bits 6:4 OC1M: Output compare 1 mode
	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	//	else inactive. In downcounting, channel 1 is inactive (OC1REF=‘0) as long as
	//	TIMx_CNT>TIMx_CCR1 else active (OC1REF=1).

	//Configure CH1 As Output
	CLEAR_BIT(TIM2->TIMx_CCMR1,0);
	CLEAR_BIT(TIM2->TIMx_CCMR1,1);


	//CH1 PWM mode1 (SET ON TOP , CLEAR ON COMPARE "NON INVERTED MODE" )
	CLEAR_BIT(TIM2->TIMx_CCMR1,4);
	SET_BIT(TIM2->TIMx_CCMR1,5);
	SET_BIT(TIM2->TIMx_CCMR1,6);


	//Configure CH2 As Output
	CLEAR_BIT(TIM2->TIMx_CCMR1,8);
	CLEAR_BIT(TIM2->TIMx_CCMR1,9);
	//CH2 PWM mode1 (SET ON TOP , CLEAR ON COMPARE "NON INVERTED MODE" )
	CLEAR_BIT(TIM2->TIMx_CCMR1,12);
	SET_BIT(TIM2->TIMx_CCMR1,13);
	SET_BIT(TIM2->TIMx_CCMR1,14);


	//Configure CH3 As Output
	CLEAR_BIT(TIM2->TIMx_CCMR2,0);
	CLEAR_BIT(TIM2->TIMx_CCMR2,1);
	//CH3 PWM mode1 (SET ON TOP , CLEAR ON COMPARE "NON INVERTED MODE" )
	CLEAR_BIT(TIM2->TIMx_CCMR2,4);
	SET_BIT(TIM2->TIMx_CCMR2,5);
	SET_BIT(TIM2->TIMx_CCMR2,6);


	//Configure CH4 As Output
	CLEAR_BIT(TIM2->TIMx_CCMR2,8);
	CLEAR_BIT(TIM2->TIMx_CCMR2,9);
	//CH4 PWM mode1 (SET ON TOP , CLEAR ON COMPARE "NON INVERTED MODE" )
	CLEAR_BIT(TIM2->TIMx_CCMR2,12);
	SET_BIT(TIM2->TIMx_CCMR2,13);
	SET_BIT(TIM2->TIMx_CCMR2,14);

	//CH1:4 Polarity
	SET_BIT(TIM2->TIMx_CCER,13);//CH4 ->  1 : High Polarity , 0 : Low Polarity
	SET_BIT(TIM2->TIMx_CCER,9);//CH3  ->  1 : High Polarity , 0 : Low Polarity
	SET_BIT(TIM2->TIMx_CCER,5);//CH2  ->  1 : High Polarity , 0 : Low Polarity
	SET_BIT(TIM2->TIMx_CCER,1);//CH1  ->  1 : High Polarity , 0 : Low Polarity


	SET_BIT(TIM2->TIMx_CCER,12);//CH4 ->  1 : OC is output , 0 : Not active
	SET_BIT(TIM2->TIMx_CCER,8);//CH3  ->  1 : OC is output , 0 : Not active
	SET_BIT(TIM2->TIMx_CCER,4);//CH2  ->  1 : OC is output , 0 : Not active
	SET_BIT(TIM2->TIMx_CCER,0);//CH1  ->  1 : OC is output , 0 : Not active


	TIM2->TIMx_PSC = TIMER->Prescaler;

	TIM2->TIMx_ARR = TIMER->Period;


	//Tick time = 1 microsecond.
	//Duty = ( ON  / Period ) * 100
	//ON = value in CCRx
	//Period = Value in ARR Register
	//so Duty = CCRx / ARR
	//So , CCRx = ARR * Duty
	//Ex Duty: 50%
	/*
	 * Duty = CCRx * ARR
	 * 50 = CCRx * 20000
	 *
	 * */
	//Duty CH1
	TIM2->TIMx_CCR1 = 20000;//10000;//10
	//Duty CH2
	TIM2->TIMx_CCR2 = 20000;//200*20;//20
	//Duty CH3
	TIM2->TIMx_CCR3 = 20000;//200*50;//200 = 1//50
	//Duty CH4
	TIM2->TIMx_CCR4 = 20000;//200*75;//75

	//Mapping GPIOA Pins0:3 to AF PP, CH1:CH4 PWM
	_TIM2_PWM_GPIO_MAPPING();


	//	Bit 0 CEN: Counter enable
	//	0: Counter disabled
	//	1: Counter enabled
	//Enable counter, Internal clock
	SET_BIT(TIM2->TIMx_CR1,0);

}


void MCAL_TIM2_5_SetFreq(TIM2_5_Typedef* TIMER,uint16_t Freq)
{

}



/**================================================================
 * @Fn    			- MCAL_TIM2_SetDuty
 * @brief 			- Set the Duty between 0 to 100 as a percentage for each channel
 * @param [in] 		- Channel : Select the Channel reqired @ref TIM2_CHANNEL_def
 * @param [in] 		- Duty : Select the Required duty from 0 to 100
 * @param [out] 	- None
 * @retval 			- None
 * Note				- This is protected from wrong value, any value outside the range will be ignored either duty or channel
 */
void MCAL_TIM2_SetDuty(uint8_t Channel,uint8_t Duty)
{

	if (Duty>=0 && Duty <=100)
	{


		switch(Channel)
		{
		case 1: TIM2->TIMx_CCR1 = 20000-(200*Duty); break;
		case 2: TIM2->TIMx_CCR2 = 20000-(200*Duty); break;
		case 3: TIM2->TIMx_CCR3 = 20000-(200*Duty); break;
		case 4: TIM2->TIMx_CCR4 = 20000-(200*Duty); break;

		}
	}
	else
	{

		//Do Nothing


		//		Duty =0;
		//		switch(Channel)
		//		{
		//		case 1: TIM2->TIMx_CCR1 = 20000-(200*Duty); break;
		//		case 2: TIM2->TIMx_CCR2 = 20000-(200*Duty); break;
		//		case 3: TIM2->TIMx_CCR3 = 20000-(200*Duty); break;
		//		case 4: TIM2->TIMx_CCR4 = 20000-(200*Duty); break;

	}
}



