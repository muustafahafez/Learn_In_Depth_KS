
#include "LIFO_h.h"
#include <stdint.h>

LIFO_Statues_t LIFO_Init(LIFO_t* lifo,unsigned int* buffer,unsigned int len){

	//check if the LIFO not exist
	if (buffer==NULL)
		return LIFO_NULL;

	lifo->base = buffer;
	lifo->head = buffer;
	lifo->count=0;
	lifo->length =len;

	return LIFO_NoError;
}


LIFO_Statues_t LIFO_PUSH(LIFO_t* Lifo,unsigned int Item){

	//check if LIFO not exist
	if (Lifo->base==NULL)
		return LIFO_NULL;
	//check if LIFO is FULL
	if (Lifo->count== Lifo->length)
		return LIFO_Full;
	*(Lifo->head)=Item;
	 (Lifo->head)++;
	 Lifo->count++;
	return LIFO_NoError;

}
LIFO_Statues_t LIFO_POP(LIFO_t* Lifo,unsigned int* Item){

	//check if LIFO not exist
	if (Lifo->base==NULL)
		return LIFO_NULL;
	//check if LIFO is Empty
	if (Lifo->count== 0)
		return LIFO_Empty;
	Lifo->head--;
	Lifo->count--;
	*Item=*(Lifo->head);
	return LIFO_NoError;
}
