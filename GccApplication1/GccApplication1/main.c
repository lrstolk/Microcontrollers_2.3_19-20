#define F_CPU 8E6

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void Opdrachtw1b3(void);
void Opdrachtw1b4(void);
void Opdrachtw1b5(void);
void Opdrachtw1b6(void);



/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, flipping bits on PORTD
Version :    	DMK, Initial code
*******************************************************************/
{
	Opdrachtw1b6();
	
	return 1;
}

void Opdrachtw1b3(void)
{
	DDRC = 0xFE;		//C op lezen
	//PORTC = 0xFF;		// C0
	
	DDRD = 0xFF;		// D op schrijven
	//PORTD = 0x01;		// D1
	
	
	while(1)
	{

		if (PINC & 0x01)
		{
			PORTD = 0x80;
			wait(250);
			PORTD = 0x00;
			wait(250);
		}
		else
		{
			PORTD = 0x00;
		}
		wait(10);
	}
}
	
void Opdrachtw1b4(void){
		DDRD = 0xFF;
		PORTD = 0x01; // alleen D0 op schrijven 
		uint8_t i = 0;
		
		while(1)
		{	
			PORTD = (1<<i);
			i++;
			wait(250);
			if (i > 7)
			{
				i = 0;
			}
		}
		
}

void Opdrachtw1b5(void)
{
	DDRD = 0xFF; // heel D op schrijven
	uint8_t ledArray[] = {0x81, 0x42, 0x24, 0x18};
	uint8_t i =0;
	while (1)
	{
		PORTD = ledArray[i];
		i++;
		wait(250);
		if (i > 3)
		{
			i = 0;
		}
		
	}
			
}

void Opdrachtw1b6(void)
{
	DDRC = 0xFE;		//C op lezen
	//PORTC = 0xFF;		// C0
	
	DDRD = 0xFF;		// D op schrijven
	//PORTD = 0x01;		// D1
	
	
	while(1)
	{

		if (PINC & 0x01)
		{
			PORTD = 0x80;
			wait(250);
			PORTD = 0x00;
			wait(250);
		}
		else
		{
			PORTD = 0x80;
			wait(1000);
			PORTD = 0x00;
			wait(1000);
		}
		wait(10);
	}
}
