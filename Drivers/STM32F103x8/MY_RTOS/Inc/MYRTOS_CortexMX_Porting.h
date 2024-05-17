/*
 * MYRTOS_CortexMX_Porting.h
 *
 *  Created on: Jan 30, 2024
 *      Author: Mustafa Hafez
 */

#ifndef MYRTOS_CORTEXMX_PORTING_H_
#define MYRTOS_CORTEXMX_PORTING_H_


//To help in locating Threads(Tasks) and switching context of them
#define OS_SET_PSP(add)
#define OS_GET_PSP(add)

//MSP for OS and PSP for Threads
#define OS_SWITCH_SP_TO_MSP
#define OS_SWITCH_SP_TO_PSP


/*In privilege mode , you have access to all of REGs*/
#define OS_SWITCH_TO_PRIVILLAGE
#define OS_SWITCH_TO_UNPRIVILLAGE



//Some CortexM Instruction set:
/*
 * mrs: read from special register
 * msr: Write to special register
 * mov: Move from source to destination
 *
 * */


#endif /* MYRTOS_CORTEXMX_PORTING_H_ */
