/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 30/07/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIOA     0
#define GPIOB     1
#define GPIOC     2
#define GPIOD     3
#define GPIOE     4
#define GPIOF     5

#define  PIN0     0
#define  PIN1     1
#define  PIN2     2
#define  PIN3     3
#define  PIN4     4
#define  PIN5     5
#define  PIN6     6
#define  PIN7     7
#define  PIN8     8
#define  PIN9     9
#define  PIN10    10
#define  PIN11    11
#define  PIN12    12
#define  PIN13    13
#define  PIN14    14
#define  PIN15    15


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

       
#define  ALTFUNCTION_PUSH_PULL_LOW_SPEED             10
#define  ALTFUNCTION_PUSH_PULL_MEDIUM_SPEED          11
#define  ALTFUNCTION_PUSH_PULL_HIGH_SPEED            12

#define  ALTFUNCTION_OPEN_DRAIN_LOW_SPEED            13
#define  ALTFUNCTION_OPEN_DRAIN_MEDIUM_SPEED         14
#define  ALTFUNCTION_OPEN_DRAIN_HIGH_SPEED           15
                     

#define GPIO_u8_HIGH  1
#define GPIO_u8_LOW   0


void GPIO_voidInit(void); 

void GPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Mode); 

void GPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value);

u8 GPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN);


#endif
