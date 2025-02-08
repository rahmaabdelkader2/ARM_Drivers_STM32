#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void SysTick_Init(void);
void SysTick_Delay(u32 milliseconds);
void SysTick_SetCallback(void (*callback)(void));

#endif // SYSTICK_INTERFACE_H