#ifndef HSCHED_H
#define HSCHED_H

#define Max_Runnable_Number 60

/* Scheduler error status */
typedef enum
{
    HSCED_enumOk,                   /* Operation successful */                  
    HSCED_enumNOk,                  /* General error */
    HSCED_enumExceedsMaxRunnable,   /* Runnable priority exceeds maximum */
    HSCED_enumNullPtr,              /* Null pointer passed */
    HSCED_enumPriorityTaken,        /* Priority slot already occupied */
    HSCED_enumSYSInit_ERROR,        /* SysTick initialization failed */
    HSCED_enumSYSSet_ERROR,         /* SysTick callback registration failed */
    HSCED_enumSYSStart_ERROR,       /* SysTick start failed */
    HSCED_enumSYSStop_ERROR,        /* SysTick stop failed */

} HSCED_ErrorStatus_t;


typedef void (*HSCED_CallBackFunc_t) (void); 


/* Structure to define a runnable configuration */
typedef struct 
{
    HSCED_CallBackFunc_t        HSCED_CallBackFunc;           /* Pointer to the runnable function */
    u32 volatile                HSCED_u32RunnablePriority;    /* Priority of the runnable */
    u32 volatile                HSCED_u32Firstdelay;          /* Initial delay in milliseconds */ 
    u32 volatile                HSCED_u32RunnableCyclicTime;  /* Cyclic time in milliseconds */ 
} HSCED_RunnableConfig_t;


HSCED_ErrorStatus_t HSCHED_init(void); // Initialize the scheduler
void HSCHED_start(void); // Start the scheduler
void HSCHED_stop(void); // Stop the scheduler
void HSCHED_SWITCH_RUNNING_TASK(void); // Switch to the next task

#endif