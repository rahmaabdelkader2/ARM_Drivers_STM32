#include "stdtypes.h"
#include "bit_math.h"
#include "GPIO_interface.h"
#include "SYS_config.h"
#include "RCC_interface.h"
#include "RCC_config.h"
#include "SYS_config.h"
#include "SYS_interface.h"
#include "SCHED_config.h"
#include "SCHED.h"

// Define GPIO Port and Pins for LED Tasks

#define TASK1_PORT   GPIO_enuPORTA  // Modify as per hardware (e.g., GPIOA = 0)
#define TASK1_PIN    0  // Example: GPIOA, PIN0
#define TASK2_PORT   GPIO_enuPORTA  // Modify as per hardware (e.g., GPIOA = 0)
#define TASK2_PIN    1  // Example: GPIOA, PIN1

// // Function to toggle GPIO manually
void Toggle_Pin(u8 port, u8 pin) {
    u8 pin_state;
    Gpio_enuGetPinValue(port, pin, &pin_state);  // Read current value
    Gpio_enuSetPinValue(port, pin, !pin_state);  // Write opposite value
}

 // Test task functions
void Task1(void) {
     Toggle_Pin(TASK1_PORT, TASK1_PIN);
}

void Task2(void) {
    Toggle_Pin(TASK2_PORT, TASK2_PIN);
}

int main(void) {
    // Initialize GPIO
    RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_ID);
    
    Gpio_enuSetPinDirection(TASK1_PORT, TASK1_PIN, Gpio_enuOutput);
    Gpio_enuSetPinDirection(TASK2_PORT, TASK2_PIN, Gpio_enuOutput);

    Gpio_enuSetPinValue(TASK1_PORT, TASK1_PIN, 0);  // Start with LEDs OFF
    Gpio_enuSetPinValue(TASK2_PORT, TASK2_PIN, 0);

    // Initialize the scheduler
    SCHED_init();

    // Define runnable task configurations
    HSCHED_Runnable_config_t Task1_Config = {
        .callback_function = Task1,
        .cyclic_time = 500, // Runs every 500 scheduler ticks
        .first_delay = 0,
        .priority = 0
    };

    HSCHED_Runnable_config_t Task2_Config = {
        .callback_function = Task2,
        .cyclic_time = 5000, // Runs every 5000 scheduler ticks
        .first_delay = 0,
        .priority = 1
    };




    // Register tasks
    SCHED_registerRunnable(&Task1_Config);
    SCHED_registerRunnable(&Task2_Config);

    // Start the scheduler
        SCHED_start();

    // Main loop (SysTick interrupt triggers tasks)
    while (1){
       
    }

    return 0;
}


