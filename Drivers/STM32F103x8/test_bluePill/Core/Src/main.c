#include "stm32f1xx_hal.h"

void delay_ms(uint32_t ms) {
  HAL_Delay(ms);
}

int main(void) {
  // Initialize HAL library
  HAL_Init();

  // Enable GPIOA, GPIOB, GPIOC peripheral clocks
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  // Configure all GPIO pins as output
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  // Configure GPIOA pins as output
  GPIO_InitStruct.Pin = GPIO_PIN_All;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Configure GPIOB pins as output
  GPIO_InitStruct.Pin = GPIO_PIN_All;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // Configure GPIOC pins as output
  GPIO_InitStruct.Pin = GPIO_PIN_All;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  while (1) {
    // Toggle all GPIOA pins
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_All);

    // Toggle all GPIOB pins
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_All);

    // Toggle all GPIOC pins
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_All);

    // Delay for 1 second
    delay_ms(1000);
  }
}
