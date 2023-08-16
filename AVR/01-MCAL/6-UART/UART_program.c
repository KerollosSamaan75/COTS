/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 19/11/2022      *****/
/********** SWC     : UART            *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void UART_voidInit(void)
{
	u8 Local_u8UCSRCValue = 0b10000000;
	u16 Local_u16BaudRateValue = 51;
	
	/*BaudRate = 9600*/
	UART_u8_UBRRL_REG = (u8)Local_u16BaudRateValue;
	UART_u8_UBRRH_REG = (u8)(Local_u16BaudRateValue>>8);
	
	/*Normal Speed*/
	CLR_BIT(UART_u8_UCSRA_REG,1);
	/*Disable MultiProcessor Mood*/
	CLR_BIT(UART_u8_UCSRA_REG,0);
	
	/*Enable Tx*/
	SET_BIT(UART_u8_UCSRB_REG,3);
	/*Enable Rx*/
	SET_BIT(UART_u8_UCSRB_REG,4);
	/*Select 8 BIT Data*/
	CLR_BIT(UART_u8_UCSRB_REG,2);	
	SET_BIT(Local_u8UCSRCValue,2);
	SET_BIT(Local_u8UCSRCValue,1);
	/*Select Asynch Mood*/
	CLR_BIT(Local_u8UCSRCValue,6);
	/*No Parity Bit*/
	CLR_BIT(Local_u8UCSRCValue,5);
	CLR_BIT(Local_u8UCSRCValue,4);
	/*Enable Two Stop Bits*/
	SET_BIT(Local_u8UCSRCValue,3);
	
	/*Update UCSRC_REG*/ 
	UART_u8_UCSRC_REG = Local_u8UCSRCValue;
}

void UART_voidSendByte(u8 Copy_u8DataByte)
{
	/*Wait Until TX REG Is Empty*/
	while(GET_BIT(UART_u8_UCSRA_REG,5) == 0);
	/*Send Data Byte*/
	UART_u8_UDR_REG = Copy_u8DataByte;
}

u8  UART_u8RecieveByte(u8* Copy_pu8RecByte)
{
	 u8 Local_u8ErrorState = STD_TYPES_NOK;
	 if(Copy_pu8RecByte != NULL)
	 {
		 /*Wait Until The Data Is Recieved*/
		 while(GET_BIT(UART_u8_UCSRA_REG,7) == 0); 
		 /*Read Data*/
		 *Copy_pu8RecByte = UART_u8_UDR_REG;
		 Local_u8ErrorState = STD_TYPES_OK;
	 }
	 return Local_u8ErrorState;
}

