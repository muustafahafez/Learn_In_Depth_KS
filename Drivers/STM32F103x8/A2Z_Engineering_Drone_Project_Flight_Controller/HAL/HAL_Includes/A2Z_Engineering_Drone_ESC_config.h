//============================================================================================*
//==============    Author   	: Eng.Mustafa Hafez     ======================================*
//==============	Company   	: A2Z Engineering       ======================================*
//==============	Driver   	: ESC                   ======================================*
//==============    Layer    	: HAL                   ======================================*
//==============    Version  	: V1.0                  ======================================*
//============================================================================================*

#ifndef INC_A2Z_ENGINEERING_DRONE_ESC_CONFIG_H_
#define INC_A2Z_ENGINEERING_DRONE_ESC_CONFIG_H_





//Maximum and Minimum RPM Based on the Datasheet of the Brushless Motor (Used in _ESC_PWM_SPEED_MAPPING function ).
#define MAX_RPM		10000
#define MIN_RPM		0


//Maximum and Minimum PWM Based on the Datasheet of the Brushless Motor (Used in _ESC_PWM_SPEED_MAPPING function ).
#define MAX_PWM		10 					// As a percentage " 2ms --> so 2ms/20ms(period) *100 = 10
#define MIN_PWM		5 					// As a percentage " 1ms --> so 1ms/20ms(period) *100 = 5




#endif /* INC_A2Z_ENGINEERING_DRONE_ESC_CONFIG_H_ */
