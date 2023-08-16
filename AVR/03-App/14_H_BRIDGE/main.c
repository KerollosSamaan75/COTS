
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
	u8 Local_u8PinValue;
	DIO_voidInit();

	while(1)
	{
		DIO_u8GetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,&Local_u8PinValue);

		if(Local_u8PinValue == DIO_u8_HIGH)
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_HIGH);
		}

		else
		{
		    DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
		    DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_HIGH);
		}

	}
	return 0;
}

