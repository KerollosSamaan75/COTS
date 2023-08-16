/*

 * main.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include"LCD_interface.h"
#include"KPD_interface.h"

#define PASSWORD_SIZE      4

int main(void)
{
	u8 Local_u8Key;
	u8 Local_u8Flag=1;
    u8 Local_Au8PassWord[PASSWORD_SIZE]={'7','5','7','9'};
    u8 Local_Au8Login[PASSWORD_SIZE];
    u8 Local_Index=0;
	DIO_voidInit();
	LCD_voidInit();
	LCD_voidSendStr("PassWord:");
	while(Local_Index < PASSWORD_SIZE )
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
		{
			LCD_voidSendChar(Local_u8Key);
			Local_Au8Login[Local_Index] = Local_u8Key;
			Local_Index++;
		}
	}
	for(int i=0 ;i<PASSWORD_SIZE ;i++)
	{
		if(Local_Au8Login[i] != Local_Au8PassWord[i] )
		{
			Local_u8Flag = 0;
			break;
		}
	}
	if(Local_u8Flag == 0)
	{
		LCD_voidClearScreen();
		LCD_u8GoToXY(1,1);
		LCD_voidSendStr("Wrong PassWord");
	}
	else
	{
		LCD_voidClearScreen();
		LCD_u8GoToXY(1,1);
		LCD_voidSendStr("True PassWord");
		LCD_u8GoToXY(2,4);
		LCD_voidSendStr("Welcome");
	}
	return 0;
}

