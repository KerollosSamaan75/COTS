/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 08/10/2022      *****/
/********** SWC     : ADC             *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADC_u8_ADMUX_REG                 *((volatile u8*)0x27)
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADC_u8_ADCSRA_REG                *((volatile u8*)0x26)
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ADC_u8_ADCH_REG                  *((volatile u8*)0x25)
#define ADC_u8_ADCL_REG                  *((volatile u8*)0x24)
#define ADC_u8_SFIOR_REG                 *((volatile u8*)0x50)

/*for read ADC in one step*/ 
#define ADC_u16_ADC_REG                  *((volatile u16*)0x24)


#endif