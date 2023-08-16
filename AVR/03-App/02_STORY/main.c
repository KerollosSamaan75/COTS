/*
 * main.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Kirollos
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"

int main(void)
{
	DIO_voidInit();
	LCD_voidInit();
	u32 Time_Out = 0;
	u8 person[8]  = {0x0E,0x0E,0x05,0x0E,0x14,0x04,0x0E,0x15};
	u8 person2[8] = {0x07,0x07,0x12,0x0E,0x09,0x14,0x12,0x00};
	u8 ball[8]    = {0x0, 0x00,0x04,0x0A,0x11,0x0A,0x04,0x00};
  	u8 arr4[8]    = {0x1F,0x08,0x04,0x02,0x1F,0x00,0x00,0x00};
   	u8 arr3[8]    = {0x00,0x00,0x01,0x01,0x1F,0x00,0x0C,0x00};
   	u8 arr2[8]    = {0x00,0x00,0x01,0x01,0x01,0x02,0x1C,0x00};
   	u8 arr1[8]    = {0x00,0x1F,0x11,0x1F,0x01,0x02,0x1C,0x00};
	LCD_u8GoToXY(2,7);
	LCD_voidSendStr("HELLO");
	LCD_u8GoToXY(3,5);
	LCD_voidSendStr("VALEO TEAM");
	_delay_ms(1000);
	LCD_voidClearScreen();
	for( u8 Location = 0; Location <10 ;Location++)
	{
		LCD_u8SendSpecialChar(0,person,2,Location);
		_delay_ms(20);
		LCD_u8GoToXY(2,Location);
		LCD_voidSendChar(' ');
	}
	LCD_u8SendSpecialChar(0,person,2,10);
	LCD_u8GoToXY(3,3);
	LCD_voidSendStr("MY NAME IS KERO");
	LCD_u8SendSpecialChar(4,arr4,4,12);
	LCD_u8SendSpecialChar(3,arr3,4,11);
	LCD_u8SendSpecialChar(2,arr2,4,10);
	LCD_u8SendSpecialChar(1,arr1,4,9);
	_delay_ms(1000);
	LCD_voidClearScreen();
	LCD_u8GoToXY(3,1);
	LCD_voidSendStr("I PLAYING FOOTBALL");
	_delay_ms(100);
	for( u8 Location = 0; Location <10 ;Location++)
	{
		LCD_u8SendSpecialChar(0,person2,1,Location);
		LCD_u8SendSpecialChar(5,ball,1,Location+1);
		_delay_ms(20);
		LCD_u8GoToXY(1,Location);
		LCD_voidSendChar(' ');
		LCD_u8GoToXY(1,Location+1);
		LCD_voidSendChar(' ');
	}
	LCD_voidClearScreen();
	LCD_u8GoToXY(3,3);
	LCD_voidSendStr("I LOVE RUNNING");
	for( u8 Location = 0; Location <10 ;Location++)
	{
		LCD_u8SendSpecialChar(0,person2,1,Location);
		_delay_ms(20);
		LCD_u8GoToXY(1,Location);
		LCD_voidSendChar(' ');
	}
	LCD_voidClearScreen();
	LCD_u8SendSpecialChar(0,person,2,10);
	LCD_u8GoToXY(3,3);
	LCD_voidSendStr("THIS IS MY STORY");
	_delay_ms(1000);
	LCD_voidClearScreen();
	LCD_u8SendSpecialChar(0,person,2,10);
	LCD_u8GoToXY(3,0);
	LCD_voidSendStr("IAM GLAD TO SEE YOU");
	_delay_ms(1000);
	LCD_voidClearScreen();
	LCD_u8GoToXY(2,6);
	LCD_voidSendStr("GOOD BYE");
	LCD_u8GoToXY(3,5);
	LCD_voidSendStr("VALEO TEAM");

}

