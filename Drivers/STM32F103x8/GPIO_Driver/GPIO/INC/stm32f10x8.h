#ifndef	_STM32F10x8_H
#define	_STM32F10x8_H




//-----------------------------
//Base address for memories
//-----------------------------

#define FLASH_MEM_BASE							0x08000000UL
#define SYSTEM_MEM_BASE							0x1FFFF000UL
#define SRAM_MEM_BASE							0x20000000UL
#define PERIPHERAL_MEM_BASE						0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERA_BASE		0xE0000000UL



//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*

//stm32f103x8 family has only A,B,C,D,E instant.
#define GPIOA	0x40010800 //Fully included in LQFP48
#define GPIOB	0x40010C00 //Fully included in LQFP48
#define GPIOC	0x40011000 //Partially included in LQFP48, PC13,PC14 and PC15
#define GPIOD	0x40011000 //Partially included in LQFP48, PD0 and PD1
#define GPIOE	0x40011800 //Not included

//-*-*-*-*-*-*-*-*-*-*-*-
//End of Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

#define AFIO	0x40010000

//-*-*-*-*-*-*-*-*-*-*-*-
//End of Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

#define EXTI	0x40010400

//-*-*-*-*-*-*-*-*-*-*-*-
//End of Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//End of Peripheral register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*



#endif
