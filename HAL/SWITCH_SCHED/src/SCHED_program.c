#include "bit_math.h"
#include "stdtypes.h"
#include "SYS_interface.h"
#include "SCHED_config.h"
#include "SCHED.h"

static void SCHED_CyclicRunRunnable(void);

static HSCHED_Runnable_config_t* Runnable_Config_Arr[MAX_TASKS_ALLOWED] = {NULL};

static volatile u64 Tick_Counter = 0;  

void SCHED_init(void)
{
    static SYS_Config_t Local_structTimerConfig = {
        .sys_callback_function = SCHED_CyclicRunRunnable, 
        .sys_cyclic_time = 1
    };

    SysTick_SetCyclicTime(Local_structTimerConfig.sys_cyclic_time);
    SysTick_SetCallback(Local_structTimerConfig.sys_callback_function);
    SysTick_Init();
    SysTick_Start();  
}

void SCHED_start(void){
    SysTick_Start();
}

void SCHED_stop(void){
    SysTick_Stop();
}

HSCHED_Error_t SCHED_registerRunnable(HSCHED_Runnable_config_t * Configuration_struct){
    if (Configuration_struct == NULL || Configuration_struct->callback_function == NULL) {
        return NULL_POINTER;
    }

    if (Configuration_struct->priority >= MAX_TASKS_ALLOWED) {
        return SCHED_NOK; 
    }

    if (Runnable_Config_Arr[Configuration_struct->priority] != NULL) {
        return SCHED_NOK;
    }

    Runnable_Config_Arr[Configuration_struct->priority] = Configuration_struct;
    return SCHED_OK;
}

static void SCHED_CyclicRunRunnable(void) {
    u32 Task_Index;

    for (Task_Index = 0; Task_Index < MAX_TASKS_ALLOWED; Task_Index++) {
        if (Runnable_Config_Arr[Task_Index] != NULL && 
            Runnable_Config_Arr[Task_Index]->callback_function != NULL) {
            
            if ((Runnable_Config_Arr[Task_Index]->first_delay == 0) && 
                (Tick_Counter % Runnable_Config_Arr[Task_Index]->cyclic_time == 0)) {
                
                Runnable_Config_Arr[Task_Index]->callback_function();
            } 
            else if (Runnable_Config_Arr[Task_Index]->first_delay > 0) {
                Runnable_Config_Arr[Task_Index]->first_delay--;
            }
        }
    }
    Tick_Counter++;  
}
