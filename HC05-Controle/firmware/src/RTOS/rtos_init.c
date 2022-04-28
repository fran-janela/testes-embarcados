/*
 * rtos_init.c
 *
 * Created: 4/27/2022 2:48:20 PM
 *  Author: Francisco Janela
 */ 

#include "rtos_init.h"
#include "tasks.h"

/*************************************************************************/
/* RTOS application HOOK                                                 */
/*************************************************************************/

/* Called if stack overflow during execution */
void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName) {
	printf("stack overflow %x %s\r\n", pxTask, (portCHAR *)pcTaskName);
	/* If the parameters have been corrupted then inspect pxCurrentTCB to
	* identify which task has overflowed its stack.
	*/
	for (;;) {
	}
}

/* This function is called by FreeRTOS idle task */
void vApplicationIdleHook(void) {
	pmc_sleep(SAM_PM_SMODE_SLEEP_WFI);
}

/* This function is called by FreeRTOS each tick */
void vApplicationTickHook(void) { }

void vApplicationMallocFailedHook(void) {
	/* Called if a call to pvPortMalloc() fails because there is insufficient
	free memory available in the FreeRTOS heap.  pvPortMalloc() is called
	internally by FreeRTOS API functions that create tasks, queues, software
	timers, and semaphores.  The size of the FreeRTOS heap is set by the
	configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */

	/* Force an assert. */
	configASSERT( ( volatile void * ) NULL );
}

/*************************************************************************/
/* RTOS application INIT                                                 */
/*************************************************************************/

void rtos_init(void){
	xQueueBTSendData = xQueueCreate(32, sizeof(BTData));
	if (xQueueBTSendData == NULL)
		printf("ERROR building xQueueBTSendData \n");
	
	xTaskCreate(task_bluetooth, "BLT", TASK_BLUETOOTH_STACK_SIZE, NULL,	TASK_BLUETOOTH_STACK_PRIORITY, NULL);
}