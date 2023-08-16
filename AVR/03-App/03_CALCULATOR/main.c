/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include"LCD_interface.h"
#include"KPD_interface.h"

int main(void)
{
	u8 Local_u8Key = KPD_u8_KEY_NOT_PRESSED;
	DIO_voidInit();
	LCD_voidInit();
	u8 Local_Au8Equation[10];
	u8 Local_Index=0;
        u8 Local_u8Sign;
        u8 Local_u8SignOrder;
        u32 Local_u8FirstNum=0;
        u32 Local_u8SecNum=0;
        u32 Local_u8FullyNum=0;
	do
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if((Local_u8Key != KPD_u8_KEY_NOT_PRESSED) && ((Local_u8Key >= '0') ||(Local_u8Key <='9')))
		{
			LCD_voidSendChar(Local_u8Key);
			Local_Au8Equation[Local_Index] = Local_u8Key;
			Local_Index++;
		}

	}while(Local_u8Key != '=');

	for(int i=0;i<Local_Index-1;i++)
	{
		if((Local_Au8Equation[i] =='+')||(Local_Au8Equation[i] =='-')||(Local_Au8Equation[i] =='*')||(Local_Au8Equation[i] =='/')||(Local_Au8Equation[i] =='%'))
		{
			Local_u8Sign = Local_Au8Equation[i];
			Local_u8SignOrder = i;
			break;
		}
	}
	for(int i=0;i<Local_u8SignOrder;i++)
	{
		 Local_u8FirstNum =(Local_u8FirstNum *10)+(Local_Au8Equation[i]-'0');
	}
	for(int i=Local_u8SignOrder+1;i<Local_Index-1;i++)
	{
		 Local_u8SecNum =(Local_u8SecNum *10)+(Local_Au8Equation[i]-'0');
	}
	switch(Local_u8Sign)
	{
		case'+':{
					Local_u8FullyNum = Local_u8FirstNum + Local_u8SecNum;
					LCD_voidClearScreen();
					LCD_voidSendNum(Local_u8FullyNum);
				 }break;

		case'-':{
					Local_u8FullyNum = Local_u8FirstNum - Local_u8SecNum;
					LCD_voidClearScreen();
					LCD_voidSendNum(Local_u8FullyNum);
				}break;

		case'*':{
					Local_u8FullyNum = Local_u8FirstNum * Local_u8SecNum;
					LCD_voidClearScreen();
					LCD_voidSendNum(Local_u8FullyNum);
				}break;

		case'/':{
				   if(Local_u8SecNum == 0)
				   {
					  LCD_voidSendStr("ERROR");
				   }
				   else
				   {
					   Local_u8FullyNum = Local_u8FirstNum / Local_u8SecNum;
					   LCD_voidClearScreen();
					   LCD_voidSendNum(Local_u8FullyNum);
				   }
				}break;

		case'%':{
				  Local_u8FullyNum = Local_u8FirstNum % Local_u8SecNum;
				  LCD_voidClearScreen();
				  LCD_voidSendNum(Local_u8FullyNum);
				}break;
	}

	Local_u8Key = KPD_u8_KEY_NOT_PRESSED;
	while(1)
	{
		Local_u8FirstNum = Local_u8FullyNum;
		Local_u8Sign = KPD_u8_KEY_NOT_PRESSED;

		while(Local_u8Sign == KPD_u8_KEY_NOT_PRESSED)
		{
			KPD_u8GetKeyState(&Local_u8Sign);
		}
		LCD_voidSendChar(Local_u8Sign);

		Local_u8Key = KPD_u8_KEY_NOT_PRESSED;
		Local_u8SecNum=0;
		while(Local_u8Key != '=')
		{
			KPD_u8GetKeyState(&Local_u8Key);
			if((Local_u8Key != KPD_u8_KEY_NOT_PRESSED) && (Local_u8Key != '='))
			{
				Local_u8SecNum =(Local_u8SecNum *10)+(Local_u8Key-'0');
				LCD_voidSendChar(Local_u8Key);
			}
		}
		LCD_voidSendChar('=');
		switch(Local_u8Sign)
		{
			case'+':{
						Local_u8FullyNum = Local_u8FirstNum + Local_u8SecNum;
						LCD_voidClearScreen();
						LCD_voidSendNum(Local_u8FullyNum);
					 }break;

			case'-':{
						Local_u8FullyNum = Local_u8FirstNum - Local_u8SecNum;
						LCD_voidClearScreen();
						LCD_voidSendNum(Local_u8FullyNum);
					}break;

			case'*':{
						Local_u8FullyNum = Local_u8FirstNum * Local_u8SecNum;
						LCD_voidClearScreen();
						LCD_voidSendNum(Local_u8FullyNum);
					}break;

			case'/':{
					   if(Local_u8SecNum == 0)
					   {
						  LCD_voidSendStr("ERROR");
					   }
					   else
					   {
						   Local_u8FullyNum = Local_u8FirstNum / Local_u8SecNum;
						   LCD_voidClearScreen();
						   LCD_voidSendNum(Local_u8FullyNum);
					   }
					}break;

			case'%':{
					  Local_u8FullyNum = Local_u8FirstNum % Local_u8SecNum;
					  LCD_voidClearScreen();
					  LCD_voidSendNum(Local_u8FullyNum);
					}break;
		}
	}

	return 0;
}

