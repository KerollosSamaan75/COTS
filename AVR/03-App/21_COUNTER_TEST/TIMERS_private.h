/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 16/10/2022      *****/
/********** SWC     : TIMERS          *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

#define TIMERS_u8_TIMSK_REG                  *((volatile u8*)0x59)
#define TIMERS_u8_TIFR_REG                   *((volatile u8*)0x58)
#define TIMERS_u8_TCCR0_REG                  *((volatile u8*)0x53)
#define TIMERS_u8_TCNT0_REG                  *((volatile u8*)0x52)
#define TIMERS_u8_OCR0_REG                   *((volatile u8*)0x5C)

#endif
