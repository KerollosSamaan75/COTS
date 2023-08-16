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
		CLR_BIT(ADC_u8_ADMUX_REG,7);
		SET_BIT(ADC_u8_ADMUX_REG,6);
	//2-Right Adjust
		CLR_BIT(ADC_u8_ADMUX_REG,5);
	//3-Disable Auto Trigger
		CLR_BIT(ADC_u8_ADCSRA_REG,5);
	//4-Select CLK/64
		CLR_BIT(ADC_u8_ADCSRA_REG,0);
		SET_BIT(ADC_u8_ADCSRA_REG,1);
		SET_BIT(ADC_u8_ADCSRA_REG,2);
	//5-Enable ADC
		SET_BIT(ADC_u8_ADCSRA_REG,7);
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
		SET_BIT(ADC_u8_ADCSRA_REG,6);
		//Wait flag =1
		while((GET_BIT(ADC_u8_ADCSRA_REG,4) == 0)&&(Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE))
		{
			Local_u32TimeOutCounter++;
		}
		if(GET_BIT(ADC_u8_ADCSRA_REG,4) == 1)
		{
			//Clear Flag
		    SET_BIT(ADC_u8_ADCSRA_REG,4);
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
		SET_BIT(ADC_u8_ADCSRA_REG,3);
		//Clear MUX4...0
		ADC_u8_ADMUX_REG &= 0b11100000;
		//Select Channel
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;  
		//Start Conversion
		SET_BIT(ADC_u8_ADCSRA_REG,6);
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
		CLR_BIT(ADC_u8_ADCSRA_REG,3);
		ADC_pfNotification(ADC_u16_ADC_REG);
		ADC_u8BusyFlag =0;
	}
}
