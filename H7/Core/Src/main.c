/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "memorymap.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "spi.h"
#include "bsp_DRV8303.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "FOC_Model.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//float load_data[5];
static uint8_t tempData[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80,0x7F};
float temp_data[4];
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* MCU Configuration--------------------------------------------------------*/

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
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
	DRV8303_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
	HAL_ADCEx_InjectedStart_IT(&hadc1);
	FOC_Model_initialize();


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
//		HAL_GPIO_TogglePin(LED3_GPIO_Port,LED5_Pin);
    /* USER CODE BEGIN 3 */
	  
//			load_data[0] = 1;
//			load_data[1] = 2;
//			load_data[2] = 3;
//			load_data[3] = 4;
//			load_data[4] = 5;
//			memcpy(tempData, (uint8_t *)&load_data, sizeof(load_data));
//			HAL_UART_Transmit_DMA(&huart2,(uint8_t *)tempData,6*4);
	  
	  
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 2;
  RCC_OscInitStruct.PLL.PLLN = 32;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 10;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */








void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	static uint8_t Motor_state=0;
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
//	if(KEY1_Pin == GPIO_Pin)
//	{
//		HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
//		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
//		HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
//		HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
//		


//	}
//	
//	
//	
//	if(KEY2_Pin == GPIO_Pin)
//	{
//		HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
//		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);


//	}
//	if(KEY3_Pin == GPIO_Pin)
//	{
//		HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
//		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);

//	}
//	
//		if(KEY4_Pin == GPIO_Pin)
//	{
//		HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
//		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);


//	}
	
		if(KEY1_Pin == GPIO_Pin)
	{

		HAL_GPIO_TogglePin(LED3_GPIO_Port,LED5_Pin);

		Motor_state = ~Motor_state;
		if(0 == Motor_state)
		{
			rtU.MotorOnOff = 0.0f;
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_3);
		}
		else
		{
			rtU.MotorOnOff = 1.0f;
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
		}
	}
}






void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	static uint8_t cnt;
	static uint16_t ADC_offset, count;
	static float adc1_in1,adc1_in2,adc1_in3,IA_Offset,IB_Offset,IC_Offset;
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
	
	
	if(hadc == &hadc1)
	{
		if(ADC_offset == 0)
		{
			
			cnt++;
			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in2 = hadc1.Instance->JDR2;
			IA_Offset += adc1_in1;
			IB_Offset += adc1_in2;
			if(cnt >= 10)
			{
				ADC_offset = 1;
				IA_Offset = IA_Offset/10;
				IB_Offset = IB_Offset/10;
			}
		}
		else
		{
			
			
			rtU.VDC =24;
//			rtU.MotorOnOff = 1;
			
//			if(state==1)
//			{
//				__HAL_TIM_SET_COUNTER(&htim2,250);  
//			}
//			counter_value = __HAL_TIM_GetCounter(&htim2);
//			encode_theta = counter_value/3999*2*PI*Pn;
//			
//			if(6*PI <= encode_theta && encode_theta < 8*PI)
//			{
//				encode_theta -= 6.0f*PI;
//			}
//			else if(4*PI <= encode_theta && encode_theta < 6*PI)
//			{
//				encode_theta -= 4.0f*PI;
//			}
//			else if(2*PI <= encode_theta && encode_theta < 4*PI)
//			{
//				encode_theta -= 2.0f*PI;
//			}
//			else if(0 <= encode_theta && encode_theta < 2*PI)
//			{
//				encode_theta = encode_theta;
//			}
//			
//			encode_wm = (encode_theta - encode_theta_last)/0.0001*30/PI/Pn;
//			if(encode_wm<0) encode_wm=(-1)*encode_wm;
//			encode_theta_last = encode_theta;

//	
//			rtU.Wm=encode_wm;
//			rtU.Theta=encode_theta;
			
			
			
			




//			if(MID_parameter.state==2)
//			{
//				__HAL_TIM_SET_COUNTER(&htim2,250);  
//			}
//			counter_value = __HAL_TIM_GetCounter(&htim2);
//			encode_theta = counter_value/3999*2*PI*JIE_MEI_KANG_PARAMETER.Pn;
//			
//			if(6*PI <= encode_theta && encode_theta < 8*PI)
//			{
//				encode_theta -= 6.0f*PI;
//			}
//			else if(4*PI <= encode_theta && encode_theta < 6*PI)
//			{
//				encode_theta -= 4.0f*PI;
//			}
//			else if(2*PI <= encode_theta && encode_theta < 4*PI)
//			{
//				encode_theta -= 2.0f*PI;
//			}
//			else if(0 <= encode_theta && encode_theta < 2*PI)
//			{
//				encode_theta = encode_theta;
//			}
//			
//			encode_wm = (encode_theta - encode_theta_last)/0.0001*30/PI/JIE_MEI_KANG_PARAMETER.Pn;
//			if(encode_wm<0) encode_wm=(-1)*encode_wm;
//			encode_theta_last = encode_theta;

//	
//			rtU.Wm=encode_wm;
//			rtU.Theta=encode_theta;


//			rtU.Wm=MID_parameter.wm;
//			rtU.Theta=MID_parameter.THETA;


//			
////			rtU.Wm=rtY.ekm_m;
////			rtU.Theta=rtY.ekm_theta;

//		
//			adc1_in1 = hadc3.Instance->JDR1;
//			adc1_in2 = hadc3.Instance->JDR2;
//			rtU.ia = -(adc1_in1 - IA_Offset)*0.00100708f;
//			rtU.ib = -(adc1_in2 - IA_Offset)*0.00100708f;
//			rtU.ic = ((adc1_in1 - IA_Offset)*0.00100708f + (adc1_in2 - IB_Offset)*0.00100708f);

			FOC_Model_step();
			TIM1->CCR1 = rtY.Tcmp1;
			TIM1->CCR2 = rtY.Tcmp2;
			TIM1->CCR3 = rtY.Tcmp3;
			
//			TIM1->CCR1 = 2100;
//			TIM1->CCR2 = 2000;
//			TIM1->CCR3 = 1900;
			
//			
//			
//			load_data[0] = MID_parameter.wm;
//			load_data[1] = encode_wm;
//			load_data[2] = ADC_VBUS;
//			load_data[3] = counter_value;
//			load_data[4] = drv8303state1read();
//			memcpy(tempData, (uint8_t *)&load_data, sizeof(load_data));
//			HAL_UART_Transmit_DMA(&huart1,(uint8_t *)tempData,6*4);





count++;
if(count >=10000){
			HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	count = 0;
}





		}
	}

}











void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  
	if(huart->Instance == USART2)
  huart->gState = HAL_UART_STATE_READY;//huart1传输完成 变为准备
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_TxCpltCallback can be implemented in the user file.
   */
}
/* USER CODE END 4 */

 /* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x0;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
