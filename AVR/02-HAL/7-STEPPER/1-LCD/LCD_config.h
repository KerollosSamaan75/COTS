/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 10/9/2022        *****/
/********** SWC     : LCD             *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
/*Options 1-DIO_u8_PORTA
          2-DIO_u8_PORTB
          3-DIO_u8_PORTC
          4-DIO_u8_PORTD */
			
#define  LCD_u8_CONTROL_PORT     DIO_u8_PORTA  

#define  LCD_u8_RS_PIN           DIO_u8_PIN0 
#define  LCD_u8_RW_PIN           DIO_u8_PIN1
#define  LCD_u8_E_PIN            DIO_u8_PIN2 

#define  LCD_u8_DATA_PORT        DIO_u8_PORTD
/***************************************************************************************************************************/
/***************************************************************************************************************************/

/*Option  1-BIT_LENGTH_8
          2-BIT_LENGTH_4  */
		  
#define  LCD_u8_MODE  BIT_LENGTH_8    
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/*Option 1-TWO_LINE_DISPLAY      
         2-ONE_LINE_DISPLAY */

#define  LCD_u8_INTIAL_LINE_NUM    	TWO_LINE_DISPLAY
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/*Option 1-FONT_SEVEN
         2-FONT_TEN */

#define  LCD_u8_INTIAL_FONT 	FONT_SEVEN	 
/***************************************************************************************************************************/
/***************************************************************************************************************************/
/*Option 1-CURSOR_ENABLE
         2-CURSOR_DISABLE */
		 
#define LCD_u8_INTIAL_CURSOR_DISPLAY    CURSOR_DISABLE
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
/*Option 1-CURSOR_BLINK_ON  
         2-CURSOR_BLINK_OFF */

#define LCD_u8_INTIAL_CURSOR_BLINK  	CURSOR_BLINK_OFF	 

#endif