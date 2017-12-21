#include <stm32f4xx_hal.h>
#include <stm32_hal_legacy.h>

#ifdef __cplusplus
extern "C"
#endif
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void TIM4_IRQHandler(void)
{
	if (TIM4->SR & TIM_SR_UIF) // if UIF flag is set
		{
			TIM4->SR &= ~TIM_SR_UIF;   // clear UIF flag
			GPIOD->ODR ^= (1 << 13);   // toggle LED state
		}
}

void EXTI0_IRQHandler(void)
{
	if ((EXTI->PR & EXTI_PR_PR0 ) !=0 )
	{
		GPIOD->ODR ^= (1 << 12);
		EXTI->PR |= EXTI_PR_PR0;
	}
		
}


void USART2_PutChar(uint8_t ch)
{
	while (!(USART2->SR & USART_SR_TXE)) ;
	USART2->DR = ch;
}



int main(void)
{
	unsigned long dly,i;
	
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN;	
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN | RCC_APB1ENR_USART2EN;
		
	
	// int pa0 config
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;
	EXTI->IMR |= EXTI_IMR_IM0;
	EXTI->RTSR |= EXTI_RTSR_TR0;
		
	GPIOD->MODER |= GPIO_MODER_MODE12_0 | GPIO_MODER_MODE13_0;	
		

	TIM4->ARR =100;
	TIM4->PSC = 15999;
	TIM4->DIER = TIM_DIER_UIE;
	TIM4->CR1 |= TIM_CR1_CEN;
	
	// config uart
	USART2->CR1 = USART_CR1_UE | USART_CR1_TE;
	USART2->BRR = (SystemCoreClock / 115200);
	
	HAL_Init();
	
	// init pa3 pa2 uart2 i/o pins
	GPIO_InitTypeDef GPIO_InitStructure; 
	GPIO_InitStructure.Pin = GPIO_PIN_2;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Alternate = GPIO_AF7_USART2;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.Pin = GPIO_PIN_3;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_OD;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
 
	// send chars
	for (i = 30; i < 128; ++i)
	{
		USART2_PutChar(i);
	};	
	
	NVIC_EnableIRQ(TIM4_IRQn);
	NVIC_EnableIRQ(EXTI0_IRQn);
	
	while(1);
	
	while (1)
	{
		
		if (TIM4->SR & TIM_SR_UIF)
		{
			TIM4->SR &= ~TIM_SR_UIF;
			GPIOD->ODR ^= (1<<12);
		}
		
//		if (GPIOA->IDR & GPIO_IDR_ID0_Msk)
//		{
//			GPIOD->ODR = 0xFFFF;
//		}	
//		else
//		{
//			GPIOD->ODR = 0x0000;
//		}
			
	//	GPIOD->ODR = 0x0000;		
	//	GPIOD->ODR = 0xFFFF;	
//		GPIOD->BSRR = GPIO_BSRR_BS12;
//		for (dly = 0; dly < 500000; dly++) ;
//		GPIOD->BSRR = GPIO_BSRR_BR12;
//		for (dly = 0; dly < 500000; dly++) ;
	}			
		


//	__GPIOD_CLK_ENABLE();
//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.Pin = GPIO_PIN_12;
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	for (;;)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_Delay(500);
	}
}
