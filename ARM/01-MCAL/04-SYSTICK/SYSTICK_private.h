/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 14/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define  AHB_8_CLOCK       0 
#define  AHB_CLOCK         1

#define STK_CTRL    (*((volatile u32*)0xE000E010))
#define STK_LOAD    (*((volatile u32*)0xE000E014))
#define STK_VAL     (*((volatile u32*)0xE000E018))
#define STK_CALIB   (*((volatile u32*)0xE000E01C))

#endif 
