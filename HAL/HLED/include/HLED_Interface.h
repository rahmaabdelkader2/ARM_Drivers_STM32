#ifndef HLED_INTERFACE_H
#define HLED_INTERFACE_H

#include "stdtypes.h"

#define HLED_LED_ON  1  /* LED is turned ON */
#define HLED_LED_OFF 0  /* LED is turned OFF */

#define LED_COUNT 8

#define LED_0 0
#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5
#define LED_6 6
#define LED_7 7

typedef enum
{
    HLED_OK,
    HLED_ERROR,
    HLED_INVALID_LED_STATE
}HLED_enuErrorStatus_t;

void HLED_voidInit(void);
HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedNum, u8 Copy_u8State);


#endif