/*
 * counter.c
 *
 *  Created on: Nov 22, 2024
 *      Author: DELL
 */

#include "counter.h"

void counterRun(void) {
	if (trafficCounters[0] > TIMER_TICK) {
		trafficCounters[0] -= TIMER_TICK;
	}
	else {
		trafficCounters[0] = 0;
	}
	if (trafficCounters[1] > TIMER_TICK) {
		trafficCounters[1] -= TIMER_TICK;
	}
	else {
		trafficCounters[1] = 0;
	}
}

void counterReset(void) {
	trafficCounters[0] = 0;
	trafficCounters[1] = 0;
}
