/*
 * STM32f103Cxx.h
 *
 *  Created on: Feb 2, 2024
 *      Author: Mustafa Hafez
 */

#ifndef INC_STM32F103CXX_H_
#define INC_STM32F103CXX_H_




//===================================================================
//					    	Start-Includes
//===================================================================
#include "stdlib.h"
#include "stdint.h"
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


//-*-*-*-*-*-*-*-*-*-*-*-
//      APB1 BUS:
//-*-*-*-*-*-*-*-*-*-*-*-


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
#define EXTI0_IRQ									6
#define EXTI1_IRQ                                   7
#define EXTI2_IRQ                                   8
#define EXTI3_IRQ                                   9
#define EXTI4_IRQ                                   10
#define EXTI5_IRQ                                   23
#define EXTI6_IRQ                                   23
#define EXTI7_IRQ                                   23
#define EXTI8_IRQ                                   23
#define EXTI9_IRQ                                   23
#define EXTI10_IRQ                                  40
#define EXTI11_IRQ                                  40
#define EXTI12_IRQ                                  40
#define EXTI13_IRQ                                  40
#define EXTI14_IRQ                                  40
#define EXTI15_IRQ                                  40





//===================================================================
//					 End-Generic Macros
//===================================================================
//===================================================================
//===================================================================
//===================================================================



#endif /* INC_STM32F103CXX_H_ */
