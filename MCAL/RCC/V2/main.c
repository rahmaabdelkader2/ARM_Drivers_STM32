#include "bit_math.h"
#include "stdtypes.h"
#include "RCC_interface.h"

#define PORTA_CRL *((u32*)0x48000000)  // Base address for GPIOA
#define PORTA_ODR *((u32*)0x48000014)  // Address for GPIOA ODR

void main(){
        // Initialize the system clock
        RCC_voidInitSysClock();
        
        // Enable peripheral for GPIOA using the defined RCC_GPIOA_ID (0 for GPIOA)
        RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);

        // Set pin 0 as output push-pull (This may vary for Black Bill)
        PORTA_CRL = 0x00000002;  // Adjust pin configuration based on your specific need
        
        // Set pin 0 to high
        PORTA_ODR = 0x00000001;

    while(1){
        // Infinite loop to keep the program running
    }
}
