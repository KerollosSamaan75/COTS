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

/*Global Pointer To Function Of Timer0 CTC*/
static void(*TIMERS_pfTimer0CTC)(void) = NULL;

void TIMERS_voidTimer0Init(void)
{
	/*Select Mood => CTC Mood*/
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	SET_BIT(TIMERS_u8_TCCR0_REG,3);
	
	/*Enable CTC Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,1);
	
	/* load a value in OCR0 to make interrupt 10ms*/
	TIMERS_u8_OCR0_REG=78;
	
	/*Set PreScaler Value = 1024*/
	SET_BIT(TIMERS_u8_TCCR0_REG,0);
	CLR_BIT(TIMERS_u8_TCCR0_REG,1);
	SET_BIT(TIMERS_u8_TCCR0_REG,2);
}

u8   TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer0CTC = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*Prototype For ISR of Timer0 CTC*/
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
		if(TIMERS_pfTimer0CTC != NULL)
		{
			TIMERS_pfTimer0CTC();
		}
}
