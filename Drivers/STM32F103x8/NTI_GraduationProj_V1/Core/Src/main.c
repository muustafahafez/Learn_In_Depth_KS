/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 ******************************************************************************
 */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "UltraSonic.h"
#include "SysTick.h"
#include "RTOS_interface.h"


/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;
TIM_HandleTypeDef htim1;


/* USER CODE BEGIN PV */
float Current_fDistance=15;
uint32_t ICU_u32Val1;
uint32_t ICU_u32Val2;
uint32_t  ICU_u32Difference;
uint8_t Is_First_Captured;
/* USER CODE END PV */
void delay(uint16_t time)
{
	__HAL_TIM_SET_COUNTER(&htim1,0);
	while(__HAL_TIM_GET_COUNTER(&htim1)<time);
}
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
static void MX_TIM1_Init(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

//ICU Handler
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
//Ultrasonic Function read
void HCSR04_Read (void);
//CAN RX Function
void CAN_Rx(uint16_t *ID, uint8_t* DLC,uint8_t* Payload);
//CAN TX Function
void CAN_Tx(uint32_t ID, uint8_t DLC,uint8_t* Payload);
//Filter Function
void CAN_RXFilterInit(uint16_t STD_ID,uint16_t STD_ID_MASK);



//RTOS Task1
void Task1(void);

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */


int main(void)
{


	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_CAN_Init();
	MX_TIM1_Init();
	SysTick_voidInit();
	/* USER CODE BEGIN 2 */

	RTOS_voidNewTask(1, 0, Task1, 0);
	//	uint8_t Fram_no =0;
	//	uint8_t Data[8]={'C','A','N',' ','N','o',':',' '};


	//	if(HAL_OK!=HAL_CAN_Start(&hcan))
	//	{
	//		Error_Handler();
	//
	//	}

	//Start RTOS
	//	SysTick_voidStart();
	//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);

	while (1)
	{
		//		Data[7]=Fram_no++;
		//
		//		CAN_Tx(0x3ff, 8, Data);
		//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);

		HCSR04_Read();
//		HAL_Delay(10);
		if(Current_fDistance<10)
		{
			//Led1 On
//			static uint8_t PinState=1;
//			PinState^=1;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);

		}
		else
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);

		}
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);

	}

}


void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}


//@brief CAN Initialization Function
static void MX_CAN_Init(void)
{
	hcan.Instance = CAN1;
	hcan.Init.Prescaler = 4;
	hcan.Init.Mode = CAN_MODE_LOOPBACK;
	hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan.Init.TimeSeg1 = CAN_BS1_6TQ;
	hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
	hcan.Init.TimeTriggeredMode = DISABLE;
	hcan.Init.AutoBusOff = DISABLE;
	hcan.Init.AutoWakeUp = DISABLE;
	hcan.Init.AutoRetransmission = ENABLE;
	hcan.Init.ReceiveFifoLocked = DISABLE;
	hcan.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan) != HAL_OK)
	{
		Error_Handler();
	}

}


static void MX_TIM1_Init(void)
{

	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_IC_InitTypeDef sConfigIC = {0};

	/* USER CODE BEGIN TIM1_Init 1 */

	/* USER CODE END TIM1_Init 1 */
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 0;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 65535;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter = 0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_IC_Init(&htim1) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC.ICFilter = 0;
	if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
	{
		Error_Handler();
	}


}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};



	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin|LED_2_Pin|LED_3_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin */
	GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin|GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

//Ultrasonic Function read - Trigger Ultrasonic , Enable ICU  interrupt
void HCSR04_Read (void)
{
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	//	HAL_delay(10);  // wait for 10 us
	//	HAL_Delay(10);
	delay(10);//micro

	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
}



// ICU ISR() , Update Value inside Current_Distance (global variable)

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // if the interrupt source is channel1
	{
		__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);

		if (Is_First_Captured==0) // if the first value is not captured
		{
			ICU_u32Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
			Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured==1)   // if the first is already captured
		{
			ICU_u32Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (ICU_u32Val2 > ICU_u32Val1)
			{
				ICU_u32Difference = ICU_u32Val2-ICU_u32Val1;
			}

			else if (ICU_u32Val1 > ICU_u32Val2)
			{
				ICU_u32Difference = (0xffff - ICU_u32Val1) + ICU_u32Val2;
			}

			Current_fDistance = (ICU_u32Difference * .034/2)*10;    //in cm
			Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
		}
	}
}



/********************************************************
 * 				CAN Functions
 * ******************************************************/
void CAN_Tx(uint32_t ID, uint8_t DLC,uint8_t* Payload)
{
	uint8_t Num_Of_TxMailboxes=0;
	uint8_t pTxMailbox=0;
	CAN_TxHeaderTypeDef pHeader;

	pHeader.DLC=DLC;
	pHeader.RTR=CAN_RTR_DATA;
	pHeader.IDE=CAN_ID_STD;
	pHeader.StdId=ID;

	//	(++) HAL_CAN_GetTxMailboxesFreeLevel() to get the number of free Tx
	//	mailboxes.
	Num_Of_TxMailboxes=HAL_CAN_GetTxMailboxesFreeLevel(&hcan);


	if(Num_Of_TxMailboxes)
	{
		//	(++) HAL_CAN_AddTxMessage() to request transmission of a new
		//	message.
		if(HAL_OK!=HAL_CAN_AddTxMessage(&hcan,&pHeader,Payload,&pTxMailbox))
		{
			Error_Handler();
		}

		//	(++) HAL_CAN_IsTxMessagePending() to check if a message is pending
		//	in a Tx mailbox.

		while(HAL_CAN_IsTxMessagePending(&hcan,pTxMailbox));
	}

}




void CAN_RXFilterInit(uint16_t STD_ID,uint16_t STD_ID_MASK)
{

	//	 (#) Configure the reception filters using the following configuration
	//	          functions:
	//	            (++) HAL_CAN_ConfigFilter()

	CAN_FilterTypeDef sFilterConfig;

	//Modes
	sFilterConfig.FilterActivation =CAN_FILTER_ENABLE;
	sFilterConfig.FilterBank =0; // Min0 , Max 13
	sFilterConfig.FilterMode =CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale =CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterFIFOAssignment =CAN_FILTER_FIFO0;

	//Filter Mask
	sFilterConfig.FilterMaskIdLow =0;
	sFilterConfig.FilterMaskIdHigh =(STD_ID_MASK<<5);
	//Filter ID
	sFilterConfig.FilterIdLow =0;
	sFilterConfig.FilterIdHigh =(STD_ID<<5);


	if(HAL_OK!=HAL_CAN_ConfigFilter(&hcan,&sFilterConfig))
	{
		Error_Handler();
	}

}




void CAN_Rx(uint16_t *ID, uint8_t *DLC,uint8_t* Payload)
{

	CAN_RxHeaderTypeDef pHeader;


	//    (++) Monitor reception of message using HAL_CAN_GetRxFifoFillLevel()
	//         until at least one message is received.
	//    (++) Then get the message using HAL_CAN_GetRxMessage().

	//wait untill a message come to FifoRx0
	while(0==HAL_CAN_GetRxFifoFillLevel(&hcan,CAN_RX_FIFO0));

	if(	HAL_CAN_GetRxMessage(&hcan,CAN_RX_FIFO0,&pHeader,Payload)!=HAL_OK)
		Error_Handler();

	//fill data
	*DLC=pHeader.DLC;
	*ID=pHeader.StdId;

}

void Task1(void)
{
	static uint8_t PinState=1;
	PinState^=1;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, PinState);

}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	while(1)
	{

	}
	/* USER CODE END Error_Handler_Debug */
}










#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
