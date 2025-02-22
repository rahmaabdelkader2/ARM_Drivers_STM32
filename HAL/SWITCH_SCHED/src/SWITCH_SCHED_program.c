#include  "bit_math.h"
#include  "stdtypes.h"
#include  "SWITCH_SCHED.h"
#include  "SWITCH_SCHED_config.h"
#include  "GPIO_interface.h"
#include  "SCHED.h"

/* Switch pin configuration array */
const HSWITCH_struct_Config_t HSWITCH_strPinConfigArray[NUM_OF_SWITCHES] = {
    {GPIO_enuPORTA, GPIO_PIN_0, Gpio_enuPullUp},  /* Start switch */
    {GPIO_enuPORTA, GPIO_PIN_1, Gpio_enuPullUp},  /* Stop switch */
    {GPIO_enuPORTA, GPIO_PIN_2, Gpio_enuPullUp}   /* Alert switch */
};

static volatile u8 HSWITCH_Status[NUM_OF_SWITCHES] = {0};


void HSWITCH_vInit(void)
{
    for (u8 i = 0; i < NUM_OF_SWITCHES; i++)
    {
        Gpio_enuSetPinDirection(HSWITCH_strPinConfigArray[i].HSWITCH_Port_Number,
                                HSWITCH_strPinConfigArray[i].HSWITCH_Pin_Number,
                                Gpio_enuInput);

        Gpio_enuSetPinPullType(HSWITCH_strPinConfigArray[i].HSWITCH_Port_Number,
                                 HSWITCH_strPinConfigArray[i].HSWITCH_Pin_Number,
                                 HSWITCH_strPinConfigArray[i].HSWITCH_Pull_State);
    }

    static HSCHED_Runnable_config_t switchTask = {
        .priority = 1,
        .cyclic_time = 10,
        .callback_function = HSWITCH_vRunnable,
        .first_delay = 0
    };

    SCHED_registerRunnable(&switchTask);
}

HSWITCH_enumErrorState_t HSWITCH_enuGetStatus(u32 Copy_u8Switch_ID, u8 *Add_pSwitchStatus)
{
    HSWITCH_enumErrorState_t Local_enuErrorState = HSWITCH_OK;

    if (Copy_u8Switch_ID >= NUM_OF_SWITCHES)
    {
        Local_enuErrorState = HSWITCH_InvalidSwitch;
    }
    else if (Add_pSwitchStatus == NULL)
    {
        Local_enuErrorState = HSWITCH_NullPtr;
    }
    else
    {
        *Add_pSwitchStatus = HSWITCH_Status[Copy_u8Switch_ID];
    }

    return Local_enuErrorState;
}

void HSWITCH_vRunnable(void)
{
    u8 switchValue = 0;

    for (u8 i = 0; i < NUM_OF_SWITCHES; i++)
    {
        Gpio_enuGetPinValue(HSWITCH_strPinConfigArray[i].HSWITCH_Port_Number,
                            HSWITCH_strPinConfigArray[i].HSWITCH_Pin_Number,
                            &switchValue);

        if (switchValue == SWITCH_PRESSED)
        {
            HSWITCH_Status[i] = SWITCH_PRESSED;
        }
        else
        {
            HSWITCH_Status[i] = SWITCH_RELEASED;
        }
    }
}
