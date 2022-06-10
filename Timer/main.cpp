#include "stm32f10x.h"                  // Device header
static void reset();
/*
		-----------------------------------------------
		Timer with two 7-segment display and STM32103C4
		-----------------------------------------------
		by:                          Halilovic Mustafa

*/


// hex values for numbers from 0 to 9 (anode)
uint16_t numbers_AN[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


int main(void)
{
	// Set clock on port A and B
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	// Set whole CRL register(first 7 pins of port A) as an output
	// A0-A6
	GPIOA->CRL |= GPIO_CRL_MODE;
	GPIOA->CRL &=~ GPIO_CRL_CNF;
	
	//Set whole CRL register(first 7 pins of port B) as an output
	// B0-B6
	GPIOB->CRL |= GPIO_CRL_MODE;
	GPIOB->CRL &=~ GPIO_CRL_CNF;
	
	reset();
	
		while(1)
		{
			
			for(int i = 0; i <= 99; i++)
			{
					if(i>=10)GPIOB->ODR = numbers_AN[i/10];
				  for(int j = 0; j < 1500000; j++)	GPIOA->ODR = numbers_AN[i%10];
			}
			reset();
		}
}

void reset()
{
	for(int i = 0; i <= 6; i++)
	{
		GPIOB->ODR |= (1<<i);
	}
}
