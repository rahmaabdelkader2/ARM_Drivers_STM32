#ifndef     SWITCH_SCHED_H
#define     SWITCH_SCHED_H

#define SWITCH_PRESSED  1
#define SWITCH_RELEASED 0

// Error States
typedef enum {
    HSWITCH_NOK = 0,           /* Operation failed */
    HSWITCH_OK,                /* Operation succeeded */
    HSWITCH_NullPtr,           /* Null pointer passed */
    HSWITCH_InvalidPin,        /* Invalid pin number */
    HSWITCH_InvalidPort,       /* Invalid port number */
    HSWITCH_InvalidState,      /* Invalid switch state */
    HSWITCH_InvalidSwitch        /* Invalid switch name */
} HSWITCH_enumErrorState_t;

// Configuration Struct
typedef struct {
    u8 HSWITCH_Port_Number;  
    u8 HSWITCH_Pin_Number;    
    u8 HSWITCH_Pull_State; 
} HSWITCH_struct_Config_t;

void HSWITCH_vInit(void);
HSWITCH_enumErrorState_t HSWITCH_enuGetStatus(u32 Copy_u8Switch_ID, u8 *Add_pSwitchStatus);
void HSWITCH_vRunnable(void);


#endif     // SWITCH_SCHED_H