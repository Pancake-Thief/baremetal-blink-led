#ifndef _UART_H
#define _UART_H

#include <stdint.h>

typedef volatile struct uart_reg_map_t{
    uint32_t SR; // Status register
    uint32_t DR; // Data Register
    uint32_t BRR; // Baud Rate Register
    uint32_t CR1; // Control Register 1
    uint32_t CR2; // Control Register 2
    uint32_t CR3; // Control Register 3
    uint32_t GTPR; // Guard time and prescaler register
} uart_reg_map_t;

#define UART ((uart_reg_map_t *) 0x40010000)

void init_uart(void);

#endif