/*
 * init.c
 *
 * Created: 4/27/2022 10:21:23 AM
 *  Author: Francisco Janela
 */

#include "init.h"
#include "interrupts.h"

/*************************************************************************/
/* IO Init                                                               */
/*************************************************************************/

void configure_output(Pio *p_pio, const pio_type_t ul_type, const uint32_t ul_mask, const uint32_t ul_attribute, uint32_t ul_id ){
	pmc_enable_periph_clk(ul_id);
	pio_configure(p_pio, ul_type, ul_mask, ul_attribute);
}

void configure_input(Pio *p_pio, const pio_type_t ul_type, const uint32_t ul_mask, const uint32_t ul_attribute, uint32_t ul_id){
	pmc_enable_periph_clk(ul_id);
	pio_configure(p_pio, ul_type, ul_mask, ul_attribute);
	pio_set_debounce_filter(p_pio, ul_mask, 60);
}

void configure_interruption(Pio *p_pio, uint32_t ul_id, uint32_t ul_mask, uint32_t ul_attr, void (*p_handler) (uint32_t, uint32_t)){
	pio_handler_set(p_pio, ul_id, ul_mask, ul_attr, p_handler);
	pio_enable_interrupt(p_pio, ul_mask);
	pio_get_interrupt_status(p_pio);
	NVIC_EnableIRQ(ul_id);
	NVIC_SetPriority(ul_id, 5);
}

void init_io(void){
	// LEDs
	pio_set_output(POWER_LED_PIO, POWER_LED_IDX_MASK, 1, 0, 1);
	// BUTTONS
	configure_input(POWER_BUT_PIO, PIO_INPUT, POWER_BUT_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE, POWER_BUT_PIO_ID);
	configure_input(UPVEL_BUT_PIO, PIO_INPUT, UPVEL_BUT_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE, UPVEL_BUT_PIO_ID);
	configure_input(DOWNVEL_BUT_PIO, PIO_INPUT, DOWNVEL_BUT_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE, DOWNVEL_BUT_PIO_ID);
	configure_interruption(POWER_BUT_PIO, POWER_BUT_PIO_ID, POWER_BUT_IDX_MASK, PIO_IT_EDGE, power_but_callback);
	configure_interruption(UPVEL_BUT_PIO, UPVEL_BUT_PIO_ID, UPVEL_BUT_IDX_MASK, PIO_IT_EDGE, upvel_but_callback);
	configure_interruption(DOWNVEL_BUT_PIO, DOWNVEL_BUT_PIO_ID, DOWNVEL_BUT_IDX_MASK, PIO_IT_EDGE, downvel_but_callback);
}

void configure_console(void) {
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		#if (defined CONF_UART_CHAR_LENGTH)
		.charlength = CONF_UART_CHAR_LENGTH,
		#endif
		.paritytype = CONF_UART_PARITY,
		#if (defined CONF_UART_STOP_BITS)
		.stopbits = CONF_UART_STOP_BITS,
		#endif
	};

	/* Configure console UART. */
	stdio_serial_init(CONF_UART, &uart_serial_options);

	/* Specify that stdout should not be buffered. */
	#if defined(__GNUC__)
	setbuf(stdout, NULL);
	#else
	/* Already the case in IAR's Normal DLIB default configuration: printf()
	* emits one character at a time.
	*/
	#endif
}