#include "bit_math.h"
#include "stdtypes.h"
#include "SYS_interface.h"
#include "SYS_private.h"
#include "SYS_config.h"

static void (*SysTick_Callback)(void) = 0; // Correctly defining the callback function

void SysTick_Init(void) {
    SysTick->LOAD = SYSTICK_RELOAD_VALUE;  // Assuming 16MHz system clock, 1ms tick
    SysTick->VAL = 0;           // Clear current value
    SysTick->CTRL = SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_CLKSOURCE; // Enable SysTick, use processor clock
}

void SysTick_Start(void) {
    SysTick->CTRL |= SYSTICK_CTRL_ENABLE; // Enable SysTick
}

void SysTick_Stop(void) {
    SysTick->CTRL &= ~SYSTICK_CTRL_ENABLE; // Disable SysTick
}
void SysTick_Delay(u32 milliseconds) {
    for (u32 i = 0; i < milliseconds; i++) {
        SysTick->VAL = 0;  // Reset counter
        while (!(SysTick->CTRL & SYSTICK_CTRL_COUNTFLAG)); // Wait for COUNTFLAG
    }
}

void SysTick_SetCallback(void (*callback)(void)) {
    SysTick_Callback = callback;
    SysTick->CTRL |= SYSTICK_CTRL_TICKINT; // Enable interrupt
}