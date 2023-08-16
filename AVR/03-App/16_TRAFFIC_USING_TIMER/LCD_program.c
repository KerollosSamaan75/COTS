   /******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 10/9/2022       *****/
/********** SWC     : LCD             *****/
/********** verison : v-1             *****/
/******************************************/

/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

/*MCAL*/
#include "DIO_interface.h"

/*HAL*/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
void LCD_voidInit(void)
{
	_delay_ms(35);
	/* Function Set CMND*/
	LCD_voidSendCmnd(CONC(0,0,1,LCD_u8_MODE,LCD_u8_INTIAL_LINE_NUM,LCD_u8_INTIAL_FONT,0,0));
	_delay_us(40);
	/* Display NO/OFF Control */
	LCD_voidSendCmnd(CONC(0,0,0,0,1,1,LCD_u8_INTIAL_CURSOR_DISPLAY,LCD_u8_INTIAL_CURSOR_BLINK));
	_delay_us(40);
	/* Display Clear */
	LCD_voidSendCmnd(0b00000001);
	_delay_ms(2);
	/* Entry Mood Set */
	LCD_voidSendCmnd(0b00000110);
	
}

void LCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
	#if LCD_u8_MODE == BIT_LENGTH_8
	/* step-1:Rs = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RS_PIN  ,DIO_u8_LOW);
	/*       :Rw = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RW_PIN  ,DIO_u8_LOW);
	/* Write command */
	DIO_u8SetPortValue (LCD_u8_DATA_PORT , Copy_u8Cmnd  );
	/* E = 1 */
	DIO_u8SetPinValue  ( LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_HIGH);
	_delay_us(1);
	/* E = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_LOW);
	
	#elif LCD_u8_MODE == BIT_LENGTH_4
	/* step-1:Rs = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RS_PIN  ,DIO_u8_LOW);
	/*       :Rw = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RW_PIN  ,DIO_u8_LOW);
	/* Write command */
	DIO_u8SetPortValue (LCD_u8_DATA_PORT , Copy_u8Cmnd  );
	/* E = 1 */
	DIO_u8SetPinValue  ( LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_HIGH);
	_delay_us(1);
	/* E = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_LOW);
	/* step-1:Rs = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RS_PIN  ,DIO_u8_LOW);
	/*       :Rw = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RW_PIN  ,DIO_u8_LOW);
	/* Write command */
	DIO_u8SetPortValue (LCD_u8_DATA_PORT , Copy_u8Cmnd <<4 );
	/* E = 1 */
	DIO_u8SetPinValue  ( LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_HIGH);
	_delay_us(1);
	/* E = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_LOW);
	
	
	
	
	#endif
}

void LCD_voidSendChar(u8 Copy_u8Char)
{
	/* step-1:Rs = 1 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RS_PIN  ,DIO_u8_HIGH);
	/*       :Rw = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_RW_PIN  ,DIO_u8_LOW);
	/* Write char */
	DIO_u8SetPortValue (LCD_u8_DATA_PORT , Copy_u8Char  );
	/* E = 1 */
	DIO_u8SetPinValue  ( LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_HIGH);
	_delay_us(1);
	/* E = 0 */
	DIO_u8SetPinValue  (LCD_u8_CONTROL_PORT ,LCD_u8_E_PIN  ,DIO_u8_LOW);
}

void LCD_voidSendStr(u8* Copy_pu8Str )
{
	u8 Local_u8StrLen = 0;
	while( Copy_pu8Str[Local_u8StrLen] != '\0')
	{
		LCD_voidSendChar ( Copy_pu8Str[Local_u8StrLen] );
		Local_u8StrLen++;
	}
}

void LCD_voidSendNum (u32  Copy_u32Num )
{
    u8 Local_u8NumArr[10]= {0};
	u8 Local_u8ArrIndex = 0;
	while(Copy_u32Num > 0)
	{
		Local_u8NumArr[Local_u8ArrIndex] = (Copy_u32Num % 10);
		Copy_u32Num /=10;
		Local_u8ArrIndex++;
	}
	for (int i = Local_u8ArrIndex-1 ; i>=0 ;i--)
	{
		LCD_voidSendChar( Local_u8NumArr[i] + '0');
	}
} 

u8 LCD_u8GoToXY (u8 Copy_u8LineNum , u8 Copy_u8Location)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8Location <= 39)
	{
			switch (Copy_u8LineNum)
		{
			case LCD_u8_LINE_1   : LCD_voidSendCmnd (0x80 + Copy_u8Location); break;
			case LCD_u8_LINE_2   : LCD_voidSendCmnd (0xC0 + Copy_u8Location); break;
			default              : Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void LCD_voidClearScreen (void)
{
	LCD_voidSendCmnd (0x01);
	_delay_ms (2);
}

u8 LCD_u8SendSpecialChar    (u8 Copy_u8CharNum , u8* Copy_pu8CharShape ,u8  Copy_u8LineNum , u8 Copy_u8Location )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8CharNum <= 7)&&(Copy_u8Location <= 39)&&(Copy_u8LineNum <=2)) 
	{
		switch(Copy_u8CharNum)
		{
			case 0:LCD_voidSendCmnd(0b01000000); break; //0
			case 1:LCD_voidSendCmnd(0b01001000); break; //8
			case 2:LCD_voidSendCmnd(0b01010000); break; //16
			case 3:LCD_voidSendCmnd(0b01011000); break; //24
			case 4:LCD_voidSendCmnd(0b01100000); break; //32
			case 5:LCD_voidSendCmnd(0b01101000); break; //40
			case 6:LCD_voidSendCmnd(0b01110000); break; //48
			case 7:LCD_voidSendCmnd(0b01111000); break; //56
		}
		for(int i=0 ;i <8 ;i++)
		{
		   LCD_voidSendChar(Copy_pu8CharShape[i]);
		}
	    LCD_u8GoToXY(Copy_u8LineNum ,Copy_u8Location );	
		LCD_voidSendChar(Copy_u8CharNum);
	}
	else
	{
	  Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void LCD_voidShiftRight(void)
{
	LCD_voidSendCmnd(0b00011100);
	_delay_ms(100);
}

void LCD_voidShiftLeft(void)
{
	LCD_voidSendCmnd(0b00011000);
	_delay_ms(100);
}