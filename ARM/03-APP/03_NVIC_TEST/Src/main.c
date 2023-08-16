#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"

#include "LCD_interface.h"
#include "EXTI_interface.h"

volatile u32 IRQ_TEMP_FLAGE = 0;


int main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_AHB, AHB_IOPC_EN);
	RCC_voidEnableClock(RCC_AHB, AHB_IOPA_EN);
	RCC_voidEnableClock(RCC_APB2, APB2_SYSCFG_EN);
	LCD_voidInit();
	NVIC_voidInit();
	EXTI_Init();
	DIO_voidSetPinDirection(DIO_u8_PORTC,DIO_u8_PIN13, INPUT_PULL_UP);
	EXTI_voidSetSenseMood(EXTI_LINE_13, EXTI_FALLING_TRIGGER);
	EXTI_voidEnableLine(EXTI_LINE_13);
	NVIC_voidEnableInterrupt(40);
//	NVIC_voidEnableInterrupt(6);
//	NVIC_voidSetPriority(6, 0b1111);  //EXTI0
//
//	NVIC_voidEnableInterrupt(7);
//	NVIC_voidSetPriority(7, 0b0011);  //EXTI1
//
//	NVIC_voidSetPendingFlag(6);

	while(1);

}


void  EXTI15_10_IRQHandler()
{
	static u8 Counter = 1;
	LCD_voidSendNum(Counter);
	EXTI_voidClearLineFlag(EXTI_LINE_13);
	Counter++;
}

//void EXTI1_IRQHandler()
//{
//	LCD_voidSendNum(1);
//}
