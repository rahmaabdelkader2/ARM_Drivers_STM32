#include "stdtypes.h"
#include "bit_math.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "RCC_config.h"
#include "SYS_interface.h"
#include "SCHED_config.h"
#include "SCHED.h"
#include "SWITCH_SCHED.h"

#define LED_PORT   GPIO_enuPORTA  // Define LED Port (GPIOB)
#define LED_PIN    GPIO_PIN_7     // Define LED Pin (Pin 5)

int main(void)
{
    /* Initialize System Clock */
    RCC_voidInitSysClock();

    /* Enable GPIO Peripheral Clocks */
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);  // Enable GPIOA (Switches)
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOB_ID);  // Enable GPIOB (LED)



    /* Configure LED Pin as Output */
    Gpio_enuSetPinDirection(LED_PORT, LED_PIN, Gpio_enuOutput);
    Gpio_enuSetPinValue(LED_PORT, LED_PIN, 0);  // Turn off LED initially

    /* Initialize Switch Handling */
    HSWITCH_vInit();

    /* Initialize Scheduler */
    SCHED_init();

    while (1)
    {
        u8 switch_status = 0;
        
        /* Check switch status */
        HSWITCH_enuGetStatus(0, &switch_status);  // Assuming Switch 0 controls LED

        /* If switch is pressed, turn on LED */
        if (switch_status == SWITCH_PRESSED)
        {
            Gpio_enuSetPinValue(LED_PORT, LED_PIN, 1);
        }
        else
        {
            Gpio_enuSetPinValue(LED_PORT, LED_PIN, 0);
        }
    }

    return 0;
}
