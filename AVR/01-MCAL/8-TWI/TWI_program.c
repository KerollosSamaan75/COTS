/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 25/11/2022      *****/
/********** SWC     : TWI             *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"


void TWI_voidMasterInit(void)
{
	/*Set PreScaler Value = 1*/
	CLR_BIT(TWI_u8_TWSR_REG,0);
	CLR_BIT(TWI_u8_TWSR_REG,1);
	/*Set TWBR With The Value => 200KHz*/ 
	TWI_u8_TWBR_REG = 12;
	/*Enable ACK*/
	SET_BIT(TWI_u8_TWCR_REG,6);
	/*Enable TWI*/
	SET_BIT(TWI_u8_TWCR_REG,2);
}

TWI_ErrorState   TWI_u8SlaveInit(u8 Copy_u8Address)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	if((Copy_u8Address <= 127)&&(Copy_u8Address != 0))
	{
		/*Set Slave Address in TWAR*/
		TWI_u8_TWAR_REG = Copy_u8Address << 1;
		/*Enable ACK*/
		SET_BIT(TWI_u8_TWCR_REG,6);
		/*Enable TWI*/
		SET_BIT(TWI_u8_TWCR_REG,2);
	}
	else
	{
		Local_enuErrorState = TWI_SLAVE_ADDRESS_NOK;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_u8SendStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/*Clear Flag + Start Condition*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	SET_BIT(TWI_u8_TWCR_REG,5);
	/*Wait For The Flag To Be One*/
	while(!GET_BIT(TWI_u8_TWCR_REG,7));
	/*Check The Status Code = Start Condition Code(0x08 from datasheet)*/
	if((TWI_u8_TWSR_REG & 0xF8) != 0x08)
	{
		Local_enuErrorState = TWI_START_CONDITION_ERROR;
	}		
	/*Clear Start Condition*/
	CLR_BIT(TWI_u8_TWCR_REG,5);
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_u8SendReStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/*Clear Flag + Start Condation*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	SET_BIT(TWI_u8_TWCR_REG,5);
	/*Wait For The Flag To Be One*/
	while(!GET_BIT(TWI_u8_TWCR_REG,7));
	/*Check The Status Code = Repeated Start Condation Code */
	if((TWI_u8_TWSR_REG & 0xF8) != 0x10)
	{
		Local_enuErrorState = TWI_REPEATEDSTART_CONDITION_ERROR;
	}		
	
	/*Clear Start Condition*/
	CLR_BIT(TWI_u8_TWCR_REG,5);
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_u8SendStopCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/*Clear Flag + Stop Condation*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	SET_BIT(TWI_u8_TWCR_REG,4);
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_u8SendSlaveAddressWithWriteOperation(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	if((Copy_u8SlaveAddress <= 127)&&(Copy_u8SlaveAddress != 0))
	{
		/*Write Slave Address + 0 in TWDR*/
		TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1;
		CLR_BIT(TWI_u8_TWDR_REG,0); 
		/*clear Flag*/
		SET_BIT(TWI_u8_TWCR_REG,7);
		/*Wait For The Flag To Be One*/
		while(!GET_BIT(TWI_u8_TWCR_REG,7));
		/*Check The Status Code = SLA + W */
		if((TWI_u8_TWSR_REG & 0xF8) != 0x18)
		{
			Local_enuErrorState = TWI_SendSlaveAddressWithWriteOperation_NOK;
		}
	}
	else
	{
		Local_enuErrorState = TWI_SLAVE_ADDRESS_NOK;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_u8SendSlaveAddressWithReadOperation( u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	if((Copy_u8SlaveAddress <= 127)&&(Copy_u8SlaveAddress != 0))
	{
		/*Write Slave Address + 1 in TWDR*/
		TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1;
		SET_BIT(TWI_u8_TWDR_REG,0); 
		/*clear Flag*/
		SET_BIT(TWI_u8_TWCR_REG,7);
		/*Wait For The Flag To Be One*/
		while(!GET_BIT(TWI_u8_TWCR_REG,7));
		/*Check The Status Code = SLA + R */
		if((TWI_u8_TWSR_REG & 0xF8) != 0x40)
		{
			Local_enuErrorState = TWI_SendSlaveAddressWithReadOperation_NOK;
		}
	}
	else
	{
		Local_enuErrorState = TWI_SLAVE_ADDRESS_NOK;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_u8SendDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/*Write Data Byte in TWDR*/
	TWI_u8_TWDR_REG = Copy_u8DataByte;
	/*clear Flag*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	/*Wait For The Flag To Be One*/
	while(!GET_BIT(TWI_u8_TWCR_REG,7));
	/*Check The Status Code = MasterSendData*/
	if((TWI_u8_TWSR_REG & 0xF8) != 0x28)
	{
		Local_enuErrorState = TWI_MasterSendDataByte_NOK;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_u8ReadDataByte(u8* Copy_pu8RecieavedData)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/*Check Pointer*/
	if(Copy_pu8RecieavedData != NULL)
	{
		/*clear Flag*/
		SET_BIT(TWI_u8_TWCR_REG,7);
		/*Wait For The Flag To Be One*/
		while(!GET_BIT(TWI_u8_TWCR_REG,7));
		/*Check The Status Code = MasterRecievedData*/
		if((TWI_u8_TWSR_REG & 0xF8) != 0x50)
		{
			Local_enuErrorState = TWI_MasterReadDataByte_NOK;
		}
		else
		{
			/*Read Data in The Pointer*/
			*Copy_pu8RecieavedData = TWI_u8_TWDR_REG;
		}
	}
	else
	{
		Local_enuErrorState = TWI_NULL_POINTER;
	}
	return Local_enuErrorState;
}