//============================================================================================*
//==============    Author   	: Eng.Mustafa Hafez     ======================================*
//==============	Company   	: A2Z Engineering       ======================================*
//==============	Driver   	: Microcontroller LIB   ======================================*
//==============    Layer    	: LIB                   ======================================*
//==============    Version  	: V1.0                  ======================================*
//============================================================================================*


#ifndef INC_STM32F103CXX_H_
#define INC_STM32F103CXX_H_




//===================================================================
//					    	Start-Includes
//===================================================================
#include "stdlib.h"
#include "stdint.h"
#include "BitField_I2C.h"
//===================================================================
//					    	End-Includes
//===================================================================
//===================================================================
//===================================================================
//===================================================================



//===================================================================
//					 Start-Base addresses for Memories
//===================================================================

#define FLASH_MEM_BASE					0x08000000UL
#define SYSTEM_MEM_BASE					0x1FFFF000UL
#define SRAM_MEM_BASE					0x20000000UL
#define PERIPHERAL_MEM_BASE				0x40000000UL
#define CORTEX_M3_INTERNAL_BASE			0xE0000000UL

//===================================================================
//					 End-Base addresses for Memories
//===================================================================
//===================================================================




//===================================================================
//					 Start-Base addresses for BUS Peripherals
//===================================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//      AHB BUS:
//-*-*-*-*-*-*-*-*-*-*-*-
#define RCC_BASE						0x40021000UL


//-*-*-*-*-*-*-*-*-*-*-*-
//      APB2 BUS:
//-*-*-*-*-*-*-*-*-*-*-*-
#define GPIOA_BASE						0x40010800UL
#define GPIOB_BASE						0x40010C00UL
#define GPIOC_BASE						0x40011000UL
#define GPIOD_BASE						0x40011400UL
#define GPIOE_BASE						0x40011800UL

#define EXTI_BASE						0x40010400UL
#define AFIO_BASE						0x40010000UL

#define SPI1_BASE						0x40013000UL

#define I2C1_BASE        		        (0x40005400UL)
#define I2C2_BASE                       (0x40005800UL)

//-*-*-*-*-*-*-*-*-*-*-*-
//      APB1 BUS:
//-*-*-*-*-*-*-*-*-*-*-*-
#define SPI2_BASE						0x40003800UL
#define SPI3_BASE						0x40003C00UL

#define TIM2_BASE						0x40000000UL
#define TIM3_BASE						0x40000400UL
#define TIM4_BASE						0x40000800UL
#define TIM5_BASE						0x40000C00UL


//===================================================================
//					 End-Base addresses for BUS Peripherals
//===================================================================
//===================================================================


//===================================================================
//					 Start-CORTEX_M3_INTERNAL_Register
//===================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC register:
//-*-*-*-*-*-*-*-*-*-*-*-
#define NVIC_BASE_ADDRESS 			0xE000E100UL

#define NVIC_ISER0					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x0))
#define NVIC_ISER1					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x4))
#define NVIC_ISER2					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x8))

#define NVIC_ICER0					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x080))
#define NVIC_ICER1					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x084))
#define NVIC_ICER2					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x088))

#define NVIC_ISPR0					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x100))
#define NVIC_ISPR1					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x104))
#define NVIC_ISPR2					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x108))

#define NVIC_ICPR0					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x180))
#define NVIC_ICPR1					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x184))
#define NVIC_ICPR2					*((volatile uint32_t*)(NVIC_BASE_ADDRESS+ 0x188))

//===================================================================
//					 End-CORTEX_M3_INTERNAL_Register
//===================================================================
//===================================================================



//===================================================================
//					 Start-Peripheral register
//===================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register GPIO:
//-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	volatile uint32_t CRL			;//configuration register low
	volatile uint32_t CRH			;//configuration register high
	volatile uint32_t IDR			;//input data register
	volatile uint32_t ODR			;// output data register
	volatile uint32_t BSRR			;//bit set/reset register
	volatile uint32_t BRR			;//reset register
	volatile uint32_t LCKR			;//This register is used to lock the configuration of the port bits
}GPIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register RCC:
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CR			;//Clock control register
	volatile uint32_t CFGR			;//Clock configuration register
	volatile uint32_t CIR			;//Clock interrupt register
	volatile uint32_t APB2RSTR		;//APB2 peripheral reset register
	volatile uint32_t APB1RSTR		;//APB1 peripheral reset register
	volatile uint32_t AHBENR		;//AHB Peripheral Clock enable register
	volatile uint32_t APB2ENR		;//APB2ENR Peripheral Clock enable register
	volatile uint32_t APB1ENR		;//APB1ENR Peripheral Clock enable register
	volatile uint32_t BDCR			;//Backup domain control register
	volatile uint32_t CSR			;//Control/status register
	volatile uint32_t AHBRSTR		;//AHB peripheral clock reset register
	volatile uint32_t CFGR2			;//Clock configuration register2

}RCC_Typedef;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register EXTI:
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t IMR			;//Interrupt mask register
	volatile uint32_t EMR			;//Event mask register
	volatile uint32_t RTSR			;//Rising trigger selection register
	volatile uint32_t FTSR			;//Falling trigger selection register
	volatile uint32_t SWIER			;//Software interrupt event register
	volatile uint32_t PR			;//Pending register

}EXTI_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register AFIO:
//-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	volatile uint32_t EVCR			;//Event control register
	volatile uint32_t MAPR			;//AF remap and debug I/O configuration register
	volatile uint32_t EXTICR[4]		;//External interrupt configuration register 1
	//	volatile uint32_t EXTICR2		;//External interrupt configuration register 2
	//	volatile uint32_t EXTICR3		;//External interrupt configuration register 3
	//	volatile uint32_t EXTICR4		;//External interrupt configuration register 4
	volatile uint32_t Reserved		;//Reserved
	volatile uint32_t MAPR2			;//AF remap and debug I/O configuration register2

}AFIO_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register SPI:
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;

}SPI_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register TIM2_5:
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{

	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;

	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;

	volatile uint32_t Reserved;

	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	volatile uint32_t TIMx_DCR;
	volatile uint32_t TIMx_DMAR;


}TIM2_5_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register I2C:
//-*-*-*-*-*-*-*-*-*-*-*-


typedef struct
{
	  volatile uint32_t CR1;
	  volatile uint32_t CR2;
	  volatile uint32_t OAR1;
	  volatile uint32_t OAR2;
	  volatile uint32_t DR;
	  volatile uint32_t SR1;
	  volatile uint32_t SR2;
	  volatile uint32_t CCR;
	  volatile uint32_t TRISE;

} I2C_TypeDef;
//===================================================================
//					 End-Peripheral register
//===================================================================
//===================================================================
//===================================================================
//===================================================================





//===================================================================
//					 Start-Peripheral Instants
//===================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants GPIO:
//-*-*-*-*-*-*-*-*-*-*-*-
#define  GPIOA 			((GPIO_Typedef*)(GPIOA_BASE))
#define  GPIOB 			((GPIO_Typedef*)(GPIOB_BASE))
#define  GPIOC 			((GPIO_Typedef*)(GPIOC_BASE))
#define  GPIOD			((GPIO_Typedef*)(GPIOD_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants RCC:
//-*-*-*-*-*-*-*-*-*-*-*-
#define  RCC 			((RCC_Typedef*)(RCC_BASE))
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants EXTI:
//-*-*-*-*-*-*-*-*-*-*-*-
#define  EXTI 			((EXTI_Typedef*)(EXTI_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants AFIO:
//-*-*-*-*-*-*-*-*-*-*-*-
#define  AFIO 			((AFIO_Typedef*)(AFIO_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants SPI:
//-*-*-*-*-*-*-*-*-*-*-*-
#define  SPI1 			((SPI_Typedef*)(SPI1_BASE))
#define  SPI2 			((SPI_Typedef*)(SPI2_BASE))
#define  SPI3 			((SPI_Typedef*)(SPI3_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants TIM:
//-*-*-*-*-*-*-*-*-*-*-*-
#define  TIM2 			((TIM2_5_Typedef*)(TIM2_BASE))
#define  TIM3 			((TIM2_5_Typedef*)(TIM3_BASE))
#define  TIM4 			((TIM2_5_Typedef*)(TIM4_BASE))
#define  TIM5 			((TIM2_5_Typedef*)(TIM5_BASE))


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants I2C:
//-*-*-*-*-*-*-*-*-*-*-*-

#define I2C1                ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                ((I2C_TypeDef *)I2C2_BASE)


//===================================================================
//					 End-Peripheral Instants
//===================================================================
//===================================================================
//===================================================================
//===================================================================





//===================================================================
//					 Start-clock enable Macros
//===================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//APB2 peripheral clock enable
//-*-*-*-*-*-*-*-*-*-*-*-
#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |=(1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |=(1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |=(1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |=(1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |=(1<<6))
#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |=(1<<0))
#define RCC_ADC1_CLK_EN()		(RCC->APB2ENR |=(1<<9))
#define RCC_ADC2_CLK_EN()		(RCC->APB2ENR |=(1<<10))
#define RCC_TIM1_CLK_EN()		(RCC->APB2ENR |=(1<<11))
#define RCC_SPI1_CLK_EN()		(RCC->APB2ENR |=(1<<12))
#define RCC_USART1_CLK_EN()		(RCC->APB2ENR |=(1<<14))

//-*-*-*-*-*-*-*-*-*-*-*-
//APB1 peripheral clock enable
//-*-*-*-*-*-*-*-*-*-*-*-
#define RCC_SPI2_CLK_EN()		(RCC->APB1ENR |=(1<<14))
#define RCC_TIM2_5_CLK_EN()		(RCC->APB1ENR |=(1<<0))


//===================================================================
//					 End-clock enable Macros
//===================================================================
//===================================================================

//===================================================================
//					 Start-NVIC Macros
//===================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Enable
//-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC_IRQ6_EXTI0_ENABLE()			NVIC_ISER0 |= (1<<EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_ENABLE()			NVIC_ISER0 |= (1<<EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_ENABLE()			NVIC_ISER0 |= (1<<EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_ENABLE()			NVIC_ISER0 |= (1<<EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_ENABLE()			NVIC_ISER0 |= (1<<EXTI4_IRQ)
#define NVIC_IRQ23_EXTI9_5_ENABLE()			NVIC_ISER0 |= (1<<EXTI5_IRQ)
#define NVIC_IRQ40_EXTI15_10_ENABLE()		NVIC_ISER1 |= (1<<8)//40-32


#define NVIC_IRQ35_SPI1_ENABLE()			NVIC_ISER1 |= (1<<SPI1_IRQ-32)
#define NVIC_IRQ36_SPI2_ENABLE()			NVIC_ISER1 |= (1<<SPI2_IRQ-32)


#define NVIC_IRQ31_I2C1_EV_Enable   	(NVIC_ISER0 |= 1<<( I2C1_EV_IRQ )) //NVIC_ISER0
#define NVIC_IRQ32_I2C1_ER_Enable   	(NVIC_ISER1 |= 1<<( I2C1_ER_IRQ - 32 )) //NVIC_ISER1 32-32
#define NVIC_IRQ33_I2C2_EV_Enable   	(NVIC_ISER1 |= 1<<( I2C2_EV_IRQ - 32 )) //NVIC_ISER1 33-32
#define NVIC_IRQ34_I2C2_ER_Enable   	(NVIC_ISER1 |= 1<<( I2C2_ER_IRQ - 32 )) //NVIC_ISER1 34-32




//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Disable
//-*-*-*-*-*-*-*-*-*-*-*-
#define NVIC_IRQ6_EXTI0_DISABLE()			NVIC_ICER0 |= (1<<EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_DISABLE()			NVIC_ICER0 |= (1<<EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_DISABLE()			NVIC_ICER0 |= (1<<EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_DISABLE()			NVIC_ICER0 |= (1<<EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_DISABLE()			NVIC_ICER0 |= (1<<EXTI4_IRQ)
#define NVIC_IRQ23_EXTI9_5_DISABLE()		NVIC_ICER0 |= (1<<EXTI5_IRQ)
#define NVIC_IRQ40_EXTI15_10_DISABLE()		NVIC_ICER1 |= (1<<8)//40-32

#define NVIC_IRQ35_SPI1_DISABLE()			NVIC_ICER1 |= (1<<SPI1_IRQ-32)
#define NVIC_IRQ36_SPI2_DISABLE()			NVIC_ICER1 |= (1<<SPI2_IRQ-32)


#define NVIC_IRQ31_I2C1_EV_Disable   	(NVIC_ICER0 |= 1<<( I2C1_EV_IRQ )) //NVIC_ICER1 //31
#define NVIC_IRQ32_I2C1_ER_Disable   	(NVIC_ICER1 |= 1<<( I2C1_ER_IRQ - 32 )) //NVIC_ICER1 32-32
#define NVIC_IRQ33_I2C2_EV_Disable   	(NVIC_ICER1 |= 1<<( I2C2_EV_IRQ - 32 )) //NVIC_ICER1 33-32
#define NVIC_IRQ34_I2C2_ER_Disable   	(NVIC_ICER1 |= 1<<( I2C2_ER_IRQ - 32 )) //NVIC_ICER1 34-32

//===================================================================
//					 End-NVIC Macros
//===================================================================
//===================================================================




//===================================================================
//					 Start-Generic Macros
//===================================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI IRQs Numbers Table 61. Vector table for connectivity line devices (continued)

//-*-*-*-*-*-*-*-*-*-*-*-
#define     EXTI0_IRQ									6
#define     EXTI1_IRQ                                   7
#define     EXTI2_IRQ                                   8
#define     EXTI3_IRQ                                   9
#define     EXTI4_IRQ                                   10
#define     EXTI5_IRQ                                   23
#define     EXTI6_IRQ                                   23
#define     EXTI7_IRQ                                   23
#define     EXTI8_IRQ                                   23
#define     EXTI9_IRQ                                   23
#define     EXTI10_IRQ                                  40
#define     EXTI11_IRQ                                  40
#define     EXTI12_IRQ                                  40
#define     EXTI13_IRQ                                  40
#define     EXTI14_IRQ                                  40
#define     EXTI15_IRQ                                  40

#define     SPI1_IRQ									35
#define     SPI2_IRQ									36


#define 	I2C1_EV_IRQ			                        31
#define 	I2C1_ER_IRQ			                        32
#define 	I2C2_EV_IRQ			                        33
#define 	I2C2_ER_IRQ			                        34


//===================================================================
//					 End-Generic Macros
//===================================================================
//===================================================================
//===================================================================
//===================================================================



#endif /* INC_STM32F103CXX_H_ */
