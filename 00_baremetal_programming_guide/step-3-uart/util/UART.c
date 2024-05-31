#include "UART.h"
#include "gpio.h"
#include "rcc.h"

void init_uart(void){
    UART->CR1 |= SET_BIT(13);
    UART->CR1 &= CLEAR_BIT(12);
    UART->CR2 &= CLEAR_BIT(12) & CLEAR_BIT(13);
    UART->BRR = 0x3415; // Equivalent to 9600 Baud rate
    UART->CR1 |= SET_BIT(3);
    RCC->APB2ENR |= SET_BIT(4);
}