/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 10/9/2022        *****/
/********** SWC     : LCD            *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE_1   1
#define LCD_u8_LINE_2   2
#define LCD_u8_LINE_3   3
#define LCD_u8_LINE_4   4


void LCD_voidInit           (void); 

void LCD_voidClearScreen    (void);

void LCD_voidSendCmnd       (u8  Copy_u8Cmnd); 

void LCD_voidSendChar       (u8  Copy_u8Char); 

void LCD_voidSendStr        (u8* Copy_pu8Str );

void LCD_voidSendNum        (u32 Copy_u32Num ); 

void LCD_voidShiftRight     (void);

void LCD_voidShiftLeft      (void);

                             /*CharNum:0--->7*/                         /*LineNum:1or2*/       /*Location:0-->39*/
u8 LCD_u8SendSpecialChar    (u8 Copy_u8CharNum , u8* Copy_pu8CharShape ,u8  Copy_u8LineNum , u8 Copy_u8Location );

u8   LCD_u8GoToXY           (u8  Copy_u8LineNum , u8 Copy_u8Location);

#endif
