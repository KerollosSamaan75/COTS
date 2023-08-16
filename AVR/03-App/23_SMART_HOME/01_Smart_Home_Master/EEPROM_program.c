/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 29/11/2022      *****/
/********** SWC     : EEPROM          *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "TWI_interface.h"

#include"EEPROM_interface.h"
#include"EEPROM_private.h"
#include"EEPROM_config.h"

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress , u8 Copy_u8DataByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorState Local_enumTWIErrorState = TWI_OK;

    /*1-Send Start Condition*/
    Local_enumTWIErrorState = TWI_enuSendStartCondition();
    Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

    /*2-Send Slave Address With Write Operation*/
    Local_enumTWIErrorState = TWI_enuSendSlaveAddWithWrite((EEPROM_u8_FIXED_ADDRESS) | (EEPROM_u8_A2_ADDRESS << 2) | ((Copy_u16ByteAddress >> 8) & 3));
    Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

    /*3-Send Byte Address*/
    Local_enumTWIErrorState = TWI_enuMasterSendDataByte((u8)Copy_u16ByteAddress);
    Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

    /*4-Send Data Byte*/
    Local_enumTWIErrorState = TWI_enuMasterSendDataByte(Copy_u8DataByte);
    Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

    /*5-Send Stop Condition*/
    TWI_enuSendStopCondition();

    /*6-Delay 5 msec*/
    _delay_ms(20);

	return Local_u8ErrorState;
}

u8 EEPROM_u8ReadDataByte (u16 Copy_u16ByteAddress , u8* Copy_pu8ReturnedData)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorState Local_enumTWIErrorState = TWI_OK;
     if(Copy_pu8ReturnedData != NULL)
     {
    	 /*1-Send Start Condition*/
		 Local_enumTWIErrorState = TWI_enuSendStartCondition();
		 Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);
		 

		 /*2-Send Slave Address With Write Operation*/
		 Local_enumTWIErrorState = TWI_enuSendSlaveAddWithWrite((EEPROM_u8_FIXED_ADDRESS) | (EEPROM_u8_A2_ADDRESS << 2)|((Copy_u16ByteAddress >> 8)));
		 Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

		 /*3-Send Byte Address*/
		 Local_enumTWIErrorState = TWI_enuMasterSendDataByte((u8)Copy_u16ByteAddress);
		 Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

		 /*4-Send Restart Condition*/
		 Local_enumTWIErrorState = TWI_enuSendReStartCondition();
		 Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

		 /*5-Send Slave Address With Read Operation*/
		 Local_enumTWIErrorState = TWI_enuSendSlaveAddressWithRead((EEPROM_u8_FIXED_ADDRESS) | (EEPROM_u8_A2_ADDRESS << 2)|((Copy_u16ByteAddress >> 8)));
		 Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

		 /*6-Read Data Byte*/
		 Local_enumTWIErrorState = TWI_enuMasterReadDataByte(Copy_pu8ReturnedData);
		 Local_u8ErrorState = Private_u8CheckErrorState(Local_enumTWIErrorState);

		 /*7-Send Stop Condition*/
		 TWI_enuSendStopCondition();

		 /*8-Delay 5 msec*/
		  _delay_ms(20);
     }
     else
     {
    	 Local_u8ErrorState = STD_TYPES_NOK;
     }

     return Local_u8ErrorState;
}

static u8 Private_u8CheckErrorState(TWI_ErrorState Copy_enumErrorState)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_enumErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
