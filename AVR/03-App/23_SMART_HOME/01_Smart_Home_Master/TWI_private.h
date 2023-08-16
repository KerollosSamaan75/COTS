/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 25/11/2022      *****/
/********** SWC     : TWI             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H 

#define TWI_u8_TWBR_REG                   *((volatile u8*)0x20)

#define TWI_u8_TWSR_REG                   *((volatile u8*)0x21)
#define TWSR_TWPS1             1
#define TWSR_TWPS0             0


#define TWI_u8_TWAR_REG                   *((volatile u8*)0x22)
#define TWAR_TWGCE             0


#define TWI_u8_TWDR_REG                   *((volatile u8*)0x23)

#define TWI_u8_TWCR_REG                   *((volatile u8*)0x56)
#define TWCR_TWINT             7
#define TWCR_TWEA              6
#define TWCR_TWSTA             5
#define TWCR_TWSTO             4
#define TWCR_TWWC              3
#define TWCR_TWEN              2
#define TWCR_TWIE              0



/* Macros For Ack in Master Transmitter Mode */
#define TWI_SC_ACK             0x08
#define TWI_RSC_ACK            0x10
#define TWI_MT_SLA_W_ACK       0x18
#define TWI_MT_DATA_ACK        0x28

/* Macros For Ack in Master Reciever Mode */
#define TWI_MR_SLA_R_ACK       0x40
#define TWI_MR_DATA_ACK        0x50

#define TWI_MR_DATA_NACK       0x58


#endif
