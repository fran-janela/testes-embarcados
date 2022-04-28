/*
 * interrupts.h
 *
 * Created: 4/27/2022 10:54:22 AM
 *  Author: franc
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <asf.h>
#include "conf_board.h"
#include <string.h>

#include "RTOS/rtos_init.h"

BTData btdata;

/*************************************************************************/
/* prototypes                                                            */
/*************************************************************************/
void power_but_callback(void);
void upvel_but_callback(void);
void downvel_but_callback(void);



#endif /* INTERRUPTS_H_ */