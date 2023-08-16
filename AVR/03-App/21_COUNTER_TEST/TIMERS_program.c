/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 16/10/2022      *****/
/********** SWC     : TIMERS          *****/
/********** verison : v-1             *****/
/******************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"TIMERS_interface.h"
#include"TIMERS_private.h"
#include"TIMERS_config.h"

/*Global Pointer To Function Of Timer0 OVF*/
static void(*TIMERS_pfTimer0OVF)(void) = NULL;

void TIMERS_voidTimer0Init(void)
{
	/*Select Mood => Normal Mood*/
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	CLR_BIT(TIMERS_u8_TCCR0_REG,3);
	
	/*Enable OVF Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,0);
	
	/*Set Preload Value*/
	TIMERS_u8_TCNT0_REG = 0;
	
	/*Set PreScaler Value*/
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	SET_BIT(TIMERS_u8_TCCR0_REG,2);
}


u8   TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer0OVF = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 TIMERS_u8Timer0Count(u8* Copy_pu8Counter)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8Counter != NULL)
	{
		*Copy_pu8Counter = TIMERS_u8_TCNT0_REG;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}
/*Prototype For ISR of Timer0 OVF*/
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{

		/*Update Preload Value*/

		/*Call App Function*/
		if(TIMERS_pfTimer0OVF != NULL)
		{
			TIMERS_pfTimer0OVF();
		}

}
