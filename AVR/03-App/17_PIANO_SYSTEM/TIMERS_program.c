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

/*Global Pointer To Function Of Timer0 CTC*/
static void(*TIMERS_pfTimer0CTC)(void) = NULL;

void TIMERS_voidTimer0Init(void)
{
	/*1-Select Mood*/
    #if  TIMER0_u8_MODE == TIMER0_NORMAL_MOOD
	     CLR_BIT(TIMERS_u8_TCCR0_REG,WGM00);
	     CLR_BIT(TIMERS_u8_TCCR0_REG,WGM01);

    #elif TIMER0_u8_MODE == TIMER0_PHASE_PWM_MOOD
	      SET_BIT(TIMERS_u8_TCCR0_REG,WGM00);
	      CLR_BIT(TIMERS_u8_TCCR0_REG,WGM01);


    #elif TIMER0_u8_MODE == TIMER0_CTC_MOOD
	      CLR_BIT(TIMERS_u8_TCCR0_REG,WGM00);
	      SET_BIT(TIMERS_u8_TCCR0_REG,WGM01);

    #elif TIMER0_u8_MODE == TIMER0_FAST_PWM_MOOD
	      SET_BIT(TIMERS_u8_TCCR0_REG,WGM00);
	      SET_BIT(TIMERS_u8_TCCR0_REG,WGM01);
    #endif

   /*2-Select OC0 Pin Mood*/
   #if  TIMER0_OC0_PIN_MOOD == TIMER0_NON_PWM_OC0_PIN_DISCONNECTED
	    CLR_BIT(TIMERS_u8_TCCR0_REG,COM00);
	    CLR_BIT(TIMERS_u8_TCCR0_REG,COM01);

  #elif TIMER0_OC0_PIN_MOOD == TIMER0_NON_PWM_OC0_PIN_TOGGLE
	    SET_BIT(TIMERS_u8_TCCR0_REG,COM00);
	    CLR_BIT(TIMERS_u8_TCCR0_REG,COM01);

  #elif TIMER0_OC0_PIN_MOOD == TIMER0_NON_PWM_OC0_PIN_CLEAR
	    CLR_BIT(TIMERS_u8_TCCR0_REG,COM00);
	    SET_BIT(TIMERS_u8_TCCR0_REG,COM01);

  #elif TIMER0_OC0_PIN_MOOD == TIMER0_NON_PWM_OC0_PIN_SET
        SET_BIT(TIMERS_u8_TCCR0_REG,COM00);
        SET_BIT(TIMERS_u8_TCCR0_REG,COM01);

  #elif TIMER0_OC0_PIN_MOOD == TIMER0_FAST_PWM_OC0_PIN_CLEAR_ON_COMPARE_SET_AT_TOP
        CLR_BIT(TIMERS_u8_TCCR0_REG,COM00);
        SET_BIT(TIMERS_u8_TCCR0_REG,COM01);

  #elif TIMER0_OC0_PIN_MOOD == TIMER0_FAST_PWM_OC0_PIN_SET_ON_COMPARE_CLEAR_AT_TOP
        SET_BIT(TIMERS_u8_TCCR0_REG,COM00);
        SET_BIT(TIMERS_u8_TCCR0_REG,COM01);

  #elif TIMER0_OC0_PIN_MOOD == TIMER0_PHASE_PWM_OC0_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER
        CLR_BIT(TIMERS_u8_TCCR0_REG,COM00);
        SET_BIT(TIMERS_u8_TCCR0_REG,COM01);

  #elif TIMER0_OC0_PIN_MOOD == TIMER0_PHASE_PWM_OC0_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER
        SET_BIT(TIMERS_u8_TCCR0_REG,COM00);
        SET_BIT(TIMERS_u8_TCCR0_REG,COM01);

   #endif
}

void TIMERS_voidTimer0Enable(void)
{
	/*Set PreScaler Value*/
	TIMERS_u8_TCCR0_REG &= 0xf8;
	TIMERS_u8_TCCR0_REG |= TIMER0_u8_PRE_SCALER_MOOD;
}

void TIMERS_voidTimer0Disable(void)
{
	TIMERS_u8_TCCR0_REG &= 0xf8;
	TIMERS_u8_TCCR0_REG |= TIMER0_NO_CLOCK_SOURCE;
}

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8Value)
{
	/*Set Preload Value*/
	TIMERS_u8_TCNT0_REG = Copy_u8Value;
}

u8 TIMERS_u8Timer0ReadCounter(void)
{
	return TIMERS_u8_TCNT0_REG;
}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8Value)
{
   TIMERS_u8_OCR0_REG = Copy_u8Value;
}

void TIMERS_voidTimer0CTCInterruptEnable(void)
{
	/*Enable CTC Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,OCIE0);
}

void TIMERS_voidTimer0OVFInterruptEnable(void)
{
	/*Enable OVF Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,TOIE0);
}

void TIMERS_voidTimer0CTCInterruptDisable(void)
{
	/*Disable CTC Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,OCIE0);
}

void TIMERS_voidTimer0OVFInterruptDisable(void)
{
	/*Disable OVF Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,TOIE0);
}

u8 TIMERS_u8Timer0ReadOVFFlag(void)
{
	u8 Local_u8OVFFlag;
	Local_u8OVFFlag = GET_BIT(TIMERS_u8_TIFR_REG,TOV0);
	return Local_u8OVFFlag;
}

u8 TIMERS_u8Timer0ReadCTCFlag(void)
{
	u8 Local_u8CTCFlag;
	Local_u8CTCFlag = GET_BIT(TIMERS_u8_TIFR_REG,OCF0);
	return Local_u8CTCFlag;
}

void TIMERS_voidTimer0ClearOVFFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,TOV0);
}

void TIMERS_voidTimer0ClearCTCFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,OCF0);
}

u8   TIMERS_u8Timer0OVFSetCallBack(void(*Copy_pf)(void))
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

u8   TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf)(void))
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



/*Prototype For ISR of Timer0 CTC*/
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
	if(TIMERS_pfTimer0CTC != NULL)
	{
		TIMERS_pfTimer0CTC();
	}
}

/*Prototype For ISR of Timer0 OVF*/
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	if(TIMERS_pfTimer0OVF != NULL)
	{
		TIMERS_pfTimer0OVF();
	}
}


