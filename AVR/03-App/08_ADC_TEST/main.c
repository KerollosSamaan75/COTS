/*
 * main.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Kero
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"

#include <util/delay.h>

int main(void)
{

	u16 App_u16DigitalValue ;
	u32 Local_u32AnalogValue = 0;
	DIO_voidInit();
	ADC_voidInit();
	LCD_voidInit();
	LCD_voidSendStr("VOLTAGE =       mv");
	LCD_u8GoToXY(LCD_u8_LINE_2,0);
	LCD_voidSendStr("TEMP =       'C");
	while(1)
	{
		ADC_u8GetDigitalValueSyncNonBlocking(ADC_u8_CHANNEL_0 ,&App_u16DigitalValue);
		Local_u32AnalogValue = (App_u16DigitalValue * 5000UL) / 1024;
		LCD_u8GoToXY(LCD_u8_LINE_1,10);
		LCD_voidSendNum(Local_u32AnalogValue);
		LCD_u8GoToXY(LCD_u8_LINE_2,7);
		LCD_voidSendNum(Local_u32AnalogValue /10);
		_delay_ms(1000);
	}
	return 0;
}





