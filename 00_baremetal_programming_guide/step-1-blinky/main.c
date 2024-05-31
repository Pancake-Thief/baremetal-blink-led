//Steps
//Activate clock for th GPIO port A
//???
#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "rcc.h"

void spin(volatile uint32_t count) {
    while(count--) (void) 0;
}

int main(){
    pin_t led = PIN('A', 5);
    RCC->AHB1ENR |= SET_BIT(led.port);
    gpio_set_mode(led.pin, GPIO_MODE_OUTPUT);
    for(;;){
        gpio_write(led.pin, true);
        spin(999999);
        gpio_write(led.pin, false);
        spin(999999);
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
  _estack, _reset
};