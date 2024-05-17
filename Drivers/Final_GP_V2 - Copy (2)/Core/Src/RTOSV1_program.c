/*************************************************************************************/
/*************************************************************************************/
/*********************   Author: Mustafa Hafez ***************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

#include "stdint.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_register.h"

#define NULL	(void*)0

STask_t System_Tasks[TASKNUM] = {{NULL}};




void HAL_IncTick(void)
{

	void_schedular();
}



RTOS_ErrorStatus RTOS_voidNewTask(uint16_t copy_u16Periodicity , uint8_t copy_u8Priorty, void (*Pfunc)(void),uint16_t copy_u16FirstDelay){

	/*check if priority is exist or not*/
	if(System_Tasks[copy_u8Priorty].PFunc==NULL)
	{
		System_Tasks[copy_u8Priorty].periodicity = copy_u16Periodicity;
		System_Tasks[copy_u8Priorty].PFunc = Pfunc;
		System_Tasks[copy_u8Priorty].FirstDelay = copy_u16FirstDelay;
		System_Tasks[copy_u8Priorty].state = RESUME_TASK;
		return RTOS_NoError;
	}
	else
	{
		return RTOS_ErrorPririotyExist;
	}


}


/*=======================================================
 * =====================================================*/
static void void_schedular(void){


	uint8_t Local_u8Ittirate = 0;
	/*check which task achieve the desired tick number*/
	for(Local_u8Ittirate =0 ; Local_u8Ittirate <TASKNUM ; Local_u8Ittirate++)
	{
		/*check if task suspended or not*/
		if(System_Tasks[Local_u8Ittirate].state==RESUME_TASK)
		{

			if(System_Tasks[Local_u8Ittirate].FirstDelay==0)
			{
				if(System_Tasks[Local_u8Ittirate].PFunc!=NULL)
				{
					System_Tasks[Local_u8Ittirate].FirstDelay = System_Tasks[Local_u8Ittirate].periodicity-1;

					System_Tasks[Local_u8Ittirate].PFunc();
				}

			}
			else
			{
				System_Tasks[Local_u8Ittirate].FirstDelay--;
			}
		}
		else
		{
			/*Do nothing*/
		}
	}

}

RTOS_ErrorStatus RTOS_voidDeleteTask(uint8_t copy_u8Priority){

	/*check if the user pass a correct priority*/
	if(copy_u8Priority<TASKNUM)
	{
		System_Tasks[copy_u8Priority].PFunc=NULL;
		return RTOS_TaskDeleted;

	}
	else
	{
		return RTOS_TaskNotDeleted;

	}

}
RTOS_ErrorStatus RTOS_voidResumeTask(uint8_t copy_u8Priority){

	/*check if task exist*/
	if(System_Tasks[copy_u8Priority].PFunc!=NULL)
	{
		System_Tasks[copy_u8Priority].state = RESUME_TASK;
		return RTOS_TaskResumed;

	}
	else {
		return RTOS_TaskResumedFailed;

	}


}
RTOS_ErrorStatus RTOS_voidSuspendTask(uint8_t copy_u8Priority){
	/*check if task exist*/

	if(System_Tasks[copy_u8Priority].PFunc!=NULL)
	{
		System_Tasks[copy_u8Priority].state = SUSPEND_TASK;
		return RTOS_TaskSuspended;

	}
	else {
		return RTOS_TaskSuspendedFailed;

	}


}
