/*
 * traffic.h
 *
 *  Created on: Nov 21, 2024
 *      Author: DELL
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

#include <stdint.h>
#include "main.h"
#include "ryg-leds.h"
#include "fsm.h"

#define TRAFFIC_NUMBER 2
#define TRAFFIC_DURATION_MIN 1000
#define TRAFFIC_DURATION_MAX 20000
#define TRAFFIC_DURATION_AUTO 1000

enum TRAFFIC_STATE {TRAFFIC_OFF, TRAFFIC_RED, TRAFFIC_GREEN, TRAFFIC_YELLOW};

extern uint32_t trafficRedDuration;
extern uint32_t trafficGreenDuration;
extern uint32_t trafficYellowDuration;

extern enum TRAFFIC_STATE trafficStates[TRAFFIC_NUMBER];
extern uint32_t trafficCounters[TRAFFIC_NUMBER];

void traffic0Off(void);
void traffic0Red(void);
void traffic0Green(void);
void traffic0Yellow(void);

void traffic1Off(void);
void traffic1Red(void);
void traffic1Green(void);
void traffic1Yellow(void);

#endif /* INC_TRAFFIC_H_ */
