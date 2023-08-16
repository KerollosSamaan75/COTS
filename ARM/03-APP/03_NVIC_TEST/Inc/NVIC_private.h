/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 10/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H



#define  GROUP_16_SUBBRIORITY_0      0x05FA0300      //4 Bit For Group And 0 Bit For SubPriority
#define  GROUP_8_SUBBRIORITY_2       0x05FA0400      //3 Bit For Group And 1 Bit For SubPriority
#define  GROUP_4_SUBBRIORITY_4       0x05FA0500      //2 Bit For Group And 2 Bit For SubPriority
#define  GROUP_2_SUBBRIORITY_8       0x05FA0600      //1 Bit For Group And 3 Bit For SubPriority
#define  GROUP_0_SUBBRIORITY_16      0x05FA0700      //0 Bit For Group And 4 Bit For SubPriority

/*Base Address = 0xE000E100 */


#define NVIC_ISER0        *((volatile u32*)0xE000E100) /*Enable External Interrupts From 00 To 31*/
#define NVIC_ISER1        *((volatile u32*)0xE000E104) /*Enable External Interrupts From 32 To 63*/
#define NVIC_ISER2        *((volatile u32*)0xE000E108) /*Enable External Interrupts From 64 To 73*/

 
#define NVIC_ICER0         *((volatile u32*)0xE000E180) /*Disable External Interrupts From 00 To 31*/
#define NVIC_ICER1         *((volatile u32*)0xE000E184) /*Disable External Interrupts From 32 To 63*/
#define NVIC_ICER2         *((volatile u32*)0xE000E188) /*Disable External Interrupts From 64 To 73*/

#define NVIC_ISPR0         *((volatile u32*)0xE000E200) /*Set Pending Flag For External Interrupts From 00 To 31*/
#define NVIC_ISPR1         *((volatile u32*)0xE000E204) /*Set Pending Flag For External Interrupts From 32 To 63*/
#define NVIC_ISPR2         *((volatile u32*)0xE000E208) /*Set Pending Flag For External Interrupts From 64 To 73*/

#define NVIC_ICPR0         *((volatile u32*)0xE000E280) /*Clear Pending Flag For External Interrupts From 00 To 31*/
#define NVIC_ICPR1         *((volatile u32*)0xE000E284) /*Clear Pending Flag For External Interrupts From 32 To 63*/
#define NVIC_ICPR2         *((volatile u32*)0xE000E288) /*Clear Pending Flag For External Interrupts From 64 To 73*/

#define NVIC_IِABR0         *((volatile u32*)0xE000E300) /*Return Active Flag For External Interrupts From 00 To 31*/
#define NVIC_IِABR1         *((volatile u32*)0xE000E304) /*Return Active Flag For External Interrupts From 32 To 63*/
#define NVIC_IِABR2         *((volatile u32*)0xE000E308) /*Return Active Flag For External Interrupts From 64 To 73*/

#define SCB_AIRCR          *((volatile u32*)0xE000ED0C) /*Select Number of Group Priority and SubPriority*/

#define NVIC_IِPR             ((volatile u8*)0xE000E400)

 

#endif 
