/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 18/9/2022        *****/
/********** SWC     : KPD             *****/
/********** verison : v-1             *****/
/******************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H
#define KPD_u8_KEYS      {{'7','8','9','/'},\
	                      {'4','5','6','*'},\
	                      {'1','2','3','-'},\
	                      {'E','0','=','+'}}
						  
#define KPD_u8_ROW_PORT       DIO_u8_PORTC
#define KPD_u8_COL_PORT       DIO_u8_PORTD

#define KPD_u8_R1_PIN     DIO_u8_PIN5
#define KPD_u8_R2_PIN     DIO_u8_PIN4
#define KPD_u8_R3_PIN     DIO_u8_PIN3
#define KPD_u8_R4_PIN     DIO_u8_PIN2

#define KPD_u8_C1_PIN     DIO_u8_PIN7
#define KPD_u8_C2_PIN     DIO_u8_PIN6
#define KPD_u8_C3_PIN     DIO_u8_PIN5
#define KPD_u8_C4_PIN     DIO_u8_PIN3


#endif
