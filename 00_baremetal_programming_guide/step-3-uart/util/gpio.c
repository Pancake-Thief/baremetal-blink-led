#include <stdio.h>
#include "gpio.h"
#include "rcc.h"

void gpio_set_mode(pin_t pin, uint8_t mode){
    gpio_reg_map_t* gpio = GPIO + (pin.port * 0x400);
    RCC->AHB1ENR |= SET_BIT(pin.port);
    gpio->MODER &= ~(0b11u << (pin.pin * 2u));
    gpio->MODER |= (mode & 0b11u) << (pin.pin * 2);
}

void gpio_write(pin_t pin, bool val){
    gpio_reg_map_t* gpio = GPIO + (pin.port * 0x400);
    gpio->BSRR &= ~(0b1u << pin.pin) << (val ? 16 : 0);
    gpio->BSRR |= (0b1u << pin.pin) << (val ? 0 : 16);
}

void gpio_set_af(pin_t pin, uint8_t mode){
    mode &= 0xFF;
    gpio_reg_map_t* gpio = GPIO + (pin.port * 0x400);
    uint32_t* temp = NULL;
    if(pin.pin > 7){
        pin.pin -= 7;
        temp = gpio->AFRH;
    } else {
        temp = gpio->AFRL;
    }
    *temp &= ~(0xFF << (pin.pin * 4));
    *temp |= (mode << (pin.pin * 4));
}