#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "stdtypes.h"

typedef enum{
    NonMaskableInt_IRQn = -14 ,
    HardFault_IRQn = -13 ,
    MemoryManagement_IRQn = -12 ,
    BusFault_IRQn = -11 ,
    UsageFault_IRQn = -10 ,
    SecureFault_IRQn = -9 ,
    SVCall_IRQn = -5 ,
    DebugMonitor_IRQn = -4 ,
    PendSV_IRQn = -2 ,
    SysTick_IRQn = -1 ,
    WWDG_STM_IRQn = 0 ,
    PVD_STM_IRQn = 1

}IRQn_Type;

void NVIC_SetPriorityGrouping(u32 priority_grouping); //Set the priority grouping
void NVIC_EnableIRQ(IRQn_Type IRQ_number); //Enable IRQn
void NVIC_DisableIRQ(IRQn_Type IRQ_number); //Disable IRQn
u32 NVIC_GetPendingIRQ (IRQn_Type IRQ_number); //Return true (IRQ-Number) if IRQn is pending
void NVIC_SetPendingIRQ (IRQn_Type IRQ_number); //Set IRQn pending
void NVIC_ClearPendingIRQ (IRQn_Type IRQ_number); //Clear IRQn pending status
u32 NVIC_GetActive (IRQn_Type IRQ_number); //Return the IRQ number of the active interrupt
void NVIC_SetPriority (IRQn_Type IRQ_number, u8 priority); //Set priority for IRQn
u32 NVIC_GetPriority (IRQn_Type IRQ_number); //Read priority of IRQn
void NVIC_SystemReset (void); //System Reset
#endif
