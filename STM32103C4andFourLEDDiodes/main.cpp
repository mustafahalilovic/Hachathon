#include "stm32f10x.h"                  // Device header
/*
		-------------------------------------------------
						STM32103C4 and four LED diodes
		-------------------------------------------------
		by:             								Halilovic Mustafa
*/

int speed = 10000;

int main()
{
	
	// Set clock on port A
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	//Set first 4 pins on A port as an output
	// PIN0
	GPIOA->CRL |=  (1<<0)|(1<<1);
	GPIOA->CRL &=~ (1<<2)|(1<<3);
	// PIN1
	GPIOA->CRL |=  (1<<4)|(1<<5);
	GPIOA->CRL &=~ (1<<6)|(1<<7);
	// PIN2
	GPIOA->CRL |=  (1<<8)|(1<<9);
	GPIOA->CRL &=~ (1<<10)|(1<<11);
	// PIN3
	GPIOA->CRL |=  (1<<12)|(1<<13);
	GPIOA->CRL &=~ (1<<14)|(1<<15);
	
	for(int i = 0; i<=3;i++)
	{
			GPIOA->ODR |= (1<<i); // reset
	}
			
	while(1)
	{
			for(int i = 0; i<=3;i++)
			{
				for(int j = 0;j < speed; j++) 
				{
					GPIOA->ODR &=~ (1<<i); // turn LED on
				}
				GPIOA->ODR |= (1<<i);
			}
			for(int i = 2; i>=0;i--)
			{
				for(int j = 0;j < speed; j++) 
				{
					GPIOA->ODR &=~ (1<<i); // turn LED on
				}
				GPIOA->ODR |= (1<<i);
			}
			speed+=50000;
			if(speed>=1000000) speed = 100000;
	}


}