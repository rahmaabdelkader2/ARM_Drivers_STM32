#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

// SysTick clock source selection
#define SYSTICK_CLK_SRC_AHB_DIV_8 0
#define SYSTICK_CLK_SRC_AHB 1

#define SYSTICK_CLK_SRC SYSTICK_CLK_SRC_AHB_DIV_8

#define SYSTICK_RELOAD_VALUE (16000000UL / 8 / 1000) - 1 // 1ms delay



#endif // SYSTICK_CONFIG_H