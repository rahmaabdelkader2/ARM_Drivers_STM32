#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

#include "stdtypes.h"


#define NVIC_BASE_ADDRESS 0xE000E100
#define NVIC  ((volatile NVIC_IRQ_REGISTERS*) NVIC_BASE_ADDRESS)

#define SCB_BASE_ADDRESS  0xE000ED00
#define SCB  ((volatile SCB_REGISTERS*) SCB_BASE_ADDRESS)
#define VECTKEY        (0x5FA << 16)  // Required VECTKEY value
#define PRIGROUP_MASK  (0x7 << 8)     // Mask for priority grouping (bits [10:8])
#define SYSRESETREQ    (1 << 2)       // System Reset Request bit
#define VECTRESET   (1 << 0)  // Bit 0 triggers vector table reset

// Define the SCB register structure
typedef struct {
    volatile u32 CPUID;   // Offset: 0x00
    volatile u32 ICSR;    // Offset: 0x04
    volatile u32 VTOR;    // Offset: 0x08
    volatile u32 AIRCR;   // Offset: 0x0C
    volatile u32 SCR;     // Offset: 0x10
    volatile u32 CCR;     // Offset: 0x14
    volatile u32 SHPR[3]; // Offset: 0x18 - 0x20
    volatile u32 SHCSR;   // Offset: 0x24
    volatile u32 CFSR;    // Offset: 0x28
    volatile u32 HFSR;    // Offset: 0x2C
    volatile u32 DFSR;    // Offset: 0x30
    volatile u32 MMFAR;   // Offset: 0x34
    volatile u32 BFAR;    // Offset: 0x38
    volatile u32 AFSR;    // Offset: 0x3C
} SCB_REGISTERS;

// Define the NVIC register structure
typedef struct {
    volatile u32 ISER[8];   // Interrupt Set Enable Registers (Offset: 0x000 - 0x01C)
    u32 RESERVED0[24];      // Reserved space
    volatile u32 ICER[8];   // Interrupt Clear Enable Registers (Offset: 0x080 - 0x09C)
    u32 RESERVED1[24];      // Reserved space
    volatile u32 ISPR[8];   // Interrupt Set Pending Registers (Offset: 0x100 - 0x11C)
    u32 RESERVED2[24];      // Reserved space
    volatile u32 ICPR[8];   // Interrupt Clear Pending Registers (Offset: 0x180 - 0x19C)
    u32 RESERVED3[24];      // Reserved space
    volatile u32 IABR[8];   // Interrupt Active Bit Registers (Offset: 0x200 - 0x21C)
    u32 RESERVED4[56];      // Reserved space
    volatile u32 IPR[240];   // Interrupt Priority Registers (Offset: 0x300 - 0x3EF)
    u32 RESERVED5[644];     // Reserved space
    volatile u32 STIR;      // Software Trigger Interrupt Register (Offset: 0xE00)
}NVIC_IRQ_REGISTERS;


#endif
