#include <avr/io.h>
#include "BIT_MATH.H"
#define F_CPU  8000000UL
#include <util/delay.h>

int main(void)
{
	DDRA=0xFF;  //FOR 8 LEDS
	DDRB=0x00;  //FOR 3 DIP SWITCHES
	PORTB=0xFF; //PULL UP FOR FIRST 4 PIN IN PORTB
	while(1)
	{
		if(PINB==0b11111110)  //FLASHING
		{
			PORTA=0xFF;
			_delay_ms(500);
			PORTA=0x00;
			_delay_ms(500);
		}

		else if (PINB == 0b11111101) //SHIFT_LEFT
		{
			SET_BIT(PORTA,0);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			SET_BIT(PORTA,1);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			SET_BIT(PORTA,2);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			SET_BIT(PORTA,3);
			_delay_ms(250);
			CLR_BIT(PORTA,3);
			SET_BIT(PORTA,4);
			_delay_ms(250);
			CLR_BIT(PORTA,4);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,7);
			_delay_ms(250);
			CLR_BIT(PORTA,7);
			_delay_ms(250);
		}
		else if (PINB==0b11111100)  //SHIFT RIGHT
		{
			SET_BIT(PORTA,7);
			_delay_ms(250);
			CLR_BIT(PORTA,7);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,4);
			_delay_ms(250);
			CLR_BIT(PORTA,4);
			SET_BIT(PORTA,3);
			_delay_ms(250);
			CLR_BIT(PORTA,3);
			SET_BIT(PORTA,2);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			SET_BIT(PORTA,1);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			SET_BIT(PORTA,0);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			_delay_ms(250);
		}
		else if(PINB==0b11111011) //CONVERGING
		{
			SET_BIT(PORTA,0);
			SET_BIT(PORTA,7);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			CLR_BIT(PORTA,7);
			SET_BIT(PORTA,1);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,2);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,3);
			SET_BIT(PORTA,4);
			_delay_ms(250);
			CLR_BIT(PORTA,3);
			CLR_BIT(PORTA,4);
			_delay_ms(250);

		}
		else if(PINB==0b11111010) //DIVERGING
		{
			SET_BIT(PORTA,3);
			SET_BIT(PORTA,4);
			_delay_ms(250);
			CLR_BIT(PORTA,3);
			CLR_BIT(PORTA,4);
			SET_BIT(PORTA,2);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,1);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,0);
			SET_BIT(PORTA,7);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			CLR_BIT(PORTA,0);
			_delay_ms(250);

		}
		else if (PINB == 0b11111001) //BINGBONG
		{
			SET_BIT(PORTA,0);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			SET_BIT(PORTA,1);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			SET_BIT(PORTA,2);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			SET_BIT(PORTA,3);
			_delay_ms(250);
			CLR_BIT(PORTA,3);
			SET_BIT(PORTA,4);
			_delay_ms(250);
			CLR_BIT(PORTA,4);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,7);
			_delay_ms(250);
			CLR_BIT(PORTA,7);
			_delay_ms(250);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,4);
			_delay_ms(250);
			CLR_BIT(PORTA,4);
			SET_BIT(PORTA,3);
			_delay_ms(250);
			CLR_BIT(PORTA,3);
			SET_BIT(PORTA,2);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			SET_BIT(PORTA,1);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			SET_BIT(PORTA,0);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			_delay_ms(250);
		}
		else if (PINB == 0b11111000) //INCREMENT
		{
			SET_BIT(PORTA,0);
			_delay_ms(300);
			SET_BIT(PORTA,1);
			_delay_ms(300);
			SET_BIT(PORTA,2);
			_delay_ms(300);
			SET_BIT(PORTA,3);
			_delay_ms(300);
			SET_BIT(PORTA,4);
			_delay_ms(300);
			SET_BIT(PORTA,5);
			_delay_ms(300);
			SET_BIT(PORTA,6);
			_delay_ms(300);
			PORTA=0x00;
		}
		else if (PINB == 0b11110111)
		{
			SET_BIT(PORTA,0);
			SET_BIT(PORTA,7);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			CLR_BIT(PORTA,7);
			SET_BIT(PORTA,1);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,2);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,3);
			SET_BIT(PORTA,4);
			_delay_ms(250);
			CLR_BIT(PORTA,3);
			CLR_BIT(PORTA,4);
			SET_BIT(PORTA,2);
			SET_BIT(PORTA,5);
			_delay_ms(250);
			CLR_BIT(PORTA,2);
			CLR_BIT(PORTA,5);
			SET_BIT(PORTA,1);
			SET_BIT(PORTA,6);
			_delay_ms(250);
			CLR_BIT(PORTA,1);
			CLR_BIT(PORTA,6);
			SET_BIT(PORTA,0);
			SET_BIT(PORTA,7);
			_delay_ms(250);
			CLR_BIT(PORTA,0);
			CLR_BIT(PORTA,7);
			_delay_ms(250);
	}

	}


return 0;
}
