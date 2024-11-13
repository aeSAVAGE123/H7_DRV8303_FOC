/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "bsp_DRV8303.h"


/** SPI1引脚定义*/
#define SPI1_SPI                        SPI1
#define SPI1_SPI_CLK_ENABLE()           __HAL_RCC_SPI1_CLK_ENABLE()

#define SPI1_SCK_GPIO_PORT              GPIOA
#define SPI1_SCK_GPIO_PIN               GPIO_PIN_5
#define SPI1_SCK_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()

#define SPI1_MISO_GPIO_PORT             GPIOA
#define SPI1_MISO_GPIO_PIN              GPIO_PIN_6
#define SPI1_MISO_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()

#define SPI1_MOSI_GPIO_PORT             GPIOA
#define SPI1_MOSI_GPIO_PIN              GPIO_PIN_7
#define SPI1_MOSI_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()

#define SPI1_NSS_GPIO_PORT             GPIOA
#define SPI1_NSS_GPIO_PIN              GPIO_PIN_4
#define SPI1_NSS_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

/** SPI3引脚定义*/
#define SPI3_SPI                        SPI3
#define SPI3_SPI_CLK_ENABLE()           __HAL_RCC_SPI3_CLK_ENABLE()

#define SPI3_SCK_GPIO_PORT              GPIOC
#define SPI3_SCK_GPIO_PIN               GPIO_PIN_10
#define SPI3_SCK_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOC_CLK_ENABLE()

#define SPI3_MISO_GPIO_PORT             GPIOC
#define SPI3_MISO_GPIO_PIN              GPIO_PIN_11
#define SPI3_MISO_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOC_CLK_ENABLE()

#define SPI3_MOSI_GPIO_PORT             GPIOC
#define SPI3_MOSI_GPIO_PIN              GPIO_PIN_12
#define SPI3_MOSI_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOC_CLK_ENABLE()

#define SPI3_NSS_GPIO_PORT             GPIOA
#define SPI3_NSS_GPIO_PIN              GPIO_PIN_15
#define SPI3_NSS_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()

void MX_SPI1_Init(void);
void MX_SPI3_Init(void);
void SPI_NSS_Init(void);
uint16_t DRV8303_ReadWrite(SPI_TypeDef* SPIx,uint16_t TxData);
void chipselect(uint8_t status);
void spisck(uint8_t clk);
void spi1writeword(uint16_t data);
uint16_t spi1readword(void);
uint16_t DRV8303_ReadWrite(SPI_TypeDef* SPIx,uint16_t TxData);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */

