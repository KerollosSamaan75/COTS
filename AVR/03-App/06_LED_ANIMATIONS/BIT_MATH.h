/*
 * BIT_MATH.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Kero
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  SET_BIT(VAR,BIT)     VAR  |=  (1<<(BIT))
#define  CLR_BIT(VAR,BIT)     VAR  &= ~(1<<(BIT))
#define  GET_BIT(VAR,BIT)     (VAR >>  (BIT))&1 )
#define  TOG_BIT(VAR,BIT)     VAR  ^=  (1<<(BIT))


#endif /* BIT_MATH_H_ */
