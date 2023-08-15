#ifndef _LIFO_H
#define _LIFO_H



typedef struct{

	unsigned int length;          /*To define the length of LIFO*/
	unsigned int count;           /*To know if we reach the end of LIFO  (count==length?)*/
	unsigned int* head;           /*Increment and decrement with  LIFO*/
	unsigned int* base;           /*Point to the first address*/
}LIFO_t;

typedef enum{
LIFO_NoError,
LIFO_Full,
LIFO_Empty,
LIFO_NULL
}LIFO_Statues_t;


/*Initialization LIFO*/


LIFO_Statues_t LIFO_Init(LIFO_t* lifo,unsigned int* buffer,unsigned int len);
LIFO_Statues_t LIFO_PUSH(LIFO_t* Lifo,unsigned int Item);
LIFO_Statues_t LIFO_POP(LIFO_t* Lifo,unsigned int* Item);



#endif
