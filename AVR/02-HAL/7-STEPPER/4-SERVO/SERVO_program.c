/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 14/11/2022      *****/
/********** SWC     : SERVO           *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_interface.h"

#include"SERVO_interface.h"
#include"SERVO_private.h"
#include"SERVO_config.h"

/*time_1 iniatialization in fast PWM mode 1-select OCR in noninverting mood 2-put 19999 in ICR(because servo turn on 50Hz) 3-prescaler = 8*/ 

u8 SERVO_u8SetServoAngle(u8 Copy_u8ServoAngle)
{
	u8  Local_u8ErrorState = STD_TYPES_OK;
	u16 Local_u16OCR1AValue;
	if(Copy_u8ServoAngle <= 180)
	{
		Local_u16OCR1AValue = ((Copy_u8ServoAngle*6)+185);
		TIMERS_voidTimer1SetOCR1A(Local_u16OCR1AValue);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}