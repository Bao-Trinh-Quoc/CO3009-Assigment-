/*
 * fsm.c
 *
 *  Created on: Nov 25, 2024
 *      Author: DELL
 */

#include "fsm.h"

#define FSM_TASK 1
#define FSM_AUTO_TASK 11
#define FSM_MANUAL_TASK 3
#define FSM_TUNNING_TASK 5

enum FSM_STATE fsmState;
static enum TRAFFIC_STATE fsmTunningState;

static uint8_t fsmIDs[FSM_TASK] = {};
static uint8_t fsmAutoIDs[FSM_AUTO_TASK] = {};
static uint8_t fsmManualIDs[FSM_MANUAL_TASK] = {};
static uint8_t fsmTunningIDs[FSM_TUNNING_TASK] = {};

void fsmAutoStop(void) {
	SCH_AddTask(counterReset, 0, 0);
}

/*
 * For pedestrian mode if needed
 * */
void fsmAutoProcessing(void) {
	return;
}

void fsmAuto(void) {
	fsmAutoIDs[0] = SCH_AddTask(fsmAutoProcessing, 10, TIMER_TICK);
	fsmAutoIDs[1] = SCH_AddTask(counterRun, 0, TIMER_TICK);
	fsmAutoIDs[2] = SCH_AddTask(lcd_counter(), 50, 1000);
	fsmAutoIDs[3] = SCH_AddTask(traffic0Red, 0, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[4] = SCH_AddTask(traffic0Green, trafficRedDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[5] = SCH_AddTask(traffic0Yellow, trafficRedDuration + trafficGreenDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[6] = SCH_AddTask(traffic1Green, 0, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[7] = SCH_AddTask(traffic1Yellow, trafficGreenDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
	fsmAutoIDs[8] = SCH_AddTask(traffic1Red, trafficGreenDuration + trafficYellowDuration, trafficRedDuration + trafficYellowDuration + trafficGreenDuration);
}

void fsmManualStop(void) {
	SCH_AddTask(traffic0Off, 0, 0);
	SCH_AddTask(traffic1Off, 0, 0);
}

void fsmManualProcessing(void) {
	if (buttonPressed(1)) {
		switch (trafficStates[0]) {
		case TRAFFIC_RED:
			SCH_AddTask(traffic0Green, 0, 0);
			break;
		case TRAFFIC_GREEN:
			SCH_AddTask(traffic0Yellow, 0, 0);
			break;
		case TRAFFIC_YELLOW:
			SCH_AddTask(traffic0Red, 0, 0);
			break;
		default:
			break;
		}
	}
	if (buttonPressed(2)) {
		switch (trafficStates[1]) {
		case TRAFFIC_RED:
			SCH_AddTask(traffic1Green, 0, 0);
			break;
		case TRAFFIC_GREEN:
			SCH_AddTask(traffic1Yellow, 0, 0);
			break;
		case TRAFFIC_YELLOW:
			SCH_AddTask(traffic1Red, 0, 0);
			break;
		default:
			break;
		}
	}
}

void fsmManual(void) {
	fsmManualIDs[0] = SCH_AddTask(fsmManualProcessing, 10, TIMER_TICK);
	// Initialize for Manual Mode
	SCH_AddTask(traffic0Red, 0, 0);
	SCH_AddTask(traffic1Green, 0, 0);
}

void fsmTunningStop(void) {
	return;
}

void fsmTunningProcessing(void) {
	if (buttonPressed(1)) {
			SCH_DeleteTask(fsmTunningIDs[1]);
			SCH_DeleteTask(fsmTunningIDs[2]);
			SCH_DeleteTask(fsmTunningIDs[3]);
			SCH_DeleteTask(fsmTunningIDs[4]);
			switch (fsmTunningState) {
				case TRAFFIC_RED:
					SCH_AddTask(lcd_red_duration, 0, 0);
					fsmTunningIDs[1] = SCH_AddTask(traffic0Green, 0, 1000);
					fsmTunningIDs[2] = SCH_AddTask(traffic1Green, 0, 1000);
					fsmTunningIDs[3] = SCH_AddTask(traffic0Off, 500, 1000);
					fsmTunningIDs[4] = SCH_AddTask(traffic1Off, 500, 1000);
					fsmTunningState = TRAFFIC_GREEN;
					break;
				case TRAFFIC_GREEN:
					SCH_AddTask(lcd_green_duration, 0, 0);
					fsmTunningIDs[1] = SCH_AddTask(traffic0Yellow, 0, 1000);
					fsmTunningIDs[2] = SCH_AddTask(traffic1Yellow, 0, 1000);
					fsmTunningIDs[3] = SCH_AddTask(traffic0Off, 500, 1000);
					fsmTunningIDs[4] = SCH_AddTask(traffic1Off, 500, 1000);
					fsmTunningState = TRAFFIC_YELLOW;
					break;
				case TRAFFIC_YELLOW:
					SCH_AddTask(lcd_yellow_duration, 0, 0);
					fsmTunningIDs[1] = SCH_AddTask(traffic0Red, 0, 1000);
					fsmTunningIDs[2] = SCH_AddTask(traffic1Red, 0, 1000);
					fsmTunningIDs[3] = SCH_AddTask(traffic0Off, 500, 1000);
					fsmTunningIDs[4] = SCH_AddTask(traffic1Off, 500, 1000);
					fsmTunningState = TRAFFIC_RED;
					break;
				default:
					break;
			}
		}


}
