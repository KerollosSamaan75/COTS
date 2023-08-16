/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 22/11/2022      *****/
/********** SWC     : SPI             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H 


#define  SPI_u8_MASTE_MOOD    1
#define  SPI_u8_SLAVE_MOOD    2


#define SPI_u8_SPDR_REG                   *((volatile u8*)0x2F)

#define SPI_u8_SPSR_REG                   *((volatile u8*)0x2E)
#define SPIF    7

#define SPI_u8_SPCR_REG                   *((volatile u8*)0x2D)
#define SPIE    7
#define SPE     6
#define DORD    5
#define MASTR   4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0




#endif
