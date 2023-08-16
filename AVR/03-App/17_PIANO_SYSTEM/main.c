/*
 * main.c
 *
 *  Created on: May 30, 2023
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include "util/delay.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "KPD_interface.h"


int main(void)
{
	u8 Local_u8KeyValue;
	DIO_voidInit();
	TIMERS_voidTimer0Init();
	TIMERS_voidTimer0Enable();
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8KeyValue);
		if(Local_u8KeyValue == '1')
		{
			TIMERS_voidTimer0SetCompareMatchValue(150);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '2')
		{
			TIMERS_voidTimer0SetCompareMatchValue(207);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '3')
		{
			TIMERS_voidTimer0SetCompareMatchValue(97);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '+')
		{
			TIMERS_voidTimer0SetCompareMatchValue(65);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '4')
		{
			TIMERS_voidTimer0SetCompareMatchValue(80);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '5')
		{
			TIMERS_voidTimer0SetCompareMatchValue(45);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '6')
		{
			TIMERS_voidTimer0SetCompareMatchValue(112);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '-')
		{
			TIMERS_voidTimer0SetCompareMatchValue(23);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '7')
		{
			TIMERS_voidTimer0SetCompareMatchValue(144);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '8')
		{
			TIMERS_voidTimer0SetCompareMatchValue(10);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '9')
		{
			TIMERS_voidTimer0SetCompareMatchValue(176);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '*')
		{
			TIMERS_voidTimer0SetCompareMatchValue(223);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '0')
		{
			TIMERS_voidTimer0SetCompareMatchValue(208);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '=')
		{
			TIMERS_voidTimer0SetCompareMatchValue(132);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '/')
		{
			TIMERS_voidTimer0SetCompareMatchValue(78);
			_delay_ms(200);
		}
		else if(Local_u8KeyValue == '%')
		{
			TIMERS_voidTimer0SetCompareMatchValue(255);
			_delay_ms(200);
		}
		else
		{
			TIMERS_voidTimer0SetCompareMatchValue(0);
		}
}
	return 0;
}


