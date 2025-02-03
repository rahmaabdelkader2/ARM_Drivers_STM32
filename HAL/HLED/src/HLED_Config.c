#include   "HLED_Config.h"
#include   "GPIO_interface.h"
#include   "GPIO_private.h"
#include   "HLED_Interface.h"


HLED_t HLED_arrLEDs[LED_COUNT] = {
    {GPIO_enuPORTA, GPIO_PIN_0, Gpio_enuPushPull},
    {GPIO_enuPORTA, GPIO_PIN_1, Gpio_enuPushPull},
    {GPIO_enuPORTA, GPIO_PIN_2, Gpio_enuPushPull},
    {GPIO_enuPORTA, GPIO_PIN_3, Gpio_enuPushPull},
    {GPIO_enuPORTA, GPIO_PIN_4, Gpio_enuPushPull},
    {GPIO_enuPORTA, GPIO_PIN_5, Gpio_enuPushPull},
    {GPIO_enuPORTA, GPIO_PIN_6, Gpio_enuPushPull},
    {GPIO_enuPORTA, GPIO_PIN_7, Gpio_enuPushPull}
};
