/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 22/11/2022      *****/
/********** SWC     : SPI             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H 


#define SPI_u8_MASTE_MOOD    1
#define  SPI_u8_SLAVE_MOOD   2


#define SPI_u8_SPDR_REG                   *((volatile u8*)0x2F)
#define SPI_u8_SPSR_REG                   *((volatile u8*)0x2E)
#define SPI_u8_SPCR_REG                   *((volatile u8*)0x2D)



#endif