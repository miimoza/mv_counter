/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define J1      0
#define J2      1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// LED INITIALIZATION
// MANCHE WHITE LED
GPIO_TypeDef *j1_manche_1_PORT = GPIOC;
uint16_t j1_manche_1_PIN = GPIO_PIN_0;

GPIO_TypeDef *j1_manche_2_PORT = GPIOA;
uint16_t j1_manche_2_PIN = GPIO_PIN_4;

GPIO_TypeDef *j2_manche_1_PORT = GPIOC;
uint16_t j2_manche_1_PIN = GPIO_PIN_1;

GPIO_TypeDef *j2_manche_2_PORT = GPIOB;
uint16_t j2_manche_2_PIN = GPIO_PIN_0;

// PARTIE GREEN LED
GPIO_TypeDef *j1_partie_1_PORT = GPIOA;
uint16_t j1_partie_1_PIN = GPIO_PIN_1;

GPIO_TypeDef *j1_partie_2_PORT = GPIOC;
uint16_t j1_partie_2_PIN = GPIO_PIN_3;

GPIO_TypeDef *j2_partie_1_PORT = GPIOC;
uint16_t j2_partie_1_PIN = GPIO_PIN_2;

GPIO_TypeDef *j2_partie_2_PORT = GPIOA;
uint16_t j2_partie_2_PIN = GPIO_PIN_0;

// ROYALE BLUE LED
GPIO_TypeDef *j1_royale_1_PORT = GPIOA;
uint16_t j1_royale_1_PIN = GPIO_PIN_10;

GPIO_TypeDef *j1_royale_2_PORT = GPIOA;
uint16_t j1_royale_2_PIN = GPIO_PIN_9;

GPIO_TypeDef *j2_royale_1_PORT = GPIOB;
uint16_t j2_royale_1_PIN = GPIO_PIN_3;

GPIO_TypeDef *j2_royale_2_PORT = GPIOC;
uint16_t j2_royale_2_PIN = GPIO_PIN_7;


// BUTTON INITIALISATION
GPIO_TypeDef *j1_button_PORT = GPIOB;
uint16_t j1_button_PIN = GPIO_PIN_5;

GPIO_TypeDef *j2_button_PORT = GPIOB;
uint16_t j2_button_PIN = GPIO_PIN_4;

void check_leds()
{
    // MANCHE
    HAL_GPIO_WritePin(j1_manche_1_PORT, j1_manche_1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j1_manche_2_PORT, j1_manche_2_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j2_manche_1_PORT, j2_manche_1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j2_manche_2_PORT, j2_manche_2_PIN, GPIO_PIN_SET);

    //PARTIE
    HAL_GPIO_WritePin(j1_partie_1_PORT, j1_partie_1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j1_partie_2_PORT, j1_partie_2_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j2_partie_1_PORT, j2_partie_1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j2_partie_2_PORT, j2_partie_2_PIN, GPIO_PIN_SET);

    //ROYALE
    HAL_GPIO_WritePin(j1_royale_1_PORT, j1_royale_1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j1_royale_2_PORT, j1_royale_2_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j2_royale_1_PORT, j2_royale_1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(j2_royale_2_PORT, j2_royale_2_PIN, GPIO_PIN_SET);
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

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
  /* USER CODE BEGIN 2 */
  // LED STATUS INITIALISATION
  GPIO_PinState j1_manche_1_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j1_manche_2_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j2_manche_1_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j2_manche_2_STATUS = GPIO_PIN_RESET;

  GPIO_PinState j1_partie_1_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j1_partie_2_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j2_partie_1_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j2_partie_2_STATUS = GPIO_PIN_RESET;

  GPIO_PinState j1_royale_1_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j1_royale_2_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j2_royale_1_STATUS = GPIO_PIN_RESET;
  GPIO_PinState j2_royale_2_STATUS = GPIO_PIN_RESET;

  // CHECK LEDS
  check_leds();
  for(int i=0; i<10000 ;i++) for(int j=0; j<500; j++) __NOP();


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */





    // CHECK BUTTON
    if(HAL_GPIO_ReadPin(j1_button_PORT,j1_button_PIN) == GPIO_PIN_RESET)
    {
        // 1e PARTIE GAGNEE
        if (j1_manche_2_STATUS == GPIO_PIN_SET)
        {
            j1_manche_1_STATUS = GPIO_PIN_RESET;
            j1_manche_2_STATUS = GPIO_PIN_RESET;
            // 2e PARTIE GAGNEE
            if (j1_partie_1_STATUS == GPIO_PIN_SET)
            {

                // 1er ROYALE GAGNEE
                if (j1_partie_2_STATUS == GPIO_PIN_SET)
                {
                    j1_partie_1_STATUS = GPIO_PIN_RESET;
                    j1_partie_2_STATUS = GPIO_PIN_RESET;

                    // 2e ROYALE GAGNEE
                    if (j1_royale_1_STATUS == GPIO_PIN_SET)
                    {
                        // WIN TOTAL
                        if (j1_royale_2_STATUS == GPIO_PIN_SET)
                        {
                            // MEGA WIN
                            j1_royale_1_STATUS = GPIO_PIN_RESET;
                            j1_royale_2_STATUS = GPIO_PIN_RESET;
                        }
                        else
                        {
                            // 2e ROYALE GAGNEE
                            j1_royale_2_STATUS = GPIO_PIN_SET;
                        }
                    }
                    else
                    {
                        // 1e ROYALE GAGNEE
                        j1_royale_1_STATUS = GPIO_PIN_SET;
                    }
                }
                else
                {
                    // 2e PARTIE GAGNEE
                    j1_partie_2_STATUS = GPIO_PIN_SET;
                }
            }
            else
            {
                // 1e PARTIE GAGNEE
                j1_partie_1_STATUS = GPIO_PIN_SET;
            }
        }
        else
        {
            // 2e MANCHE GAGNE
            if (j1_manche_1_STATUS == GPIO_PIN_SET)
            {
                j1_manche_2_STATUS = GPIO_PIN_SET;
            }
            else
            {
                // 1e MANCHE GAGNE
                j1_manche_1_STATUS = GPIO_PIN_SET;
            }
        }
    }

    if(HAL_GPIO_ReadPin(j2_button_PORT,j2_button_PIN) == GPIO_PIN_RESET)
    {
        // 1e PARTIE GAGNEE
        if (j2_manche_2_STATUS == GPIO_PIN_SET)
        {
            j2_manche_1_STATUS = GPIO_PIN_RESET;
            j2_manche_2_STATUS = GPIO_PIN_RESET;
            // 2e PARTIE GAGNEE
            if (j2_partie_1_STATUS == GPIO_PIN_SET)
            {

                // 1er ROYALE GAGNEE
                if (j2_partie_2_STATUS == GPIO_PIN_SET)
                {
                    j2_partie_1_STATUS = GPIO_PIN_RESET;
                    j2_partie_2_STATUS = GPIO_PIN_RESET;

                    // 2e ROYALE GAGNEE
                    if (j2_royale_1_STATUS == GPIO_PIN_SET)
                    {
                        // WIN TOTAL
                        if (j2_royale_2_STATUS == GPIO_PIN_SET)
                        {
                            // MEGA WIN
                            j2_royale_1_STATUS = GPIO_PIN_RESET;
                            j2_royale_2_STATUS = GPIO_PIN_RESET;
                        }
                        else
                        {
                            // 2e ROYALE GAGNEE
                            j2_royale_2_STATUS = GPIO_PIN_SET;
                        }
                    }
                    else
                    {
                        // 1e ROYALE GAGNEE
                        j2_royale_1_STATUS = GPIO_PIN_SET;
                    }
                }
                else
                {
                    // 2e PARTIE GAGNEE
                    j2_partie_2_STATUS = GPIO_PIN_SET;
                }
            }
            else
            {
                // 1e PARTIE GAGNEE
                j2_partie_1_STATUS = GPIO_PIN_SET;
            }
        }
        else
        {
            // 2e MANCHE GAGNE
            if (j2_manche_1_STATUS == GPIO_PIN_SET)
            {
                j2_manche_2_STATUS = GPIO_PIN_SET;
            }
            else
            {
                // 1e MANCHE GAGNE
                j2_manche_1_STATUS = GPIO_PIN_SET;
            }
        }
    }

    // LED UPDATE
    // MANCHE
    HAL_GPIO_WritePin(j1_manche_1_PORT, j1_manche_1_PIN, j1_manche_1_STATUS);
    HAL_GPIO_WritePin(j1_manche_2_PORT, j1_manche_2_PIN, j1_manche_2_STATUS);
    HAL_GPIO_WritePin(j2_manche_1_PORT, j2_manche_1_PIN, j2_manche_1_STATUS);
    HAL_GPIO_WritePin(j2_manche_2_PORT, j2_manche_2_PIN, j2_manche_2_STATUS);

    //PARTIE
    HAL_GPIO_WritePin(j1_partie_1_PORT, j1_partie_1_PIN, j1_partie_1_STATUS);
    HAL_GPIO_WritePin(j1_partie_2_PORT, j1_partie_2_PIN, j1_partie_2_STATUS);
    HAL_GPIO_WritePin(j2_partie_1_PORT, j2_partie_1_PIN, j2_partie_1_STATUS);
    HAL_GPIO_WritePin(j2_partie_2_PORT, j2_partie_2_PIN, j2_partie_2_STATUS);

    // ROYALE
    HAL_GPIO_WritePin(j1_royale_1_PORT, j1_royale_1_PIN, j1_royale_1_STATUS);
    HAL_GPIO_WritePin(j1_royale_2_PORT, j1_royale_2_PIN, j1_royale_2_STATUS);
    HAL_GPIO_WritePin(j2_royale_1_PORT, j2_royale_1_PIN, j2_royale_1_STATUS);
    HAL_GPIO_WritePin(j2_royale_2_PORT, j2_royale_2_PIN, j2_royale_2_STATUS);

    // DELAY TO AVOID MULTIPLE BUTTON INTERUPTION
    for(int i=0; i<1000 ;i++) for(int j=0; j<500; j++) __NOP();


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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
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
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
