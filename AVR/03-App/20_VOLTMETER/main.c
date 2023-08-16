/*
 * main.c
 *
 *  Created on: Oct 12, 2022
 *      Author: Kero
 */

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
#include "KPD_interface.h"

int main(void)
{
	u8 Local_u8KeyValue;
	u16 Local_u16DigitalValue;
	u16 Local_u16AnalogValue;
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	while(1)
	{
		LCD_voidClearScreen();
		LCD_voidSendStr("1-Volttmeter");
		LCD_u8GoToXY(2,0);
		LCD_voidSendStr("2-Ohmmeter");
		KPD_u8GetKeyState(&Local_u8KeyValue);
		while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
		{
			KPD_u8GetKeyState(&Local_u8KeyValue);
		}

		if(Local_u8KeyValue == '1')
		{
			LCD_voidClearScreen();
			LCD_voidSendStr("Voltage=      mV");
			LCD_u8GoToXY(2,0);
			LCD_voidSendStr("3-Back");
			while(Local_u8KeyValue != '3')
			{

				ADC_u8GetDigitalValueSyncNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
				Local_u16AnalogValue = (Local_u16DigitalValue * 5000UL)/1024;
				LCD_u8GoToXY(1,9);
				LCD_voidSendNum(Local_u16AnalogValue);
				_delay_ms(100);
				KPD_u8GetKeyState(&Local_u8KeyValue);
            }
		}
		else if(Local_u8KeyValue == '2')
		{
			LCD_voidClearScreen();
			LCD_voidSendStr("RES=     Ohm");
			LCD_u8GoToXY(2,0);
			LCD_voidSendStr("3-Back");
			while(Local_u8KeyValue != '3')
			{
				ADC_u8GetDigitalValueSyncNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
				Local_u16AnalogValue = (Local_u16DigitalValue * 5000UL)/1024;
				LCD_u8GoToXY(1,5);
				LCD_voidSendNum((Local_u16AnalogValue /10));
				_delay_ms(100);
				KPD_u8GetKeyState(&Local_u8KeyValue);
			}
		}

	}
	return 0;
}

