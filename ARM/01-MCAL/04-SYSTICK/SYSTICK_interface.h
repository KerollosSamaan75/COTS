/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 14/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void SYSTICK_voidInit               (void);
void SYSTICK_voidEnableTimer        (void);
void SYSTICK_voidDisnableTimer      (void);
void SYSTICK_voidEnableInterrupt    (void);
void SYSTICK_voidDisableInterrupt   (void);
u8   SYSTICK_u8GetInterruptFlag     (void);
void SYSTICK_voidSetCallBack        (void(*Copy_PF)(void));
void SYSTICK_voidSetReloadValue     (u32 Copy_u32ReloadValue);





#endif
