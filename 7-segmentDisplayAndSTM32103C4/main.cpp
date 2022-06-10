#include "stm32f10x.h"                  // Device header

/*
		---------------------------------
		7-segment display and STM32103C4
		---------------------------------
		by:							Halilovic Mustafa
*/

// hex values for numbers from 0 to 9 (anode)
uint16_t numbers_AN[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
uint16_t numbers_CAT[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; // cathode
int counter=0;

int main(void)
{
	// Set clock on port A and B
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	// Set whole CRL register(first 7 pins of port A) as an output
	GPIOA->CRL |= GPIO_CRL_MODE;
	GPIOA->CRL &=~ GPIO_CRL_CNF;
	
	// Set first pin on port B as an output
	GPIOB->CRL &=~ (1<<0);
	GPIOB->CRL &=~ (1<<1);
	GPIOB->CRL &=~ (1<<2);
	GPIOB->CRL |=  (1<<3);
	
	
	while(1)
	{
		 if(GPIOB->IDR & GPIO_IDR_IDR0) // if button is presed
		 {
			 counter++;
			 if(counter==10) counter=0;
			 while(GPIOB->IDR & GPIO_IDR_IDR0){;} // while button is presed go to infinity loop
		 }
		 GPIOA->ODR = numbers_AN[counter];
	}
	
}