/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 25/11/2022      *****/
/********** SWC     : TWI            *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum
{
	TWI_OK = 1,
	TWI_START_CONDITION_ERROR,
	TWI_REPEATEDSTART_CONDITION_ERROR,
	TWI_SLAVE_ADDRESS_NOK,
	TWI_SendSlaveAddressWithWriteOperation_NOK,
	TWI_SendSlaveAddressWithReadOperation_NOK,
	TWI_MasterSendDataByte_NOK,
	TWI_NULL_POINTER,
	TWI_MasterReadDataByte_NOK
}TWI_ErrorState;


void TWI_voidMasterInit(void);

TWI_ErrorState   TWI_u8SlaveInit(u8 Copy_u8Address);

TWI_ErrorState   TWI_u8SendStartCondition(void);

TWI_ErrorState   TWI_u8SendReStartCondition(void);

TWI_ErrorState   TWI_u8SendStopCondition(void);

TWI_ErrorState   TWI_u8SendSlaveAddressWithWriteOperation(u8 Copy_u8SlaveAddress);

TWI_ErrorState   TWI_u8SendSlaveAddressWithReadOperation( u8 Copy_u8SlaveAddress);

TWI_ErrorState   TWI_u8SendDataByte(u8 Copy_u8DataByte);

TWI_ErrorState   TWI_u8ReadDataByte(u8* Copy_pu8RecieavedData);

#endif