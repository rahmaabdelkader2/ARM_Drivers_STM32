#include "stdtypes.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "HLED_Interface.h"

int main(void) {
    // Initialize the system clock
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);  // Enable GPIOA clock (Modify if needed)

    // Initialize the LED driver
    HLED_voidInit();

    
    HLED_enuSetLedState(LED_0, HLED_LED_ON);

    while (1) {
        // Keep running indefinitely
    }

    return 0;
}
