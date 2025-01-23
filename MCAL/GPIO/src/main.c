#include "bit_math.h"
#include "stdtypes.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

int main(){
        // Initialize the system clock
        RCC_voidInitSysClock();
        
        // Enable peripheral for GPIOA using the defined RCC_GPIOA_ID (0 for GPIOA)
        RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);
 
        // Set pin 0 in GPIOA as output
        Gpio_enuSetPinDirection(GPIOA, GPIO_PIN_5, Gpio_enuOutput);
        
        Gpio_enuSetPinOutputType(GPIOA, GPIO_PIN_5, Gpio_enuPushPull);
        Gpio_enuSetPinSpeed(GPIOA, GPIO_PIN_5, Gpio_enuLowSpeed);
        Gpio_enuSetPinValue(GPIOA, GPIO_PIN_5, LOGIC_HIGH);
        


    while(1){
        // Infinite loop to keep the program running
    }
    return 0;
}
