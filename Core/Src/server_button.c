/*
 * server_button.c
 *
 *  Created on: Nov 29, 2024
 *      Author: DELL
 */

#include "server_button.h"

static GPIO_TypeDef* sv_buttonPorts[SERVER_BUTTON_NUMBER] = {SERVER_BUTTON0_GPIO_Port, SERVER_BUTTON1_GPIO_Port, SERVER_BUTTON2_GPIO_Port, SERVER_BUTTON3_GPIO_Port};
static uint16_t sv_buttonPins[SERVER_BUTTON_NUMBER] = {SERVER_BUTTON0_Pin, SERVER_BUTTON1_Pin, SERVER_BUTTON2_Pin, SERVER_BUTTON3_Pin};

static uint8_t sv_button_flags[SERVER_BUTTON_NUMBER] = {0};
static uint8_t sv_button_previous_states[SERVER_BUTTON_NUMBER] = {0};

void server_button_reading() {
	for (uint8_t i = 0; i < SERVER_BUTTON_NUMBER; i++) {
		uint8_t current_state = HAL_GPIO_ReadPin(sv_buttonPorts[i], sv_buttonPins[i]);

		if (current_state && (sv_button_previous_states[i] == 0)) {
			// Detect transition from OFF to ON
			sv_button_flags[i] = 1;
		}

		// Update the previous state
		sv_button_previous_states[i] = current_state;
	}
}

unsigned char server_button_pressed(uint8_t index) {
	if (index < 0 || index >= SERVER_BUTTON_NUMBER) return 0;
	if (sv_button_flags[index] == 1) {
		sv_button_flags[index] = 0;
		return 1;
	}
	return 0;
}
