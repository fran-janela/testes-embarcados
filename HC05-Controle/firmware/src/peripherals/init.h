/*
 * init.h
 *
 * Created: 4/27/2022 10:21:04 AM
 *  Author: Francisco Janela
 */ 


#ifndef INIT_H_
#define INIT_H_

#include <asf.h>
#include "interrupt.h"
#include "aux_bt.h"


//=============================== BUTTONS ===============================//
#define BUT_PIO										PIOA
#define BUT_PIO_ID									ID_PIOA
#define BUT_IDX										11
#define BUT_IDX_MASK								(1 << BUT_IDX)

#define POWER_BUT_PIO								PIOA
#define POWER_BUT_PIO_ID							ID_PIOA
#define POWER_BUT_IDX								0
#define POWER_BUT_IDX_MASK							(1 << POWER_BUT_IDX)

#define UPVEL_BUT_PIO								PIOB
#define UPVEL_BUT_PIO_ID							ID_PIOB
#define UPVEL_BUT_IDX								2
#define UPVEL_BUT_IDX_MASK							(1 << UPVEL_BUT_IDX)

#define DOWNVEL_BUT_PIO								PIOB
#define DOWNVEL_BUT_PIO_ID							ID_PIOB
#define DOWNVEL_BUT_IDX								3
#define DOWNVEL_BUT_IDX_MASK						(1 << DOWNVEL_BUT_IDX)
//================================ LEDS =================================//
#define POWER_LED_PIO								PIOC
#define POWER_LED_PIO_ID							ID_PIOC
#define POWER_LED_IDX								30
#define POWER_LED_IDX_MASK							(1 << POWER_LED_IDX)
//============================== JOYSTICK ===============================//



/*************************************************************************/
/* prototypes                                                            */
/*************************************************************************/
void configure_output(Pio *p_pio, const pio_type_t ul_type, const uint32_t ul_mask, const uint32_t ul_attribute, uint32_t ul_id);
void configure_input(Pio *p_pio, const pio_type_t ul_type, const uint32_t ul_mask, const uint32_t ul_attribute, uint32_t ul_id);
void configure_interruption(Pio *p_pio, uint32_t ul_id, uint32_t ul_mask, uint32_t ul_attr, void (*p_handler) (uint32_t, uint32_t));
void init_io(void);
void configure_console(void);


#endif /* INIT_H_ */