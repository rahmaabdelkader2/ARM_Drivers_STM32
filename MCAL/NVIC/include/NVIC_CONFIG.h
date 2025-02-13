#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

#define VECTKEY (0x5FA << 16) // Required VECTKEY value

#define PRIGROUP_MASK (0x7 << 8) // Mask for priority grouping (bits [10:8])

#define SYSRESETREQ (1 << 2) // System Reset Request bit

#define VECTRESET (1 << 0) // Bit 0 triggers vector table reset

#endif
