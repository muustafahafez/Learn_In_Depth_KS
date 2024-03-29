/*
 * Data_Student.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mustafa Hafez
 */

#ifndef DATA_STUDENT_H_
#define DATA_STUDENT_H_




#define DPRINT(...)			{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}



struct SData {

	uint8_t Name[40];
	uint32_t ID;
	uint8_t Age;
	float Height;

};



struct SStudent_t  {

	struct SData student;
	struct SStudent_t * PNextStudent;

};





void  AddStudent();
void PrintAll();
void DeleteAll();
void DeleteID(uint8_t ID);





#endif /* DATA_STUDENT_H_ */
