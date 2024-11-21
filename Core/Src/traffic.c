/*
 * traffic.c
 *
 *  Created on: Nov 21, 2024
 *      Author: DELL
 */

uint32_t trafficRedDuration = 5000;
uint32_t trafficGreenDuration = 3000;
uint32_t trafficYellowDuration = 2000;
enum TRAFFIC_STATE trafficStates[TRAFFIC_NUMBER] = {};
uint32_t trafficCounters[TRAFFIC_NUMBER];

void trafficToggle(uint8_t index, enum TRAFFIC_STATE state) {
	switch (state) {
	case TRAFFIC_OFF:
		turnOffLed(index);
		trafficStates[index] = TRAFFIC_OFF;
		break;
	case TRAFFIC_RED:
		turnOnRed(index);
		trafficStates[index] = TRAFFIC_RED;
		if (fsmState == FSM_AUTO) {
			trafficCounters[index] = trafficRedDuration;
		}
		break;
	case TRAFFIC_GREEN:
		turnOnGreen(index);
		trafficStates[index] = TRAFFIC_GREEN;
		if (fsmState == FSM_AUTO) {
			trafficCounters[index] = trafficGreenDuration;
		}
		break;
	case TRAFFIC_YELLOW:
		turnOnYellow(index);
		trafficStates[index] = TRAFFIC_YELLOW;
		if (fsmState == FSM_AUTO) {
			trafficCounters[index] = trafficYellowDuration;
		}
		break;
	default:
		break;
	}
}

void traffic0Off(void) {
	trafficToggle(0, TRAFFIC_OFF);
}
void traffic0Red(void) {
	trafficToggle(0, TRAFFIC_RED);
}
void traffic0Green(void) {
	trafficToggle(0, TRAFFIC_GREEN);
}
void traffic0Yellow(void) {
	trafficToggle(0, TRAFFIC_YELLOW);
}

void traffic1Off(void) {
	trafficToggle(1, TRAFFIC_OFF);
}
void traffic1Red(void) {
	trafficToggle(1, TRAFFIC_RED);
}
void traffic1Green(void) {
	trafficToggle(1, TRAFFIC_GREEN);
}
void traffic1Yellow(void) {
	trafficToggle(1, TRAFFIC_YELLOW);
}
