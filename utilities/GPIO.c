/*
 * GPIO.c
 *
 *  Created on: May 9, 2024
 *      Author: samue
 */

#include "GPIO.h"
#include "bits.h"

void configGPIO(uint32_t* gpioX, uint8_t pinNum, gpio_config_t* gpio_config){
	if(gpioX == NULL || gpio_config == NULL){
		printf("Error: Invalid GPIO port or GPIO config\n");
		return;
	}

	CLEAR_BIT32(*(gpioX + GPIO_MODER), 0b11, pinNum * 2);
	SET_BIT32(*(gpioX + GPIO_MODER), gpio_config->moder, pinNum * 2);

	CLEAR_BIT32(*(gpioX + GPIO_OTYPER), 0b1, pinNum);
	SET_BIT32(*(gpioX + GPIO_OTYPER), gpio_config->otyper, pinNum);

	CLEAR_BIT32(*(gpioX + GPIO_OSPEEDR), 0b11, pinNum * 2);
	SET_BIT32(*(gpioX + GPIO_OSPEEDR), gpio_config->ospeeder, pinNum * 2);

	CLEAR_BIT32(*(gpioX + GPIO_PUPDR), 0b11, pinNum * 2);
	SET_BIT32(*(gpioX + GPIO_PUPDR), gpio_config->pupdr, pinNum * 2);
	return;
}
