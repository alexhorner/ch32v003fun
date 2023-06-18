// Could be defined here, or in the processor defines.
#define SYSTEM_CORE_CLOCK 48000000

#include "ch32v003fun.h"
#include <stdio.h>

int main()
{
	SystemInit48HSI();
	//SetupDebugPrintf();

	//printf("Hello world!\n");

	// Enable GPIOs
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOA;// | RCC_APB2Periph_GPIOC;

	// GPIO A0 Push-Pull
	GPIOA->CFGLR &= ~(0xf<<(4*0));
	GPIOA->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*0);

	// GPIO A1 Push-Pull
	GPIOA->CFGLR &= ~(0xf<<(4*1));
	GPIOA->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*1);

	// GPIO C0 Push-Pull
	//GPIOC->CFGLR &= ~(0xf<<(4*0));
	//GPIOC->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*0);

	while(1)
	{
		GPIOA->BSHR = 1 | (1<<4);	 // Turn on GPIOs
		//GPIOC->BSHR = 1;
		//printf("On!\n");
		Delay_Ms( 250 );
		GPIOA->BSHR = (1<<16) | (1<<(16+4)); // Turn off GPIODs
		//GPIOC->BSHR = (1<<16);
		//printf("Off!\n");
		Delay_Ms( 250 );
	}
}
