#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

#define RCC_AHB1 0
#define RCC_AHB2 1
#define RCC_APB1 3
#define RCC_APB2 4

/* AHB1 Peripheral IDs*/
#define RCC_GPIOA_ID     0  // GPIOA enable bit position
#define RCC_GPIOB_ID     1  // GPIOB enable bit position
#define RCC_GPIOC_ID     2  // GPIOC enable bit position
#define RCC_GPIOD_ID     3  // GPIOD enable bit position
#define RCC_GPIOE_ID     4  // GPIOE enable bit position
#define RCC_GPIOH_ID     7  // GPIOH enable bit position
#define RCC_CRC_ID      12  // CRC enable bit position
#define RCC_DMA1_ID     21  // DMA1 enable bit position
#define RCC_DMA2_ID     22  // DMA2 enable bit position

/* AHB2 Peripheral IDs*/
#define RCC_OTGFS_ID     7  // USB OTG FS enable bit position


/* APB1 Peripheral IDs*/
#define RCC_TIM2_ID      0  // TIM2 enable bit position
#define RCC_TIM3_ID      1  // TIM3 enable bit position
#define RCC_TIM4_ID      2  // TIM4 enable bit position
#define RCC_TIM5_ID      3  // TIM5 enable bit position
#define RCC_WWDG_ID     11  // Window Watchdog enable bit position
#define RCC_SPI2_ID     14  // SPI2 enable bit position
#define RCC_SPI3_ID     15  // SPI3 enable bit position
#define RCC_USART2_ID   17  // USART2 enable bit position
#define RCC_I2C1_ID     21  // I2C1 enable bit position
#define RCC_I2C2_ID     22  // I2C2 enable bit position
#define RCC_I2C3_ID     23  // I2C3 enable bit position
#define RCC_PWR_RST_ID  28  // Power and Reset enable bit position

/* APB2 Peripheral IDs*/
#define RCC_TIM1_ID      0  // TIM1 enable bit position
#define RCC_USART1_ID    4  // USART1 enable bit position
#define RCC_USART6_ID    5  // USART6 enable bit position
#define RCC_ADC1_ID      8  // ADC1 enable bit position
#define RCC_SDIO_ID     11  // SDIO enable bit position
#define RCC_SPI1_ID     12  // SPI1 enable bit position
#define RCC_SPI14_ID    13  // SPI13 enable bit position
#define RCC_SYSCFG_ID   14  // SYSCFG enable bit position



void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 copy_u8BusId   ,u8 copy_u8PerId);
void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId);


#endif