/*
 * main.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"

int main()
{
	DIO_voidInit();

	while(1)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		_delay_ms(1000);
	}
	return 0;
}
