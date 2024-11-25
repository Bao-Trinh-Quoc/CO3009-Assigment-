/*
 * fsm.h
 *
 *  Created on: Nov 25, 2024
 *      Author: DELL
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "button.h"
#include "counter.h"
#include "scheduler.h"
#include "test_module.h"
#include "traffic.h"
#include "i2c-lcd.h"

enum FSM_STATE {FSM_INIT, FSM_AUTO, FSM_MANUAL, FSM_TUNNING};
extern enum FSM_STATE fsmState;

void fsmInit(void);
void fsmProcessing(void);

#endif /* INC_FSM_H_ */
