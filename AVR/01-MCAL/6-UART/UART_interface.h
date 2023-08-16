/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 19/11/2022      *****/
/********** SWC     : UART            *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);

void UART_voidSendByte(u8 Copy_u8DataByte);

u8  UART_u8RecieveByte(u8* Copy_pu8RecByte);

#endif