/*
 * GPIO.h
 *
 *  Created on: Apr 22, 2024
 *      Author: samue
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

/////////////////////////////////////////////
/*  Definitions, Enumerations and Structs  */
/////////////////////////////////////////////

#define GPIOA_ADDR 0x4002000
#define GPIO_MODER GPIOA_ADDR
#define GPIO_OTYPER GPIO_ADDR + 0x04
#define GPIO_OSPEEDER GPIO_ADDR + 0x08
#define GPIO_PUPDR GPIOA_ADDR + 0x0C

typedef enum gpio_moder_e {
	INPUT = 0b00,
	OUTPUT = 0b01,
	ALT_FUNC = 0b10,
	ANALOG = 0b11
} gpio_moder_e;

typedef enum gpio_otyper_e {
	OUTPUT_PUSH_PULL = 0,
	OUTPUT_OPEN_DRAIN = 1
} gpio_otyper_e;

typedef enum gpio_ospeeder_e {
	LOW = 0b00,
	MEDIUM = 0b01,
	HIGH = 0b10,
	VERY_HIGH = 0b11
} gpio_ospeeder_e;

typedef enum gpio_pupdr_e {
	DISABLE = 0b00,
	PULL_UP = 0b01,
	PULL_DOWN = 0b10,
	RESERVED = 0b11
} gpio_pupdr_e;

typedef struct gpio_config_t{
	gpio_moder_e moder;
	gpio_otyper_e otyper;
	gpio_ospeeder_e ospeeder;
	gpio_pupdr_e pupdr;
} gpio_config_t;

/////////////////////////////////////////////
/*                Functions                */
/////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  @brief This function sets the given gpio port                                                        */
/* 		   and pin to the given gpio config settings.                                                    */
/*                                                                                                       */
/*  @param[in] uint16* gpioX: Address of port                                                            */
/*  @param[in] uint8_t pinNum: Pin number to be configured                                               */
/*  @param[in] gpio_config_t* gpio_config: The configuration that will be applied to given port and pin  */
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void configGPIO(uint16_t* gpioX, uint8_t pinNum, gpio_config_t* gpio_config);

#endif /* GPIO_H_ */
