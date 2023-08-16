/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 22/11/2022      *****/
/********** SWC     : SPI            *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInit(void);

u8   SPI_u8TransRecieve(u8 Copy_u8TransByte , u8*Copy_pu8RecieveByte);

void SPI_voidSendSlaveByte  (u8 Copy_u8TransByte);

u8 SPI_u8RecieveByte   (u8*Copy_pu8RecieveByte);

#endif