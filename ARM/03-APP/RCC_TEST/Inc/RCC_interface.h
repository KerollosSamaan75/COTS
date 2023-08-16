/**********************************************************************/
/********************  Author : Kerollos Samaan  **********************/
/********************  Date   : 30/07/2023       **********************/
/********************  Version: V1.0             **********************/
/**********************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define  RCC_AHB    0
#define  RCC_APB1   1
#define  RCC_APB2   2
/***************************************************************************************************************************/
#define AHB_DMA_1_EN             0
#define AHB_DMA_2_EN             1
#define AHB_SRAM_EN              2
#define AHB_FLITF_EN             4
#define AHB_CRC_EN               6
#define AHB_FSMC_EN              8
#define AHB_SDIO_EN              10
/***************************************************************************************************************************/
#define APB2_AFIO_EN             0
#define APB2_IOPA_EN             2
#define APB2_IOPB_EN             3
#define APB2_IOPC_EN             4
#define APB2_IOPD_EN             5
#define APB2_IOPE_EN             6
#define APB2_IOPF_EN             7
#define APB2_IOPG_EN             8
#define APB2_ADC_1_EN            9
#define APB2_ADC_2_EN            10
#define APB2_TIM_1_EN            11
#define APB2_SPI_1_EN            12
#define APB2_TIM_8_EN            13
#define APB2_USART_1_EN          14
#define APB2_ADC_3_EN            15
#define APB2_TIM_9_EN            19
#define APB2_TIM_10_EN           20
#define APB2_TIM_11_EN           21
/***************************************************************************************************************************/
#define APB1_TIM_2_EN            0
#define APB1_TIM_3_EN            1
#define APB1_TIM_4_EN            2
#define APB1_TIM_5_EN            3
#define APB1_TIM_6_EN            4
#define APB1_TIM_7_EN            5
#define APB1_TIM_12_EN           6
#define APB1_TIM_13_EN           7
#define APB1_TIM_14_EN           8
#define APB1_WWDG_EN             11
#define APB1_SPI_2_EN            14
#define APB1_SPI_3_EN            15
#define APB1_USART_2_EN          17
#define APB1_USART_3_EN          18
#define APB1_USART_4_EN          19
#define APB1_USART_5_EN          20
#define APB1_I2C_1_EN            21
#define APB1_I2C_2_EN            22
#define APB1_USB_EN              23
#define APB1_CAN_EN              25
#define APB1_BKP_EN              27
#define APB1_PWR_EN              28
#define APB1_DAC_EN              29
/***************************************************************************************************************************/

void RCC_voidInitSystemClock(void);
void RCC_voidEnableClock (u8 Copy_u8BusID,u8 copy_u8PerID);
void RCC_voidDisableClock(u8 Copy_u8BusID,u8 copy_u8PerID);

#endif
