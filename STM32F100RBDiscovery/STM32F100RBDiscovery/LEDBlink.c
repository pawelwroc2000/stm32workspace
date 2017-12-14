#include "stm32f10x.h"

#ifdef __cplusplus
extern "C"
#endif

int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;	

	GPIOC->BSRR = (1 << 8);
	
	for (;;)
	{

	}
}
