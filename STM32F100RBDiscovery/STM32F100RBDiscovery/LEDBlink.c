#include "stm32f10x.h"

#ifdef __cplusplus
extern "C"
#endif

int main(void)
{
	
	__asm("mov R5, #0x000000FE");
	__asm("mov R5, r4");
	
	
	__asm("ldr R6, = 0x40021018");
	__asm("ldr R0, = 0x00000010");
	__asm("str R0,[R6]");

	__asm("ldr R6, = 0x40011000");
	__asm("ldr R0, = 0x00000004");
	__asm("str R0,[R6]");	
	
	__asm("ldr R6, = 0x40011004");
	__asm("ldr R0, = 0x00000011");
	__asm("str R0,[R6]");
	
	__asm("ldr R6, = 0x4001100C");
	__asm("ldr R0, = 0x11111111");
	__asm("str R0,[R6]");
	
	__asm("ldr R6, = 0x4001100C");
	__asm("ldr R0, = 0x00000000");
	__asm("str R0,[R6]");
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN;	
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN | RCC_APB1ENR_TIM4EN;
	
	
	GPIOC->CRH =  GPIO_CRH_MODE8_0 | GPIO_CRH_MODE9_0;
	GPIOA->CRL |=  GPIO_CRL_CNF0_0;
	
	
	
	
	TIM3->PSC = 7999;
	TIM3->ARR = 1000;
	TIM3->CR1 |= TIM_CR1_CEN;
	
	TIM4->PSC = 7999;
	TIM4->ARR = 50;
	TIM4->CR1 |= TIM_CR1_CEN;
		
	while(1)
	{
		if (TIM3->SR & TIM_SR_UIF)
		{
			TIM3->SR &= ~TIM_SR_UIF;
			GPIOC->ODR ^= (1 << 8);
		}
		
		if (TIM4->SR & TIM_SR_UIF)
		{
			TIM4->SR &= ~TIM_SR_UIF;
			GPIOC->ODR ^= (1 << 9);
		}		
	};
		
	
	volatile unsigned long int i;
	
	for (;;)
	{
		if (GPIOA->IDR &(1<<0))
		{
			GPIOC->BSRR = 0xFFFF;			
		}
		else
		{
			GPIOC->BRR = 0xFFFF;			
		};

		//for (i = 0; i < 40000; ++i) ;

		//for (i = 0; i < 40000; ++i) ;
	}
}
