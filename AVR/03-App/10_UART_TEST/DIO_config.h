/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 8/9/2022        *****/
/********** SWC     : DIO             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/* Intial Directions For All Pins */

/* Options:  DIO_u8_INTIAL_OUTPUT
          :  DIO_u8_INTIAL_INPUT */
		  
/* PORTA */
#define  DIO_u8_PA0_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PA1_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PA2_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PA3_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PA4_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PA5_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PA6_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PA7_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
                                                         
/* PORTB */                                              
#define  DIO_u8_PB0_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PB1_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PB2_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PB3_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PB4_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PB5_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PB6_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
#define  DIO_u8_PB7_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT
                                                         
/* PORTC */                                              
#define  DIO_u8_PC0_INTIAL_DIRECTION                    DIO_u8_INTIAL_INPUT
#define  DIO_u8_PC1_INTIAL_DIRECTION                    DIO_u8_INTIAL_INPUT
#define  DIO_u8_PC2_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT   //R4
#define  DIO_u8_PC3_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT   //R3
#define  DIO_u8_PC4_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT   //R2
#define  DIO_u8_PC5_INTIAL_DIRECTION                    DIO_u8_INTIAL_OUTPUT   //R1
#define  DIO_u8_PC6_INTIAL_DIRECTION                    DIO_u8_INTIAL_INPUT
#define  DIO_u8_PC7_INTIAL_DIRECTION                    DIO_u8_INTIAL_INPUT
                                                         
/* PORTD */                                              
#define  DIO_u8_PD0_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT
#define  DIO_u8_PD1_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT
#define  DIO_u8_PD2_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT
#define  DIO_u8_PD3_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT
#define  DIO_u8_PD4_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT
#define  DIO_u8_PD5_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT
#define  DIO_u8_PD6_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT
#define  DIO_u8_PD7_INTIAL_DIRECTION                     DIO_u8_INTIAL_INPUT


/* Intial Values For All Pins */

/* Options: DIO_u8_OUTPUT_LOW
	      : DIO_u8_OUTPUT_HIGH
          : DIO_u8_INPUT_FLOATING
	      : DIO_u8_INPUT_PULLUP */
		  
/* PORTA */
#define  DIO_u8_PA0_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
#define  DIO_u8_PA1_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
#define  DIO_u8_PA2_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
#define  DIO_u8_PA3_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
#define  DIO_u8_PA4_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
#define  DIO_u8_PA5_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
#define  DIO_u8_PA6_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
#define  DIO_u8_PA7_INTIAL_VALUE                     DIO_u8_OUTPUT_LOW
                                                       
					                                   
/* PORTB */                                            
#define  DIO_u8_PB0_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PB1_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PB2_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PB3_INTIAL_VALUE                       DIO_u8_OUTPUT_LOW
#define  DIO_u8_PB4_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PB5_INTIAL_VALUE                       DIO_u8_OUTPUT_LOW
#define  DIO_u8_PB6_INTIAL_VALUE                       DIO_u8_OUTPUT_LOW
#define  DIO_u8_PB7_INTIAL_VALUE                       DIO_u8_OUTPUT_LOW
                                                     
                                                     
/* PORTC */                                          
#define  DIO_u8_PC0_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
#define  DIO_u8_PC1_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
#define  DIO_u8_PC2_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PC3_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PC4_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PC5_INTIAL_VALUE                       DIO_u8_OUTPUT_HIGH
#define  DIO_u8_PC6_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
#define  DIO_u8_PC7_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
                                                       
					                                   
/* PORTD */                                            
#define  DIO_u8_PD0_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
#define  DIO_u8_PD1_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
#define  DIO_u8_PD2_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
#define  DIO_u8_PD3_INTIAL_VALUE                       DIO_u8_INPUT_PULLUP
#define  DIO_u8_PD4_INTIAL_VALUE                       DIO_u8_INPUT_FLOATING
#define  DIO_u8_PD5_INTIAL_VALUE                       DIO_u8_INPUT_PULLUP
#define  DIO_u8_PD6_INTIAL_VALUE                       DIO_u8_INPUT_PULLUP
#define  DIO_u8_PD7_INTIAL_VALUE                       DIO_u8_INPUT_PULLUP
                    
#endif
