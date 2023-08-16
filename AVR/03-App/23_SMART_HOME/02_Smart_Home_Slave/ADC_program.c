/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 08/10/2022      *****/
/********** SWC     : ADC             *****/
/********** verison : v-1             *****/
/******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void (*ADC_pfNotification)(u16) = NULL;
/*ADC Busy Flag*/
static u8 ADC_u8BusyFlag = 0;

void ADC_voidInit(void)
{
	//1-Select Vref = AVCC
		CLR_BIT(ADC_u8_ADMUX_REG , REFS1);
		SET_BIT(ADC_u8_ADMUX_REG , REFS0);
		
	//2-Right Adjust
		CLR_BIT(ADC_u8_ADMUX_REG , ADLAR);
		
	//3-Run in single conversion mode
		CLR_BIT(ADC_u8_ADCSRA_REG , ADATE);
		

	//4-Select prescaller
		#if PRESCALLER == PSC_2

			SET_BIT(ADC_u8_ADCSRA_REG,ADPS0);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS1);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS2);

		#elif PRESCALLER == PSC_4

			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS0);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS1);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS2);

		#elif PRESCALLER == PSC_8

			SET_BIT(ADC_u8_ADCSRA_REG,ADPS0);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS1);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS2);

		#elif PRESCALLER == PSC_16

			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS0);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS1);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS2);

		#elif PRESCALLER == PSC_32

			SET_BIT(ADC_u8_ADCSRA_REG,ADPS0);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS1);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS2);

		#elif PRESCALLER == PSC_64

			CLR_BIT(ADC_u8_ADCSRA_REG,ADPS0);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS1);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS2);

		#elif PRESCALLER == PSC_128

			SET_BIT(ADC_u8_ADCSRA_REG,ADPS0);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS1);
			SET_BIT(ADC_u8_ADCSRA_REG,ADPS2);
		#endif
		
	//5-Enable ADC
		SET_BIT(ADC_u8_ADCSRA_REG,ADEN);
}

void ADC_voidEnable(void)
{
	//Enable ADC
	SET_BIT(ADC_u8_ADCSRA_REG,ADEN);
}

void ADC_voidDisable(void)
{
     //Disable ADC
     CLR_BIT(ADC_u8_ADCSRA_REG,ADEN);
}

u8 ADC_u8GetDigitalValueSyncNonBlocking(u8 Copy_u8ChannelNum,u16 *Copy_pu16DigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeOutCounter = 0;
	if((Copy_u8ChannelNum < 32)&&(Copy_pu16DigitalValue != NULL))
	{
		
		//Clear MUX4...0
		ADC_u8_ADMUX_REG &= 0b11100000;
		
		//Select Channel
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;  
		
		//Start Conversion
		SET_BIT(ADC_u8_ADCSRA_REG,ADSC);
		
		//Wait flag =1
		while((GET_BIT(ADC_u8_ADCSRA_REG,ADIF) == 0)&&(Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE))
		{
			Local_u32TimeOutCounter++;
		}
		if(GET_BIT(ADC_u8_ADCSRA_REG,ADIF) == 1)
		{
			//Clear Flag
		    SET_BIT(ADC_u8_ADCSRA_REG,ADIF);
		    //Read Digital Value
		    *Copy_pu16DigitalValue = ADC_u16_ADC_REG;
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
			
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8GetDigitalValueAsync(u8 Copy_u8ChannelNum,void(*Copy_pfNotification)(u16))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8ChannelNum < 32)&&(Copy_pfNotification != NULL)&&(ADC_u8BusyFlag == 0))
	{
		/*Set ADC_u8BusyFlag*/
		ADC_u8BusyFlag = 1;
		
		/*Update Global Pointer to Function*/
		ADC_pfNotification = Copy_pfNotification;
		
		/*Enable ADC Interrupt*/
		SET_BIT(ADC_u8_ADCSRA_REG,ADIE);
		
		//Clear MUX4...0
		ADC_u8_ADMUX_REG &= 0b11100000;
		
		//Select Channel
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		
		//Start Conversion
		SET_BIT(ADC_u8_ADCSRA_REG,ADSC);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	if(ADC_pfNotification != NULL)
	{
		CLR_BIT(ADC_u8_ADCSRA_REG,ADIE);
		ADC_pfNotification(ADC_u16_ADC_REG);
		ADC_u8BusyFlag =0;
	}
}