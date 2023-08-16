/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 01/10/2022      *****/
/********** SWC     : STEPPER         *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define  F_CPU  8000000UL 
#include <util/delay.h>

#include "DIO_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"

u8 STEPPER_u8Rotate(u16 Copy_u16Degree ,u8 Copy_u8Direction)
{
	u8  Local_u8ErrorState = STD_TYPES_OK;
	u16 Local_u16Steps;
	if(Copy_u16Degree > 360)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	else
	{
		Local_u16Steps =((Copy_u16Degree * 2048UL)/360);
		switch(Copy_u8Direction)
		{
			case COUNTER_CLOCKWISE_DIRECTION:
			{
				for(int i=0;i<(Local_u16Steps/4);i++)
				{
					//Step_1
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_HIGH);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_LOW);
					_delay_ms(10);
					//Step_2
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_HIGH);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_LOW);
					_delay_ms(10);
					//Step_3
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_HIGH);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_LOW);
					_delay_ms(10);
					//Step_4
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_HIGH);
					_delay_ms(10);
				}
			}
			break;
			
			case CLOCKWISE_DIRECTION:
			{
				for(int i=0;i<(Local_u16Steps/4);i++)
				{
					//Step_1
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_HIGH);
					_delay_ms(10);
					//Step_2
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_HIGH);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_LOW);
					_delay_ms(10);
					//Step_3
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_HIGH);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_LOW);
					_delay_ms(10);
					//Step_4
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN0,DIO_u8_HIGH);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN1,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN2,DIO_u8_LOW);
					DIO_u8SetPinValue(STEPPER_u8_PORT,DIO_u8_PIN3,DIO_u8_LOW);
					_delay_ms(10);
				}
			}
			break;
			default:Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	
	return Local_u8ErrorState;
}
