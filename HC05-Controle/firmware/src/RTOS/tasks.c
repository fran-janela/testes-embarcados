/*
 * tasks.c
 *
 * Created: 4/27/2022 2:46:41 PM
 *  Author: franc
 */ 

#include "tasks.h"

void task_bluetooth(void) {
	printf("Task Bluetooth started \n");
	
	printf("Inicializando HC05 \n");
	config_usart0();
	hc05_init();
	
	BTData msg;

	char head = '0';
	char D0 = '0';
	char D1 = '0';
	char eop = 'X';

	// Task não deve retornar.
	while(1) {
		if (xQueueReceive(xQueueBTSendData, &msg, (TickType_t) 500)) {
			char dataArray[2];
			data_convert(dataArray, msg.data);
			
			while(!usart_is_tx_ready(USART_COM)) {
				vTaskDelay(10 / portTICK_PERIOD_MS);
			}
			usart_write(USART_COM, msg.id);
			
			while(!usart_is_tx_ready(USART_COM)) {
				vTaskDelay(10 / portTICK_PERIOD_MS);
			}
			usart_write(USART_COM, dataArray[1]);
			
			while(!usart_is_tx_ready(USART_COM)) {
				vTaskDelay(10 / portTICK_PERIOD_MS);
			}
			usart_write(USART_COM, dataArray[0]);
			
			while(!usart_is_tx_ready(USART_COM)) {
				vTaskDelay(10 / portTICK_PERIOD_MS);
			}
			usart_write(USART_COM, eop);
		}
	}
}