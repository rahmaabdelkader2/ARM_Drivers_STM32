#include "bit_math.h"
#include "stdtypes.h"
#include "RCC_interface.h"

#define PORTA_CRL *((u32*)0x40010800)
// #define PORTA_CRH *((u32*)0x40010804)
// #define PORTA_IDR *((u32*)0x40010808)
#define PORTA_ODR *((u32*)0x4001080C)


void main(){

        RCC_voidInitSysClock();
        /*enable perihpheral 2 on APB2 bus (GPIOA)*/
        RCC_voidEnableClock(RCC_APB2,2);

        /*set pin 0 as output push pull*/
        PORTA_CRL = 0x00000002;
        
        /*set pin 0 to high*/
        PORTA_ODR = 0x00000001;



    while(1){
        
    }

}