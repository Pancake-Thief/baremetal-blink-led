#include <stdint.h>
#include <stdbool.h>
#include "systick.h"
#include "gpio.h"
#include "rcc.h"

#define CPU_FREQ 16000000 //16 MHz

void delay_ms(uint32_t ms){
    uint32_t until = s_ticks + ms;
    while(s_ticks < until) (void) 0;
}

int main(){
    pin_t led = PIN('A', 5);
    gpio_set_mode(led.pin, GPIO_MODE_OUTPUT);

    systick_init(CPU_FREQ / 1000);
    uint32_t period = 500;
    static bool on = true;
    uint32_t timestamp = s_ticks;
    for(;;){
        uint32_t now = s_ticks;
        if((now - timestamp) > period){
            timestamp = now;
            gpio_write(led.pin, on);
            on = !on;
        }
    }
    return 0;
}

// Startup code
__attribute__((naked, noreturn)) void _reset(void) {
  // memset .bss to zero, and copy .data section to RAM region
  extern long _sbss, _ebss, _sdata, _edata, _sidata;
  for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;

  main();             // Call main()
  for (;;) (void) 0;  // Infinite loop in the case if main() returns
}

extern void _estack(void);  // Defined in link.ld

// 16 standard and 91 STM32-specific handlers
__attribute__((section(".vectors"))) void (*const tab[16 + 91])(void) = {
  _estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SYSTICK_HANDLER
  };