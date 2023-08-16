/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 16/10/2022      *****/
/********** SWC     : TIMERS          *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidTimer0Init(void);
void TIMERS_voidTimer1Init(void);

u8   TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void));

void TIMERS_voidTimer1SetOCR1A(u16 Copy_OCR1A_Value);




#endif