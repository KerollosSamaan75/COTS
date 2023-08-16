/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 18/9/2022        *****/
/********** SWC     : DIO             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define  BIT_LENGTH_8   1
#define  BIT_LENGTH_4   0

#define  TWO_LINE_DISPLAY  1
#define  ONE_LINE_DISPLAY  0

#define  FONT_SEVEN        0
#define  FONT_TEN          1

#define  CURSOR_ENABLE     1
#define  CURSOR_DISABLE    0

#define  CURSOR_BLINK_ON    1
#define  CURSOR_BLINK_OFF   0

#define  CONC(B7,B6,B5,B4,B3,B2,B1,B0)               HELP_CONC(B7,B6,B5,B4,B3,B2,B1,B0)
#define  HELP_CONC(B7,B6,B5,B4,B3,B2,B1,B0)          0b##B7##B6##B5##B4##B3##B2##B1##B0 




#endif