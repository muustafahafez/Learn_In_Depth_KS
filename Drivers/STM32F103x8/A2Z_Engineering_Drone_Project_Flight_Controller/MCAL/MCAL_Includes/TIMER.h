//============================================================================================*
//==============    Author   	: Eng.Mustafa Hafez     ======================================*
//==============	Company   	: A2Z Engineering       ======================================*
//==============	Driver   	: TIMER2-PWM            ======================================*
//==============    Layer    	: MCAL                  ======================================*
//==============    Version  	: V1.0                  ======================================*
//============================================================================================*

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


//===================================================================
//					    	Start-Includes
//===================================================================
#include "STM32f103Cxx.h"
//===================================================================
//					    	End-Includes
//===================================================================
//===================================================================



//===================================================================
//						Start-User type definitions
//===================================================================

typedef struct
{
	TIM2_5_Typedef*    Instance;//@ref TIM_Instance_def
	uint32_t 		   Prescaler;//@ref TIM_Prescaler_def
	uint32_t 		   CounterMode; //@ref TIM_COUNTERMODE_def
	uint32_t 		   Period;//@ref TIM_Period_def
	uint32_t    	   ClockDivision;//@ref TIM_ClockDivision
	uint32_t 		   AutoReloadPreload;//@ref TIM_AutoReloadPreload
}TIM_Handler_t;

//===================================================================
//						End-User type definitions
//===================================================================
//===================================================================




//===================================================================
//						Start-APIs Supported by "MCAL TIMER DRIVER"
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
void _TIM2_PWM_GPIO_MAPPING();

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
void MCAL_TIM2_Init(TIM_Handler_t* TIMER);



void MCAL_TIM2_5_SetFreq(TIM2_5_Typedef* TIMER,uint16_t Freq);


/**================================================================
 * @Fn    			- MCAL_TIM2_SetDuty
 * @brief 			- Set the Duty between 0 to 100 as a percentage for each channel
 * @param [in] 		- Channel : Select the Channel reqired @ref TIM2_CHANNEL_def
 * @param [in] 		- Duty : Select the Required duty from 0 to 100
 * @param [out] 	- None
 * @retval 			- None
 * Note				- This is protected from wrong value, any value outside the range will be ignored either duty or channel
 */
void MCAL_TIM2_SetDuty(uint8_t Channel,uint8_t Duty);


//===================================================================
//						End-APIs Supported by "MCAL GPIO DRIVER"
//===================================================================
//===================================================================





//===================================================================
//						Start-Macros Configuration References
//===================================================================



//@ref TIM_COUNTERMODE_def
#define TIM_COUNTERMODE_UP               			  0x00000000U                          /*!< Counter used as up-counter   */
#define TIM_COUNTERMODE_DOWN               			  0x00000001U                          /*!< Counter used as up-counter   */


//@ref TIM_ClockDivision
#define TIM_CLOCKDIVISION_DIV1			              0x00000000U                          /*!< Clock division: tDTS=tCK_INT   */


//@ref TIM_AutoReloadPreload
#define TIM_AUTORELOAD_PRELOAD_DISABLE                0x00000000U                          /*!< TIMx_ARR register is not buffered */



//@ref TIM_Prescaler_def
#define TIM_Prescaler_Eight                			  8-1                                 /*!< PSC = Val - 1 */

//@ref TIM_Period_def
#define TIM_Period_20MS                				  20000-1                             /*!< TIMx_ARR register = Val -1 */




//@ref TIM2_CHANNEL_def
#define TIM2_CHANNEL_1										1
#define TIM2_CHANNEL_2										2
#define TIM2_CHANNEL_3										3
#define TIM2_CHANNEL_4										4

//===================================================================
//						End-Macros Configuration References
//===================================================================
//===================================================================


#endif /* INC_TIMER_H_ */
