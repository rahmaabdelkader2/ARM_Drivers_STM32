#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

typedef void (*SYS_CallBackFunc_t) (void);

typedef struct 
{
    SYS_CallBackFunc_t sys_callback_function;
    u32                sys_cyclic_time;
}SYS_Config_t;



void SysTick_Init(void);
void SysTick_Start(void);
void SysTick_Stop(void);
void SysTick_Delay(u32 milliseconds);
void SysTick_SetCallback(void (*callback)(void));
void SysTick_SetCyclicTime(u32 cyclic_time) ;
#endif // SYSTICK_INTERFACE_H