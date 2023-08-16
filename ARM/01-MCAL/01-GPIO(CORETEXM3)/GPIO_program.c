/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 08/08/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void GPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					if(Copy_u8PIN <= 7)
					{
						  GPIOA_CRL &= ~((0b1111)      << (Copy_u8PIN * 4));
						  GPIOA_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));
					}
					else if(Copy_u8PIN > 7 && Copy_u8PIN <= 15)
					{
						  GPIOA_CRH &= ~((0b1111)      << ((Copy_u8PIN-8) * 4));
						  GPIOA_CRH |=  ((Copy_u8Mode) << ((Copy_u8PIN-8) * 4));
					}
					break;
					 
		case GPIOB :
					if(Copy_u8PIN <= 7)
					{
						  GPIOB_CRL &= ~((0b1111)      << (Copy_u8PIN * 4));
						  GPIOB_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));
					}
					else if(Copy_u8PIN > 7 && Copy_u8PIN <= 15)
					{
						  GPIOB_CRH &= ~((0b1111)      << ((Copy_u8PIN-8) * 4));
						  GPIOB_CRH |=  ((Copy_u8Mode) << ((Copy_u8PIN-8) * 4));
					}
					break;
		
		case GPIOC :
					if(Copy_u8PIN <= 7)
					{
						  GPIOC_CRL &= ~((0b1111)      << (Copy_u8PIN * 4));
						  GPIOC_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));
					}
					else if(Copy_u8PIN > 7 && Copy_u8PIN <= 15)
					{
						  GPIOC_CRH &= ~((0b1111)      << ((Copy_u8PIN-8) * 4));
						  GPIOC_CRH |=  ((Copy_u8Mode) << ((Copy_u8PIN-8) * 4));
					}
					break;
		default:break;
	}
} 

void GPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value)
{
	switch(Copy_u8PORT)
	{
		case GPIOA : 
					switch(Copy_u8Value)
					{
						case GPIO_u8_HIGH : SET_BIT(GPIOA_ODR,Copy_u8PIN); break;
						case GPIO_u8_LOW  : CLR_BIT(GPIOA_ODR,Copy_u8PIN); break;

						//case GPIO_u8_HIGH : GPIOA_BSR = (1 << (Copy_u8PIN));  break;
						//case GPIO_u8_LOW  : GPIOA_BRR = (1 << (Copy_u8PIN));  break;
					}
					break; 
		
		case GPIOB : 
					switch(Copy_u8Value)
					{
						case GPIO_u8_HIGH : SET_BIT(GPIOB_ODR,Copy_u8PIN); break;
						case GPIO_u8_LOW  : CLR_BIT(GPIOB_ODR,Copy_u8PIN); break;

						//case GPIO_u8_HIGH : GPIOB_BSR = (1 << (Copy_u8PIN));  break;
						//case GPIO_u8_LOW  : GPIOB_BRR = (1 << (Copy_u8PIN));  break;
					}
		            break; 
					
		case GPIOC : 
					switch(Copy_u8Value)
					{
						case GPIO_u8_HIGH : SET_BIT(GPIOC_ODR,Copy_u8PIN); break;
						case GPIO_u8_LOW  : CLR_BIT(GPIOC_ODR,Copy_u8PIN); break;

						//case GPIO_u8_HIGH : GPIOC_BSR = (1 << (Copy_u8PIN));  break;
						//case GPIO_u8_LOW  : GPIOC_BRR = (1 << (Copy_u8PIN));  break;
					}
		            break; 
	   default :break;
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	u8 Local_u8PinValue = 0 ;
	
	switch(Copy_u8PORT)
	{
		case GPIOA : Local_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8PIN); break;
		case GPIOB : Local_u8PinValue = GET_BIT(GPIOB_IDR,Copy_u8PIN); break;
		case GPIOC : Local_u8PinValue = GET_BIT(GPIOC_IDR,Copy_u8PIN); break;
		default :break;
	}
	return Local_u8PinValue;
}
