   /******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 10/9/2022       *****/
/********** SWC     : LCD             *****/
/********** verison : v-1             *****/
/******************************************/

/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL*/
#include "DIO_interface.h"


/*HAL*/
#include "SEVENSEG_interface.h"
#include "SEVENSEG_private.h"
#include "SEVENSEG_config.h"

void SEVENSEG_voidInit(u8 Copy_u8PortName)
{
	DIO_u8SetPortDirection(Copy_u8PortName,DIO_u8_OUTPUT);
}

void SEVENSEG_voidWrite(u8 Copy_u8PortName,u8 Copy_u8Number)
{
	DIO_u8SetPortValue(Copy_u8PortName,~arr[Copy_u8Number]);
}
