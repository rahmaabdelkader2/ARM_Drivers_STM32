#include "bit_math.h"
#include "stdtypes.h"
#include "SYS_interface.h"
#include "SYS_private.h"
#include "SYS_config.h"

static void (*SysTick_Callback)(void) = 0;
static u32 SysTick_CyclicTime = 1; 

void SysTick_Handler(void) {
    if (SysTick_Callback != NULL) {
        SysTick_Callback();
    }
}

void SysTick_Init(void) {
    SysTick->LOAD = (SYSTICK_RELOAD_VALUE * SysTick_CyclicTime) - 1;  // Set reload value
    SysTick->VAL = 0;   // Clear current value
    SysTick->CTRL = SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_CLKSOURCE | SYSTICK_CTRL_TICKINT; // Enable SysTick and interrupts
}

void SysTick_Start(void) {
    SysTick->CTRL |= SYSTICK_CTRL_ENABLE; // Enable SysTick
}

void SysTick_Stop(void) {
    SysTick->CTRL &= ~SYSTICK_CTRL_ENABLE; // Disable SysTick
}

void SysTick_SetCallback(void (*callback)(void)) {
    SysTick_Callback = callback;
}

void SysTick_SetCyclicTime(u32 cyclic_time) {
    SysTick_CyclicTime = cyclic_time;
    SysTick->LOAD = (SYSTICK_RELOAD_VALUE * SysTick_CyclicTime) - 1; // Adjust LOAD value
}
