#include "stm32f10x.h"

#ifdef __cplusplus
extern "C"
#endif

int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN;	
		
	GPIOC->CRH =  GPIO_CRH_MODE8_0 | GPIO_CRH_MODE9_0;
	GPIOA->CRL |=  GPIO_CRL_CNF0_0;
	
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
