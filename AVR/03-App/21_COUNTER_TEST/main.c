/*
 * main.c
 *
 *  Created on: Oct 24, 2022
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "GI_interface.h"

#include "LCD_interface.h"


int main(void)
{
	u8 Local_u8Counter = 100;
	DIO_voidInit();
	LCD_voidInit();
	TIMERS_voidTimer0Init();
	LCD_u8GoToXY(1,4);

	LCD_voidSendStr("Counter");

	while(1)
	{
		TIMERS_u8Timer0Count(&Local_u8Counter);

			LCD_u8GoToXY(2,5);
			LCD_voidSendNum(Local_u8Counter);
	}
	return 0;
}


