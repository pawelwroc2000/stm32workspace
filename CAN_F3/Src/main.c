/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef CanHandle;
UART_HandleTypeDef huart2;


/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
unsigned char i,RxData,j;
unsigned char tab[60];
CanTxMsgTypeDef        TxMessage;
CanRxMsgTypeDef        RxMessage;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void CAN_Tx(unsigned char data)
{
	CAN->sTxMailBox[0].TDLR=data;
	CAN->sTxMailBox[0].TIR|=1;
}

unsigned char CAN_Rx(void)
{
	while(!CAN->RF0R&3);
	unsigned char RxD=(CAN->sFIFOMailBox[0].RDLR)&0xFF;
	CAN->RF0R|=1<<5;
	return RxD;
}
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */

/*
  CAN->sTxMailBox[0].TIR=0;
  CAN->sTxMailBox[0].TIR=0x245<<21;
  CAN->sTxMailBox[0].TDHR=0;
  CAN->sTxMailBox[0].TDTR=1;

  CAN->FMR|=1<<0;
  CAN->FMR|=14<<8;
  CAN->FS1R|=1<<14;
  CAN->sFilterRegister[14].FR1=0x245<<21;
  CAN->FM1R|=1<<14;
  CAN->FA1R|=1<<14;
  CAN->FMR&=~(1<<0);
*/

  j=sprintf(tab,"START\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();

  // ver2
  CAN_FilterConfTypeDef  sFilterConfig;


  j=sprintf(tab,"1\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();

  /*
  CanHandle.Init.TTCM = DISABLE;
  CanHandle.Init.ABOM = DISABLE;
  CanHandle.Init.AWUM = DISABLE;
  CanHandle.Init.NART = DISABLE;
  CanHandle.Init.RFLM = DISABLE;
  CanHandle.Init.TXFP = DISABLE;
  CanHandle.Init.Mode = CAN_MODE_LOOPBACK;
  CanHandle.Init.SJW = CAN_SJW_1TQ;
  CanHandle.Init.BS1 = CAN_BS1_6TQ;
  CanHandle.Init.BS2 = CAN_BS2_8TQ;
  CanHandle.Init.Prescaler = 2;

*/

  MX_CAN_Init();



   /*##-2- Configure the CAN Filter ###########################################*/
  sFilterConfig.FilterNumber = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x0000;
  sFilterConfig.FilterIdLow = 0x0000;
  sFilterConfig.FilterMaskIdHigh = 0x0000;
  sFilterConfig.FilterMaskIdLow = 0x0000;
  sFilterConfig.FilterFIFOAssignment = 0;
  sFilterConfig.FilterActivation = ENABLE;
  sFilterConfig.BankNumber = 14;
  HAL_CAN_ConfigFilter(&CanHandle,&sFilterConfig);
 // HAL_CAN_Receive_IT(&CanHandle, CAN_FIFO0);

  if(HAL_CAN_ConfigFilter(&CanHandle, &sFilterConfig) != HAL_OK)
  {
    /* Filter configuration Error */
	  j=sprintf(tab,"error0\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }

  if(HAL_CAN_Init(&CanHandle) != HAL_OK)
 {
   /* Initialization Error */
	  j=sprintf(tab,"error\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
 }

  CanHandle.pTxMsg=&TxMessage;
  CanHandle.pRxMsg=&RxMessage;


  /*

  //##-3- Start the Transmission process #####################################
  CanHandle.pTxMsg->StdId = 0x11;
  CanHandle.pTxMsg->RTR = CAN_RTR_DATA;
  CanHandle.pTxMsg->IDE = CAN_ID_STD;
  CanHandle.pTxMsg->DLC = 2;
  CanHandle.pTxMsg->Data[0] = (unsigned char)65;
  CanHandle.pTxMsg->Data[1] = (unsigned char)66;

  if(HAL_CAN_Transmit(&CanHandle, 10) != HAL_OK)
  {
    // Transmission Error
	  j=sprintf(tab,"error\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }
  if(HAL_CAN_GetState(&CanHandle) != HAL_CAN_STATE_READY)
  {
	  j=sprintf(tab,"error\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }


  */

  /*##-4- Start the Reception process ########################################*/
  if(HAL_CAN_Receive(&CanHandle, CAN_FIFO0,10) != HAL_OK)
  {
    /* Reception Error */
	  j=sprintf(tab,"error1\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }


  if(HAL_CAN_GetState(&CanHandle) != HAL_CAN_STATE_READY)
  {
	  j=sprintf(tab,"error2\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }

  if (CanHandle.pRxMsg->StdId != 0x11)
  {
	  j=sprintf(tab,"error\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }

  if (CanHandle.pRxMsg->IDE != CAN_ID_STD)
  {
	  j=sprintf(tab,"error3\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }

  if (CanHandle.pRxMsg->DLC != 2)
  {
	  j=sprintf(tab,"error4\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }

  j=sprintf(tab,"9\n",i); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();


  if ( (RxMessage.Data[0]== (unsigned char)65) &&
	   (RxMessage.Data[1]== (unsigned char)66)) //    CanHandle.pRxMsg->Data[0] == (unsigned char)65)
  {
	  j=sprintf(tab,"can[0]=%i can[1]=%i\n",RxMessage.Data[0],RxMessage.Data[1]); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
  }

  j=sprintf(tab,"Koniec!\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();

  // end ver2


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  ++i;


	  // wyslij message
	  //ver.1
	  //CAN_Tx(i);
	  //ver.2

	  /*
	  //##-3- Start the Transmission process #####################################
	  CanHandle.pTxMsg->StdId = 0x11;
	  CanHandle.pTxMsg->RTR = CAN_RTR_DATA;
	  CanHandle.pTxMsg->IDE = CAN_ID_STD;
	  CanHandle.pTxMsg->DLC = 8;
	  CanHandle.pTxMsg->Data[0] = i;
	  CanHandle.pTxMsg->Data[1] = i;
	  CanHandle.pTxMsg->Data[2] = i;
	  CanHandle.pTxMsg->Data[3] = i;
	  CanHandle.pTxMsg->Data[4] = i;
	  CanHandle.pTxMsg->Data[5] = i;
	  CanHandle.pTxMsg->Data[6] = i;
	  CanHandle.pTxMsg->Data[7] = i;

	  if(HAL_CAN_Transmit(&CanHandle, 10) != HAL_OK)
	  {
	    // Transmission Error
		  j=sprintf(tab,"error\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
	  }else{
		  j=sprintf(tab,"Send %i\n",i); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
	  }
*/

	 // RxData=CAN_Rx();

	  /*##-4- Start the Reception process ########################################*/
	  if(HAL_CAN_Receive(&CanHandle, CAN_FIFO0,100) != HAL_OK)
	  {
	    /* Reception Error */
		  j=sprintf(tab,"error5\n"); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
	  }
	  else
	  {
		  j=sprintf(tab,"CANval: %i %i\n",CanHandle.pRxMsg->Data[0],CanHandle.pRxMsg->Data[7]); if(HAL_UART_Transmit(&huart2, (uint8_t *)&tab,j,5000)!= HAL_OK) Error_Handler();
	  }


	 // HAL_Delay(20);

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}


/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1; //
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;//
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;//
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* CAN init function */

static void MX_CAN_Init(void)
{

	CanHandle.Instance = CAN;
	CanHandle.Init.Prescaler = 18;
	CanHandle.Init.Mode = CAN_MODE_NORMAL;
	CanHandle.Init.SJW = CAN_SJW_1TQ;
	CanHandle.Init.BS1 = CAN_BS1_3TQ;
	CanHandle.Init.BS2 = CAN_BS2_5TQ;
	CanHandle.Init.TTCM = DISABLE;
	CanHandle.Init.ABOM = DISABLE;
	CanHandle.Init.AWUM = DISABLE;
	CanHandle.Init.NART = DISABLE;
	CanHandle.Init.RFLM = DISABLE;
	CanHandle.Init.TXFP = DISABLE;
  if (HAL_CAN_Init(&CanHandle) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}


/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);



}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
