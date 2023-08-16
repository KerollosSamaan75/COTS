/*
 * main.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Kerollos
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include "util/delay.h"

#include "DIO_interface.h"
#include "TWI_interface.h"
#include "SPI_interface.h"

#include "LCD_interface.h"
#include "KPD_interface.h"
#include "EEPROM_interface.h"

#include "main_config.h"

int main(void)
{
	u8 Local_u8KeyValue;
	u8 Local_u8ReadingByte;
	u8 Local_u8PassFlag=0;
	u8 Local_u8TryNum=0;
	u8 Local_u8Index=0;
	u8 Local_u8AirCondPower=AIR_CONDITION_POWER_OFF;
	u32 Local_u32Time_Out=0;
	u8 Local_u8AdminPass[4];
	u8 Local_u8GuestPass[4];
	u8 Local_u8TemperatureValue=0;
	DIO_voidInit();
	TWI_voidMasterInit();
	SPI_voidInit();
	LCD_voidInit();
	LCD_voidSendStr("Welcome To Smart");
	LCD_u8GoToXY(2,6);
	LCD_voidSendStr("Home");
	_delay_ms(500);
/*********************************Admin Set Password*****************************/
	EEPROM_u8ReadDataByte(0,&Local_u8ReadingByte);
	if(Local_u8ReadingByte == 0xff)
	{
		_delay_ms(1000);
		LCD_voidClearScreen();
		LCD_u8GoToXY(1,1);
		LCD_voidSendStr("Login For First");
		LCD_u8GoToXY(2,6);
		LCD_voidSendStr("Time");
		_delay_ms(1000);
		LCD_voidClearScreen();
		LCD_voidSendStr("Set Admin Pass");
		LCD_u8GoToXY(2,0);
		LCD_voidSendStr("Admin pass:");
		for(u8 i = 0 ;i < 4 ;i++)
		{
			KPD_u8GetKeyState(&Local_u8KeyValue);
			while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
			{
				KPD_u8GetKeyState(&Local_u8KeyValue);
			}
			EEPROM_u8WriteDataByte(i,Local_u8KeyValue);
			LCD_u8GoToXY(2,11+i);
			LCD_voidSendChar(Local_u8KeyValue);
			_delay_ms(100);
			LCD_u8GoToXY(2,11+i);
			LCD_voidSendChar('*');
		}
		LCD_voidClearScreen();
		LCD_voidSendStr("Pass Saved");
	}
/*****************************************************************************************/

/****************Set Guest Password*******************************************************/
	EEPROM_u8ReadDataByte(4,&Local_u8ReadingByte);
		if(Local_u8ReadingByte == 0xff)
		{
		    _delay_ms(1000);
			LCD_voidClearScreen();
			LCD_voidSendStr("Set Guest Pass");
			LCD_u8GoToXY(2,0);
			LCD_voidSendStr("Guest pass:");
			for(u8 i = 0 ;i < 4 ;i++)
			{
				KPD_u8GetKeyState(&Local_u8KeyValue);
				while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
				{
					KPD_u8GetKeyState(&Local_u8KeyValue);
				}
				EEPROM_u8WriteDataByte(i+4,Local_u8KeyValue);
				LCD_u8GoToXY(2,11+i);
				LCD_voidSendChar(Local_u8KeyValue);
				_delay_ms(100);
				LCD_u8GoToXY(2,11+i);
				LCD_voidSendChar('*');
			}
			LCD_voidClearScreen();
			LCD_voidSendStr("Pass Saved");
		}
/*****************************************************************************************************/
/************************Select Mood************************************************/
		while(1)
		{
			DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_LOW);
			Local_u8PassFlag  = 0;
			Local_u32Time_Out = 0;

			LCD_voidClearScreen();
			LCD_voidSendStr("Select Mood:");
			LCD_u8GoToXY(2,0);
			LCD_voidSendStr("1:Admin");
			LCD_u8GoToXY(2,8);
			LCD_voidSendStr("2:Guest");
	/***********************************************************************************/
		KPD_u8GetKeyState(&Local_u8KeyValue);
		while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
		{
			KPD_u8GetKeyState(&Local_u8KeyValue);
		}
		/*****************************************Admin Mood***************************************/
		if(Local_u8KeyValue == '1')
		{
		   DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_HIGH);
		   while(Local_u8PassFlag == 0 && Local_u8TryNum < 3)
		   {
				Local_u8PassFlag =1;
				LCD_voidClearScreen();
				LCD_voidSendStr("Admin Pass:");
				for(u8 i = 0 ;i < 4 ;i++)
				{
					KPD_u8GetKeyState(&Local_u8KeyValue);
					while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
					{
						KPD_u8GetKeyState(&Local_u8KeyValue);
					}
					Local_u8AdminPass[i]=Local_u8KeyValue;
					LCD_u8GoToXY(1,11+i);
					LCD_voidSendChar(Local_u8KeyValue);
					_delay_ms(100);
					LCD_u8GoToXY(1,11+i);
					LCD_voidSendChar('*');
				}

				for(u8 i = 0 ;i < 4 ;i++)
				{
					EEPROM_u8ReadDataByte(i,&Local_u8ReadingByte);
					if(Local_u8ReadingByte != Local_u8AdminPass[i])
					{
						Local_u8PassFlag =0;
						Local_u8TryNum++;
						break;
					}
				}

				if(Local_u8PassFlag == 0 && Local_u8TryNum < 3)
				{
					LCD_voidClearScreen();
					LCD_u8GoToXY(1,0);
					LCD_voidSendStr("Wrong PassWord");
					LCD_u8GoToXY(2,0);
					LCD_voidSendStr("Tries Left:");
					LCD_u8GoToXY(2,12);
					LCD_voidSendNum(3-Local_u8TryNum);
					_delay_ms(1000);
				}
		   }

		   if(Local_u8TryNum == 3)
		   {
			   DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_LOW);
			   DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
			   Local_u8TryNum = 0;
			   LCD_voidClearScreen();
			   LCD_voidSendStr("Waiting For   S");
			   for( u8 i = 5; i > 0; i--)
			   {
				   LCD_u8GoToXY(1,12);
				   LCD_voidSendNum(i);
				   _delay_ms(1000);
			   }
		   }

		   else if(Local_u8PassFlag == 1)
		   {

			  Local_u8TryNum = 0;
			  LCD_voidClearScreen();
			  LCD_u8GoToXY(1,2);
			  LCD_voidSendStr("Welcome Admin");
			  _delay_ms(500);
			  while(Local_u32Time_Out < MAX_TIME )
			  {
				  LCD_voidClearScreen();
				  LCD_voidSendStr("1:Room1");
				  LCD_u8GoToXY(1,9);
				  LCD_voidSendStr("2:Room2");
				  LCD_u8GoToXY(2,0);
				  LCD_voidSendStr("3:Room3");
				  LCD_u8GoToXY(2,9);
				  LCD_voidSendStr("4:More");
				  KPD_u8GetKeyState(&Local_u8KeyValue);
				  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED  && Local_u32Time_Out < MAX_TIME)
				  {
					  KPD_u8GetKeyState(&Local_u8KeyValue);
					  Local_u32Time_Out++;
				  }
				  if(Local_u8KeyValue == '4')
				  {
					  while(Local_u8KeyValue != '3')
					  {
						  LCD_voidClearScreen();
						  LCD_voidSendStr("1:Air Condition");
						  LCD_u8GoToXY(2,0);
						  LCD_voidSendStr("2:TV");
						  LCD_u8GoToXY(2,8);
						  LCD_voidSendStr("3:Back");
						  KPD_u8GetKeyState(&Local_u8KeyValue);
						  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
						  {
							  KPD_u8GetKeyState(&Local_u8KeyValue);
						  }
						  if(Local_u8KeyValue == '1')
						  {
							  while(Local_u8KeyValue != '3')
							  {
								  LCD_voidClearScreen();
								  LCD_voidSendStr("1:Set Temperature");
								  LCD_u8GoToXY(2,0);
								  LCD_voidSendStr("2:Control");
								  LCD_u8GoToXY(2,10);
								  LCD_voidSendStr("3:Back");
								  KPD_u8GetKeyState(&Local_u8KeyValue);
								  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
								  {
									  KPD_u8GetKeyState(&Local_u8KeyValue);
								  }
								  if(Local_u8KeyValue == '1')
								  {
									  Local_u8Index = 0;
									  Local_u8TemperatureValue =0;
									  LCD_voidClearScreen();
									  LCD_voidSendStr("Set Temp:  `C");
									  while(Local_u8Index < 2)
									  {
										  KPD_u8GetKeyState(&Local_u8KeyValue);
										  while( Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
										  {
											  KPD_u8GetKeyState(&Local_u8KeyValue);
										  }
										  LCD_u8GoToXY(1,9+Local_u8Index);
										  LCD_voidSendChar(Local_u8KeyValue);
										  Local_u8TemperatureValue = ((Local_u8TemperatureValue*10)+(Local_u8KeyValue -'0'));
										  Local_u8Index++;
									  }
									  SPI_voidSendSlaveByte(Local_u8TemperatureValue);
									  _delay_ms(500);
									  LCD_voidClearScreen();
									  LCD_voidSendStr("Temperature Send");
									  LCD_u8GoToXY(2,0);
									  LCD_voidSendStr("Temp =  `C");
									  LCD_u8GoToXY(2,6);
									  LCD_voidSendNum(Local_u8TemperatureValue);
									  _delay_ms(1000);
								  }
								  else if(Local_u8KeyValue == '2')
								  {
									  while(Local_u8KeyValue != '0')
									  {
										  LCD_voidClearScreen();
										  LCD_voidSendStr("Air Condition");
										  LCD_u8GoToXY(2,0);
										  LCD_voidSendStr("1-On");
										  LCD_u8GoToXY(2,5);
										  LCD_voidSendStr("2-Off");
										  LCD_u8GoToXY(2,11);
										  LCD_voidSendStr("0-Back");
										  KPD_u8GetKeyState(&Local_u8KeyValue);
										  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
										  {
											  KPD_u8GetKeyState(&Local_u8KeyValue);
										  }
										  if(Local_u8KeyValue == '1')
										  {
											  SPI_voidSendSlaveByte(AIR_CONDITION_POWER_ON);
										  }
										  else if(Local_u8KeyValue == '2')
										  {
											  SPI_voidSendSlaveByte(AIR_CONDITION_POWER_OFF);
										  }
									  }
								  }
							  }
							  KPD_u8GetKeyState(&Local_u8KeyValue);

						  }
						  else if(Local_u8KeyValue == '2')
						  {
							  while(Local_u8KeyValue != '0')
							  {
								  LCD_voidClearScreen();
								  LCD_voidSendStr("Television");
								  LCD_u8GoToXY(2,0);
								  LCD_voidSendStr("1-On");
								  LCD_u8GoToXY(2,5);
								  LCD_voidSendStr("2-Off");
								  LCD_u8GoToXY(2,11);
								  LCD_voidSendStr("0-Back");
								  KPD_u8GetKeyState(&Local_u8KeyValue);
								  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
								  {
									  KPD_u8GetKeyState(&Local_u8KeyValue);
								  }
								  if(Local_u8KeyValue == '1')
								  {
									 SPI_voidSendSlaveByte(TV_TURN_ON);
								  }
								  else if(Local_u8KeyValue == '2')
								  {
									  SPI_voidSendSlaveByte(TV_TURN_OFF);
								  }
							  }
						  }
					  }
					  Local_u32Time_Out = 0;
				  }
				  else if(Local_u8KeyValue == '1')
				  {
					  while(Local_u8KeyValue != '0')
					  {
						  LCD_voidClearScreen();
						  LCD_voidSendStr("Room1");
						  LCD_u8GoToXY(2,0);
						  LCD_voidSendStr("1-On");
						  LCD_u8GoToXY(2,5);
						  LCD_voidSendStr("2-Off");
						  LCD_u8GoToXY(2,11);
						  LCD_voidSendStr("0-Back");
						  KPD_u8GetKeyState(&Local_u8KeyValue);
						  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
						  {
							  KPD_u8GetKeyState(&Local_u8KeyValue);
						  }
						  if(Local_u8KeyValue == '1')
						  {
							 SPI_voidSendSlaveByte(ROOM_1_TURN_ON);
						  }
						  else if(Local_u8KeyValue == '2')
						  {
							  SPI_voidSendSlaveByte(ROOM_1_TURN_OFF);
						  }
					  }
					  Local_u32Time_Out = 0;
				  }

				  else if(Local_u8KeyValue == '2')
				  {
					  while(Local_u8KeyValue != '0')
					  {
						  LCD_voidClearScreen();
						  LCD_voidSendStr("Room2");
						  LCD_u8GoToXY(2,0);
						  LCD_voidSendStr("1-On");
						  LCD_u8GoToXY(2,5);
						  LCD_voidSendStr("2-Off");
						  LCD_u8GoToXY(2,11);
						  LCD_voidSendStr("0-Back");
						  KPD_u8GetKeyState(&Local_u8KeyValue);
						  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
						  {
							  KPD_u8GetKeyState(&Local_u8KeyValue);
						  }
						  if(Local_u8KeyValue == '1')
						  {
							  SPI_voidSendSlaveByte(ROOM_2_TURN_ON);
						  }
						  else if(Local_u8KeyValue == '2')
						  {
							  SPI_voidSendSlaveByte(ROOM_2_TURN_OFF);
						  }
					  }
					  Local_u32Time_Out = 0;
				  }

				  else if(Local_u8KeyValue == '3')
				  {
					  while(Local_u8KeyValue != '0')
					  {
						  LCD_voidClearScreen();
						  LCD_voidSendStr("Room3");
						  LCD_u8GoToXY(2,0);
						  LCD_voidSendStr("1-On");
						  LCD_u8GoToXY(2,5);
						  LCD_voidSendStr("2-Off");
						  LCD_u8GoToXY(2,11);
						  LCD_voidSendStr("0-Back");
						  KPD_u8GetKeyState(&Local_u8KeyValue);
						  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
						  {
							  KPD_u8GetKeyState(&Local_u8KeyValue);
						  }
						  if(Local_u8KeyValue == '1')
						  {
							  SPI_voidSendSlaveByte(ROOM_3_TURN_ON);
						  }
						  else if(Local_u8KeyValue == '2')
						  {
							  SPI_voidSendSlaveByte(ROOM_3_TURN_OFF);
						  }
					  }
					  Local_u32Time_Out = 0;
				  }
			  }
	      }
		}
	/********************************************************************************************************/
	/********************************guest Mood**************************************************************/
	   else if(Local_u8KeyValue == '2')
		{
		   DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
		   while(Local_u8PassFlag == 0 && Local_u8TryNum < 3)
		   {
				Local_u8PassFlag =1;
				LCD_voidClearScreen();
				LCD_voidSendStr("Guest Pass:");
				for(u8 i = 0 ;i < 4 ;i++)
				{
					KPD_u8GetKeyState(&Local_u8KeyValue);
					while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
					{
						KPD_u8GetKeyState(&Local_u8KeyValue);
					}
					Local_u8GuestPass[i]=Local_u8KeyValue;
					LCD_u8GoToXY(1,11+i);
					LCD_voidSendChar(Local_u8KeyValue);
					_delay_ms(100);
					LCD_u8GoToXY(1,11+i);
					LCD_voidSendChar('*');
				}

				for(u8 i = 0 ;i < 4 ;i++)
				{
					EEPROM_u8ReadDataByte(i+4,&Local_u8ReadingByte);
					if(Local_u8ReadingByte != Local_u8GuestPass[i])
					{
						Local_u8PassFlag =0;
						Local_u8TryNum++;
						break;
					}
				}

				if(Local_u8PassFlag == 0 && Local_u8TryNum < 3)
				{
					LCD_voidClearScreen();
					LCD_u8GoToXY(1,0);
					LCD_voidSendStr("Wrong PassWord");
					LCD_u8GoToXY(2,0);
					LCD_voidSendStr("Tries Left:");
					LCD_u8GoToXY(2,12);
					LCD_voidSendNum(3-Local_u8TryNum);
					_delay_ms(1000);
				}
		   }

		   if(Local_u8TryNum == 3)
		   {
			   DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_LOW);
			   DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
			   Local_u8TryNum = 0;
			   LCD_voidClearScreen();
			   LCD_voidSendStr("Waiting For   S");
			   for( u8 i = 5; i > 0; i--)
			   {
				   LCD_u8GoToXY(1,12);
				   LCD_voidSendNum(i);
				   _delay_ms(1000);
			   }
		   }

		   else if(Local_u8PassFlag == 1)
		   {

			  Local_u8TryNum = 0;
			  LCD_voidClearScreen();
			  LCD_u8GoToXY(1,2);
			  LCD_voidSendStr("Welcome Guest");
			  _delay_ms(500);
			  KPD_u8GetKeyState(&Local_u8KeyValue);
			  while(Local_u32Time_Out < MAX_TIME && Local_u8KeyValue != '4')
			  {
				  LCD_voidClearScreen();
				  LCD_voidSendStr("1:Room1");
				  LCD_u8GoToXY(1,9);
				  LCD_voidSendStr("2:Room2");
				  LCD_u8GoToXY(2,0);
				  LCD_voidSendStr("3:Room3");
				  LCD_u8GoToXY(2,9);
				  LCD_voidSendStr("4:Back");
				  KPD_u8GetKeyState(&Local_u8KeyValue);
				  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED  && Local_u32Time_Out < MAX_TIME)
				  {
					  KPD_u8GetKeyState(&Local_u8KeyValue);
					  Local_u32Time_Out++;
				  }
				  if(Local_u8KeyValue == '1')
				  {
					  while(Local_u8KeyValue != '0')
					  {
						  LCD_voidClearScreen();
						  LCD_voidSendStr("Room1");
						  LCD_u8GoToXY(2,0);
						  LCD_voidSendStr("1-On");
						  LCD_u8GoToXY(2,5);
						  LCD_voidSendStr("2-Off");
						  LCD_u8GoToXY(2,11);
						  LCD_voidSendStr("0-Back");
						  KPD_u8GetKeyState(&Local_u8KeyValue);
						  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
						  {
							  KPD_u8GetKeyState(&Local_u8KeyValue);
						  }
						  if(Local_u8KeyValue == '1')
						  {
							 SPI_voidSendSlaveByte(ROOM_1_TURN_ON);
						  }
						  else if(Local_u8KeyValue == '2')
						  {
							  SPI_voidSendSlaveByte(ROOM_1_TURN_OFF);
						  }
					  }
					  Local_u32Time_Out = 0;
				  }

				  else if(Local_u8KeyValue == '2')
				  {
					  while(Local_u8KeyValue != '0')
					  {
						  LCD_voidClearScreen();
						  LCD_voidSendStr("Room2");
						  LCD_u8GoToXY(2,0);
						  LCD_voidSendStr("1-On");
						  LCD_u8GoToXY(2,5);
						  LCD_voidSendStr("2-Off");
						  LCD_u8GoToXY(2,11);
						  LCD_voidSendStr("0-Back");
						  KPD_u8GetKeyState(&Local_u8KeyValue);
						  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
						  {
							  KPD_u8GetKeyState(&Local_u8KeyValue);
						  }
						  if(Local_u8KeyValue == '1')
						  {
							  SPI_voidSendSlaveByte(ROOM_2_TURN_ON);
						  }
						  else if(Local_u8KeyValue == '2')
						  {
							  SPI_voidSendSlaveByte(ROOM_2_TURN_OFF);
						  }
					  }
					  Local_u32Time_Out = 0;
				  }

				  else if(Local_u8KeyValue == '3')
				  {
					  while(Local_u8KeyValue != '0')
					  {
						  LCD_voidClearScreen();
						  LCD_voidSendStr("Room3");
						  LCD_u8GoToXY(2,0);
						  LCD_voidSendStr("1-On");
						  LCD_u8GoToXY(2,5);
						  LCD_voidSendStr("2-Off");
						  LCD_u8GoToXY(2,11);
						  LCD_voidSendStr("0-Back");
						  KPD_u8GetKeyState(&Local_u8KeyValue);
						  while(Local_u8KeyValue == KPD_u8_KEY_NOT_PRESSED)
						  {
							  KPD_u8GetKeyState(&Local_u8KeyValue);
						  }
						  if(Local_u8KeyValue == '1')
						  {
							  SPI_voidSendSlaveByte(ROOM_3_TURN_ON);
						  }
						  else if(Local_u8KeyValue == '2')
						  {
							  SPI_voidSendSlaveByte(ROOM_3_TURN_OFF);
						  }
					  }
					  Local_u32Time_Out = 0;
				  }
			  }
		   }

		}
	}


	return 0;

}

