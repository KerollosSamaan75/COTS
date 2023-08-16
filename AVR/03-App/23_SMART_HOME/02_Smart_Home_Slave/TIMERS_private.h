/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 16/10/2022      *****/
/********** SWC     : TIMERS          *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H


#define TIMERS_u8_TIMSK_REG                  *((volatile u8*)0x59)
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE   5
#define TOIE2   6
#define OCIE2   7

#define TIMERS_u8_TIFR_REG                   *((volatile u8*)0x58)
#define TOV0    0
#define OCF0    1
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF     5
#define TOV2    6
#define OCF2    7

#define TIMERS_u8_TCCR0_REG                  *((volatile u8*)0x53)
#define WGM00   6
#define WGM01   3
#define COM00   4
#define COM01   5
#define CS00    0
#define CS01    1
#define CS02    2

#define TIMERS_u8_TCNT0_REG                  *((volatile u8*)0x52)

#define TIMERS_u8_OCR0_REG                   *((volatile u8*)0x5C)

#define TIMERS_u8_TCCR1A_REG                 *((volatile u8*)0x4F)
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define WGM11   1
#define WGM10   0

#define TIMERS_u8_TCCR1B_REG                 *((volatile u8*)0x4E)
#define WGM13   4
#define WGM12   3
#define CS10    0
#define CS11    1
#define CS12    2

#define TIMERS_u8_TCNT1H_REG                 *((volatile u8*)0x4D)
#define TIMERS_u8_TCNT1L_REG                 *((volatile u8*)0x4C)
#define TIMERS_u16_TCNT1_REG                 *((volatile u16*)0x4C)

#define TIMERS_u8_OCR1AH_REG                 *((volatile u8*)0x4B)
#define TIMERS_u8_OCR1AL_REG                 *((volatile u8*)0x4A)
#define TIMERS_u16_OCR1A_REG                 *((volatile u16*)0x4A)

#define TIMERS_u8_OCR1BH_REG                 *((volatile u8*)0x49)
#define TIMERS_u8_OCR1BL_REG                 *((volatile u8*)0x48)
#define TIMERS_u16_OCR1B_REG                 *((volatile u16*)0x48)

#define TIMERS_u8_ICR1H_REG                  *((volatile u8*)0x47)
#define TIMERS_u8_ICR1L_REG                  *((volatile u8*)0x46)
#define TIMERS_u16_ICR1_REG                  *((volatile u16*)0x46)


#define TIMER0_NORMAL_MOOD       0
#define TIMER0_PHASE_PWM_MOOD    1
#define TIMER0_CTC_MOOD          2
#define TIMER0_FAST_PWM_MOOD     3

#define TIMER0_NON_PWM_OC0_PIN_DISCONNECTED                            0
#define TIMER0_NON_PWM_OC0_PIN_TOGGLE                                  1
#define TIMER0_NON_PWM_OC0_PIN_CLEAR                                   2
#define TIMER0_NON_PWM_OC0_PIN_SET                                     3

#define TIMER0_FAST_PWM_OC0_PIN_CLEAR_ON_COMPARE_SET_AT_TOP            4
#define TIMER0_FAST_PWM_OC0_PIN_SET_ON_COMPARE_CLEAR_AT_TOP            5

#define TIMER0_PHASE_PWM_OC0_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER     6
#define TIMER0_PHASE_PWM_OC0_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER     7

#define TIMER0_NO_CLOCK_SOURCE            0
#define TIMER0_NO_PRE_SCALER              1
#define TIMER0_PRE_SCALER_8               2
#define TIMER0_PRE_SCALER_64              3
#define TIMER0_PRE_SCALER_256             4
#define TIMER0_PRE_SCALER_1024            5
#define TIMER0_CLOCK_ON_FALLING_EDGE      6
#define TIMER0_CLOCK_ON_RISING_EDGE       7

/*********************************************************************************************************************************/
#define TIMER1_NORMAL_MOOD       0
#define TIMER0_CTC_MOOD_4         4
#define TIMER1_FAST_PWM_MOOD_14  14


#define TIMER1_NON_PWM_OC1A_PIN_DISCONNECTED                            0
#define TIMER1_NON_PWM_OC1A_PIN_TOGGLE                                  1
#define TIMER1_NON_PWM_OC1A_PIN_CLEAR                                   2
#define TIMER1_NON_PWM_OC1A_PIN_SET                                     3

#define TIMER1_FAST_PWM_OC1A_PIN_CLEAR_ON_COMPARE_SET_AT_TOP            4
#define TIMER1_FAST_PWM_OC1A_PIN_SET_ON_COMPARE_CLEAR_AT_TOP            5

#define TIMER1_PHASE_PWM_OC1A_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER     6
#define TIMER1_PHASE_PWM_OC1A_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER     7

#define TIMER1_NON_PWM_OC1B_PIN_DISCONNECTED                            0
#define TIMER1_NON_PWM_OC1B_PIN_TOGGLE                                  1
#define TIMER1_NON_PWM_OC1B_PIN_CLEAR                                   2
#define TIMER1_NON_PWM_OC1B_PIN_SET                                     3

#define TIMER1_FAST_PWM_OC1B_PIN_CLEAR_ON_COMPARE_SET_AT_TOP            4
#define TIMER1_FAST_PWM_OC1B_PIN_SET_ON_COMPARE_CLEAR_AT_TOP            5

#define TIMER1_PHASE_PWM_OC1B_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER     6
#define TIMER1_PHASE_PWM_OC1B_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER     7

#define TIMER1_NO_CLOCK_SOURCE            0
#define TIMER1_NO_PRE_SCALER              1
#define TIMER1_PRE_SCALER_8               2
#define TIMER1_PRE_SCALER_64              3
#define TIMER1_PRE_SCALER_256             4
#define TIMER1_PRE_SCALER_1024            5
#define TIMER1_CLOCK_ON_FALLING_EDGE      6
#define TIMER1_CLOCK_ON_RISING_EDGE       7

#endif
