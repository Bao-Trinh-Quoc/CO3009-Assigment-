/*
 * test_module.c
 *
 *  Created on: Nov 22, 2024
 *      Author: DELL
 */
#include "test_module.h"

void testMCU(void) {
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void testButton(void) {
	// Add code to test here if needed
	if (buttonPressed(0) || buttonPressed(1) || buttonPressed(2) || buttonPressed(3)) {
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}
}
void testLED(void) {
	// Add code to test here if needed
	turnOnGreen(0);
	turnOnGreen(1);
	turnOnRed(0);
	turnOnRed(1);
	turnOnYellow(0);
	turnOnYellow(1);

}
