/*
 * main.c
 *
 *  Created on: Oct 12, 2022
 *      Author: Kero
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "ADC_interface.h"

#include "LCD_interface.h"

int main(void)
{
	u16 App_u16DigitalValue;
	u16 Local_u16AnalogValue;
	u16 Temperature;
	DIO_voidInit();
	ADC_voidInit();
	LCD_voidInit();
	while(1)
	{
		ADC_u8GetDigitalValueSyncNonBlocking(ADC_u8_CHANNEL_0 ,&App_u16DigitalValue);
		Local_u16AnalogValue = (App_u16DigitalValue * 5000UL) / 1024;
		Temperature = Local_u16AnalogValue /10;
		if(Local_u16AnalogValue <= 3000 )
		{

			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			LCD_voidClearScreen();
			LCD_voidSendStr("Good Morning");
			_delay_ms(500);

		}
		else if(Local_u16AnalogValue > 3000 )
		{
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			LCD_voidClearScreen();
			LCD_voidSendStr("Good Night");
			_delay_ms(500);
		}

	}

	return 0;
}
