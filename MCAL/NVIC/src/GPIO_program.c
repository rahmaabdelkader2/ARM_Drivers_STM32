#include "stdtypes.h"
#include "bit_math.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


Gpio_tenuErrorStatus Gpio_enuSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_enuDirection Copy_enuDirection){
    Gpio_tenuErrorStatus Local_enuErrorStatus = Gpio_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = Gpio_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = Gpio_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuDirection == Gpio_enuInput){
                    CLEAR_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuOutput){
                    SET_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAF){
                    CLEAR_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAnalog){
                    SET_BIT(GPIOA_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 1:
                if(Copy_enuDirection == Gpio_enuInput){
                    CLEAR_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuOutput){
                    SET_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAF){
                    CLEAR_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAnalog){
                    SET_BIT(GPIOB_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 2:
                if(Copy_enuDirection == Gpio_enuInput){
                    CLEAR_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuOutput){
                    SET_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAF){
                    CLEAR_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAnalog){
                    SET_BIT(GPIOC_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 3:
                if(Copy_enuDirection == Gpio_enuInput){
                    CLEAR_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuOutput){
                    SET_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAF){
                    CLEAR_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAnalog){
                    SET_BIT(GPIOD_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 4:
                if(Copy_enuDirection == Gpio_enuInput){
                    CLEAR_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuOutput){
                    SET_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAF){
                    CLEAR_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAnalog){
                    SET_BIT(GPIOE_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 5:
                if(Copy_enuDirection == Gpio_enuInput){
                    CLEAR_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuOutput){
                    SET_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAF){
                    CLEAR_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuDirection == Gpio_enuAnalog){
                    SET_BIT(GPIOH_MODER, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_MODER, (Copy_u8Pin * 2) + 1);
                }
                break;

        }


}
return Local_enuErrorStatus;
}

Gpio_tenuErrorStatus Gpio_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
    Gpio_tenuErrorStatus Local_enuErrorStatus = Gpio_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = Gpio_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = Gpio_enuPinNumberError;
    }
    else if(Copy_u8Value > 1){
        Local_enuErrorStatus = Gpio_enuPinValueError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_u8Value == 0){
                    CLEAR_BIT(GPIOA_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOA_ODR, Copy_u8Pin);
                }
                break;
            case 1:
                if(Copy_u8Value == 0){
                    CLEAR_BIT(GPIOB_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOB_ODR, Copy_u8Pin);
                }
                break;
            case 2:
                if(Copy_u8Value == 0){
                    CLEAR_BIT(GPIOC_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOC_ODR, Copy_u8Pin);
                }
                break;
            case 3:
                if(Copy_u8Value == 0){
                    CLEAR_BIT(GPIOD_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOD_ODR, Copy_u8Pin);
                }
                break;
            case 4:
                if(Copy_u8Value == 0){
                    CLEAR_BIT(GPIOE_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOE_ODR, Copy_u8Pin);
                }
                break;
            case 5:
                if(Copy_u8Value == 0){
                    CLEAR_BIT(GPIOH_ODR, Copy_u8Pin);
                }
                else{
                    SET_BIT(GPIOH_ODR, Copy_u8Pin);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}

Gpio_tenuErrorStatus Gpio_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value){
    Gpio_tenuErrorStatus Local_enuErrorStatus = Gpio_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = Gpio_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = Gpio_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                *Copy_pu8Value = GET_BIT(GPIOA_IDR, Copy_u8Pin);
                break;
            case 1:
                *Copy_pu8Value = GET_BIT(GPIOB_IDR, Copy_u8Pin);
                break;
            case 2:
                *Copy_pu8Value = GET_BIT(GPIOC_IDR, Copy_u8Pin);
                break;
            case 3:
                *Copy_pu8Value = GET_BIT(GPIOD_IDR, Copy_u8Pin);
                break;
            case 4:
                *Copy_pu8Value = GET_BIT(GPIOE_IDR, Copy_u8Pin);
                break;
            case 5:
                *Copy_pu8Value = GET_BIT(GPIOH_IDR, Copy_u8Pin);
                break;
        }
    }
    return Local_enuErrorStatus;
}

Gpio_tenuErrorStatus Gpio_enuSetPinSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_enuSpeed Copy_enuSpeed){
    Gpio_tenuErrorStatus Local_enuErrorStatus = Gpio_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = Gpio_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = Gpio_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuSpeed == Gpio_enuLowSpeed){
                    CLEAR_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuMediumSpeed){
                    SET_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuHighSpeed){
                    CLEAR_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuVeryHighSpeed){
                    SET_BIT(GPIOA_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 1:
                if(Copy_enuSpeed == Gpio_enuLowSpeed){
                    CLEAR_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuMediumSpeed){
                    SET_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuHighSpeed){
                    CLEAR_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuVeryHighSpeed){
                    SET_BIT(GPIOB_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 2:
                if(Copy_enuSpeed == Gpio_enuLowSpeed){
                    CLEAR_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuMediumSpeed){
                    SET_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuHighSpeed){
                    CLEAR_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuVeryHighSpeed){
                    SET_BIT(GPIOC_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 3:
                if(Copy_enuSpeed == Gpio_enuLowSpeed){
                    CLEAR_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuMediumSpeed){
                    SET_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuHighSpeed){
                    CLEAR_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuVeryHighSpeed){
                    SET_BIT(GPIOD_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 4:
                if(Copy_enuSpeed == Gpio_enuLowSpeed){
                    CLEAR_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuMediumSpeed){
                    SET_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuHighSpeed){
                    CLEAR_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuVeryHighSpeed){
                    SET_BIT(GPIOE_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 5:
                if(Copy_enuSpeed == Gpio_enuLowSpeed){
                    CLEAR_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuMediumSpeed){
                    SET_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuHighSpeed){
                    CLEAR_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuSpeed == Gpio_enuVeryHighSpeed){
                    SET_BIT(GPIOH_OSPEEDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_OSPEEDR, (Copy_u8Pin * 2) + 1);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}

Gpio_tenuErrorStatus Gpio_enuSetPinPullType(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_PinInputType Copy_enuPullType){
    Gpio_tenuErrorStatus Local_enuErrorStatus = Gpio_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = Gpio_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = Gpio_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuPullType == Gpio_enuNoPull){
                    CLEAR_BIT(GPIOA_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOA_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullUp){
                    SET_BIT(GPIOA_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOA_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullDown){
                    CLEAR_BIT(GPIOA_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOA_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 1:
                if(Copy_enuPullType == Gpio_enuNoPull){
                    CLEAR_BIT(GPIOB_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOB_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullUp){
                    SET_BIT(GPIOB_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOB_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullDown){
                    CLEAR_BIT(GPIOB_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOB_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 2:
                if(Copy_enuPullType == Gpio_enuNoPull){
                    CLEAR_BIT(GPIOC_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOC_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullUp){
                    SET_BIT(GPIOC_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOC_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullDown){
                    CLEAR_BIT(GPIOC_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOC_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 3:
                if(Copy_enuPullType == Gpio_enuNoPull){
                    CLEAR_BIT(GPIOD_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOD_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullUp){
                    SET_BIT(GPIOD_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOD_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullDown){
                    CLEAR_BIT(GPIOD_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOD_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 4:
                if(Copy_enuPullType == Gpio_enuNoPull){
                    CLEAR_BIT(GPIOE_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOE_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullUp){
                    SET_BIT(GPIOE_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOE_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullDown){
                    CLEAR_BIT(GPIOE_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOE_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
            case 5:
                if(Copy_enuPullType == Gpio_enuNoPull){
                    CLEAR_BIT(GPIOH_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOH_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullUp){
                    SET_BIT(GPIOH_PUPDR, Copy_u8Pin * 2);
                    CLEAR_BIT(GPIOH_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                else if(Copy_enuPullType == Gpio_enuPullDown){
                    CLEAR_BIT(GPIOH_PUPDR, Copy_u8Pin * 2);
                    SET_BIT(GPIOH_PUPDR, (Copy_u8Pin * 2) + 1);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}

Gpio_tenuErrorStatus Gpio_enuSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_PinOutputType Copy_enuOutputType){
    Gpio_tenuErrorStatus Local_enuErrorStatus = Gpio_enuOK;
    if(Copy_u8Port > 5){
        Local_enuErrorStatus = Gpio_enuPortError;
    }
    else if(Copy_u8Pin > 15){
        Local_enuErrorStatus = Gpio_enuPinNumberError;
    }
    else{
        switch(Copy_u8Port){
            case 0:
                if(Copy_enuOutputType == Gpio_enuPushPull){
                    CLEAR_BIT(GPIOA_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == Gpio_enuOpenDrain){
                    SET_BIT(GPIOA_OTYPER, Copy_u8Pin);
                }
                break;
            case 1:
                if(Copy_enuOutputType == Gpio_enuPushPull){
                    CLEAR_BIT(GPIOB_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == Gpio_enuOpenDrain){
                    SET_BIT(GPIOB_OTYPER, Copy_u8Pin);
                }
                break;
            case 2:
                if(Copy_enuOutputType == Gpio_enuPushPull){
                    CLEAR_BIT(GPIOC_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == Gpio_enuOpenDrain){
                    SET_BIT(GPIOC_OTYPER, Copy_u8Pin);
                }
                break;
            case 3:
                if(Copy_enuOutputType == Gpio_enuPushPull){
                    CLEAR_BIT(GPIOD_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == Gpio_enuOpenDrain){
                    SET_BIT(GPIOD_OTYPER, Copy_u8Pin);
                }
                break;
            case 4:
                if(Copy_enuOutputType == Gpio_enuPushPull){
                    CLEAR_BIT(GPIOE_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == Gpio_enuOpenDrain){
                    SET_BIT(GPIOE_OTYPER, Copy_u8Pin);
                }
                break;
            case 5:
                if(Copy_enuOutputType == Gpio_enuPushPull){
                    CLEAR_BIT(GPIOH_OTYPER, Copy_u8Pin);
                }
                else if(Copy_enuOutputType == Gpio_enuOpenDrain){
                    SET_BIT(GPIOH_OTYPER, Copy_u8Pin);
                }
                break;
        }
    }
    return Local_enuErrorStatus;
}
