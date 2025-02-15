#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


typedef enum 
{
    SYSTICK_enumOk,                   /* Operation successful */                  
    SYSTICK_enumNOk,                  /* General error */
    SYSTICK_enumSYSInit_ERROR,        /* SysTick initialization failed */
    SYSTICK_enumSYSSet_ERROR,         /* SysTick callback registration failed */
    SYSTICK_enumSYSStart_ERROR,       /* SysTick start failed */
    SYSTICK_enumSYSStop_ERROR,        /* SysTick stop failed */

} SYSTICK_ErrorStatus_t;

SYSTICK_ErrorStatus_t SysTick_Init(void);
SYSTICK_ErrorStatus_t SysTick_Delay(u32 milliseconds);
SYSTICK_ErrorStatus_t SysTick_SetCallback(void (*callback)(void));

#endif // SYSTICK_INTERFACE_H