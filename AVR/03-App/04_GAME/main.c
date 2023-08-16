/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>

#include"LCD_interface.h"
#include"KPD_interface.h"

int main(void)
{

	DIO_voidInit();
	LCD_voidInit();
	s8 Ball_Location =1;
	u8 KeyValue = KPD_u8_KEY_NOT_PRESSED;
	u8 customChar[] = {0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
	u8 Ball[]       = {0x00,0x04,0x0A,0x15,0x0E,0x04,0x1F,0x00};
	LCD_u8SendSpecialChar(0,customChar);
	LCD_u8SendSpecialChar(1,Ball);
	for(u8 Location = 0; Location < 20 ; Location++)
	{
		LCD_u8GoToXY(LCD_u8_LINE_1,Location);
		LCD_voidSendChar(0);
	}
	LCD_u8GoToXY(LCD_u8_LINE_2,19);
	LCD_voidSendChar(0);
	LCD_u8GoToXY(LCD_u8_LINE_3,19);
	LCD_voidSendChar(0);

	for(s8 Location = 19; Location >= 0 ; Location--)
	{
		LCD_u8GoToXY(LCD_u8_LINE_4,Location);
		LCD_voidSendChar(0);
   }
	LCD_u8GoToXY(LCD_u8_LINE_3,0);
	LCD_voidSendChar(0);
	LCD_u8GoToXY(LCD_u8_LINE_2,0);
	LCD_voidSendChar(0);
	while(1)
	{
		KeyValue = KPD_u8_KEY_NOT_PRESSED;
		/*******************************************************************************************************/
		/**************************************First Line******************************************************/
		/*******************************************************************************************************/
		while( KeyValue != '2' && Ball_Location > 0 && Ball_Location < 19)
		{
			while(KeyValue != '2' && KeyValue != '4' && Ball_Location > 0 && Ball_Location < 19)
			{
				LCD_u8GoToXY(LCD_u8_LINE_2,Ball_Location);
				LCD_voidSendChar(1);
				_delay_ms(50);
				LCD_u8GoToXY(LCD_u8_LINE_2,Ball_Location);
				LCD_voidSendChar(' ');
				Ball_Location++;
				KPD_u8GetKeyState(&KeyValue);
			}


			while(KeyValue != '2' && KeyValue != '6' && Ball_Location > 0 && Ball_Location < 19)
			{
				LCD_u8GoToXY(LCD_u8_LINE_2,Ball_Location);
				LCD_voidSendChar(1);
				_delay_ms(50);
				LCD_u8GoToXY(LCD_u8_LINE_2,Ball_Location);
				LCD_voidSendChar(' ');
				Ball_Location--;
				KPD_u8GetKeyState(&KeyValue);
			}

		}
		/*******************************************************************************************************/
		/**************************************Second Line******************************************************/
		/*******************************************************************************************************/
		while( KeyValue != '8' && Ball_Location > 0 && Ball_Location < 19 )
		{
			while( KeyValue != '8' && KeyValue != '4' && Ball_Location > 0 && Ball_Location < 19 )
			{
				LCD_u8GoToXY(LCD_u8_LINE_3,Ball_Location);
				LCD_voidSendChar(1);
				_delay_ms(50);
				LCD_u8GoToXY(LCD_u8_LINE_3,Ball_Location);
				LCD_voidSendChar(' ');
				Ball_Location++;
				KPD_u8GetKeyState(&KeyValue);
			}

			while( KeyValue != '8' && KeyValue != '6' && Ball_Location > 0 && Ball_Location < 19 )
			{
				LCD_u8GoToXY(LCD_u8_LINE_3,Ball_Location);
				LCD_voidSendChar(1);
				_delay_ms(50);
				LCD_u8GoToXY(LCD_u8_LINE_3,Ball_Location);
				LCD_voidSendChar(' ');
				Ball_Location--;
				KPD_u8GetKeyState(&KeyValue);
			}

		}

		/*******************************************************************************************************/
		/*****************************************Gameover******************************************************/
		/*******************************************************************************************************/
		if(Ball_Location == 0 || Ball_Location == 19)
		{
			LCD_u8GoToXY(LCD_u8_LINE_2,6);
			LCD_voidSendStr("GAMEOVER");
			LCD_u8GoToXY(LCD_u8_LINE_3,6);
			LCD_voidSendStr("TRYAGAIN");

			_delay_ms(2000);

			LCD_u8GoToXY(LCD_u8_LINE_2,6);
			LCD_voidSendStr("        ");
			LCD_u8GoToXY(LCD_u8_LINE_3,6);
			LCD_voidSendStr("         ");


			Ball_Location = 1;
			KeyValue = KPD_u8_KEY_NOT_PRESSED;
		}
	}
	return 0;
}

