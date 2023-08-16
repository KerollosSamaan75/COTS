/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 02/10/2022      *****/
/********** SWC     : EXTI            *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#define EXTI_u8_MCUCR            *((volatile u8*)0x55)
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3


#define EXTI_u8_MCUCSR           *((volatile u8*)0x54)
#define ISC2	6


#define EXTI_u8_GICR             *((volatile u8*)0x5B)
#define INT0	6
#define INT1	7
#define INT2	5


#define EXTI_u8_GIFR             *((volatile u8*)0x5A)
#define INTF0	6
#define INTF1	7
#define INTF2	5


#endif