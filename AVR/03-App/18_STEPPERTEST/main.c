/*
 * main.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Kero
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "STEPPER_interface.h"
int main(void)
{

	u16 Local_u16_Degree=270;
	DIO_voidInit();
	STEPPER_u8Rotate(Local_u16_Degree,COUNTER_CLOCKWISE_DIRECTION);

	return 0;
}



