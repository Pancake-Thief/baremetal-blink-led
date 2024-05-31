#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>
#include <stdbool.h>

#define GPIOA ((gpio_reg_map_t *) 0x40020000)
#define PIN(portInp, pinInp) {.port = (portInp) - 'A', .pin = (pinInp)}
#define SET_BIT(bitPos) (1u << (bitPos))

enum { GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG };

typedef volatile struct gpio_reg_map_t
{
    uint32_t MODER;
    uint32_t OTYPER;
    uint32_t OSPEEDR;
    uint32_t PUPDR;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t LCKR;
    uint32_t AFRL;
    uint32_t AFRH;
} gpio_reg_map_t;

typedef struct pin_t{
    uint8_t port;
    uint8_t pin;
} pin_t;

void gpio_set_mode(uint8_t pin, uint8_t mode);
void gpio_write(uint8_t pin, bool val);

#endif