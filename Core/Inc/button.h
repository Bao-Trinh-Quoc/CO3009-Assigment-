/*
 * button.h
 *
 *  Created on: Nov 22, 2024
 *      Author: DELL
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdint.h>
#include "main.h"

#define BUTTON_NUMBER 4
#define BUTTON_PRESSED_DURATION 2000
#define BUTTON_HOLDING_DURATION 200
#define BUTTON_PRESSED GPIO_PIN_RESET
#define BUTTON_RELEASED GPIO_PIN_SET

void buttonReading(void);
unsigned char buttonPressed(uint8_t index);

#endif /* INC_BUTTON_H_ */
