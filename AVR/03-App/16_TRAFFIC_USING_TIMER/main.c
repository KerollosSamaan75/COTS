/*
 * main.c
 *
 *  Created on: May 18, 2023
 *      Author: Kero
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "GI_interface.h"

#include "LCD_interface.h"

volatile unsigned char counter1=0;
volatile unsigned char counter_green=10;
volatile unsigned char counter_yellow=5;
volatile unsigned char counter_red=7;

void App_voidIncrease_Counter(void);

int main(void)
{
	DIO_voidInit();
	LCD_voidInit();
	TIMERS_u8Timer0SetCallBack(&App_voidIncrease_Counter);
	TIMERS_voidTimer0Init();
	GI_voidEnale();

	while(1)
	{
		counter_green=10;
		counter_yellow=5;
		counter_red=7;
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);  //red
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);  //Green

		LCD_voidClearScreen();
		LCD_voidSendStr("remaining 10 sec");
		while(counter_green > 0)
		{
			if(counter1 == 100)
			{
				counter1=0;
				counter_green--;
				LCD_u8GoToXY(1,10);
				LCD_voidSendChar(' ');
				LCD_voidSendChar((counter_green%10)+48);
			}
		}

		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);  //Green
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);  //yellow
		LCD_voidClearScreen();
	    LCD_voidSendStr("remaining 5 sec");

		while(counter_yellow > 0)
		{
			if(counter1 == 100)
			{
				counter1=0;
				counter_yellow--;
				LCD_u8GoToXY(1,10);
				LCD_voidSendChar((counter_yellow%10)+48);
			}
		}
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);  //yellow
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);  //red
		LCD_voidClearScreen();
		LCD_voidSendStr("remaining 7 sec");

		while(counter_red > 0)
		{
			if(counter1 == 100)
			{
				counter1=0;
				counter_red--;
				LCD_u8GoToXY(1,10);
				LCD_voidSendChar((counter_red%10)+48);
			}
		}
	}
	return 0;
}

void App_voidIncrease_Counter(void)
{
	counter1++;
}


