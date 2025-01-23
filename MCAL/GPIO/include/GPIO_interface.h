#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H



typedef enum
{
    Gpio_enuOK = 0,
    Gpio_enuPortError,
    Gpio_enuPinNumberError,
    Gpio_enuPinValueError,
    Gpio_enuPinDirectionError
}Gpio_tenuErrorStatus;

typedef enum
{
    Gpio_enuInput = 0,
    Gpio_enuOutput,
    Gpio_enuAF,
    Gpio_enuAnalog
    
}Gpio_enuDirection;

typedef enum
{
    Gpio_enuPushPull = 0,
    Gpio_enuOpenDrain
}Gpio_PinOutputType;

typedef enum
{
    Gpio_enuLowSpeed = 0,
    Gpio_enuMediumSpeed,
    Gpio_enuHighSpeed,
    Gpio_enuVeryHighSpeed
}Gpio_enuSpeed;

typedef enum
{
    Gpio_enuNoPull = 0,
    Gpio_enuPullUp,
    Gpio_enuPullDown
}Gpio_PinInputType;


Gpio_tenuErrorStatus Gpio_enuSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_enuDirection Copy_enuDirection);
Gpio_tenuErrorStatus Gpio_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
Gpio_tenuErrorStatus Gpio_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);
Gpio_tenuErrorStatus Gpio_enuSetPinSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_enuSpeed Copy_enuSpeed);
Gpio_tenuErrorStatus Gpio_enuSetPinPullType(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_PinInputType Copy_enuPullType);
Gpio_tenuErrorStatus Gpio_enuSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, Gpio_PinOutputType Copy_enuOutputType);

#endif    