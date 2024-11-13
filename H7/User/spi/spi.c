#include "spi.h"
#include "./led/bsp_led.h"
#include "stm32h7xx_hal.h"

SPI_HandleTypeDef hspi1;



/* SPI1 init function */
void MX_SPI1_Init(void)
{

    SPI1_SPI_CLK_ENABLE();

    hspi1.Instance = SPI1_SPI;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 7;
    HAL_SPI_Init(&hspi1);
    __HAL_SPI_ENABLE(&hspi1);

}
/* SPI3 init function */
//void MX_SPI3_Init(void)
//{


//    SPI3_SPI_CLK_ENABLE();

//    hspi3.Instance = SPI3_SPI;
//    hspi3.Init.Mode = SPI_MODE_MASTER;
//    hspi3.Init.Direction = SPI_DIRECTION_2LINES;
//    hspi3.Init.DataSize = SPI_DATASIZE_16BIT;
//    hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
//    hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
//    hspi3.Init.NSS = SPI_NSS_SOFT;
//    hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
//    hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
//    hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
//    hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
//    hspi3.Init.CRCPolynomial = 7;

//    HAL_SPI_Init(&hspi3);
//    __HAL_SPI_ENABLE(&hspi3);

//}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if(spiHandle->Instance==SPI1)
    {
        SPI1_SPI_CLK_ENABLE();
        SPI1_SCK_GPIO_CLK_ENABLE();
        SPI1_MISO_GPIO_CLK_ENABLE();
        SPI1_MOSI_GPIO_CLK_ENABLE();


        GPIO_InitStruct.Pin = SPI1_SCK_GPIO_PIN;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(SPI1_SCK_GPIO_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = SPI1_MISO_GPIO_PIN;
        HAL_GPIO_Init(SPI1_MISO_GPIO_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = SPI1_MOSI_GPIO_PIN;
        HAL_GPIO_Init(SPI1_MOSI_GPIO_PORT, &GPIO_InitStruct);

    }
//    else if(spiHandle->Instance==SPI3)
//    {

//        SPI3_SPI_CLK_ENABLE();
//        SPI3_SCK_GPIO_CLK_ENABLE();
//        SPI3_MISO_GPIO_CLK_ENABLE();
//        SPI3_MOSI_GPIO_CLK_ENABLE();

//        GPIO_InitStruct.Pin =SPI3_SCK_GPIO_PIN;
//        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//        GPIO_InitStruct.Pull = GPIO_NOPULL;
//        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//        GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
//        HAL_GPIO_Init(SPI3_SCK_GPIO_PORT, &GPIO_InitStruct);

//        GPIO_InitStruct.Pin =SPI3_MISO_GPIO_PIN;
//        HAL_GPIO_Init(SPI3_MISO_GPIO_PORT, &GPIO_InitStruct);

//        GPIO_InitStruct.Pin =SPI3_MOSI_GPIO_PIN;
//        HAL_GPIO_Init(SPI3_MOSI_GPIO_PORT, &GPIO_InitStruct);
//    }
}

void SPI_NSS_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    SPI1_NSS_GPIO_CLK_ENABLE();
//    SPI3_NSS_GPIO_CLK_ENABLE();

    HAL_GPIO_WritePin(SPI1_NSS_GPIO_PORT, SPI1_NSS_GPIO_PIN , GPIO_PIN_SET);
//    HAL_GPIO_WritePin(SPI3_NSS_GPIO_PORT, SPI3_NSS_GPIO_PIN , GPIO_PIN_SET);

    GPIO_InitStruct.Pin = SPI1_NSS_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(SPI1_NSS_GPIO_PORT, &GPIO_InitStruct);

//    GPIO_InitStruct.Pin = SPI3_NSS_GPIO_PIN;
//    HAL_GPIO_Init(SPI3_NSS_GPIO_PORT, &GPIO_InitStruct);
}

FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
{
    FlagStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH_EXT(SPIx));
    assert_param(IS_SPI_I2S_GET_FLAG(SPI_I2S_FLAG));

    /* Check the status of the specified SPI flag */
    if ((SPIx->SR & SPI_I2S_FLAG) != (uint16_t)RESET)
    {
        /* SPI_I2S_FLAG is set */
        bitstatus = SET;
    }
    else
    {
        /* SPI_I2S_FLAG is reset */
        bitstatus = RESET;
    }
    /* Return the SPI_I2S_FLAG status */
    return  bitstatus;
}

static void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data)
{
    assert_param(IS_SPI_ALL_PERIPH_EXT(SPIx));
    SPIx->TXDR = Data;
		LED3_TOGGLE; 
}

static uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx)
{
    assert_param(IS_SPI_ALL_PERIPH_EXT(SPIx));
    return SPIx->RXDR;
}

static uint16_t SPI_ReadWriteByte(SPI_TypeDef* SPIx,uint16_t TxData)
{
    uint16_t re_Data;
		
    /** 等待TXE标志，TXE=1，发送数据到发送缓冲区*/
    while( SPI_I2S_GetFlagStatus(SPIx,SPI_FLAG_TXE) == RESET){}
    SPI_I2S_SendData(SPIx,TxData);
		
		LED2_TOGGLE; 
    /** 等待RXNE标志，RXNE=1，发送数据到接收缓冲区*/
    while( SPI_I2S_GetFlagStatus(SPIx,SPI_FLAG_RXNE) == RESET){}
    re_Data=SPI_I2S_ReceiveData(SPIx);
			
	
			
    return re_Data;
}



//// 使用HAL库实现的SPI发送/接收函数
//uint16_t SPI_ReadWriteByte(SPI_HandleTypeDef *hspi, uint16_t TxData)
//{
//    uint16_t RxData = 0;
//		uint8_t txBuffer[2];
//	  uint8_t rxBuffer[2] = { 0 };
//		txBuffer[0] = (TxData >> 8) & 0xFF;  // 高8位
//		txBuffer[1] = TxData & 0xFF;          // 低8位


//    // 使用 HAL 库的 TransmitReceive 函数进行发送和接收
//    if (HAL_SPI_TransmitReceive(hspi, txBuffer, rxBuffer, 2, HAL_MAX_DELAY) != HAL_OK) {
//        // 传输失败，调用错误处理函数
////        Error_Handler();
//    }

//    // 组合接收的数据
//    RxData = (rxBuffer[0] << 8) | rxBuffer[1];
//    return RxData;
//}

/* SPI */

	//片选信号 0选中，1不选
void chipselect(uint8_t status)				
{
	if(status==0){					
	 HAL_GPIO_WritePin(GPIOA, SPI1_NSS_GPIO_PIN, GPIO_PIN_RESET);}
	else if(status==1){
	 HAL_GPIO_WritePin(GPIOA, SPI1_NSS_GPIO_PIN, GPIO_PIN_SET);}	
}
	//片选信号 0选中，1不选



//时钟控制，1时钟高电平，0时钟低电平
void spisck(uint8_t clk)	
{
	 if(clk==0){					
	 HAL_GPIO_WritePin(GPIOA, SPI1_SCK_GPIO_PIN, GPIO_PIN_RESET);}
	else if(clk==1){
	 HAL_GPIO_WritePin(GPIOA, SPI1_SCK_GPIO_PIN, GPIO_PIN_SET);}
}



//写入一个字节的数据
void spi1writeword(uint16_t data)
{
	uint8_t i;
	chipselect(0);//片选选中芯片
	for(i=0;i<16;i++)//开始发送数据
	{
		spisck(1);//时钟高电平
			
		if(data&(0x8000>>i)){//SPI是MSB高位数据在前
		 HAL_GPIO_WritePin(GPIOA, SPI1_MOSI_GPIO_PIN, GPIO_PIN_SET);}	//准备数据1 
		else{
		 HAL_GPIO_WritePin(GPIOA, SPI1_MOSI_GPIO_PIN, GPIO_PIN_RESET);}//准备数据0 
		
		spisck(0);//时钟低电平，将数据发送出去
	}
	HAL_GPIO_WritePin(GPIOA, SPI1_MOSI_GPIO_PIN, GPIO_PIN_RESET);
	chipselect(1);		//片选释放芯片
}



	//读取一个字节
uint16_t spi1readword(void)
{
	uint8_t i;//循环
	uint16_t data=0;//准备的数据原型 
	
	chipselect(0);		//片选选中芯片
	for(i=0;i<16;i++)//开始接收数据
	{
		spisck(1);//时钟高电平，接收数据
		spisck(0);//时钟低电平，淮备接收下-个bit 
			
		if(HAL_GPIO_ReadPin(GPIOB, SPI1_MISO_GPIO_PIN)){//如巢引I脚是高电平
		data|=0x8000>>i;//MSB在先，先接收高字节
		}
	}
	chipselect(1);		//片选释放芯片
	return data;//返回接收到的数据

}


	//读取DRV8303的ID
	uint16_t drv8303IDread(void)
	{
		uint16_t command=0; uint16_t regvalue =0;
		command = DRV8303_Read_Mode|DRV8303_Status_Reg2; 
		spi1writeword(command);
		regvalue = spi1readword();//读取状态寄存器2 
		return regvalue&0x0f;
	}
	//读取DRV8303的ID
	
	
	
	
	//读取DRV8303的状态寄存器1
	uint16_t drv8303state1read(void)
	{
		uint16_t command=0; uint16_t regvalue =0;
		command = DRV8303_Read_Mode|DRV8303_Status_Reg1; 
		spi1writeword(command);
		regvalue = spi1readword();//读取状态寄存器2 
		return regvalue;
	}
	//读取DRV8303的状态寄存器1
	
	
	
	//读取DRV8303的状态寄存器2
	uint16_t drv8303state2read(void)
	{
		uint16_t command=0; uint16_t regvalue =0;
		command = DRV8303_Read_Mode|DRV8303_Status_Reg2; 
		spi1writeword(command);
		regvalue = spi1readword();//读取状态寄存器2 
		return regvalue;
	}
	//读取DRV8303的状态寄存器2
	
/* SPI */

uint16_t DRV8303_ReadWrite(SPI_TypeDef* SPIx,uint16_t TxData)
{

    uint16_t Data;

    DRV8303_SPI_NSS_LOW()

    SPI_ReadWriteByte(SPIx,TxData);
//		SPI_ReadWriteByte(&hspi1,TxData);
	
		DRV8303_SPI_NSS_High()
		
    HAL_Delay(10);
	
		DRV8303_SPI_NSS_LOW()

    Data = SPI_ReadWriteByte(SPIx,TxData);
//		Data = SPI_ReadWriteByte(&hspi1,TxData);
	
    DRV8303_SPI_NSS_High()
    
		return Data;
	

}
