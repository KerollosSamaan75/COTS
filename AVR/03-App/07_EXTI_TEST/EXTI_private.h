/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 02/10/2022      *****/
/********** SWC     : EXTI            *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#define EXTI_u8_MCUCR            *((volatile u8*)0x55)
#define EXTI_u8_MCUCSR           *((volatile u8*)0x54)
#define EXTI_u8_GICR             *((volatile u8*)0x5B)
#define EXTI_u8_GIFR             *((volatile u8*)0x5A)


#endif