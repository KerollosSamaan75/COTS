#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#define   GPIOA_MODER    *((u32*) 0x48000000)
#define   GPIOA_OTYPER   *((u32*) 0x48000014)
int main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_AHB, 17);
	SET_BIT(GPIOA_MODER,10);
	SET_BIT(GPIOA_OTYPER,5);

    while(1);

}
