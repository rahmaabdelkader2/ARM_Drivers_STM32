#include "stdtypes.h"
#include "bit_math.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "HLED_Interface.h"
#include "HLED_Config.h"

extern HLED_t HLED_arrLEDs[LED_COUNT];

void HLED_voidInit(void){
    u8 Local_u8Counter = 0;
    for(Local_u8Counter = 0; Local_u8Counter < LED_COUNT; Local_u8Counter++){
        Gpio_enuSetPinDirection(HLED_arrLEDs[Local_u8Counter].LED_PORT, HLED_arrLEDs[Local_u8Counter].LED_PIN, Gpio_enuOutput);
    }
}

HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedNum, u8 Copy_u8State){
    HLED_enuErrorStatus_t Local_enuErrorStatus = HLED_OK;
    if(Copy_u8LedNum >= LED_COUNT){
        Local_enuErrorStatus = HLED_ERROR;
    }
    else if(Copy_u8State > 1){
        Local_enuErrorStatus = HLED_INVALID_LED_STATE;
    }
    else{
        Gpio_enuSetPinValue(HLED_arrLEDs[Copy_u8LedNum].LED_PORT, HLED_arrLEDs[Copy_u8LedNum].LED_PIN, Copy_u8State);
    }
    return Local_enuErrorStatus;
}