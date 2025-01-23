#include "stdtypes.h"
#include "bit_math.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
    #if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CR |= 0x00010000; /* Enable HSE with no bypass */
        while (!(RCC_CR & 0x00020000)); /* Wait for HSE to be ready */
        RCC_CFGR |= 0x00000001; /* Set HSE as system clock */
    #elif RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR |= 0x00050000; /* Enable HSE with bypass */
        while (!(RCC_CR & 0x00020000)); /* Wait for HSE to be ready */
        RCC_CFGR |= 0x00000001; /* Set HSE as system clock */
    #elif RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR |= 0x00000001; /* Enable HSI */
        while (!(RCC_CR & 0x00000002)); /* Wait for HSI to be ready */
        RCC_CFGR |= 0x00000000; /* Set HSI as system clock */
    #elif RCC_CLOCK_TYPE == RCC_PLL
        RCC_CR &= ~0x01000000; /* Disable PLL before configuration */
        
        #if RCC_PLL_INPUT == RCC_PLL_IN_HSI
            RCC_PLLCFGR = (RCC_PLLCFGR & ~(0x3 << 22)) | (0x0 << 22); /* HSI as PLL source */
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
            RCC_PLLCFGR = (RCC_PLLCFGR & ~(0x3 << 22)) | (0x1 << 22); /* HSE as PLL source */
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
            RCC_PLLCFGR = (RCC_PLLCFGR & ~(0x3 << 22)) | (0x1 << 22); /* HSE as PLL source */
            RCC_PLLCFGR |= (1 << 4); /* Divide HSE by 2 */
        #endif

        RCC_PLLCFGR |= (RCC_PLL_M << 0) | (RCC_PLL_N << 6) | (RCC_PLL_P << 16);
        RCC_CR |= 0x01000000; /* Enable PLL */
        while (!(RCC_CR & 0x02000000)); /* Wait for PLL to be ready */
        RCC_CFGR |= 0x00000002; /* Set PLL as system clock */
    #else
        #error("You chose a wrong clock type")
    #endif
}

void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
    if (copy_u8PerId <= 31) {
        switch (copy_u8BusId) {
        case RCC_AHB1:
            SET_BIT(RCC_AHB1ENR, copy_u8PerId);
            break;
        case RCC_AHB2:
            SET_BIT(RCC_AHB2ENR, copy_u8PerId);
            break;
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, copy_u8PerId);
            break;
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, copy_u8PerId);
            break;
        default:
            /* Return error */
            break;
        }
    } else {
        /* Return error */
    }
}
