#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIOA 0x40020000
#define GPIOB 0x40020400
#define GPIOC 0x40020800
#define GPIOD 0x40020C00
#define GPIOE 0x40021000
#define GPIOH 0x40021C00


#define GPIOA_MODER    *((volatile u32  *)(GPIOA + 0x00))  // PORT MODE REISTER
#define GPIOA_OTYPER   *((volatile u32  *)(GPIOA + 0x04))       
#define GPIOA_OSPEEDR  *((volatile u32  *)(GPIOA + 0x08))
#define GPIOA_PUPDR    *((volatile u32  *)(GPIOA + 0x0C))
#define GPIOA_IDR      *((volatile u32  *)(GPIOA + 0x10))
#define GPIOA_ODR      *((volatile u32  *)(GPIOA + 0x14))
#define GPIOA_BSRR     *((volatile u32  *)(GPIOA + 0x18))
#define GPIOA_LCKR     *((volatile u32  *)(GPIOA + 0x1C))
#define GPIOA_AFRL     *((volatile u32  *)(GPIOA + 0x20))


#define GPIOB_MODER    *((u32*)(GPIOB + 0x00))  // PORT MODE REISTER
#define GPIOB_OTYPER   *((u32*)(GPIOB + 0x04))
#define GPIOB_OSPEEDR  *((u32*)(GPIOB + 0x08))
#define GPIOB_PUPDR    *((u32*)(GPIOB + 0x0C))
#define GPIOB_IDR      *((u32*)(GPIOB + 0x10))
#define GPIOB_ODR      *((u32*)(GPIOB + 0x14))
#define GPIOB_BSRR     *((u32*)(GPIOB + 0x18))
#define GPIOB_LCKR     *((u32*)(GPIOB + 0x1C))
#define GPIOB_AFRH     *((u32*)(GPIOB + 0x24))

#define GPIOC_MODER    *((u32*)(GPIOC + 0x00))  // PORT MODE REISTER
#define GPIOC_OTYPER   *((u32*)(GPIOC + 0x04))
#define GPIOC_OSPEEDR  *((u32*)(GPIOC + 0x08))
#define GPIOC_PUPDR    *((u32*)(GPIOC + 0x0C))
#define GPIOC_IDR      *((u32*)(GPIOC + 0x10))
#define GPIOC_ODR      *((u32*)(GPIOC + 0x14))
#define GPIOC_BSRR     *((u32*)(GPIOC + 0x18))
#define GPIOC_LCKR     *((u32*)(GPIOC + 0x1C))
#define GPIOC_AFRH     *((u32*)(GPIOC + 0x24))

#define GPIOD_MODER    *((u32*)(GPIOD + 0x00))  // PORT MODE REISTER
#define GPIOD_OTYPER   *((u32*)(GPIOD + 0x04))
#define GPIOD_OSPEEDR  *((u32*)(GPIOD + 0x08))
#define GPIOD_PUPDR    *((u32*)(GPIOD + 0x0C))
#define GPIOD_IDR      *((u32*)(GPIOD + 0x10))
#define GPIOD_ODR      *((u32*)(GPIOD + 0x14))
#define GPIOD_BSRR     *((u32*)(GPIOD + 0x18))
#define GPIOD_LCKR     *((u32*)(GPIOD + 0x1C))
#define GPIOD_AFRH     *((u32*)(GPIOD + 0x24))

#define GPIOE_MODER    *((u32*)(GPIOE + 0x00))  // PORT MODE REISTER
#define GPIOE_OTYPER   *((u32*)(GPIOE + 0x04))
#define GPIOE_OSPEEDR  *((u32*)(GPIOE + 0x08))
#define GPIOE_PUPDR    *((u32*)(GPIOE + 0x0C))
#define GPIOE_IDR      *((u32*)(GPIOE + 0x10))
#define GPIOE_ODR      *((u32*)(GPIOE + 0x14))
#define GPIOE_BSRR     *((u32*)(GPIOE + 0x18))
#define GPIOE_LCKR     *((u32*)(GPIOE + 0x1C))
#define GPIOE_AFRH     *((u32*)(GPIOE + 0x24))

#define GPIOH_MODER    *((u32*)(GPIOH + 0x00))  // PORT MODE REISTER
#define GPIOH_OTYPER   *((u32*)(GPIOH + 0x04))
#define GPIOH_OSPEEDR  *((u32*)(GPIOH + 0x08))
#define GPIOH_PUPDR    *((u32*)(GPIOH + 0x0C))
#define GPIOH_IDR      *((u32*)(GPIOH + 0x10))
#define GPIOH_ODR      *((u32*)(GPIOH + 0x14))
#define GPIOH_BSRR     *((u32*)(GPIOH + 0x18))
#define GPIOH_LCKR     *((u32*)(GPIOH + 0x1C))
#define GPIOH_AFRH     *((u32*)(GPIOH + 0x24))



#define GPIO_PIN_0  0
#define GPIO_PIN_1  1
#define GPIO_PIN_2  2
#define GPIO_PIN_3  3
#define GPIO_PIN_4  4
#define GPIO_PIN_5  5
#define GPIO_PIN_6  6
#define GPIO_PIN_7  7
#define GPIO_PIN_8  8
#define GPIO_PIN_9  9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15



#endif