/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 02/10/2022      *****/
/********** SWC     : EXTI            *****/
/********** verison : v-1             *****/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*Global Pointer TO a Function*/
static void (*EXTI_ApfEXTI[3])(void)={NULL,NULL,NULL};

u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndex,u8 Copy_u8EdgeIndex)
{

	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8EXTIIndex)
	{
		case EXTI_u8_INT0:
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RAISING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,1);
					SET_BIT(EXTI_u8_MCUCR,0);
					SET_BIT(EXTI_u8_GICR,6);
				break;

				case EXTI_u8_FALLING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,1);
					CLR_BIT(EXTI_u8_MCUCR,0);
					SET_BIT(EXTI_u8_GICR,6);
				break;

				case EXTI_u8_ANY_LOGICAL_CHANGE:
					CLR_BIT(EXTI_u8_MCUCR,1);
					SET_BIT(EXTI_u8_MCUCR,0);
					SET_BIT(EXTI_u8_GICR,6);
				break;

				case EXTI_u8_LOW_LEVEL:
					CLR_BIT(EXTI_u8_MCUCR,1);
					CLR_BIT(EXTI_u8_MCUCR,0);
					SET_BIT(EXTI_u8_GICR,6);
				break;

				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
		break;

		case EXTI_u8_INT1:
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RAISING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,3);
					SET_BIT(EXTI_u8_MCUCR,2);
					SET_BIT(EXTI_u8_GICR,7);
				break;

				case EXTI_u8_FALLING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,3);
					CLR_BIT(EXTI_u8_MCUCR,2);
					SET_BIT(EXTI_u8_GICR,7);
				break;

				case EXTI_u8_ANY_LOGICAL_CHANGE:
					CLR_BIT(EXTI_u8_MCUCR,3);
					SET_BIT(EXTI_u8_MCUCR,2);
					SET_BIT(EXTI_u8_GICR,7);
				break;

				case EXTI_u8_LOW_LEVEL:
					CLR_BIT(EXTI_u8_MCUCR,3);
					CLR_BIT(EXTI_u8_MCUCR,2);
					SET_BIT(EXTI_u8_GICR,7);
				break;

				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
		break;
		case EXTI_u8_INT2:
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RAISING_EDGE:
					SET_BIT(EXTI_u8_MCUCSR,6);
					SET_BIT(EXTI_u8_GICR,5);
				break;

				case EXTI_u8_FALLING_EDGE:
					CLR_BIT(EXTI_u8_MCUCSR,6);
					SET_BIT(EXTI_u8_GICR,5);
				break;

				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
		break;

		default:Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8EXTIDisable(u8 Copy_u8EXTIIndex)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8EXTIIndex)
	{
		case EXTI_u8_INT0:CLR_BIT(EXTI_u8_GICR,6); break;
		case EXTI_u8_INT1:CLR_BIT(EXTI_u8_GICR,7); break;
		case EXTI_u8_INT2:CLR_BIT(EXTI_u8_GICR,5); break;
		default:Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}

u8 EXTI_u8EXTISetCallBack (u8 Copy_u8EXTIIndex,void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState =STD_TYPES_OK;
	if((Copy_u8EXTIIndex <=EXTI_u8_INT2)&&(Copy_pf != NULL))
	{
		EXTI_ApfEXTI[Copy_u8EXTIIndex] = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*Prototype For ISR of EXTI0*/
void __vector_1(void)    __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_ApfEXTI[0] != NULL)
	{
		EXTI_ApfEXTI[0]();
	}
}

/*Prototype For ISR of EXTI1*/
void __vector_2(void)    __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_ApfEXTI[1] != NULL)
	{
		EXTI_ApfEXTI[1]();
	}
}

/*Prototype For ISR of EXTI2*/
void __vector_3(void)    __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_ApfEXTI[2] != NULL)
	{
		EXTI_ApfEXTI[2]();
	}
}
