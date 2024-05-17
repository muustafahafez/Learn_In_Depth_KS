/*************************************************************************************/
/*************************************************************************************/
/*********************   Author: Mustafa Hafez ***************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
#ifndef  _RTOS_PRIVATE
#define  _RTOS_PRIVATE


/* the periodicity in ms unit
 * FirstDelay is to handle the CPU load
 * state used for suspend and Resume tasks
 * PFunc is a pointer to the function of desired task that take nothing and return nothig
 * */
typedef struct {

	uint16_t periodicity;
	uint16_t FirstDelay;
	uint8_t 	state;
	void (*PFunc)(void);


}STask_t;


/*Tasks Statues*/
#define RESUME_TASK		1
#define SUSPEND_TASK	2




static void void_schedular(void);

#endif



