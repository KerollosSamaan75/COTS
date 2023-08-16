/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 16/10/2022      *****/
/********** SWC     : TIMERS          *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

/********************************************************************************************************************************/
/**************************************       TIMER0 CONFIG    ******************************************************************/
/********************************************************************************************************************************/
/* Options : 1-TIMER0_NORMAL_MOOD
             2-TIMER0_PHASE_PWM_MOOD
             3-TIMER0_CTC_MOOD
             4-TIMER0_FAST_PWM_MOOD */

#define TIMER0_u8_MODE  TIMER0_CTC_MOOD


/*Options : 1-TIMER0_NON_PWM_OC0_PIN_DISCONNECTED
            2-TIMER0_NON_PWM_OC0_PIN_TOGGLE
            3-TIMER0_NON_PWM_OC0_PIN_CLEAR
            4-TIMER0_NON_PWM_OC0_PIN_SET

            5-TIMER0_FAST_PWM_OC0_PIN_CLEAR_ON_COMPARE_SET_AT_TOP
            6-TIMER0_FAST_PWM_OC0_PIN_SET_ON_COMPARE_CLEAR_AT_TOP

            7-TIMER0_PHASE_PWM_OC0_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER
            8-TIMER0_PHASE_PWM_OC0_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER */

#define TIMER0_OC0_PIN_MOOD    TIMER0_NON_PWM_OC0_PIN_DISCONNECTED


/*Options : 1-TIMER0_NO_CLOCK_SOURCE
            2-TIMER0_NO_PRE_SCALER
            3-TIMER0_PRE_SCALER_8
            4-TIMER0_PRE_SCALER_64
            5-TIMER0_PRE_SCALER_256
            6-TIMER0_PRE_SCALER_1024
            7-TIMER0_CLOCK_ON_FALLING_EDGE
            8-TIMER0_CLOCK_ON_RISING_EDGE */

#define  TIMER0_u8_PRE_SCALER_MOOD    TIMER0_PRE_SCALER_1024


/********************************************************************************************************************************/
/********************************************************************************************************************************/

/********************************************************************************************************************************/
/***********************************************   TIMER_1 CONFIG    ************************************************************/
/********************************************************************************************************************************/

/* Options : 1-TIMER1_NORMAL_MOOD
             2- TIMER0_CTC_MOOD_4
             3-TIMER1_FAST_PWM_MOOD_14 */

#define TIMER1_u8_MODE  TIMER1_FAST_PWM_MOOD_14


/*Options : 1-TIMER1_NON_PWM_OC1A_PIN_DISCONNECTED
            2-TIMER1_NON_PWM_OC1A_PIN_TOGGLE
            3-TIMER1_NON_PWM_OC1A_PIN_CLEAR
            4-TIMER1_NON_PWM_OC1A_PIN_SET

            5-TIMER1_FAST_PWM_OC1A_PIN_CLEAR_ON_COMPARE_SET_AT_TOP
            6-TIMER1_FAST_PWM_OC1A_PIN_SET_ON_COMPARE_CLEAR_AT_TOP

            7-TIMER1_PHASE_PWM_OC1A_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER
            8-TIMER1_PHASE_PWM_OC1A_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER */


#define TIMER1_OC1A_PIN_MOOD    TIMER1_FAST_PWM_OC1A_PIN_CLEAR_ON_COMPARE_SET_AT_TOP


/*Options : 1-TIMER1_NON_PWM_OC1B_PIN_DISCONNECTED
            2-TIMER1_NON_PWM_OC1B_PIN_TOGGLE
            3-TIMER1_NON_PWM_OC1B_PIN_CLEAR
            4-TIMER1_NON_PWM_OC1B_PIN_SET

            5-TIMER1_FAST_PWM_OC1B_PIN_CLEAR_ON_COMPARE_SET_AT_TOP
            6-TIMER1_FAST_PWM_OC1B_PIN_SET_ON_COMPARE_CLEAR_AT_TOP

            7-TIMER1_PHASE_PWM_OC1B_PIN_CLEAR_UP_COUNTER_SET_DOWN_COUNTER
            8-TIMER1_PHASE_PWM_OC1B_PIN_SET_UP_COUNTER_CLEAR_DOWN_COUNTER */


#define TIMER1_OC1B_PIN_MOOD    TIMER1_NON_PWM_OC1B_PIN_DISCONNECTED


/*Options : 1-TIMER1_NO_CLOCK_SOURCE
            2-TIMER1_NO_PRE_SCALER
            3-TIMER1_PRE_SCALER_8
            4-TIMER1_PRE_SCALER_64
            5-TIMER1_PRE_SCALER_256
            6-TIMER1_PRE_SCALER_1024
            7-TIMER1_CLOCK_ON_FALLING_EDGE
            8-TIMER1_CLOCK_ON_RISING_EDGE  */

#define  TIMER1_u8_PRE_SCALER_MOOD    TIMER1_PRE_SCALER_8

#endif
