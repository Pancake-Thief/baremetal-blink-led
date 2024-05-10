/*
 * bits.h
 *
 *  Created on: May 9, 2024
 *      Author: samue
 */

#ifndef BITS_H_
#define BITS_H_

#define CLEAR_BIT32(des, bits, position) (des) &= ~(((uint32_t)(bits)) << (position))
#define SET_BIT32(des, bits, position) (des) |= ((uint32_t) (bits)) << (position)

#endif /* BITS_H_ */
