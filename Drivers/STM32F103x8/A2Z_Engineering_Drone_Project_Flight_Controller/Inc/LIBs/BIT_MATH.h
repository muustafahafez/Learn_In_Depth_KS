/*
 * BIT_MATH.h
 *
 *  Created on: Apr 3, 2024
 *      Author: Mustafa Hafez
 */

#ifndef INC_BIT_MATH_H_
#define INC_BIT_MATH_H_



#define SET_BIT(REG, BIT)  			REG |=(1<<BIT)

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1<<BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

//((REG) |= (BIT))
#endif /* INC_BIT_MATH_H_ */
