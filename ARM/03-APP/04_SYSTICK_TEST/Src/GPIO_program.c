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



void DIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case DIO_u8_PORTA :
		switch(Copy_u8Mode)
		{
			case INPUT_FLOATING :
			/*Select Pin as Input*/
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Floating*/
			CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_PULL_UP :
			/*Select Pin as Input*/
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Pull up*/
			SET_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_PULL_DOWN :
			/*Select Pin as Input*/
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Pull down*/
			CLR_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOA_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_ANALOG  :
			/*Select Input Pin as Analog*/
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_PUSH_PULL_LOW_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_PUSH_PULL_MEDIUM_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Medium speed*/
			SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_PUSH_PULL_HIGH_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
			/*Select Output Pin with High speed*/
			SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_OPEN_DRAIN_LOW_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_OPEN_DRAIN_MEDIUM_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_OPEN_DRAIN_HIGH_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
			/*Select Output Pin with High speed*/
			SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOA_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;
																	
			case ALTFUNCTION_PUSH_PULL :
			/*Select Pin as  Alternate function*/
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
			break;

			case ALTFUNCTION_OPEN_DRAIN :
			/*Select Pin as  Alternate function*/
			CLR_BIT(GPIOA_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOA_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOA_OTYPER,Copy_u8PIN);
			break;
		}
		break;

		case DIO_u8_PORTB :
		switch(Copy_u8Mode)
		{
			case INPUT_FLOATING :
			/*Select Pin as Input*/
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Floating*/
			CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_PULL_UP :
			/*Select Pin as Input*/
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Pull up*/
			SET_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_PULL_DOWN :
			/*Select Pin as Input*/
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Pull down*/
			CLR_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOB_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_ANALOG  :
			/*Select Input Pin as Analog*/
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_PUSH_PULL_LOW_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_PUSH_PULL_MEDIUM_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Medium speed*/
			SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_PUSH_PULL_HIGH_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
			/*Select Output Pin with High speed*/
			SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_OPEN_DRAIN_LOW_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_OPEN_DRAIN_MEDIUM_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_OPEN_DRAIN_HIGH_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
			/*Select Output Pin with High speed*/
			SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOB_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;
																	
			case ALTFUNCTION_PUSH_PULL :
			/*Select Pin as  Alternate function*/
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOB_OTYPER,Copy_u8PIN);
			break;

			case ALTFUNCTION_OPEN_DRAIN :
			/*Select Pin as  Alternate function*/
			CLR_BIT(GPIOB_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOB_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOB_OTYPER,Copy_u8PIN);
			break;
		}
		break;
		
		case DIO_u8_PORTC :
		switch(Copy_u8Mode)
		{
			case INPUT_FLOATING :
			/*Select Pin as Input*/
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Floating*/
			CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_PULL_UP :
			/*Select Pin as Input*/
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Pull up*/
			SET_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_PULL_DOWN :
			/*Select Pin as Input*/
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Input Pin as Pull down*/
			CLR_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOC_PUPDR , (Copy_u8PIN * 2 + 1));
			break;

			case INPUT_ANALOG  :
			/*Select Input Pin as Analog*/
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_PUSH_PULL_LOW_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOA_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_PUSH_PULL_MEDIUM_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Medium speed*/
			SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_PUSH_PULL_HIGH_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);
			/*Select Output Pin with High speed*/
			SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_OPEN_DRAIN_LOW_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;


			case OUTPUT_OPEN_DRAIN_MEDIUM_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
			/*Select Output Pin with Low speed*/
			CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case OUTPUT_OPEN_DRAIN_HIGH_SPEED :
			/*Select Pin as Output*/
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
			/*Select Output Pin with High speed*/
			SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2));
			SET_BIT(GPIOC_OSPEEDR , (Copy_u8PIN * 2 + 1));
			break;

			case ALTFUNCTION_PUSH_PULL :
			/*Select Pin as  Alternate function*/
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Push Pull*/
			CLR_BIT(GPIOC_OTYPER,Copy_u8PIN);
			break;

			case ALTFUNCTION_OPEN_DRAIN :
			/*Select Pin as  Alternate function*/
			CLR_BIT(GPIOC_MODER , (Copy_u8PIN * 2));
			SET_BIT(GPIOC_MODER , (Copy_u8PIN * 2 + 1));
			/*Select Output Pin as Open Drain*/
			SET_BIT(GPIOC_OTYPER,Copy_u8PIN);
			break;
		}
		break;
	}
}


void DIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value)
{
	switch(Copy_u8PORT)
	{
		case DIO_u8_PORTA :
		switch(Copy_u8Value)
		{
			case DIO_u8_HIGH : SET_BIT(GPIOA_ODR,Copy_u8PIN); break;
			case DIO_u8_LOW  : CLR_BIT(GPIOA_ODR,Copy_u8PIN); break;

			//case GPIO_u8_HIGH : GPIOA_BSRR = (1 << (Copy_u8PIN));  break;
			//case GPIO_u8_LOW  : GPIOA_BRR  = (1 << (Copy_u8PIN));  break;
		}
		break;
		
		case DIO_u8_PORTB :
		switch(Copy_u8Value)
		{
			case DIO_u8_HIGH : SET_BIT(GPIOB_ODR,Copy_u8PIN); break;
			case DIO_u8_LOW  : CLR_BIT(GPIOB_ODR,Copy_u8PIN); break;

			//case GPIO_u8_HIGH : GPIOB_BSRR = (1 << (Copy_u8PIN));  break;
			//case GPIO_u8_LOW  : GPIOB_BRR  = (1 << (Copy_u8PIN));  break;
		}
		break;
					
		case DIO_u8_PORTC :
		switch(Copy_u8Value)
		{
			case DIO_u8_HIGH : SET_BIT(GPIOC_ODR,Copy_u8PIN); break;
			case DIO_u8_LOW  : CLR_BIT(GPIOC_ODR,Copy_u8PIN); break;

			//case GPIO_u8_HIGH : GPIOC_BSRR = (1 << (Copy_u8PIN));  break;
			//case GPIO_u8_LOW  : GPIOC_BRR  = (1 << (Copy_u8PIN));  break;
		}
		break;
	   default :break;
	}
}

u8   DIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	u8 Local_u8PinValue = 0 ;
	
	switch(Copy_u8PORT)
	{
		case DIO_u8_PORTA : Local_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8PIN); break;
		case DIO_u8_PORTB : Local_u8PinValue = GET_BIT(GPIOB_IDR,Copy_u8PIN); break;
		case DIO_u8_PORTC : Local_u8PinValue = GET_BIT(GPIOC_IDR,Copy_u8PIN); break;
		default :break;
	}
	return Local_u8PinValue;
}
