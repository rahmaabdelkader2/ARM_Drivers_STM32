#include "stdtypes.h"
#include "bit_math.h"
#include "NVIC_CONFIG.h"
#include "NVIC_interface.h"


void NVIC_EnableIRQ(IRQn_Type IRQ_number){
    if (IRQ_number >= 0) {  // if it's external interrupt
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ISER[Local_u8RegIndex], Local_u8BitIndex);
    }
}

void NVIC_DisableIRQ(IRQn_Type IRQ_number){
    if(IRQ_number >= 0){
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ICER[Local_u8RegIndex], Local_u8BitIndex);
    }
}

u32 NVIC_GetPendingIRQ(IRQn_Type IRQ_number){
    if(IRQ_number >= 0){
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        return IS_BIT_SET(NVIC->ISPR[Local_u8RegIndex], Local_u8BitIndex);
    }
    return 0;
}

void NVIC_SetPendingIRQ(IRQn_Type IRQ_number){
    if(IRQ_number >= 0){
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ISPR[Local_u8RegIndex], Local_u8BitIndex);
    }
}

void NVIC_ClearPendingIRQ(IRQn_Type IRQ_number){
    if(IRQ_number >= 0){
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ICPR[Local_u8RegIndex], Local_u8BitIndex);
    }
}

u32 NVIC_GetActive(IRQn_Type IRQ_number){
    if(IRQ_number >= 0){
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        return IS_BIT_SET(NVIC->IABR[Local_u8RegIndex], Local_u8BitIndex);
    }
    return 0;
}

void NVIC_SetPriority(IRQn_Type IRQ_number, u8 priority) {
    if (IRQ_number >= 0) {
        u8 registerIndex = IRQ_number / 4;
        u8 byteOffset = (IRQ_number % 4) * 8;
        
        NVIC->IPR[registerIndex] &= ~(0xFF << byteOffset);
        NVIC->IPR[registerIndex] |= (priority << (byteOffset + 6));
    }
}

u32 NVIC_GetPriority(IRQn_Type IRQ_number) {
    if (IRQ_number >= 0) {
        u8 Local_u8RegIndex = IRQ_number / 4;
        u8 Local_u8BitIndex = (IRQ_number % 4) * 8;
        return (NVIC->IPR[Local_u8RegIndex] >> (Local_u8BitIndex + 6)) & 0x03;
    }
    return 0;
}

void NVIC_SetPriorityGrouping(u32 priority_grouping) {
    u32 Local_u32Reg = SCB->AIRCR;
    Local_u32Reg = (Local_u32Reg & ~PRIGROUP_MASK) | VECTKEY | (priority_grouping << 8);
    SCB->AIRCR = Local_u32Reg;
}

void NVIC_SystemReset(void) {
    SCB->AIRCR = VECTKEY | SYSRESETREQ;
    while (1);
}
