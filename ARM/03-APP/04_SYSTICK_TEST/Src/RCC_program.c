/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 30/07/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSystemClock(void)
{
	#if    RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	       RCC_CR   = 0x00010000; /*Enable HSE_CRYSTAL without Bypass*/
		   RCC_CFGR = 0x00000001; /*HSE selected as system clock*/
		   
		   
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
		   RCC_CR   = 0x00050000; /*Enable HSE_RC with Bypass*/
		   RCC_CFGR = 0x00000001; /*HSE selected as system clock*/
	       
		   
	#elif  RCC_CLOCK_TYPE == RCC_HSI
	       RCC_CR   = 0x00000081; /*Enable HSI With Triming - 0*/
		   RCC_CFGR = 0x00000000; /*HSI selected as system clock*/
		   
		   
	#elif  RCC_CLOCK_TYPE == RCC_PLL
	
	       #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		   
				 #if   RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_2
				       RCC_CFGR = 0x00000002;
					   RCC_CR   = 0x01000000;
					   
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_3
				       RCC_CFGR = 0x00040002;
					   RCC_CR   = 0x01000000;
					
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_4
				       RCC_CFGR = 0x00080002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_5
				       RCC_CFGR = 0x000C0002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_6
				       RCC_CFGR = 0x00100002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_7
				       RCC_CFGR = 0x00140002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_8
				       RCC_CFGR = 0x00180002;
					   RCC_CR   = 0x01000000;
					   
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_9
				       RCC_CFGR = 0x001C0002;
					   RCC_CR   = 0x01000000;
					   
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_10
				       RCC_CFGR = 0x00200002;
					   RCC_CR   = 0x01000000;
					   
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_11
				       RCC_CFGR = 0x00240002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_12
				       RCC_CFGR = 0x00280002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_13
				       RCC_CFGR = 0x002C0002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_14
				       RCC_CFGR = 0x00300002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_15
				       RCC_CFGR = 0x00340002;
					   RCC_CR   = 0x01000000;
				 
				 #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_16
				       RCC_CFGR = 0x00380002;
					   RCC_CR   = 0x01000000;
				 
				 #else
		               #error("You Choose Wrong RCC_PLL_MUL_VAL")
			
		         #endif
				 
				 
		   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		        
				 #if   RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_2
					   RCC_CFGR = 0x00030002;
					   RCC_CR   = 0x01000000;
				 
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_3
		               RCC_CFGR = 0x00070002;
					   RCC_CR   = 0x01000000;
				 
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_4
		               RCC_CFGR = 0x000B0002;
					   RCC_CR   = 0x01000000;
				 
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_5
		               RCC_CFGR = 0x000F0002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_6
				       RCC_CFGR = 0x00130002;
					   RCC_CR   = 0x01000000;
		         
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_7
		               RCC_CFGR = 0x00170002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_8
					   RCC_CFGR = 0x001B0002;
					   RCC_CR   = 0x01000000;
				 
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_9
		               RCC_CFGR = 0x001F0002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_10
				       RCC_CFGR = 0x00230002;
					   RCC_CR   = 0x01000000;
		         
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_11
		               RCC_CFGR = 0x00270002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_12
				       RCC_CFGR = 0x002B0002;
					   RCC_CR   = 0x01000000;
		         
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_13
		               RCC_CFGR = 0x002F0002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_14
		               RCC_CFGR = 0x00330002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_15
		               RCC_CFGR = 0x00370002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_16
					   RCC_CFGR = 0x003B0002;
					   RCC_CR   = 0x01000000;
					   
		         #else
		               #error("You Choose Wrong RCC_PLL_MUL_VAL")
		         
		         #endif
		   
		   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
				
				 #if   RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_2
					   RCC_CFGR = 0x00010002;
					   RCC_CR   = 0x01000000;
		         
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_3
	                   RCC_CFGR = 0x00050002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_4
		               RCC_CFGR = 0x00090002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_5
		               RCC_CFGR = 0x000E0002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_6
		               RCC_CFGR = 0x00110002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_7
		               RCC_CFGR = 0x00150002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_8
		               RCC_CFGR = 0x00190002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_9
		               RCC_CFGR = 0x001E0002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_10
		               RCC_CFGR = 0x00210002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_11
		               RCC_CFGR = 0x00250002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_12
		               RCC_CFGR = 0x00290002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_13
		               RCC_CFGR = 0x002E0002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_14
		               RCC_CFGR = 0x00310002;
					   RCC_CR   = 0x01000000;
				 
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_15
		               RCC_CFGR = 0x00350002;
					   RCC_CR   = 0x01000000;
					   
		         #elif RCC_PLL_MUL_VAL == PLL_INPUT_CLOCK_16
		               RCC_CFGR = 0x00390002;
					   RCC_CR   = 0x01000000;
					   
		         #else
		               #error("You Choose Wrong RCC_PLL_MUL_VAL")
		         
		         #endif
		   
		   #else
		         #error("You Choose Wrong RCC_PLL_INPUT")
			
		   #endif
		   
	#else
		   #error("You Choose Wrong Clock Type")
	#endif
}

void RCC_voidEnableClock (u8 Copy_u8BusID,u8 copy_u8PerID)
{
	 if(copy_u8PerID <= 31)
	 {
		 switch(Copy_u8BusID)
		 {
			 case RCC_AHB  : SET_BIT(RCC_AHBENR  , copy_u8PerID);  break; 
			 case RCC_APB1 : SET_BIT(RCC_APB1ENR , copy_u8PerID);  break;
			 case RCC_APB2 : SET_BIT(RCC_APB2ENR , copy_u8PerID);  break;
		   //default       : /*Return Error*/ break;
		 }
	 }
	 else
	 {
		 /*Return Error*/
	 }
}

void RCC_voidDisableClock(u8 Copy_u8BusID,u8 copy_u8PerID)
{
	if(copy_u8PerID <= 31)
	 {
		 switch(Copy_u8BusID)
		 {
			 case RCC_AHB  : CLR_BIT(RCC_AHBENR  , copy_u8PerID);  break;
			 case RCC_APB1 : CLR_BIT(RCC_APB1ENR , copy_u8PerID);  break;
			 case RCC_APB2 : CLR_BIT(RCC_APB2ENR , copy_u8PerID);  break;
		   //default       : /*Return Error*/ break;
		 }
	 }
	 else
	 {
		 /*Return Error*/
	 }
}
