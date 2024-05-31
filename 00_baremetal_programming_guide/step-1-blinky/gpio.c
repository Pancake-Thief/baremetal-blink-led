#include "gpio.h"

void gpio_set_mode(uint8_t pin, uint8_t mode){
    gpio_reg_map_t* gpio = GPIOA;
    gpio->MODER &= ~(0b11u << (pin * 2u));
    gpio->MODER |= (mode & 0b11u) << (pin * 2);
}

void gpio_write(uint8_t pin, bool val){
    gpio_reg_map_t* gpio = GPIOA;
    gpio->BSRR &= ~(0b1u << pin) << (val ? 16 : 0);
    gpio->BSRR |= (0b1u << pin) << (val ? 0 : 16);
}