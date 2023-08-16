/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 08/10/2022      *****/
/********** SWC     : ADC             *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#define ADC_u8_CHANNEL_0      0
#define ADC_u8_CHANNEL_1      1
#define ADC_u8_CHANNEL_2      2
#define ADC_u8_CHANNEL_3      3
#define ADC_u8_CHANNEL_4      4
#define ADC_u8_CHANNEL_5      5
#define ADC_u8_CHANNEL_6      6
#define ADC_u8_CHANNEL_7      7

void ADC_voidInit(void);

u8 ADC_u8GetDigitalValueSyncNonBlocking(u8 Copy_u8ChannelNum,u16 *Copy_pu16DigitalValue);

u8 ADC_u8GetDigitalValueAsync          (u8 Copy_u8ChannelNum,void(*Copy_pfNotification)(u16));
#endif