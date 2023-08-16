/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 29/11/2022      *****/
/********** SWC     : EEPROM           *****/
/********** verison : v-1             *****/
/******************************************/
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress , u8 Copy_u8DataByte);
u8 EEPROM_u8ReadDataByte (u16 Copy_u16ByteAddress , u8* Copy_pu8ReturnedData);

#endif