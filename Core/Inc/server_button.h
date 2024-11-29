/*
 * server_button.h
 *
 *  Created on: Nov 29, 2024
 *      Author: DELL
 */

#ifndef INC_SERVER_BUTTON_H_
#define INC_SERVER_BUTTON_H_

#include "main.h"

#define SERVER_BUTTON_NUMBER 4


void server_button_reading();
unsigned char server_button_pressed(uint8_t index);

#endif /* INC_SERVER_BUTTON_H_ */
