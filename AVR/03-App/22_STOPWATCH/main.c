/*
 * main.c
 *
 *  Created on: Oct 27, 2022
 *      Author: Kero
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "GI_interface.h"

#include "LCD_interface.h"
#include "KPD_interface.h"

int main(void)
{
	u8 Local_u8KeyValue;
	u8 Local_Au8Num[6];
	DIO_voidInit();
	GI_voidEnale();
	LCD_voidInit();
	LCD_u8GoToXY(1,4);
	LCD_voidSendStr("StopWatch");
	LCD_u8GoToXY(2,3);
	LCD_voidSendStr("00:00:00");
	while(1);

	//TIMERS_voidTimer0Init();


	return 0;
}
