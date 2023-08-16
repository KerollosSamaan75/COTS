/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 14/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

void(*UnderFlowNF)(void)= NULL;

void SYSTICK_voidInit(void)
{
	#if   CLOCK_SOURCE == AHB_8_CLOCK
	      CLR_BIT(STK_CTRL , 2);
		
	#elif  CLOCK_SOURCE == AHB_CLOCK	
		   SET_BIT(STK_CTRL , 2);
		   
	#endif	   
}

void SYSTICK_voidEnableTimer (void)
{
	SET_BIT(STK_CTRL , 0);
}

void SYSTICK_voidDisnableTimer(void)
{
	CLR_BIT(STK_CTRL , 0);
}

void SYSTICK_voidEnableInterrupt(void)
{
	SET_BIT(STK_CTRL , 1);
}

void SYSTICK_voidDisableInterrupt(void)
{
	CLR_BIT(STK_CTRL , 1);
}

u8 SYSTICK_u8GetInterruptFlag(void)

{
	u8 Local_u8FlagState;
	Local_u8FlagState = GET_BIT(STK_CTRL , 16);
	return Local_u8FlagState;
}

void SYSTICK_voidSetCallBack(void(*Copy_PF)(void))
{
	UnderFlowNF = Copy_PF;
}

void SYSTICK_voidSetReloadValue(u32 Copy_u32ReloadValue)
{
	STK_LOAD = Copy_u32ReloadValue;
}

void  SysTick_Handler()
{
	if(UnderFlowNF != NULL)
	{
		UnderFlowNF();
		SYSTICK_u8GetInterruptFlag();
	}
}
