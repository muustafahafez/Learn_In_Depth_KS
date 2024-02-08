/*
 * EXTI.h
 *
 *  Created on: Feb 4, 2024
 *      Author: Mustafa Hafez
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_


//===================================================================
//					    	Start-Includes
//===================================================================
#include "GPIO.h"
#include "STM32f103Cxx.h"

//===================================================================
//					    	End-Includes
//===================================================================
//===================================================================


//===================================================================
//						Start-User type definitions
//===================================================================
typedef struct{
	uint8_t 		 EXTI_Line ; 				//EXTI0:EXTI15
	GPIO_Typedef* 	 GPIO_PORT ; 				//GPIOA,GPIOB,GPIOC,GPIOD
	uint16_t 		 GPIO_PIN  ;				//PIN0:PIN15
	uint8_t  	 	 IRQ_Num   ;				//From IVT

}Private_EXTI_GPIO_Map_t;

typedef struct{
	Private_EXTI_GPIO_Map_t  PinConfig              ; //select from @ref EXTI_def
	uint8_t					 SenseControl           ;//select from @ref EXTI_SENSE_def
	uint8_t					 EXTI_State				;//select from @ref EXTI_STATE_def
	void					 (*CallBackFunc)(void)  ;

}EXTI_PinConfig_t;
//===================================================================
//						End-User type definitions
//===================================================================
//===================================================================




//===================================================================
//						Start-Macros Configuration References
//===================================================================

//select from @ref EXTI_def

//EXTI0
#define EXTI0PA0		                            (Private_EXTI_GPIO_Map_t){EXTI0,GPIOA,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PB0		                            (Private_EXTI_GPIO_Map_t){EXTI0,GPIOB,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PC0		                            (Private_EXTI_GPIO_Map_t){EXTI0,GPIOC,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PD0		                            (Private_EXTI_GPIO_Map_t){EXTI0,GPIOD,GPIO_PIN_0,EXTI0_IRQ}

//EXTI1
#define EXTI1PA1		                            (Private_EXTI_GPIO_Map_t){EXTI1,GPIOA,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PB1		                            (Private_EXTI_GPIO_Map_t){EXTI1,GPIOB,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PC1		                            (Private_EXTI_GPIO_Map_t){EXTI1,GPIOC,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PD1		                            (Private_EXTI_GPIO_Map_t){EXTI1,GPIOD,GPIO_PIN_1,EXTI1_IRQ}

//EXTI2
#define EXTI2PA2		                            (Private_EXTI_GPIO_Map_t){EXTI2,GPIOA,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PB2		                            (Private_EXTI_GPIO_Map_t){EXTI2,GPIOB,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PC2		                            (Private_EXTI_GPIO_Map_t){EXTI2,GPIOC,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PD2		                            (Private_EXTI_GPIO_Map_t){EXTI2,GPIOD,GPIO_PIN_2,EXTI2_IRQ}

//EXTI3
#define EXTI3PA3		                            (Private_EXTI_GPIO_Map_t){EXTI3,GPIOA,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PB3		                            (Private_EXTI_GPIO_Map_t){EXTI3,GPIOB,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PC3		                            (Private_EXTI_GPIO_Map_t){EXTI3,GPIOC,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PD3		                            (Private_EXTI_GPIO_Map_t){EXTI3,GPIOD,GPIO_PIN_3,EXTI3_IRQ}

//EXTI4
#define EXTI4PA4		                            (Private_EXTI_GPIO_Map_t){EXTI4,GPIOA,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PB4		                            (Private_EXTI_GPIO_Map_t){EXTI4,GPIOB,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PC4		                            (Private_EXTI_GPIO_Map_t){EXTI4,GPIOC,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PD4		                            (Private_EXTI_GPIO_Map_t){EXTI4,GPIOD,GPIO_PIN_4,EXTI4_IRQ}

//EXTI5
#define EXTI5PA5		                            (Private_EXTI_GPIO_Map_t){EXTI5,GPIOA,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PB5		                            (Private_EXTI_GPIO_Map_t){EXTI5,GPIOB,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PC5		                            (Private_EXTI_GPIO_Map_t){EXTI5,GPIOC,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PD5		                            (Private_EXTI_GPIO_Map_t){EXTI5,GPIOD,GPIO_PIN_5,EXTI5_IRQ}

//EXTI6
#define EXTI6PA6		                            (Private_EXTI_GPIO_Map_t){EXTI6,GPIOA,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PB6		                            (Private_EXTI_GPIO_Map_t){EXTI6,GPIOB,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PC6		                            (Private_EXTI_GPIO_Map_t){EXTI6,GPIOC,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PD6		                            (Private_EXTI_GPIO_Map_t){EXTI6,GPIOD,GPIO_PIN_6,EXTI6_IRQ}

//EXTI7
#define EXTI7PA7		                            (Private_EXTI_GPIO_Map_t){EXTI7,GPIOA,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PB7		                            (Private_EXTI_GPIO_Map_t){EXTI7,GPIOB,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PC7		                            (Private_EXTI_GPIO_Map_t){EXTI7,GPIOC,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PD7		                            (Private_EXTI_GPIO_Map_t){EXTI7,GPIOD,GPIO_PIN_7,EXTI7_IRQ}

//EXTI8
#define EXTI8PA8		                            (Private_EXTI_GPIO_Map_t){EXTI8,GPIOA,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PB8		                            (Private_EXTI_GPIO_Map_t){EXTI8,GPIOB,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PC8		                            (Private_EXTI_GPIO_Map_t){EXTI8,GPIOC,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PD8		                            (Private_EXTI_GPIO_Map_t){EXTI8,GPIOD,GPIO_PIN_8,EXTI8_IRQ}

//EXTI9
#define EXTI9PA9		                            (Private_EXTI_GPIO_Map_t){EXTI9,GPIOA,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PB9		                            (Private_EXTI_GPIO_Map_t){EXTI9,GPIOB,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PC9		                            (Private_EXTI_GPIO_Map_t){EXTI9,GPIOC,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PD9		                            (Private_EXTI_GPIO_Map_t){EXTI9,GPIOD,GPIO_PIN_9,EXTI9_IRQ}

//EXTI9
#define EXTI10PA10		                            (Private_EXTI_GPIO_Map_t){EXTI10,GPIOA,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10PB10		                            (Private_EXTI_GPIO_Map_t){EXTI10,GPIOB,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10PC10		                            (Private_EXTI_GPIO_Map_t){EXTI10,GPIOC,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10PD10		                            (Private_EXTI_GPIO_Map_t){EXTI10,GPIOD,GPIO_PIN_10,EXTI10_IRQ}

//EXTI11
#define EXTI11PA11		                            (Private_EXTI_GPIO_Map_t){EXTI11,GPIOA,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11PB11		                            (Private_EXTI_GPIO_Map_t){EXTI11,GPIOB,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11PC11		                            (Private_EXTI_GPIO_Map_t){EXTI11,GPIOC,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11PD11		                            (Private_EXTI_GPIO_Map_t){EXTI11,GPIOD,GPIO_PIN_11,EXTI11_IRQ}

//EXTI12
#define EXTI12PA12		                            (Private_EXTI_GPIO_Map_t){EXTI12,GPIOA,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12PB12		                            (Private_EXTI_GPIO_Map_t){EXTI12,GPIOB,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12PC12		                            (Private_EXTI_GPIO_Map_t){EXTI12,GPIOC,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12PD12		                            (Private_EXTI_GPIO_Map_t){EXTI12,GPIOD,GPIO_PIN_12,EXTI12_IRQ}

//EXTI13
#define EXTI13PA13		                            (Private_EXTI_GPIO_Map_t){EXTI13,GPIOA,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13PB13		                            (Private_EXTI_GPIO_Map_t){EXTI13,GPIOB,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13PC13		                            (Private_EXTI_GPIO_Map_t){EXTI13,GPIOC,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13PD13		                            (Private_EXTI_GPIO_Map_t){EXTI13,GPIOD,GPIO_PIN_13,EXTI13_IRQ}

//EXTI14
#define EXTI14PA14		                            (Private_EXTI_GPIO_Map_t){EXTI14,GPIOA,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14PB14		                            (Private_EXTI_GPIO_Map_t){EXTI14,GPIOB,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14PC14		                            (Private_EXTI_GPIO_Map_t){EXTI14,GPIOC,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14PD14		                            (Private_EXTI_GPIO_Map_t){EXTI14,GPIOD,GPIO_PIN_14,EXTI14_IRQ}

//EXTI15
#define EXTI15PA15		                            (Private_EXTI_GPIO_Map_t){EXTI15,GPIOA,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15PB15		                            (Private_EXTI_GPIO_Map_t){EXTI15,GPIOB,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15PC15		                            (Private_EXTI_GPIO_Map_t){EXTI15,GPIOC,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15PD15		                            (Private_EXTI_GPIO_Map_t){EXTI15,GPIOD,GPIO_PIN_15,EXTI15_IRQ}


//select from @ref EXTI_SENSE_def
#define EXTI_SENSE_RISING							0
#define EXTI_SENSE_FALLING							1
#define EXTI_SENSE_RISING_FALLING					2


//select from @ref EXTI_STATE_def
#define EXTI_STATE_DISABLE							0
#define EXTI_STATE_ENABLE							1






//===================================================================
//						End-Macros Configuration References
//===================================================================
//===================================================================


//===================================================================
//						Start-APIs Supported by "MCAL EXTI DRIVER"
//===================================================================
void MCAL_EXTI_voidDeInit();
void MCAL_EXTI_voidInit(EXTI_PinConfig_t* Pin_conf);
void MCAL_EXTI_voidUpdate(EXTI_PinConfig_t* Pin_conf);

//===================================================================
//						End-APIs Supported by "MCAL EXTI DRIVER"
//===================================================================
//===================================================================


//===================================================================
//						Start - Generic Macros
//===================================================================

#define EXTI_GET_GPIO_PIN(x)	 ((x==GPIOA?)0:\
								  (x==GPIOB?)1:\
								  (x==GPIOC?)2:\
								  (x==GPIOD?)3:0)


#define EXTI0			0
#define EXTI1			1
#define EXTI2			2
#define EXTI3			3
#define EXTI4			4
#define EXTI5			5
#define EXTI6			6
#define EXTI7			7
#define EXTI8			8
#define EXTI9			9
#define EXTI10			10
#define EXTI11			11
#define EXTI12			12
#define EXTI13			13
#define EXTI14			14
#define EXTI15			15

//===================================================================
//						End - Generic Macros

//===================================================================
//===================================================================



#endif /* INC_EXTI_H_ */
