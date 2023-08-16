/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 25/11/2022      *****/
/********** SWC     : TWI             *****/
/********** verison : v-1             *****/
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"


void TWI_voidMasterInit(void)
{
	/*Set PreScaler Value = 1*/
	CLR_BIT(TWI_u8_TWSR_REG ,TWSR_TWPS0);
	CLR_BIT(TWI_u8_TWSR_REG ,TWSR_TWPS1);

	/*Set TWBR With The Value => 400KHz*/ 
	TWI_u8_TWBR_REG = 2;

	/*Enable ACK*/
	//SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEN);
}

TWI_ErrorState   TWI_enuSlaveInit(u8 Copy_u8Address)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	
	if((Copy_u8Address <= 127)&&(Copy_u8Address != 0))
	{
		/*Set Slave Address in TWAR*/
		TWI_u8_TWAR_REG = Copy_u8Address << 1;

		/*Enable ACK*/
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEA);

		/*Enable TWI*/
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWEN);
	}
	else
	{
		Local_enuErrorState = TWI_SLA_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	/*1-Start Condition*/ 
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);
	
	/*2-Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);

	/*3-Wait For The Flag To Be One*/
	while(GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT) == 0);
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_SC_ACK)
	{
		Local_enuErrorState = TWI_SC_ACK_ERROR;
	}

	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendReStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	
	/*1-Start Condition*/ 
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);
	
	/*2-Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);

	/*3-Wait For The Flag To Be One*/
	while(GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT) == 0);
	/*Check The Status Code */
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_RSC_ACK)
	{
		Local_enuErrorState = TWI_RSC_ACK_ERROR;

	}
	
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendStopCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	/*1-Stop Condition*/
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWSTO);
	
	/*2-Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);

	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	if((Copy_u8SlaveAddress <= 127)&&(Copy_u8SlaveAddress != 0))
	{
		/*1-Write Slave Address + 0 in TWDR*/
		TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1;
		CLR_BIT(TWI_u8_TWDR_REG,0); 

		/*2-Clear Start Condition*/
	    CLR_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);

		/*3-clear Flag*/
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);

		/*4-Wait For The Flag To Be One*/
		while(GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT) == 0);

		/*Check The Status Code*/
		if((TWI_u8_TWSR_REG & 0xF8) != TWI_MT_SLA_W_ACK)
		{
			Local_enuErrorState = TWI_MT_SLA_W_ACK_ERROR;
		}

	}
	else
	{
		Local_enuErrorState = TWI_SLA_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendSlaveAddressWithRead( u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	if((Copy_u8SlaveAddress <= 127)&&(Copy_u8SlaveAddress != 0))
	{
		/*1-Write Slave Address + 1 in TWDR*/
		TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1;
		SET_BIT(TWI_u8_TWDR_REG,0); 

		/*2-Clear Start Condition*/
	    CLR_BIT(TWI_u8_TWCR_REG,TWCR_TWSTA);

		/*3-clear Flag*/
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
		
		/*4-Wait For The Flag To Be One*/
		while(GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT) == 0);
		/*Check The Status Code*/
		if((TWI_u8_TWSR_REG & 0xF8) != TWI_MR_SLA_R_ACK)
		{
			Local_enuErrorState = TWI_MR_SLA_R_ACK_ERROR;
		}

	}
	else
	{
		Local_enuErrorState = TWI_SLA_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuMasterSendDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	/*1-Write Data Byte in TWDR*/
	TWI_u8_TWDR_REG = Copy_u8DataByte;

	/*2-clear Flag*/
	SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);
	
	/*3-Wait For The Flag To Be One*/
	while(GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT) == 0);
	/*Check The Status Code*/
	if((TWI_u8_TWSR_REG & 0xF8) != TWI_MT_DATA_ACK)
	{
		Local_enuErrorState = TWI_MT_DATA_ACK_ERROR;
	}

	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuMasterReadDataByte(u8* Copy_pu8RecieavedData)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	/*Check Pointer*/
	if(Copy_pu8RecieavedData != NULL)
	{
		/*1-clear Flag*/
		SET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT);

		/*2-Wait For The Flag To Be One*/
		while(GET_BIT(TWI_u8_TWCR_REG,TWCR_TWINT) == 0);

		/*Check The Status Code*/
		if((TWI_u8_TWSR_REG & 0xF8) != TWI_MR_DATA_NACK)
		{
			Local_enuErrorState = TWI_MR_DATA_ACK_ERROR;
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

