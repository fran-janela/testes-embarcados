/*
 * interrupts.c
 *
 * Created: 4/27/2022 10:54:14 AM
 *  Author: franc
 */ 


#include "interrupts.h"
#include "init.h"

/*************************************************************************/
/* BUTTONS interruptions                                                 */
/*************************************************************************/
void power_but_callback(void){
	if (!pio_get(POWER_BUT_PIO, PIO_INPUT, POWER_BUT_IDX_MASK)) {
		// PINO == 0 --> Borda de descida
		btdata.id = 'P';
		btdata.data = 1;
		xQueueSendFromISR(xQueueBTSendData, &btdata, 0);
	} else {
		// PINO == 1 --> Borda de subida
		btdata.id = 'P';
		btdata.data = 0;
		xQueueSendFromISR(xQueueBTSendData, &btdata, 0);
	}
}
void upvel_but_callback(void){
		
	if (!pio_get(UPVEL_BUT_PIO, PIO_INPUT, UPVEL_BUT_IDX_MASK)) {
		// PINO == 0 --> Borda de descida
		btdata.id = 'U';
		btdata.data = 1;
		xQueueSendFromISR(xQueueBTSendData, &btdata, 0);
	} else {
		btdata.id = 'U';
		btdata.data = 0;
		xQueueSendFromISR(xQueueBTSendData, &btdata, 0);
		// PINO == 1 --> Borda de subida
	}
}
void downvel_but_callback(void){
	if (!pio_get(DOWNVEL_BUT_PIO, PIO_INPUT, DOWNVEL_BUT_IDX_MASK)) {
		// PINO == 0 --> Borda de descida
		btdata.id = 'D';
		btdata.data = 1;
		xQueueSendFromISR(xQueueBTSendData, &btdata, 0);
	} else {
		// PINO == 1 --> Borda de subida
		btdata.id = 'D';
		btdata.data = 0;
		xQueueSendFromISR(xQueueBTSendData, &btdata, 0);
	}
}