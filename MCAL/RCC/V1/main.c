#include "bit_math.h"
#include "stdtypes.h"
#include "RCC_interface.h"

#define PORTA_CRL *((u32*)0x48000000)  // Adjusted base address for GPIOA
#define PORTA_ODR *((u32*)0x48000014)  // Adjusted address for GPIOA ODR

void main(){
        // Initialize the system clock
        RCC_voidInitSysClock();
        
        // Enable peripheral for GPIOA (Typically APB2 or APB1 depending on the board)
        RCC_voidEnableClock(RCC_APB2, 2);

        // Set pin 0 as output push-pull (This may vary for Black Bill)
        PORTA_CRL = 0x00000002;  // Adjust as needed based on the Black Bill's specific GPIO config
        
        // Set pin 0 to high
        PORTA_ODR = 0x00000001;

    while(1){
        // Infinite loop to keep the program running
    }
}
