/*
 * ryg-leds.h
 *
 *  Created on: Nov 21, 2024
 *      Author: DELL
 */

#ifndef INC_RYG_LEDS_H_
#define INC_RYG_LEDS_H_

#include "traffic.h"

void turnOffLed(uint8_t index);
void turnOnRed(uint8_t index);
void turnOnGreen(uint8_t index);
void turnOnYellow(uint8_t index);

#endif /* INC_RYG_LEDS_H_ */
