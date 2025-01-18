#include "stdtypes.h"
#include"bit_math.h"
#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"

void RCC_voidInitSysClock(void)
{
    #if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CR =   0x00010000; /* Enable HSE with no bypass */
        RCC_CFGR = 0x00000001;
    #elif RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR   = 0x00050000; /* Enable HSE with bypass */
        RCC_CFGR = 0x00000001;
    #elif RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
        RCC_CFGR = 0x00000000;
    #elif RCC_CLOCK_TYPE == RCC_PLL
        #if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
        RCC_CR   = 0x01000000; /* Enable HSI/2 */
        RCC_CFGR = 0x00000002;
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
        RCC_CR   = 0x01010000; /* Enable HSE/2 */
        RCC_CFGR = 0x00030002;
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
        RCC_CR   = 0x01000000; /* Enable HSE */
        RCC_CFGR = 0x00010002;
        #endif 
    #else
        #error("You chosed wrong clock type")
    #endif
}

void RCC_voidEnableClock(u8 copy_u8BusId   ,u8 copy_u8PerId)
{
    if(copy_u8PerId<=31){
        switch(copy_u8BusId){
        case RCC_AHB  : SET_BIT(RCC_AHBENR,copy_u8PerId); break;
        case RCC_APB1 : SET_BIT(RCC_APB1ENR,copy_u8PerId); break;
        case RCC_APB2 : SET_BIT(RCC_APB2ENR,copy_u8PerId); break;
        default: /*return error*/ break;
    }
    }
    else{
        //return error
    }

    
}  
