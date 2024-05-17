//============================================================================================*
//==============    Author   	: Eng.Mustafa Hafez     ======================================*
//==============	Company   	: A2Z Engineering       ======================================*
//==============	Driver   	: ESC                   ======================================*
//==============    Layer    	: HAL                   ======================================*
//==============    Version  	: V1.0                  ======================================*
//============================================================================================*


#include "TIMER.h"
#include "A2Z_Engineering_Drone_ESC.h"
#include "A2Z_Engineering_Drone_ESC_config.h"



/**================================================================
 * @Fn    			- _ESC_PWM_SPEED_MAPPING
 * @brief 			- Mapping the required speed depending on the Parameters of the datasheet for Motors
 * @param [in] 		- DesiredSpeed : Desierd speed in RPM
 * @retval 			- Reqired PWM to set the channel according to that
 * Note				- The function parameters like MAX and MIN RPM could be changed in " A2Z_Engineering_Drone_ESC_config.h"
 */
float _ESC_PWM_SPEED_MAPPING(float DesiredSpeed)
{


	float Req_PWM = 0;
	Req_PWM = (  (  (DesiredSpeed - MIN_RPM) * (MAX_PWM - MIN_PWM)   ) / (MAX_RPM-MIN_RPM) )  + MIN_PWM;

	return Req_PWM;

}



/**================================================================
 * @Fn    			- HAL_ESC_SetMotorSpeed
 * @brief 			- Set the speed of motors in RPM (Angle in servo ) between MIN_RPM to MAX_RPM as in " A2Z_Engineering_Drone_ESC_config.h"
 * @param [in] 		- Motor : Select the Motor from reqired @ref ESC_MOTOR_def
 * @param [in] 		- Direction : Select the Motor Direction from reqired @ref ESC_MOTOR_DIR_def
 * @param [in] 		- DesiredSpeed : Select the Motor Speed (Angle in servo) between MIN_RPM to MAX_RPM as in " A2Z_Engineering_Drone_ESC_config.h".
 * @param [out] 	- None
 * @retval 			- None
 * Note				- This is protected from wrong value, any value outside the range will be ignored.
 */
void HAL_ESC_SetMotorSpeed(uint8_t Motor,uint8_t Direction,float DesiredSpeed)
{
	float Req_Duty=0;
	if((DesiredSpeed>=MIN_RPM)&&(DesiredSpeed<=MAX_RPM))
	{
		Req_Duty=_ESC_PWM_SPEED_MAPPING(DesiredSpeed);

		switch(Motor)
		{
		case ESC_MOTOR_FR: TIM2->TIMx_CCR1 = 20000-(200*Req_Duty); break;
		case ESC_MOTOR_FL: TIM2->TIMx_CCR2 = 20000-(200*Req_Duty); break;
		case ESC_MOTOR_RR: TIM2->TIMx_CCR3 = 20000-(200*Req_Duty); break;
		case ESC_MOTOR_RL: TIM2->TIMx_CCR4 = 20000-(200*Req_Duty); break;

		}

	}

}
