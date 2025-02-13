#include "stdtypes.h"
#include "bit_math.h"
#include "NVIC_CONFIG.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

Error_Status_t NVIC_EnableIRQ(IRQn_Type IRQ_number)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (IRQ_number >= 0)
    { // if it's external interrupt
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ISER[Local_u8RegIndex], Local_u8BitIndex);
    }
    else
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID;
    return Local_ErrorStatus;
}

Error_Status_t NVIC_DisableIRQ(IRQn_Type IRQ_number)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (IRQ_number >= 0)
    {
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ICER[Local_u8RegIndex], Local_u8BitIndex);
    }
    else
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID;
    return Local_ErrorStatus;
}

Error_Status_t NVIC_GetPendingIRQ(IRQn_Type IRQ_number, u32 *pending)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (IRQ_number >= 0)
    {
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        *pending = IS_BIT_SET(NVIC->ISPR[Local_u8RegIndex], Local_u8BitIndex);
    }
    else
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID;
    return Local_ErrorStatus;
    // }
    // {
    //     if (IRQ_number >= 0)
    //     {
    //         u8 Local_u8RegIndex = IRQ_number / 32;
    //         u8 Local_u8BitIndex = IRQ_number % 32;
    //         return IS_BIT_SET(NVIC->ISPR[Local_u8RegIndex], Local_u8BitIndex);
    //     }
    //     return 0;
    // }
}
Error_Status_t NVIC_SetPendingIRQ(IRQn_Type IRQ_number)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (IRQ_number >= 0)
    {
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ISPR[Local_u8RegIndex], Local_u8BitIndex);
    }
    else
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID;
    return Local_ErrorStatus;
}

Error_Status_t NVIC_ClearPendingIRQ(IRQn_Type IRQ_number)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (IRQ_number >= 0)
    {
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        SET_BIT(NVIC->ICPR[Local_u8RegIndex], Local_u8BitIndex);
    }
    else
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID;
    return Local_ErrorStatus;
}

Error_Status_t NVIC_GetActive(IRQn_Type IRQ_number, u8 *activeFlag)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (IRQ_number >= 0)
    {
        u8 Local_u8RegIndex = IRQ_number / 32;
        u8 Local_u8BitIndex = IRQ_number % 32;
        *activeFlag = IS_BIT_SET(NVIC->IABR[Local_u8RegIndex], Local_u8BitIndex);
    }
    else
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID;
    return Local_ErrorStatus;
}

Error_Status_t NVIC_SetPriority(IRQn_Type IRQ_number, u8 priority)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    // Ensure the IRQ number is valid
    if (IRQ_number < 0 || IRQ_number >= 240)
    {
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID; // Invalid IRQ number
        return Local_ErrorStatus;
    }
    // Ensure the priority is valid (only upper 4 bits are used)
    if (priority > 0xF0)
    {
        Local_ErrorStatus = NVIC_PRIORITY_INVALID; // Invalid priority
        return Local_ErrorStatus;
    }

    priority &= 0xF0; // Ensure only upper 4 bits are used

    // Set the priority in the corresponding IPR register
    NVIC->IPR[IRQ_number] = priority;

    return NVIC_OK; // Success
}

Error_Status_t NVIC_GetPriority(IRQn_Type IRQ_number, u8 *priority)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;

    // Ensure the IRQ number is valid
    if (IRQ_number < 0 || IRQ_number >= 240)
    {
        Local_ErrorStatus = NVIC_IRQ_NUMBER_INVALID; // Invalid IRQ number
        return Local_ErrorStatus;
    }

    // Ensure the priority pointer is valid
    if (priority == NULL)
    {
        Local_ErrorStatus = NVIC_NULL_POINTER; // Invalid priority pointer
        return Local_ErrorStatus;
    }
    // Read the priority from the corresponding IPR register
    *priority = NVIC->IPR[IRQ_number];

    // Mask out the lower 4 bits (reserved) and ensure only upper 4 bits are used
    *priority &= 0xF0;

    return NVIC_OK; // Success
}

Error_Status_t NVIC_SetPriorityGrouping(NVIC_PRIORITY_GROUP priority_grouping)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (priority_grouping < 8)
    {
        u32 Local_u32Reg = SCB->AIRCR;
        Local_u32Reg = VECTKEY | (priority_grouping << 8);
        SCB->AIRCR = Local_u32Reg;
    }
    else
        Local_ErrorStatus = NVIC_GROUPING_INVALID;
    return Local_ErrorStatus;
}
Error_Status_t NVIC_GetPriorityGrouping(u8 *priority_grouping)
{
    Error_Status_t Local_ErrorStatus = NVIC_OK;
    if (priority_grouping == NULL)
    {
        Local_ErrorStatus = NVIC_NULL_POINTER;
        return Local_ErrorStatus;
    }
    *priority_grouping = (SCB->AIRCR & PRIGROUP_MASK) >> 8;
    return Local_ErrorStatus;
}
void NVIC_SystemReset(void)
{
    SCB->AIRCR = VECTKEY | SYSRESETREQ;
    while (1)
        ;
}
