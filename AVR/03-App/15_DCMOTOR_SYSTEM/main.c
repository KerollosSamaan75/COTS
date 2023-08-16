/*

 * main.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"

#include"LCD_interface.h"
#include"KPD_interface.h"

#define PASSWORD_SIZE      4

int main(void)
{
	u8 Local_u8Key;
	u8 Local_u8LoginFlag=1;
	u8 Local_u8ExitFlag=1;
	u8 Local_u8BackFlag=1;
	u8 Local_u8TryNumber=0;
    u8 Local_Au8PassWord[PASSWORD_SIZE]={'7','5','7','9'};
    u8 Local_Au8Login[PASSWORD_SIZE];
    u8 Local_Index=0;
	DIO_voidInit();
	LCD_voidInit();
    do
    {
    	Local_u8LoginFlag = 1;
    	Local_u8ExitFlag  = 1;
    	Local_u8BackFlag  = 1;
    	u8 Local_Index=0;
        LCD_voidClearScreen();
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
				Local_u8LoginFlag = 0;
				break;
			}
		}
		if(Local_u8LoginFlag == 0)
		{
			Local_u8TryNumber++;
			Local_Index =0;
			_delay_ms(100);
			LCD_voidClearScreen();
			LCD_u8GoToXY(1,1);
			LCD_voidSendStr("Wrong PassWord");
			_delay_ms(500);
			LCD_voidClearScreen();

		}
		else if(Local_u8LoginFlag == 1)
		{
			Local_u8TryNumber =0;
			_delay_ms(100);
			LCD_voidClearScreen();
			LCD_u8GoToXY(1,1);
			LCD_voidSendStr("True PassWord");
			LCD_u8GoToXY(2,0);
			LCD_voidSendStr("Welcome To Motor");
			do
			{
				_delay_ms(300);
				LCD_voidClearScreen();
				LCD_u8GoToXY(1,0);
				LCD_voidSendStr("1.DC Motor");
				LCD_u8GoToXY(2,0);
				LCD_voidSendStr("2.Exit");
				KPD_u8GetKeyState(&Local_u8Key);
				while(Local_u8Key == KPD_u8_KEY_NOT_PRESSED)
				{
					KPD_u8GetKeyState(&Local_u8Key);
				}
				if(Local_u8Key == '2')
				{
					Local_u8ExitFlag=0;
					break;
				}
				else if(Local_u8Key == '1')
				{
					LCD_voidClearScreen();
					LCD_u8GoToXY(1,0);
					LCD_voidSendStr("1.RotCW");
					LCD_u8GoToXY(1,10);
					LCD_voidSendStr("3.Back");
					LCD_u8GoToXY(2,0);
					LCD_voidSendStr("2.RotCCW");
					KPD_u8GetKeyState(&Local_u8Key);
					while(Local_u8Key == KPD_u8_KEY_NOT_PRESSED)
					{
						KPD_u8GetKeyState(&Local_u8Key);
					}

					while((Local_u8Key != '3'))
					{

						if(Local_u8Key == '1')
						{
							DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
							DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
						}
						else if(Local_u8Key == '2')
						{
							DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
							DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
						}
						KPD_u8GetKeyState(&Local_u8Key);
						while(Local_u8Key == KPD_u8_KEY_NOT_PRESSED)
						{
							KPD_u8GetKeyState(&Local_u8Key);
						}
					}
					DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
					DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
					Local_u8BackFlag = 0;
				}
			}while(Local_u8BackFlag == 0);
		}

    }while(((Local_u8LoginFlag == 0 )&&(Local_u8TryNumber < 3))||(Local_u8ExitFlag==0));
    LCD_voidClearScreen();
	LCD_u8GoToXY(1,0);
	LCD_voidSendStr("Reset The System");
	return 0;
}

