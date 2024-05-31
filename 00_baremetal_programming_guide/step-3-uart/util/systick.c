#include "gpio.h"
#include "rcc.h"
#include "systick.h"
#include <stdint.h>

volatile uint32_t s_ticks;

void systick_init(uint32_t ticks){
    if ((ticks - 1) > 0xFFFFFF) return;
    SYSTICK->LOAD = ticks - 1;
    SYSTICK->VAL = 0;
    SYSTICK->CTRL = SET_BIT(0u) | SET_BIT(1u) | SET_BIT(2u);
    RCC->APB2ENR |= SET_BIT(14u);
}

void SYSTICK_HANDLER(void){
    s_ticks++;
}