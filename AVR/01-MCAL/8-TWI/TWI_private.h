/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 25/11/2022      *****/
/********** SWC     : TWI             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H 


#define TWI_u8_TWDR_REG                   *((volatile u8*)0x23)
#define TWI_u8_TWAR_REG                   *((volatile u8*)0x22)
#define TWI_u8_TWSR_REG                   *((volatile u8*)0x21)
#define TWI_u8_TWBR_REG                   *((volatile u8*)0x20)
#define TWI_u8_TWCR_REG                   *((volatile u8*)0x56)

#endif