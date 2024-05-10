/*
 * main.c
 *
 *  Created on: Apr 17, 2024
 *      Author: samue
 */

//LED is connected to PA5 or PB13 unsure
// I believe that means its at Port A pin 5 or Port B pin 13
// Need to set GPIO Moder to Output
//has 4 32 bit mapped
// 128 bits controls 16 I/Os each IO gets 8 bits for config
// 2 bits for MODER
// 1 bit reserved under OTYPER
// 1 bit for OTYPER
// 2 bit for OSPEEDR
// 2 bits for PUPDR

//GPIOx_IDR read only/input data register
//GPIOx_IDR output data register read and write
//For atomic bit set/reset, the ODR bits can be individually set and reset by writing to the GPIOx_BSRR register
//GPIOx_BSRR bit set/reset register


#include "GPIO.h"

int main()
{
	//Init section
	volatile uint32_t* gpioA = GPIOA_ADDR;
	uint8_t pinNum = 5;
	gpio_config_t gpioA_config;
	gpioA_config.moder = OUTPUT;
	gpioA_config.otyper = OUTPUT_PUSH_PULL;
	gpioA_config.ospeeder = LOW;
	gpioA_config.pupdr = PULL_UP;


	//Maybe make a struct and pass by value?
	configGPIO(gpioA, pinNum, gpioA_config);

}
