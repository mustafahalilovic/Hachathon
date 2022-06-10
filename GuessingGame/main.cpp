#include "stm32f10x.h"                  // Device header
#include <stdlib.h>
/*
		--------------------------------------------
		Small 7-segment display game (Guessing game)
		--------------------------------------------
		by:                        Halilovic Mustafa
*/

// hex values for numbers from 0 to 9 (anode)
uint16_t numbers_AN[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
uint16_t end[3] = {0x06, 0x2B, 0x21};// end message
uint16_t score[5] = {0x92,0xA7, 0xA3, 0xAF, 0x86}; // score (how many wrongs you have)
int wrong_counter, score_counter;
int randNum1, randNum2;

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
	
	// Set second pin on port B as an output
	GPIOB->CRL &=~ (1<<4);
	GPIOB->CRL &=~ (1<<5);
	GPIOB->CRL &=~ (1<<6);
	GPIOB->CRL |=  (1<<7);
	
	poc:
	randNum1 = rand()%10 +0;
	randNum2 = rand()%10 +0;
	wrong_counter=0, score_counter=0;
	
	while(1)
	{	
			GPIOA->ODR = numbers_AN[randNum1];
			if(GPIOB->IDR & GPIO_IDR_IDR0) // hiden random number is bigger 
			{
				if(randNum2>randNum1)
				{
					score_counter++;
					randNum1 = randNum2;
					randNum2 = rand()%10 +0;
				}
				else wrong_counter++;
				while(GPIOB->IDR & GPIO_IDR_IDR0){;}
			}
			if(GPIOB->IDR & GPIO_IDR_IDR1) // hiden random number is smaller 
			{
				if(randNum2<randNum1)
				{
					score_counter++;
					randNum1 = randNum2;
					randNum2 = rand()%10 +0;
				}
				else wrong_counter++;
				while(GPIOB->IDR & GPIO_IDR_IDR1){;}
			}
			// End of a game
			if(score_counter==7) 
			{
				// displaying e n d
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 1000000; j++) {
					GPIOA->ODR = end[i];
					}
					}
				// displaying s c o r e
				for(int i = 0; i < 5; i++)
				{
					for(int j = 0; j < 1000000; j++) {
					GPIOA->ODR = score[i];
					}
				}
				// Score
				for(int i = 0; i < 1000000; i++){
				GPIOA->ODR = numbers_AN[score_counter-wrong_counter];}
				goto poc;
			}
			
	}
	
}