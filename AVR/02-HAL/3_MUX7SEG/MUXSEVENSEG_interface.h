/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 22/7/2023       *****/
/********** SWC     : MUXSEVENSEG     *****/
/********** verison : v-1             *****/
/******************************************/

#ifndef MUXSEVENSEG_INTERFACE_H
#define MUXSEVENSEG_INTERFACE_H

#define SEV_SEGM_1    1
#define SEV_SEGM_2    2
#define SEV_SEGM_3    3
#define SEV_SEGM_4    4

void MUXSEVENSEG_voidWriteDigit(u8 Copy_u8SevSegmNum,u8 Copy_u8Digit);

void MUXSEVENSEG_voidWriteNumber(u16 Copy_u16Number);

#endif
