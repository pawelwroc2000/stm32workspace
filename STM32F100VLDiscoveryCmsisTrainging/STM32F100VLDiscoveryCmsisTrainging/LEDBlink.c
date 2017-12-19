#include <stm32f1xx_hal.h>
#include <stm32_hal_legacy.h>

#ifdef __cplusplus
extern "C"
#endif
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}


void EXTI0_IRQHandler(void)
{
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	EXTI->PR |= EXTI_PR_PIF0;
	
}

int main(void)
{
	HAL_Init();
	
	__GPIOC_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Pin = GPIO_PIN_8;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA->CRL |=  GPIO_CRL_CNF0_1;
	
	NVIC_EnableIRQ(EXTI0_IRQn);
		
//	RCC->APB2ENR |= RCC_APB2ENR_
//	
//	EXTI->RTSR |= 5;
	
	for (;;)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_Delay(500);
	}
}
