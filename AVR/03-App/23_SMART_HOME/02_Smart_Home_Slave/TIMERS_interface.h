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

void TIMERS_voidTimer0Enable(void);
void TIMERS_voidTimer1Enable(void);

void TIMERS_voidTimer0Disable(void);
void TIMERS_voidTimer1Disable(void);

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8Value);
void TIMERS_voidTimer1SetPreLoadValue(u16 Copy_u16Value);

u8   TIMERS_u8Timer0ReadCounter(void);
u16  TIMERS_u16Timer1ReadCounter(void);
u16  TIMERS_u16Timer1ReadInputCaptureUnit(void);

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8Value);
void TIMERS_voidTimer1SetChannel_ACompareMatchValue(u16 Copy_u16Value);
void TIMERS_voidTimer1SetChannel_BCompareMatchValue(u16 Copy_u16Value);
void TIMERS_voidTimer1SetTopValue(u16 Copy_u16Value);


void TIMERS_voidTimer0CTCInterruptEnable(void);
void TIMERS_voidTimer1ChannelA_CTCInterruptEnable(void);
void TIMERS_voidTimer1ChannelB_CTCInterruptEnable(void);
void TIMERS_voidTimer1InputCaptureInterruptEnable(void);

void TIMERS_voidTimer0OVFInterruptEnable(void);
void TIMERS_voidTimer1OVFInterruptEnable(void);

void TIMERS_voidTimer0CTCInterruptDisable(void);
void TIMERS_voidTimer1ChannelA_CTCInterruptDisable(void);
void TIMERS_voidTimer1ChannelB_CTCInterruptDisable(void);
void TIMERS_voidTimer1InputCaptureInterruptDisable(void);

void TIMERS_voidTimer0OVFInterruptDisable(void);
void TIMERS_voidTimer1OVFInterruptDisable(void);

u8   TIMERS_u8Timer0ReadOVFFlag(void);
u8   TIMERS_u8Timer1ReadOVFFlag(void);

u8   TIMERS_u8Timer0ReadCTCFlag(void);
u8   TIMERS_u8Timer1ReadChannelB_CTCFlag(void);
u8   TIMERS_u8Timer1ReadChannelA_CTCFlag(void);
u8   TIMERS_u8Timer1ReadInputCaptureFlag(void);

void TIMERS_voidTimer0ClearOVFFlag(void);
void TIMERS_voidTimer1ClearOVFFlag(void);

void TIMERS_voidTimer0ClearCTCFlag(void);
void TIMERS_voidTimer1ClearChannelB_CTCFlag(void);
void TIMERS_voidTimer1ClearChannelA_CTCFlag(void);
void TIMERS_voidTimer1ClearInputCaptureFlag(void);

u8   TIMERS_u8Timer0OVFSetCallBack(void(*Copy_pf)(void));
u8   TIMERS_u8Timer1OVFSetCallBack(void(*Copy_pf)(void));

u8   TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf)(void));
u8   TIMERS_u8Timer1ChannelA_CTCSetCallBack(void(*Copy_pf)(void));
u8   TIMERS_u8Timer1ChannelB_CTCSetCallBack(void(*Copy_pf)(void));
u8   TIMERS_u8Timer1InputCaptureSetCallBack(void(*Copy_pf)(void));



#endif
