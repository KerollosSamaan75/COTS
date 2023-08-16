/*
 * main.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Kerollos
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "ADC_interface.h"
#include "GI_interface.h"
#include "TIMERS_interface.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "util/delay.h"

#include "main_config.h"

static u8 TempatureRequiredValue = 24; //initial value
static u8 Counter=0;
static u8 AirConditionPowerStatus=0;
static u16 DigitalValue=0;
static u16 TempratureSensorReading=0;

void ReadTempratureSensor(void);

int main(void)
{
	u8 Local_u8RecievedByte;
	DIO_voidInit();
	SPI_voidInit();
	ADC_voidInit();
	TIMERS_voidTimer0SetCompareMatchValue(78);  //to achieve tick equal to 10 msec
	TIMERS_voidTimer0Init();
	TIMERS_u8Timer0CTCSetCallBack(&ReadTempratureSensor);
	TIMERS_voidTimer0CTCInterruptEnable();
	TIMERS_voidTimer0Enable();
	GI_voidEnable();
	while(1)
	{
		SPI_u8RecieveByte(&Local_u8RecievedByte);
		switch(Local_u8RecievedByte)
		{
		   case ROOM_1_TURN_ON :DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_HIGH); break;
		   case ROOM_1_TURN_OFF:DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_LOW);  break;

		   case ROOM_2_TURN_ON :DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_HIGH); break;
		   case ROOM_2_TURN_OFF:DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_LOW);  break;

		   case ROOM_3_TURN_ON :DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_HIGH); break;
		   case ROOM_3_TURN_OFF:DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_LOW);  break;

		   case AIR_CONDITION_POWER_ON :DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_HIGH); break;
		   case AIR_CONDITION_POWER_OFF:DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_LOW);  break;

		   case TV_TURN_ON :DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_HIGH); break;
		   case TV_TURN_OFF:DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);  break;

		   default :TempatureRequiredValue = Local_u8RecievedByte; break;
		}
	}
	return 0;
}

void ReadTempratureSensor(void)
{
	Counter++;
	if(Counter == 10) //Read ADC Every 1000ms // 10ticks*10ms
	{
		Counter = 0;

		ADC_u8GetDigitalValueSyncNonBlocking(0,&DigitalValue);

		TempratureSensorReading = (DigitalValue /2);

		DIO_u8GetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,&AirConditionPowerStatus);

		if(AirConditionPowerStatus == DIO_u8_LOW)
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
		}
		else if((TempratureSensorReading > TempatureRequiredValue+1) && (AirConditionPowerStatus == DIO_u8_HIGH))
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		else if((TempratureSensorReading < TempatureRequiredValue+1) && (AirConditionPowerStatus == DIO_u8_HIGH))
		{
			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
		}


	}
}
