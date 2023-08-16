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

/*Global Pointer To Function Of Timer1 OVF*/
static void(*TIMERS_pfTimer1OVF)(void) = NULL;

/*Global Pointer To Function Of Timer0 CTC*/
static void(*TIMERS_pfTimer0CTC)(void) = NULL;

/*Global Pointer To Function Of Timer1 Channel_A CTC*/
static void(*TIMERS_pfTimer1CannelA_CTC)(void) = NULL;

/*Global Pointer To Function Of Timer1 Channel_B CTC*/
static void(*TIMERS_pfTimer1CannelB_CTC)(void) = NULL;

/*Global Pointer To Function Of Timer1 Input Capture Unit*/
static void(*TIMERS_pfTimer1InputCapture)(void) = NULL;

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

void TIMERS_voidTimer1Init(void)
{
	  /*1-Select Mood*/
	  #if   TIMER1_u8_MODE == TIMER1_NORMAL_MOOD
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,WGM10);
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,WGM11);
	        CLR_BIT(TIMERS_u8_TCCR1B_REG,WGM12);
	        CLR_BIT(TIMERS_u8_TCCR1B_REG,WGM13);

     #elif  TIMER1_u8_MODE == TIMER0_CTC_MOOD_4     //channel A only OCR1A
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,WGM10);
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,WGM11);
	        SET_BIT(TIMERS_u8_TCCR1B_REG,WGM12);
	        CLR_BIT(TIMERS_u8_TCCR1B_REG,WGM13);

      #elif TIMER1_u8_MODE == TIMER1_FAST_PWM_MOOD_14
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,WGM10);
			SET_BIT(TIMERS_u8_TCCR1A_REG,WGM11);
			SET_BIT(TIMERS_u8_TCCR1B_REG,WGM12);
			SET_BIT(TIMERS_u8_TCCR1B_REG,WGM13);
      #endif


	  /*2-Select OC1A Pin Mood*/
	  #if  TIMER1_OC1A_PIN_MOOD == TIMER1_NON_PWM_OC1A_PIN_DISCONNECTED
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);

	  #elif TIMER1_OC1A_PIN_MOOD == TIMER1_NON_PWM_OC1A_PIN_TOGGLE
		    SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);

	  #elif TIMER1_OC1A_PIN_MOOD == TIMER1_NON_PWM_OC1A_PIN_CLEAR
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
		    SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);

	  #elif TIMER1_OC1A_PIN_MOOD == TIMER1_NON_PWM_OC1A_PIN_SET
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);

	  #elif TIMER1_OC1A_PIN_MOOD == TIMER1_FAST_PWM_OC1A_PIN_CLEAR_ON_COMPARE_SET_AT_TOP
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);

	  #elif TIMER1_OC1A_PIN_MOOD == TIMER1_FAST_PWM_OC1A_PIN_SET_ON_COMPARE_CLEAR_AT_TOP
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);

	  #elif TIMER1_OC1A_PIN_MOOD == TIMER1_PHASE_PWM_OC1A_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);

	  #elif TIMER1_OC1A_PIN_MOOD == TIMER1_PHASE_PWM_OC1A_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1A1);
	   #endif

	  /*3-Select OC1B Pin Mood*/
      #if  TIMER1_OC1B_PIN_MOOD == TIMER1_NON_PWM_OC1B_PIN_DISCONNECTED
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);

	  #elif TIMER1_OC1B_PIN_MOOD == TIMER1_NON_PWM_OC1B_PIN_TOGGLE
		    SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);

	  #elif TIMER1_OC1B_PIN_MOOD == TIMER1_NON_PWM_OC1B_PIN_CLEAR
		    CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
		    SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);

	  #elif TIMER1_OC1B_PIN_MOOD == TIMER1_NON_PWM_OC1B_PIN_SET
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);

	  #elif TIMER1_OC1B_PIN_MOOD == TIMER1_FAST_PWM_OC1B_PIN_CLEAR_ON_COMPARE_SET_AT_TOP
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);

	  #elif TIMER1_OC1B_PIN_MOOD == TIMER1_FAST_PWM_OC1B_PIN_SET_ON_COMPARE_CLEAR_AT_TOP
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);

	  #elif TIMER1_OC1B_PIN_MOOD == TIMER1_PHASE_PWM_OC1B_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER
	        CLR_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);

	  #elif TIMER1_OC1B_PIN_MOOD == TIMER1_PHASE_PWM_OC1B_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B0);
	        SET_BIT(TIMERS_u8_TCCR1A_REG,COM1B1);
	   #endif
}

void TIMERS_voidTimer0Enable(void)
{
	/*Set PreScaler Value*/
	TIMERS_u8_TCCR0_REG &= 0xf8;
	TIMERS_u8_TCCR0_REG |= TIMER0_u8_PRE_SCALER_MOOD;
}

void TIMERS_voidTimer1Enable(void)
{
	/*Set PreScaler Value*/
	TIMERS_u8_TCCR1B_REG &= 0xf8;
	TIMERS_u8_TCCR1B_REG |= TIMER1_u8_PRE_SCALER_MOOD;
}

void TIMERS_voidTimer0Disable(void)
{
	TIMERS_u8_TCCR0_REG &= 0xf8;
}

void TIMERS_voidTimer1Disable(void)
{
	TIMERS_u8_TCCR1B_REG &= 0xf8;
}

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8Value)
{
	/*Set Preload Value*/
	TIMERS_u8_TCNT0_REG = Copy_u8Value;
}

void TIMERS_voidTimer1SetPreLoadValue(u16 Copy_u16Value)
{
	/*Set Preload Value*/
	TIMERS_u16_TCNT1_REG = Copy_u16Value;
}

u8 TIMERS_u8Timer0ReadCounter(void)
{
	return TIMERS_u8_TCNT0_REG;
}

u16 TIMERS_u16Timer1ReadCounter(void)
{
	return TIMERS_u16_TCNT1_REG;
}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8Value)
{
   TIMERS_u8_OCR0_REG = Copy_u8Value;
}

void TIMERS_voidTimer1SetChannel_ACompareMatchValue(u16 Copy_u16Value)
{
	TIMERS_u16_OCR1A_REG = Copy_u16Value;
}

void TIMERS_voidTimer1SetChannel_BCompareMatchValue(u16 Copy_u16Value)
{
	TIMERS_u16_OCR1B_REG = Copy_u16Value;
}

void TIMERS_voidTimer1SetTopValue(u16 Copy_u16Value) //for fast pwm mode-14
{
	TIMERS_u16_ICR1_REG = Copy_u16Value;
}

u16 TIMERS_u16Timer1ReadInputCaptureUnit(void)
{
	return TIMERS_u16_ICR1_REG;
}

void TIMERS_voidTimer0CTCInterruptEnable(void)
{
	/*Enable CTC Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,OCIE0);
}

void TIMERS_voidTimer1ChannelA_CTCInterruptEnable(void)
{
	/*Enable Channel_A CTC Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,OCIE1A);
}

void TIMERS_voidTimer1ChannelB_CTCInterruptEnable(void)
{
	/*Enable Channel_B CTC Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,OCIE1B);
}

void TIMERS_voidTimer1InputCaptureInterruptEnable(void)
{
	/*Enable Input Capture Unit Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,TICIE);
}

void TIMERS_voidTimer0OVFInterruptEnable(void)
{
	/*Enable OVF Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,TOIE0);
}

void TIMERS_voidTimer1OVFInterruptEnable(void)
{
	/*Enable OVF Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,TOIE1);
}

void TIMERS_voidTimer0CTCInterruptDisable(void)
{
	/*Disable CTC Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,OCIE0);
}


void TIMERS_voidTimer1ChannelA_CTCInterruptDisable(void)
{
	/*Disable Channel_A CTC Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,OCIE1A);
}

void TIMERS_voidTimer1ChannelB_CTCInterruptDisable(void)
{
	/*Disable Channel_B CTC Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,OCIE1B);
}

void TIMERS_voidTimer1InputCaptureInterruptDisable(void)
{
	/*Disable Input Capture Unit Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,TICIE);
}


void TIMERS_voidTimer0OVFInterruptDisable(void)
{
	/*Disable OVF Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,TOIE0);
}

void TIMERS_voidTimer1OVFInterruptDisable(void)
{
	/*Disable OVF Interrupt*/
	CLR_BIT(TIMERS_u8_TIMSK_REG,TOIE1);
}

u8 TIMERS_u8Timer0ReadOVFFlag(void)
{
	u8 Local_u8OVFFlag;
	Local_u8OVFFlag = GET_BIT(TIMERS_u8_TIFR_REG,TOV0);
	return Local_u8OVFFlag;
}

u8 TIMERS_u8Timer1ReadOVFFlag(void)
{
	u8 Local_u8OVFFlag;
	Local_u8OVFFlag = GET_BIT(TIMERS_u8_TIFR_REG,TOV1);
	return Local_u8OVFFlag;
}

u8 TIMERS_u8Timer0ReadCTCFlag(void)
{
	u8 Local_u8CTCFlag;
	Local_u8CTCFlag = GET_BIT(TIMERS_u8_TIFR_REG,OCF0);
	return Local_u8CTCFlag;
}

u8 TIMERS_u8Timer1ReadChannelB_CTCFlag(void)
{
	u8 Local_u8CTCFlag;
	Local_u8CTCFlag = GET_BIT(TIMERS_u8_TIFR_REG,OCF1B);
	return Local_u8CTCFlag;
}

u8 TIMERS_u8Timer1ReadChannelA_CTCFlag(void)
{
	u8 Local_u8CTCFlag;
	Local_u8CTCFlag = GET_BIT(TIMERS_u8_TIFR_REG,OCF1A);
	return Local_u8CTCFlag;
}

u8 TIMERS_u8Timer1ReadInputCaptureFlag(void)
{
	u8 Local_u8CTCFlag;
	Local_u8CTCFlag = GET_BIT(TIMERS_u8_TIFR_REG,ICF);
	return Local_u8CTCFlag;
}

void TIMERS_voidTimer0ClearOVFFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,TOV0);
}

void TIMERS_voidTimer1ClearOVFFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,TOV1);
}

void TIMERS_voidTimer0ClearCTCFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,OCF0);
}

void TIMERS_voidTimer1ClearChannelB_CTCFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,OCF1B);
}

void TIMERS_voidTimer1ClearChannelA_CTCFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,OCF1A);
}

void TIMERS_voidTimer1ClearInputCaptureFlag(void)
{
	SET_BIT(TIMERS_u8_TIFR_REG,ICF);
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

u8   TIMERS_u8Timer1OVFSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1OVF = Copy_pf;
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

u8   TIMERS_u8Timer1ChannelA_CTCSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1CannelA_CTC = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   TIMERS_u8Timer1ChannelB_CTCSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1CannelB_CTC = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8   TIMERS_u8Timer1InputCaptureSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TIMERS_pfTimer1InputCapture = Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*Prototype For ISR of Timer1 Input Capture Unit*/
void __vector_6(void)   __attribute__((signal));
void __vector_6(void)
{
	if(TIMERS_pfTimer1InputCapture != NULL)
	{
		TIMERS_pfTimer1InputCapture();
	}
}

/*Prototype For ISR of Timer1 Channel_A CTC*/
void __vector_7(void)   __attribute__((signal));
void __vector_7(void)
{
	if(TIMERS_pfTimer1CannelA_CTC != NULL)
	{
		TIMERS_pfTimer1CannelA_CTC();
	}
}

/*Prototype For ISR of Timer1 Channel_B CTC*/
void __vector_8(void)   __attribute__((signal));
void __vector_8(void)
{
	if(TIMERS_pfTimer1CannelB_CTC != NULL)
	{
		TIMERS_pfTimer1CannelB_CTC();
	}
}

/*Prototype For ISR of Timer1 OVF*/
void __vector_9(void)   __attribute__((signal));
void __vector_9(void)
{
	if(TIMERS_pfTimer1OVF != NULL)
	{
		TIMERS_pfTimer1OVF();
	}
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


