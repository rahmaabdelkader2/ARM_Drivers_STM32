#include "bit_math.h"
#include "stdtypes.h"
#include "SYS_interface.h"
#include "SYS_private.h"
#include "SYS_config.h"

static void (*SysTick_Callback)(void) = 0; 
SYSTICK_ErrorStatus_t SysTick_Init(void) {
    SysTick->LOAD = SYSTICK_RELOAD_VALUE;  // Assuming 16MHz system clock, 1ms tick
    SysTick->VAL = 0;           // Clear current value
    SysTick->CTRL = SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_CLKSOURCE; // Enable SysTick, use processor clock
    
    if (!(SysTick->CTRL & SYSTICK_CTRL_ENABLE)) {
        return SYSTICK_enumSYSInit_ERROR; // Check if initialization failed
    }
    return SYSTICK_enumOk;
}

SYSTICK_ErrorStatus_t SysTick_Delay(u32 milliseconds) {
    for (u32 i = 0; i < milliseconds; i++) {
        SysTick->VAL = 0;  // Reset counter
        while (!(SysTick->CTRL & SYSTICK_CTRL_COUNTFLAG)); // Wait for COUNTFLAG
    }
    
    return SYSTICK_enumOk;
}

SYSTICK_ErrorStatus_t SysTick_SetCallback(void (*callback)(void)) {
    if (callback == NULL_PTR) {
        return SYSTICK_enumSYSSet_ERROR; // Callback registration failed due to NULL pointer
    }
    
    SysTick_Callback = callback;
    SysTick->CTRL |= SYSTICK_CTRL_TICKINT; // Enable interrupt
    
    if (!(SysTick->CTRL & SYSTICK_CTRL_TICKINT)) {
        return SYSTICK_enumSYSSet_ERROR; // Check if enabling interrupt failed
    }
    return SYSTICK_enumOk;
}
