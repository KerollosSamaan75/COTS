/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 30/07/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* options : 1- RCC_HSI
	         2- RCC_HSE_CRYSTAL
	         3- RCC_HSE_RC
	         4- RCC_PLL	        */

#define RCC_CLOCK_TYPE     RCC_HSI

/**********************************************************************************************************************/
/**********************************************************************************************************************/

/* options : 1- RCC_PLL_IN_HSI_DIV_2
	         2- RCC_PLL_IN_HSE_DIV_2
	         3- RCC_PLL_IN_HSE	        */

/* select value only if you choose PLL as input */

#if RCC_CLOCK_TYPE == RCC_PLL

#define RCC_PLL_INPUT         RCC_PLL_IN_HSE


/* options : 1-  PLL_INPUT_CLOCK_2 
			 2-	 PLL_INPUT_CLOCK_3 
			 3-	 PLL_INPUT_CLOCK_4 
			 4-	 PLL_INPUT_CLOCK_5 
			 5-	 PLL_INPUT_CLOCK_6 
			 6-	 PLL_INPUT_CLOCK_7 
			 7-	 PLL_INPUT_CLOCK_8 
			 8-	 PLL_INPUT_CLOCK_9 
			 9-	 PLL_INPUT_CLOCK_10
			 10	 PLL_INPUT_CLOCK_11
			 11- PLL_INPUT_CLOCK_12
			 12- PLL_INPUT_CLOCK_13
			 13- PLL_INPUT_CLOCK_14
			 14- PLL_INPUT_CLOCK_15
			 15- PLL_INPUT_CLOCK_16   */


#define RCC_PLL_MUL_VAL         PLL_INPUT_CLOCK_16


#endif

#endif
