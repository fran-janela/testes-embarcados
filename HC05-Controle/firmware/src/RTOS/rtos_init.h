/*
 * rtos_init.h
 *
 * Created: 4/27/2022 2:48:05 PM
 *  Author: franc
 */ 


#ifndef RTOS_INIT_H_
#define RTOS_INIT_H_

#include <asf.h>
#include "conf_board.h"
#include <string.h>


#define TASK_BLUETOOTH_STACK_SIZE            (4096/sizeof(portSTACK_TYPE))
#define TASK_BLUETOOTH_STACK_PRIORITY        (tskIDLE_PRIORITY)

/*************************************************************************/
/* RTOS application RESOURCES                                            */
/*************************************************************************/

typedef struct{
	char id;
	uint32_t data;
} BTData;

QueueHandle_t xQueueBTSendData;


/*************************************************************************/
/* prototypes                                                            */
/*************************************************************************/
void rtos_init(void);
void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationMallocFailedHook(void);
void xPortSysTickHandler(void);

/*************************************************************************/
/* prototypes                                                            */
/*************************************************************************/


#endif /* RTOS_INIT_H_ */