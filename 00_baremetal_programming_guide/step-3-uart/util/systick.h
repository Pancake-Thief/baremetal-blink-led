#ifndef _SYSTICK_H
#define _SYSTICK_H

#include <stdint.h>

#define SYSTICK ((systick_reg_map_t *) 0xE000E010)

extern volatile uint32_t s_ticks;

typedef volatile struct systick_reg_map_t
{
    uint32_t CTRL;
    uint32_t LOAD;
    uint32_t VAL;
    uint32_t CALIB;
} systick_reg_map_t;

void systick_init(uint32_t ticks);
void SYSTICK_HANDLER(void);

#endif