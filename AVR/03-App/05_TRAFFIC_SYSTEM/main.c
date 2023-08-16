#include <avr/io.h>
#define F_CPU  8000000UL
#include <util/delay.h>
#define ZERO  0b00111111
#define ONE   0b00000110
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111
int main(void)
{
	unsigned char arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	DDRA=0xff; //FOR FIRST 7-SEGMENT
	DDRB=0xff; //FOR SEC 7-SEGMENT
	DDRC=0b00000111; //FOR 3LED
	while(1)
	{
		int i=0;
		PORTC=0x01; //TURN ON RED LED
		PORTA=~arr[1];
		PORTB=~arr[0];
		_delay_ms(2000);
		PORTA=~arr[0];
		for( i=9;i>0;i--)
		{
			PORTB=~arr[i];
			_delay_ms(2000);

		}
		PORTB=~arr[i];
		_delay_ms(2000);
//		PORTC=0x00; //TURN OFF RED LED
		PORTC=0x02; //TURN ON YELLOW LED
		for(i=3;i>0;i--)
		{
			PORTB=~arr[i];
			_delay_ms(2000);

		}
		PORTB=~arr[i];
		_delay_ms(2000);
//		PORTC=0x00; //TURN OFF YELLOW LED
		PORTC=0x04; //TURN ON GREEN LED
		PORTA=~arr[1];
		_delay_ms(2000);
		PORTA=~arr[0];
		for( i=9;i>0;i--)
		{
			PORTB=~arr[i];
			_delay_ms(2000);

		}
		PORTB=~arr[i];
		_delay_ms(2000);
//		PORTC=0x00; //TURN OFF GREEN LED
	}
	return 0;
}


