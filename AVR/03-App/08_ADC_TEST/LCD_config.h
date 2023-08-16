/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 10/9/2022        *****/
/********** SWC     : LCD             *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define LCD_RS_PORT      DIO_u8_PORTA

#define LCD_EN_PORT      DIO_u8_PORTA

#define LCD_DATA_PORT    DIO_u8_PORTB

#define LCD_RS_PIN       DIO_u8_PIN3

#define LCD_EN_PIN       DIO_u8_PIN2

#define LCD_DB4_PIN       DIO_u8_PIN0
#define LCD_DB5_PIN       DIO_u8_PIN1
#define LCD_DB6_PIN       DIO_u8_PIN2
#define LCD_DB7_PIN       DIO_u8_PIN4

/*Option 1-CURSOR_ENABLE
         2-CURSOR_DISABLE */

#define CURSOR_DISPLAY    CURSOR_DISABLE
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
/*Option 1-CURSOR_BLINK_ON
         2-CURSOR_BLINK_OFF */

#define CURSOR_BLINK  	CURSOR_BLINK_OFF
#endif
