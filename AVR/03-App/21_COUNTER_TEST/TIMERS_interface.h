/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 16/10/2022      *****/
/********** SWC     : TIMERS          *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidTimer0Init(void);

u8   TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void));

u8   TIMERS_u8Timer0Count(u8* Copy_pu8Counter);

#endif
