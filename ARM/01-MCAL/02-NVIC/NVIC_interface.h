/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 10/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void  NVIC_voidInit(void);
void  NVIC_voidEnableInterrupt  (u8 Copy_u8INTNumber);
void  NVIC_voidDisableInterrupt (u8 Copy_u8INTNumber);
void  NVIC_voidSetPendingFlag   (u8 Copy_u8INTNumber);
void  NVIC_voidClearPendingFlag (u8 Copy_u8INTNumber);
void  NVIC_voidSetPriority      (u8 Copy_u8InterruptID,u8 Copy_u8Priority);
u8    NVIC_u8GetActiveFlag      (u8 Copy_u8INTNumber);

#endif
