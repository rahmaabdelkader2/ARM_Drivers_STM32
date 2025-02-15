#include "stdtypes.h"
#include "bit_math.h"
#include "HSCHED.h"
#include "SYS_interface.h"


/* Array to store registered runnables */
static volatile HSCED_RunnableConfig_t *HSCED_Runnable_Array[Max_Runnable_Number] = {0};
/* Variable to keep track of scheduler ticks */

static volatile u64 HSCED_u64Ticks = 0;
static void HSCED_vSchedulerHandler(void)
{
    u32 Local_u32RunnableIndex = 0;
    HSCED_RunnableConfig_t *Local_Runnable = 0;

    /* Increment scheduler ticks */
    HSCED_u64Ticks++;

    /* Loop through the array of runnables */
    for (Local_u32RunnableIndex = 0; Local_u32RunnableIndex < Max_Runnable_Number; Local_u32RunnableIndex++)
    {
        /* Check if the runnable is registered */
        if (HSCED_Runnable_Array[Local_u32RunnableIndex] != 0)
        {
            Local_Runnable = HSCED_Runnable_Array[Local_u32RunnableIndex];

            /* Check if the runnable is due to run */
            if (HSCED_u64Ticks >= Local_Runnable->HSCED_u32Firstdelay)
            {
                /* Call the runnable */
                Local_Runnable->HSCED_CallBackFunc();

                /* Update the first delay */
                Local_Runnable->HSCED_u32Firstdelay += Local_Runnable->HSCED_u32RunnableCyclicTime;
            }
        }
    }
}


HSCED_ErrorStatus_t HSCED_enumStart(void)
{
    HSCED_ErrorStatus_t Local_enumErrorRet = HSCED_enumOk;

    HSCED_u64Ticks = 0;

    /* Initialize SysTick (since it enables the timer) */
    if (SysTick_Init() != SYSTICK_enumOk)
    {
        return SYSTICK_enumSYSInit_ERROR;
    }

    /* Set the callback function */
    if (SysTick_SetCallback(&HSCED_vSchedulerHandler) != SYSTICK_enumOk)
    {
        return HSCED_enumSYSSet_ERROR;
    }

    return Local_enumErrorRet;
}

HSCED_ErrorStatus_t HSCED_enumStop(void)
{
    HSCED_ErrorStatus_t Local_enumErrorRet = HSCED_enumOk;

    HSCED_u64Ticks = 0;

    /* Disable SysTick interrupt to stop scheduling */
    SysTick->CTRL &= ~SYSTICK_CTRL_TICKINT;

    return Local_enumErrorRet;
}
