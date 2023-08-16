   /******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 22/7/2023       *****/
/********** SWC     : MUXSEVENSEG    *****/
/********** verison : v-1             *****/
/******************************************/

/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL*/
#include "DIO_interface.h"

#include <util/delay.h>


/*HAL*/
#include "MUXSEVENSEG_interface.h"
#include "MUXSEVENSEG_private.h"
#include "MUXSEVENSEG_config.h"

void MUXSEVENSEG_voidWriteDigit(u8 Copy_u8SevSegmNum,u8 Copy_u8Digit)
{
	switch(Copy_u8SevSegmNum)
	{
	   case SEV_SEGM_1:
	      DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
	      DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
	      DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_HIGH);
	      DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_HIGH);
	      break;

	   case SEV_SEGM_2:
		  DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
		  DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
		  DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_HIGH);
		  DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_HIGH);
		  break;

	   case SEV_SEGM_3:
		  DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
		  DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
		  DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_LOW);
		  DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_HIGH);
	   	 break;

	   case SEV_SEGM_4:
		  DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
		  DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
		  DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_HIGH);
		  DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_LOW);
	   	break;
	}

	switch(Copy_u8Digit)
	{
	   case 0:
			   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
			   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
			   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
			   break;

	   case 1:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	   		   break;
	   case 2:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	   		   break;
	   case 3:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	   		   break;
	   case 4:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	   		   break;
	   case 5:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	   		   break;
	   case 6:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	   		   break;
	   case 7:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	   		   break;
	   case 8:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_HIGH);
	   		   break;
	   case 9:
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
	   		   DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_HIGH);
	   		   break;
	}
	_delay_ms(5);
}

void MUXSEVENSEG_voidWriteNumber(u16 Copy_u16Number)
{
	u8 Local_u8DigitIndex = 4 ;
	while(Copy_u16Number != 0 )
	{
		MUXSEVENSEG_voidWriteDigit(Local_u8DigitIndex , (Copy_u16Number % 10));
		Local_u8DigitIndex --;
		Copy_u16Number /= 10;
	}
}
