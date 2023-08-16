/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 16/10/2022      *****/
/********** SWC     : TIMERS          *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H


void TIMERS_voidTimer0Init(void);
void TIMERS_voidTimer0Enable(void);
void TIMERS_voidTimer0Disable(void);
void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8Value);
u8   TIMERS_u8Timer0ReadCounter(void);
void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8Value);
void TIMERS_voidTimer0CTCInterruptEnable(void);
void TIMERS_voidTimer0OVFInterruptEnable(void);
void TIMERS_voidTimer0CTCInterruptDisable(void);
void TIMERS_voidTimer0OVFInterruptDisable(void);
u8   TIMERS_u8Timer0ReadOVFFlag(void);
u8   TIMERS_u8Timer0ReadCTCFlag(void);
void TIMERS_voidTimer0ClearOVFFlag(void);
void TIMERS_voidTimer0ClearCTCFlag(void);
u8   TIMERS_u8Timer0OVFSetCallBack(void(*Copy_pf)(void));
u8   TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf)(void));




#endif
