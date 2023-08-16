/*
 * main.c
 *
 *  Created on: Nov 21, 2022
 *      Author: Kero
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_interface.h"
#include "GI_interface.h"

#include "LCD_interface.h"

u8 UARTRecievedData;
void UpdateRecievedData(u8 Copy_RecievedData);

int main(void)
{
	DIO_voidInit();
	GI_voidEnale();
	UART_voidInit();
	LCD_voidInit();
	UART_voidSendAsynString("KERO");
	UART_voidRecieveAsyncByte(&UpdateRecievedData);
	while(1);
	return 0;
}

void UpdateRecievedData(u8 Copy_RecievedData)
{
	UARTRecievedData = Copy_RecievedData;
	LCD_voidSendChar(UARTRecievedData);
}
