/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 08/10/2022      *****/
/********** SWC     : ADC             *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_u32_TIME_OUT_MAX_VALUE     5000

/* ***********************
 * Prescaller Options :
 * PSC_2 		Fosc/2
 * PSC_4 		Fosc/4
 * PSC_8 		Fosc/8
 * PSC_16 		Fosc/16
 * PSC_32		Fosc/32
 * PSC_64		Fosc/64
 * PSC_128 		Fosc/128
 *************************/

#define PSC_2 		0
#define PSC_4 		1
#define PSC_8 		2
#define PSC_16 		3
#define PSC_32		4
#define PSC_64		5
#define PSC_128 	6

#define PRESCALLER		PSC_2

#endif