#ifndef    SCHED_H
#define    SCHED_H

typedef void (*HSCHED_cbf)(void);

typedef struct 
{
   u32 priority;
   u32 cyclic_time;
   HSCHED_cbf callback_function;
   u32 first_delay;

}HSCHED_Runnable_config_t;

typedef enum 
{
    SCHED_OK,
    SCHED_NOK,
    NULL_POINTER

}HSCHED_Error_t;

void SCHED_init(void);
void SCHED_start(void);
void SCHED_stop(void);
HSCHED_Error_t SCHED_registerRunnable(HSCHED_Runnable_config_t * Configuration_struct);



#endif    // SCHED_H