/*
 * tasks.h
 *
 * Created: 4/27/2022 2:46:24 PM
 *  Author: franc
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include <asf.h>
#include "conf_board.h"
#include <string.h>

#include "rtos_init.h"
#include "peripherals/init.h"
#include "functions.h"

void task_bluetooth(void);


#endif /* TASKS_H_ */