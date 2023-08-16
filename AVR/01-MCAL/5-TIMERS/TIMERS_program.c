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
	TIMERS_u8_TCNT0_REG = 24;
	
	/*Set PreScaler Value*/
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
}
void TIMERS_voidTimer1Init(void)
{
	/*Select Mood => 14*/
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	
	/*Select Mood For Output Pin(OC1A) For ChannelA => Non Inverting Mood*/
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);
	
	/*Select Top Value Of ICR => 1999*/
	TIMERS_u16_ICR1_REG = 19999;
	
	/*Set Angle Of Servo Motor => 0*/
	TIMERS_u16_OCR1A_REG = 185;

	/*Set PreScaler Value*/
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);
	SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
}

void TIMERS_voidTimer1SetOCR1A(u16 Copy_OCR1A_Value)
{
	TIMERS_u16_OCR1A_REG = Copy_OCR1A_Value;
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


/*Prototype For ISR of Timer0 OVF*/
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	static u16 Local_u16CounterOVF = 0;
	Local_u16CounterOVF++;
	if(Local_u16CounterOVF == 4)
	{
		/*Update Preload Value*/
	    TIMERS_u8_TCNT0_REG = 24;
		/*Clear OVF Counter*/ 
		Local_u16CounterOVF = 0;
		/*Call App Function*/
		if(TIMERS_pfTimer0OVF != NULL)
		{
			TIMERS_pfTimer0OVF();
		}
	}
}
