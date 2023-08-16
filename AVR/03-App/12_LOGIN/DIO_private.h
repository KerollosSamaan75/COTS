/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 8/9/2022        *****/
/********** SWC     : DIO             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define  DIO_u8_PORTA_REG      *((volatile u8 *)0x3B)
#define  DIO_u8_DDRA_REG       *((volatile u8 *)0x3A)
#define  DIO_u8_PINA_REG       *((volatile u8 *)0x39)

#define  DIO_u8_PORTB_REG      *((volatile u8 *)0x38)
#define  DIO_u8_DDRB_REG       *((volatile u8 *)0x37)
#define  DIO_u8_PINB_REG       *((volatile u8 *)0x36)

#define  DIO_u8_PORTC_REG      *((volatile u8 *)0x35)
#define  DIO_u8_DDRC_REG       *((volatile u8 *)0x34)
#define  DIO_u8_PINC_REG       *((volatile u8 *)0x33)

#define  DIO_u8_PORTD_REG      *((volatile u8 *)0x32)
#define  DIO_u8_DDRD_REG       *((volatile u8 *)0x31)
#define  DIO_u8_PIND_REG       *((volatile u8 *)0x30)


/*MACROS FOR PIN DIRECTION*/
#define  DIO_u8_INTIAL_OUTPUT      1
#define  DIO_u8_INTIAL_INPUT       0

/*MACROS FOR PIN VALUE*/
#define  DIO_u8_OUTPUT_LOW         0
#define  DIO_u8_OUTPUT_HIGH		   1
#define  DIO_u8_INPUT_FLOATING     0 
#define	 DIO_u8_INPUT_PULLUP       1

#define  CONC(B7,B6,B5,B4,B3,B2,B1,B0)               HELP_CONC(B7,B6,B5,B4,B3,B2,B1,B0)
#define  HELP_CONC(B7,B6,B5,B4,B3,B2,B1,B0)          0b##B7##B6##B5##B4##B3##B2##B1##B0 




#endif