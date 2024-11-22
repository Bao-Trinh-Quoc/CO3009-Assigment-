/*
 * ryg-leds.c
 *
 *  Created on: Nov 21, 2024
 *      Author: DELL
 */

#include "ryg-leds.h"

/*
 * 11 == RED
 * 01 == YELLOW
 * 10 == GREEN
 * 00 == NONE
 * */

static GPIO_TypeDef* controlTraffic0Ports[TRAFFIC_NUMBER] = {CONTROL_TRAFFIC0_0_GPIO_Port, CONTROL_TRAFFIC1_0_GPIO_Port};
static uint16_t controlTraffic0Pins[TRAFFIC_NUMBER] = {CONTROL_TRAFFIC0_0_Pin, CONTROL_TRAFFIC1_0_Pin};

static GPIO_TypeDef* controlTraffic1Ports[TRAFFIC_NUMBER] = {CONTROL_TRAFFIC0_1_GPIO_Port, CONTROL_TRAFFIC1_1_GPIO_Port};
static uint16_t controlTraffic1Pins[TRAFFIC_NUMBER] = {CONTROL_TRAFFIC0_1_Pin, CONTROL_TRAFFIC1_1_Pin};

void turnOffLed(uint8_t index) {
	HAL_GPIO_WritePin(controlTraffic0Ports[index], controlTraffic0Pins[index], GPIO_PIN_RESET);
	HAL_GPIO_WritePin(controlTraffic1Ports[index], controlTraffic1Pins[index], GPIO_PIN_RESET);
}
void turnOnRed(uint8_t index) {
	HAL_GPIO_WritePin(controlTraffic0Ports[index], controlTraffic0Pins[index], GPIO_PIN_SET);
	HAL_GPIO_WritePin(controlTraffic1Ports[index], controlTraffic1Pins[index], GPIO_PIN_SET);
}
void turnOnGreen(uint8_t index) {
	HAL_GPIO_WritePin(controlTraffic0Ports[index], controlTraffic0Pins[index], GPIO_PIN_SET);
	HAL_GPIO_WritePin(controlTraffic1Ports[index], controlTraffic1Pins[index], GPIO_PIN_RESET);
}
void turnOnYellow(uint8_t index) {
	HAL_GPIO_WritePin(controlTraffic0Ports[index], controlTraffic0Pins[index], GPIO_PIN_RESET);
	HAL_GPIO_WritePin(controlTraffic1Ports[index], controlTraffic1Pins[index], GPIO_PIN_SET);
}
