/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 13/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_LINE_0       0
#define EXTI_LINE_1       1
#define EXTI_LINE_2       2
#define EXTI_LINE_3       3
#define EXTI_LINE_4       4
#define EXTI_LINE_5       5
#define EXTI_LINE_6       6
#define EXTI_LINE_7       7
#define EXTI_LINE_8       8
#define EXTI_LINE_9       9
#define EXTI_LINE_10      10
#define EXTI_LINE_11      11
#define EXTI_LINE_12      12
#define EXTI_LINE_13      13
#define EXTI_LINE_14      14
#define EXTI_LINE_15      15

#define EXTI_RISING_TRIGGER      0
#define EXTI_FALLING_TRIGGER     1
#define EXTI_ON_CHANGE_TRIGGER   2


void EXTI_Init(void);
void EXTI_voidSetSenseMood     (u8 Copy_u8Line_Num ,u8 Copy_u8SenseMood);
void EXTI_voidEnableLine       (u8 Copy_u8Line_Num);
void EXTI_voidDisableLine      (u8 Copy_u8Line_Num);
void EXTI_voidClearLineFlag    (u8 Copy_u8Line_Num);

#endif
