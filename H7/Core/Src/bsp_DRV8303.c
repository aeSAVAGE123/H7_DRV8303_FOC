//
// Created by uoc11 on 2023/10/20.
//
#include "bsp_DRV8303.h"
//#include "./led/bsp_led.h"
#include "spi.h"
//#include "./systick/bsp_SysTick.h"

uint16_t WtiteWord1=DRV8303_Write_Mode|DRV8303_Control_Reg1|DRV8303_GATE_CURRENT_0_25|DRV8303_GATE_RESET_Normal
                    |DRV8303_PWM_MODE_6|DRV8303_OCP_MODE_OC_Latch_Shut_Down|DRV8303_OC_ADJ_SET_0_060;

uint16_t WtiteWord2=DRV8303_Write_Mode|DRV8303_Control_Reg2|DRV8303_OCTW_MODE_Report_OT_OC|DRV8303_GAIN_40
                    |DRV8303_DC_CAL_CH1_A1_INPUT|DRV8303_DC_CAL_CH2_A2_INPUT|DRV8303_OC_TOFF_Cycle_by_Cycle;

uint16_t ReadReg=DRV8303_Read_Mode|DRV8303_Control_Reg1;

uint16_t Re_vaule1=0;
uint16_t Re_vaule2=0;
uint16_t Re_vaule3=0;
uint16_t Re_vaule4=0;

float load_data[5];

extern SPI_HandleTypeDef hspi1;

extern SPI_HandleTypeDef hspi3;

/** DRv8303的SPI初始化以及使能*/
static void DRV8303_SPI_Init(void)
{
    SPI_NSS_Init();
    MX_SPI1_Init();
//    MX_SPI3_Init();

}

static void DRV8303_EN_GATE_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    DRV8303_EN_GATE1_GPIO_ENABLE();
//    DRV8303_EN_GATE1_GPIO_ENABLE();

    HAL_GPIO_WritePin(DRV8303_EN_GATE1_GPIO_PORT, DRV8303_EN_GATE1_GPIO_PIN, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(DRV8303_EN_GATE2_GPIO_PORT, DRV8303_EN_GATE2_GPIO_PIN, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin = DRV8303_EN_GATE1_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(DRV8303_EN_GATE1_GPIO_PORT, &GPIO_InitStruct);

//    GPIO_InitStruct.Pin = DRV8303_EN_GATE2_GPIO_PIN;
//    HAL_GPIO_Init(DRV8303_EN_GATE2_GPIO_PORT, &GPIO_InitStruct);
}
/** DRv8303的设置参数*/
void DRV8303_Init(void)
{
	uint16_t  wconfig=0, rconfig=0, regvalue=0;
		DRV8303_EN_GATE_Init();
    
		DRV8303_SPI_Init();

    DRV8303_EN_GATE1_High();
	
    HAL_Delay(500);      //延时500ms让DRV8303启动完成
	
//	/** 写入DRv8303_1的控制寄存器1和控制寄存器2*/
//    DRV8303_ReadWrite(DRV8303_1,WtiteWord1);

//    DRV8303_ReadWrite(DRV8303_1,WtiteWord2);

//    /** 读取DRv8303_1和DRv8303_2的控制寄存器1*/
//    ReadReg=DRV8303_Read_Mode|DRV8303_Control_Reg1;
//    Re_vaule1=DRV8303_ReadWrite(DRV8303_1,ReadReg);


//    /** 读取DRv8303_1和DRv8303_2的控制寄存器2*/
//    ReadReg=DRV8303_Read_Mode|DRV8303_Control_Reg2;
//    Re_vaule3=DRV8303_ReadWrite(DRV8303_1,ReadReg);
		

	
	wconfig = DRV8303_Write_Mode|DRV8303_Control_Reg1|DRV8303_GATE_CURRENT_0_25|DRV8303_GATE_RESET_Normal
	           |DRV8303_PWM_MODE_6|DRV8303_OCP_MODE_OC_Latch_Shut_Down|DRV8303_OC_ADJ_SET_0_060;
	
	load_data[0] = wconfig;
	spi1writeword(wconfig);//写控制寄存器1
	
	rconfig = DRV8303_Read_Mode|DRV8303_Control_Reg1; 
	
	spi1writeword(rconfig);	//发送读取命令

	regvalue = spi1readword();//读取状态寄存器1 
	
	if((regvalue & 0x07ff)!=(wconfig&0x07ff))
		{ 
		load_data[0] = regvalue & 0x07ff;
		load_data[1] = wconfig&0x07ff;	
//		return 1;
		}//返回1.表示控制寄存器1写入失败 wconfig=0:

	
	wconfig = 0;
	wconfig = DRV8303_Write_Mode|DRV8303_Control_Reg2|DRV8303_OCTW_MODE_Report_OT_OC|DRV8303_GAIN_40
            |DRV8303_DC_CAL_CH1_A1_INPUT|DRV8303_DC_CAL_CH2_A2_INPUT|DRV8303_OC_TOFF_Cycle_by_Cycle;
	load_data[1] = wconfig;
		
	spi1writeword(wconfig);//写控制寄存器2
	
	rconfig=DRV8303_Control_Reg1|DRV8303_Control_Reg2;
		
	spi1writeword(rconfig);//发送读取命令
		
	regvalue = spi1readword();//读取状态寄存器2
		
	if((regvalue & 0x007f) != (wconfig&0x007f))
		{
//		return 2;
		}//返回2.表示控制寄存器2写入失败 return 0


}
