/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 30/07/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*Clock Types*/
#define  RCC_HSE_CRYSTAL        0
#define  RCC_HSE_RC			    1
#define  RCC_HSI                2
#define	 RCC_PLL                3


/*Pll Input Types*/
#define  RCC_PLL_IN_HSI_DIV_2   0
#define  RCC_PLL_IN_HSE_DIV_2   1
#define  RCC_PLL_IN_HSE         2

/* PLL multiplication factor*/
#define  PLL_INPUT_CLOCK_2      0
#define  PLL_INPUT_CLOCK_3      1
#define  PLL_INPUT_CLOCK_4      2
#define  PLL_INPUT_CLOCK_5      3
#define  PLL_INPUT_CLOCK_6      4
#define  PLL_INPUT_CLOCK_7      5
#define  PLL_INPUT_CLOCK_8      6
#define  PLL_INPUT_CLOCK_9      7
#define  PLL_INPUT_CLOCK_10     8
#define  PLL_INPUT_CLOCK_11     9
#define  PLL_INPUT_CLOCK_12     10
#define  PLL_INPUT_CLOCK_13     11
#define  PLL_INPUT_CLOCK_14     12
#define  PLL_INPUT_CLOCK_15     13
#define  PLL_INPUT_CLOCK_16     14

#define RCC_CR              *((volatile u32*)0x40021000) /*Frist  REG used to Select CLK for Processor*/

#define RCC_CFGR            *((volatile u32*)0x40021004) /*Second REG used to Select CLK for Processor*/

#define RCC_CIR             *((volatile u32*)0x40021008)

#define RCC_APB2RSTR        *((volatile u32*)0x4002100C)

#define RCC_APB1RSTR        *((volatile u32*)0x40021010)

#define RCC_AHBENR          *((volatile u32*)0x40021014)  /*Control(ENABLE/DISABLE) CLK For all Prepherials on AHB Bus*/

#define RCC_APB2ENR         *((volatile u32*)0x40021018)  /*Control(ENABLE/DISABLE) CLK For all Prepherials on APB2 Bus*/

#define RCC_APB1ENR         *((volatile u32*)0x4002101C)  /*Control(ENABLE/DISABLE) CLK For all Prepherials on APB1 Bus*/

#define RCC_BDCR            *((volatile u32*)0x40021020) 

#define RCC_CSR             *((volatile u32*)0x40021024) 

#define RCC_AHBRSTR         *((volatile u32*)0x40021028) 

#define RCC_CFGR2           *((volatile u32*)0x4002102C) 

#define RCC_CFGR3           *((volatile u32*)0x40021030) 




#define RCC_CSR             *((volatile u32*)0x40021024) 

#endif 