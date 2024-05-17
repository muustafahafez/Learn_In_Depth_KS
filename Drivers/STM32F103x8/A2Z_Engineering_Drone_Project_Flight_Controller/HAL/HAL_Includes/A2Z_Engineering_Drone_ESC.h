//============================================================================================*
//==============    Author   	: Eng.Mustafa Hafez     ======================================*
//==============	Company   	: A2Z Engineering       ======================================*
//==============	Driver   	: ESC                   ======================================*
//==============    Layer    	: HAL                   ======================================*
//==============    Version  	: V1.0                  ======================================*
//============================================================================================*

#ifndef INC_A2Z_ENGINEERING_DRONE_ESC_H_
#define INC_A2Z_ENGINEERING_DRONE_ESC_H_


#include "TIMER.h"


/**================================================================
 * @Fn    			- _ESC_PWM_SPEED_MAPPING
 * @brief 			- Mapping the required speed depending on the Parameters of the datasheet for Motors
 * @param [in] 		- DesiredSpeed : Desired speed in RPM
 * @retval 			- Reqired PWM to set the channel according to that
 * Note				- The function parameters like MAX and MIN RPM could be changed in " A2Z_Engineering_Drone_ESC_config.h"
 */
float _ESC_PWM_SPEED_MAPPING(float DesiredSpeed);


/**================================================================
 * @Fn    			- HAL_ESC_SetMotorSpeed
 * @brief 			- Set the speed of motors in RPM (Angle in servo ) between MIN_RPM to MAX_RPM as in " A2Z_Engineering_Drone_ESC_config.h"
 * @param [in] 		- Motor : Select the Motor from required @ref ESC_MOTOR_def
 * @param [in] 		- Direction : Select the Motor Direction from reqired @ref ESC_MOTOR_DIR_def
 * @param [in] 		- DesiredSpeed : Select the Motor Speed (Angle in servo) between MIN_RPM to MAX_RPM as in " A2Z_Engineering_Drone_ESC_config.h".
 * @param [out] 	- None
 * @retval 			- None
 * Note				- This is protected from wrong value, any value outside the range will be ignored.
 */
void HAL_ESC_SetMotorSpeed(uint8_t Motor,uint8_t Direction,float DesiredSpeed);




//@ref ESC_MOTOR_DIR_def
#define ESC_MOTOR_DIR_CW		1
#define ESC_MOTOR_DIR_CCW		2


//@ref ESC_MOTOR_def
#define ESC_MOTOR_FR			1
#define ESC_MOTOR_FL			2
#define ESC_MOTOR_RR			3
#define ESC_MOTOR_RL			4



#endif /* INC_A2Z_ENGINEERING_DRONE_ESC_H_ */
