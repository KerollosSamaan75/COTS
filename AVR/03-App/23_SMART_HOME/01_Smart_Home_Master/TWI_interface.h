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
	TWI_SLA_ERROR,
	
	TWI_SC_ACK_ERROR,
	
	TWI_RSC_ACK_ERROR,
	
	TWI_MT_SLA_W_ACK_ERROR,
	
	TWI_MR_SLA_R_ACK_ERROR,
	
	TWI_MT_DATA_ACK_ERROR,
	
	TWI_MR_DATA_ACK_ERROR,
	
	TWI_NULL_POINTER
	
}TWI_ErrorState;


void             TWI_voidMasterInit(void);

TWI_ErrorState   TWI_enuSlaveInit(u8 Copy_u8Address);
					 
TWI_ErrorState   TWI_enuSendStartCondition(void);
					 
TWI_ErrorState   TWI_enuSendReStartCondition(void);
					 
TWI_ErrorState   TWI_enuSendStopCondition(void);
					 
TWI_ErrorState   TWI_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAddress);
					 
TWI_ErrorState   TWI_enuSendSlaveAddressWithRead( u8 Copy_u8SlaveAddress);
					 
TWI_ErrorState   TWI_enuMasterSendDataByte(u8 Copy_u8DataByte);
					 
TWI_ErrorState   TWI_enuMasterReadDataByte(u8* Copy_pu8RecieavedData);

#endif
