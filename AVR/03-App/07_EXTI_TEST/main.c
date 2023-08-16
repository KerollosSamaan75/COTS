/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Kero
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include <avr/delay.h>
#include"DIO_interface.h"
#include"GI_interface.h"
#include"EXTI_interface.h"

void Tog_LED(void);

int main()
{
	DIO_voidInit();
	GI_voidEnale();
	EXTI_u8EXTISetCallBack(EXTI_u8_INT1,&Tog_LED);
	EXTI_u8EXTIEnable(EXTI_u8_INT1,EXTI_u8_FALLING_EDGE);
	while(1);
	return 0;
}

void Tog_LED(void)
{
	static u8 Local_u8Flag=0;
	if(Local_u8Flag == 0)
	{
		_delay_ms(50);
		//DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_HIGH);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_HIGH);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_HIGH);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_HIGH);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
		Local_u8Flag=1;
	}
	else
	{
		_delay_ms(50);
		//DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
		Local_u8Flag=0;
	}

}
