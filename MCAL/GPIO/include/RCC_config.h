#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/* Options : RCC_HSE_CRYSTAL
            RCC_HSE_RC
            RCC_HSI
            RCC_PLL    
*/
#define RCC_CLOCK_TYPE      RCC_HSI

/* Options : RCC_PLL_IN_HSI
            RCC_PLL_IN_HSE_DIV_2
            RCC_PLL_IN_HSE
*/
/* Select value only if you have PLL as input source clock */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT    RCC_PLL_IN_HSE_DIV_2
#define RCC_PLL_M        8   /* PLL input division factor */
#define RCC_PLL_N        336 /* PLL multiplication factor */
#define RCC_PLL_P        2   /* PLL division factor for main system clock */
#endif

#endif
