/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 30/07/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*Macro For Ports*/
#define  DIO_u8_PORTA   0
#define  DIO_u8_PORTB   1
#define  DIO_u8_PORTC   2
#define  DIO_u8_PORTD   3
#define  DIO_u8_PORTE   4
#define  DIO_u8_PORTF   5

/*Macro For PINS*/
#define  DIO_u8_PIN0    0
#define  DIO_u8_PIN1	1
#define  DIO_u8_PIN2	2
#define  DIO_u8_PIN3	3
#define  DIO_u8_PIN4	4
#define  DIO_u8_PIN5	5
#define  DIO_u8_PIN6	6
#define  DIO_u8_PIN7	7
#define  DIO_u8_PIN8	8
#define  DIO_u8_PIN9	9
#define  DIO_u8_PIN10	10
#define  DIO_u8_PIN11	11
#define  DIO_u8_PIN12	12
#define  DIO_u8_PIN13	13
#define  DIO_u8_PIN14	14
#define  DIO_u8_PIN15	15


#define  INPUT_FLOATING                               0
#define  INPUT_PULL_UP                                1
#define  INPUT_PULL_DOWN                              2
#define  INPUT_ANALOG                                 3
                         
#define  OUTPUT_PUSH_PULL_LOW_SPEED                   4
#define  OUTPUT_PUSH_PULL_MEDIUM_SPEED                5
#define  OUTPUT_PUSH_PULL_HIGH_SPEED                  6

#define  OUTPUT_OPEN_DRAIN_LOW_SPEED                  7
#define  OUTPUT_OPEN_DRAIN_MEDIUM_SPEED               8
#define  OUTPUT_OPEN_DRAIN_HIGH_SPEED                 9

       
#define  ALTFUNCTION_PUSH_PULL                        10
#define  ALTFUNCTION_OPEN_DRAIN                       11

                     
/*Macro For Pin Value*/
#define  DIO_u8_HIGH  1
#define  DIO_u8_LOW   0


void GPIO_voidInit(void); 

void DIO_voidSetPinDirection   (u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Mode);

void DIO_voidSetPinValue       (u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value);

u8   DIO_u8GetPinValue         (u8 Copy_u8PORT , u8 Copy_u8PIN);


#endif
