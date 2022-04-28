/*
 * aux_bt.h
 *
 * Created: 4/27/2022 2:51:26 PM
 *  Author: franc
 */ 


#ifndef AUX_BT_H_
#define AUX_BT_H_

#include <asf.h>
#include "conf_board.h"
#include <string.h>

/**************************************************************************

Defining if it is for bluetooth or debugging serial output

-- Uncomment for debugging

**************************************************************************/

//#define DEBUG_SERIAL

#ifdef DEBUG_SERIAL
#define USART_COM USART1
#define USART_COM_ID ID_USART1

#else
#define USART_COM USART0
#define USART_COM_ID ID_USART0
#endif

/*************************************************************************/
/* prototypes                                                            */
/*************************************************************************/
int hc05_init(void);
void config_usart0(void);
void usart_send_command(Usart *usart, char buffer_rx[], int bufferlen, char buffer_tx[], int timeout);
int usart_get_string(Usart *usart, char buffer[], int bufferlen, uint timeout_ms);
void usart_put_string(Usart *usart, char str[]);
uint32_t usart_puts(uint8_t *pstring);



#endif /* AUX_BT_H_ */