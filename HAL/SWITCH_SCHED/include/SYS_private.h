#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_BASE_ADDRESS 0xE000E010
#define SysTick  ((volatile SysTick_Type*) SYSTICK_BASE_ADDRESS)

typedef struct
{
    volatile u32 CTRL;  // Control and Status Register
    volatile u32 LOAD;  // Reload Value Register
    volatile u32 VAL;   // Current Value Register
    volatile u32 CALIB; // Calibration Value Register
} SysTick_Type;

// SysTick Control and Status Register Bits
#define SYSTICK_CTRL_ENABLE      (1 << 0) // Enable SysTick
#define SYSTICK_CTRL_TICKINT     (1 << 1) // Enable SysTick interrupt
#define SYSTICK_CTRL_CLKSOURCE   (1 << 2) // Clock source: 1 = Processor clock, 0 = External clock
#define SYSTICK_CTRL_COUNTFLAG   (1 << 16) // Timer reached zero



#endif // SYSTICK_PRIVATE_H