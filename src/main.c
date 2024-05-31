/*
 * main.c
 *
 *  Created on: Apr 17, 2024
 *      Author: samue
 */

//LED is connected to PA5 or PB13 unsure
// I believe that means its at Port A pin 5 or Port B pin 13
#include <stdint.h>
#include "GPIO.h"

__attribute__((naked, noreturn)) void _reset()
{
	//Init section
	uint32_t* gpioA = (uint32_t*) GPIOA_ADDR;
	uint8_t pinNum = 5;
	gpio_config_t gpioA_config;
	gpioA_config.moder = OUTPUT;
	gpioA_config.otyper = OUTPUT_PUSH_PULL;
	gpioA_config.ospeeder = LOW;
	gpioA_config.pupdr = PULL_UP;


	//Maybe make a struct and pass by value?
	configGPIO(gpioA, pinNum, &gpioA_config);

}
extern void _estack(void);  // Defined in link.ld

// 16 standard and 91 STM32-specific handlers
__attribute__((section(".vectors"))) void (*const tab[16 + 91])(void) = {
  _estack, _reset
};